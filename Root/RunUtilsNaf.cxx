#include "brendlingerHiggsTestbed/RunUtilsNaf.h"
#include "HGamAnalysisFramework/Config.h"
#include <SampleHandler/SampleLocal.h>
#include <EventLoop/GEDriver.h>

// See header file for documentation

namespace HG {

  HG::StrV parseArgumentsPrime(Config *conf, int argc, char **argv)
  {
    StrV files;
    for (int argi=1; argi<argc; ++argi) {
      TString arg=argv[argi];
      
      // 1. Check if argument is a configuration file. If so add it!
      if ( arg.EndsWith(".cfg") || arg.EndsWith(".config" )) {
        conf->addFile(arg); continue;
      }
      
      // 2. If the argument contains ".root", i.e. *.root*, add it to files to run over
      if (arg.Contains(".root")) {
        files.push_back(arg); continue;
      }
      
      // 3. If the arguemnt ends with colon, add a new argument
      if (arg.EndsWith(":")) {
        TString key(arg); key.ReplaceAll(":","");
        conf->setValue(key,argv[++argi]); continue;
      }
      
      // if we get here, the arguemnt cannot be understood
      HG::fatal("Cannot interpret argument: "+arg);
    }

    return files;
  }
    
  void runJobNaf(HgammaAnalysis *alg, int argc, char** argv) {
    /*
     *  Fetch the program name and create a help
     */
    //TString help = getHelp(argv[0]);
    
    /*
     *   1. Let's read the configuration
     */
    
    Config conf;
    StrV files = parseArgumentsPrime(&conf, argc, argv);
    
    // TEnv uses value from first file it's specified in.
    // If specified, read in additional configuration
    if (conf.isDefined("Include"))
      for (TString cfg : conf.getStrV("Include"))
        conf.addFile(cfg);
  
    // Fill unspecified values from default config, specified here.
    if (!conf.isDefined("BaseConfig")) {
       HG::fatal("You must specify a base configuration file, option: BaseConfig. Exiting.");
    } else {
       conf.addFile(PathResolverFindCalibFile(conf.getStr("BaseConfig").Data()));
    }
   
    // what's the sample name ?
    TString progName = argv[0];
    TString sampleName = conf.getStr("SampleName","sample");
    TString submitDir  = conf.getStr("OutputDir",progName+"_DATE");
    if (submitDir.Contains("DATE")) {
      TDatime now = TDatime();
      submitDir.ReplaceAll("DATE",Form("%d.%.2d.%.2d_%.2d.%.2d.%.2d",
                                       now.GetYear(),now.GetMonth(),now.GetDay(),
                                       now.GetHour(),now.GetMinute(),now.GetSecond()));
      conf.setValue("OutputDir", submitDir.Data());
    }
    
    // print wether the DC14 is activated (in Makefile.RootCore)
#ifdef __Rel20p1__
    printf("  Code setup assumes release 20.1 input. That is, you should be using AnaBase,2.3.X\n");
#elif __Rel20p7__
    printf("  Code setup assumes release 20.7 input. That is, you should be using AnaBase,2.4.X\n");
#else
    printf("  This base release isn't known to the code. Proceed at your own risk!\n");
#endif
    
    printf("\n");
    printf("  %20s  %s\n", "SampleName:", sampleName.Data());
    printf("  %20s  %s\n", "OutputDir:", submitDir.Data());

    if ( HG::fileExist(submitDir) )
      fatal("Output directory "+submitDir+" already exist.\n"+
            "  Rerun after deleting it, or specifying a new one, like below.\n"+
            "    OutputDir: NEWDIR");
    
    // Add the confiuration to the algorithm!
    alg->setConfig(conf);
    
    /******************
     *
     *  Handling of the input
     *
     */

    // create a new sample handler to describe the data files we use
    SH::SampleHandler sh;
    
    // this is the basic description of our job
    EL::Job job;

    // Set to branch access mode
    TString accessMode = conf.getStr("xAODAccessMode", "class");
    if (accessMode == "branch") {
      job.options()->setString(EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_branch);
    } else if (accessMode == "class") {
      job.options()->setString(EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_class);
    } else if (accessMode == "athena") {
      job.options()->setString(EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_athena);
    } else {
      fatal("xAODAccessMode not recognized, should be on of: class, branch, athena");
    }

    // Add our algorithm to the job
    job.algsAdd(alg);
    
    /*
     *  1. Individual input files
     */

    // add to the input file list if specified
    if (conf.isDefined("InputFile"))
      for (auto file : conf.getStrV("InputFile")) files.push_back(file);
    
    if (files.size()) {
      // If one or several root files are specified as arugment, run over these
      std::auto_ptr<SH::SampleLocal> sample (new SH::SampleLocal (sampleName.Data()));
      printf("\n  %s\n","InputFiles:");
      for ( TString file : files ) {
        printf("    %s\n",file.Data());
        sample->add (file.Data());
      }
      printf("\n");

      // add the files to the sample handler
      sh.add (sample.release());

    } else if (conf.isDefined("InputFaxDS")) {
      SH::addGrid(sh, conf.getStr("InputFaxDS").Data());
    } else if (conf.isDefined("InputFileList")) {

      /*
       *  3. Input file sumbission
       */
      TString fileList=conf.getStr("InputFileList");
      printf("  %20s  %s\n", "InputFileList:", fileList.Data());
      if (!HG::fileExist(fileList))
	fileList = gSystem->ExpandPathName(("$ROOTCOREBIN/data/"+fileList).Data());
      if (!HG::fileExist(fileList))
        HG::fatal("The input file-list specified: "+conf.getStr("InputFileList")+" doesn't exist.");
      SH::readFileList(sh, sampleName.Data(), fileList.Data());

      printf("\n  %20s  %s\n\n","InputFileList:",fileList.Data());
      // print out the files
      sh.print();
    } else {
      fatal("No input specified!");
    }

    // set the name of the tree in our files
    // in the xAOD the TTree containing the EDM containers is "CollectionTree"
    // what does "nc_tree" mean??
    sh.setMetaString ("nc_tree", "CollectionTree");
    job.sampleHandler(sh);

    // First check whether ROOTCORE is set to use multiple CPUs
    // Since it's buggy on lxplus, force user to specify in config file for now
    // TString var = gSystem->ExpandPathName("$ROOTCORE_NCPUS");
    // if (var != "") numWorkers = atoi(var.Data());

    // Set number of events to be processed
    if (conf.isDefined("NumEvents"))
      job.options()->setDouble(EL::Job::optMaxEvents, conf.getInt("NumEvents"));

    // Set number of events to be skipped
    if (conf.isDefined("SkipEvents"))
      job.options()->setDouble(EL::Job::optSkipEvents, conf.getInt("SkipEvents"));

    EL::GEDriver driver;
    driver.submit(job, submitDir.Data());

    //-----------------------------------------------------------------
    
    printf("\n  Output directory: %s\n",submitDir.Data());
    printf("  xAOD ouptut in:   %s/data-MxAOD\n\n",submitDir.Data());
    
  } // runJob
  
  
} // namespace HG
