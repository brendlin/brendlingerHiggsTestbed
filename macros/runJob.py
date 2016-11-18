#!/bin/usr/env python

import ROOT
import os,sys

#-------------------------------------------------------------------------
def getOutputName(outname,put_in_run_directory=True,preserve_dir=False) :
    import datetime,os
    #ctime = datetime.datetime.now()
    #thetime = ctime.strftime('%Y_%m_%d_%H_%M_%S')
    rootcorebindir = os.getenv('ROOTCOREBIN')
    if put_in_run_directory :
        os.system('mkdir -p %s/../run'%(rootcorebindir))
    #dirName = "%s/../run/%s_%s"%(rootcorebindir,outname,thetime)
    if put_in_run_directory and outname[0] != '/' :
        dirName = "%s/../run/%s"%(rootcorebindir,outname)
    else :
        dirName = "%s"%(outname)
    if os.path.exists(dirName) and not preserve_dir :
        print 'Warning: Output directory exists.'
        tmp = raw_input('Please enter a new output directory (or press enter to overwrite old one): ')
        if not tmp : 
            #
            # Remove very safely.
            #
            def ClearDir(_dir) :
                if os.path.exists(_dir) : 
                    cmd = 'rm %s/*'%_dir ; print cmd; 
                    if os.listdir(_dir) :
                        os.system(cmd)
                    cmd = 'rmdir %s'%_dir; print cmd;
                    os.system(cmd)
                return
            
            ClearDir('%s/%s'%(dirName,'output-SKIM'))
            ClearDir('%s/%s'%(dirName,'data-SKIM'  ))
            ClearDir('%s/%s'%(dirName,'output-MxAOD'))
            ClearDir('%s/%s'%(dirName,'data-MxAOD'))
            ClearDir('%s/%s'%(dirName,'hist'       ))
            ClearDir('%s/%s'%(dirName,'input'      ))
            ClearDir('%s/%s/%s'%(dirName,'fetch','data-SKIM'))
            ClearDir('%s/%s/%s'%(dirName,'fetch','data-MxAOD'))
            ClearDir('%s/%s'%(dirName,'fetch'      ))
            ClearDir('%s/%s'%(dirName,'run'        ))
            ClearDir('%s/%s'%(dirName,'submit'     ))
            ClearDir('%s/%s'%(dirName,'veto'       ))
            ClearDir('%s/%s'%(dirName,'tmp'        ))
            ClearDir('%s'   %(dirName))

        else :
            dirName = "%s/../run/%s"%(rootcorebindir,tmp)

    return dirName

def LoadRootCore() :
    import ROOT
    if 'RootCore' not in ROOT.gSystem.GetLibraries() :
        print 'Loading c++...'
        ROOT.gROOT.ProcessLine (".x $ROOTCOREDIR/scripts/load_packages.C")
        # Some weird bug where functions are not accessible until a class is called
        # ROOT.PSL.EDM
    return

#-------------------------------------------------------------------------
def main (options,args) :
    
    outputname = getOutputName(options.out,put_in_run_directory=False)
    LoadRootCore()

    myjob = ROOT.EL.Job()
    myjob.options().setString (ROOT.EL.Job.optXaodAccessMode, ROOT.EL.Job.optXaodAccessMode_branch)
    #myjob.options().setString (ROOT.EL.Job.optXaodAccessMode, ROOT.EL.Job.optXaodAccessMode_class)
    #myjob.options().setString (ROOT.EL.Job.optXaodAccessMode, ROOT.EL.Job.optXaodAccessMode_athena)
    if not options.alg :
        print 'Error! You must specify an algorithm!'
        sys.exit()
    exec ('alg = ROOT.%s("%s")'%(options.alg,options.alg))
    conf = ROOT.HG.Config()
    conf.addFile(options.config)

    # TEnv uses value from first file it's specified in.
    # If specified, read in additional configuration
    if (conf.isDefined("Include")) :
        for cfg in conf.getStrV("Include") :
            conf.addFile(cfg);

    # Fill unspecified values from default config, specified here.
    if not conf.isDefined("BaseConfig") :
        print 'You must specify a base configuration file, option: BaseConfig. Exiting.'
        sys.exit()
    conf.addFile(ROOT.PathResolverFindCalibFile(conf.getStr("BaseConfig").Data()))

    conf.setValue('OutputDir',outputname)
    alg.setConfig(conf);
    myjob.algsAdd(alg)
    myjob.options().setDouble(ROOT.EL.Job.optMaxEvents,options.n)

    # RunUtils has:
    # InputFileList from conf (uses SH::readFileList)
    # addGrid (InputFaxDS)
    # files from argv command line
    # (could also do scanDir or whatever)

    myhandler = ROOT.SH.SampleHandler()

    # local file
    if '.root' in options.input :
        fileName = options.input
        sample = ROOT.SH.SampleLocal(options.input.split('/')[-1].replace('.root',''))
        sample.add(fileName)
        myhandler.add(sample)
    
    # Dataset stored on DESY-HH_LOCALGROUPDISK
    else :
        if not os.getenv('ATLAS_LOCAL_DQ2CLIENT_PATH') :
            print 'Error! Please execute localSetupDQ2Client and voms-proxy-init!'
            sys.exit()
            
        ROOT.SH.scanRucio(myhandler,options.input)

        # srm://srm.ndgf.org
        # root://ftp1.ndgf.org
        # srm://dcache-se-atlas.desy.de/pnfs/desy.de/atlas/dq2
        disk = 'DESY-HH_LOCALGROUPDISK'
        ROOT.SH.makeGridDirect(myhandler,disk,'srm://dcache-se-atlas.desy.de','',False) 
        # last argument is for partial datasets

    ROOT.SH.scanNEvents(myhandler)
    myhandler.printContent()
    myhandler.setMetaString('nc_tree','CollectionTree') # must be done AFTER scanDir
    myjob.sampleHandler(myhandler)
    myhandler.setMetaDouble(ROOT.EL.Job.optEventsPerWorker,options.max)

    if options.sge :
        driver = ROOT.EL.GEDriver();
        myjob.options().setString(ROOT.EL.Job.optSubmitFlags, '-q default.q,short.q,long.q  -l os=sld6 -l site=hh -l h_vmem=4G')
    else :
        driver = ROOT.EL.DirectDriver()
    
    driver.submit(myjob,outputname)

    return 0

if __name__ == "__main__":
    from optparse import OptionParser
    p = OptionParser()
    #
    # Options to input data. isData and isAtlfast are only used when --input is specified.
    #
    p.add_option('-i','--input',type  ='string'     ,default=''   ,dest='input'  ,help='input directory (as ready by SH)')
    # p.add_option('--isData'   ,action='store_true',default=False,dest='isData'   ,help='IsData'   )
    # p.add_option('--isAtlfast',action='store_true',default=False,dest='isAtlfast',help='isAtlfast')
    # p.add_option('--mc15a'    ,action='store_true',default=False,dest='mc15a'    ,help='(for pileup reweighting) is it mc15a? Default is mc15c.')
    # p.add_option('--mc15b'    ,action='store_true',default=False,dest='mc15b'    ,help='(for pileup reweighting) is it mc15a? Default is mc15c.')

    # p.add_option('--samples'  ,type  ='string'     ,default=''   ,dest='samples',help='input samples (see Sample.h)')
    p.add_option('--alg'      ,type  ='string'     ,default=''   ,dest='alg'    ,help='algorithm (SkimAndSlim, HGamCutflowAndMxAOD, ...')
    #
    # Other options
    #
    p.add_option('-n','--n',type  ='int'        ,default=-1    ,dest='n'     ,help='max nevents to run over'  )
    p.add_option('--max'   ,type  ='int'        ,default=500000,dest='max'   ,help='max nevents per condor/sge process'  )
    # p.add_option('--dconfig',type  ='string',default='DefaultConfiguration_mc15.conf',dest='dconfig',help='default config file' )
    p.add_option('--config' ,type  ='string',default='sr3l_soft.conf'           ,dest='config' ,help='config file' )
    p.add_option('--out'   ,type  ='string'    ,default='out'   ,dest='out',help='output name' )
    # p.add_option('--treename'  ,type  ='string',default='susy'  ,dest='treename',help='tree name' )
    # p.add_option('--skim'  ,action='store_true',default=False  ,dest='skim',help='do a skim (d3pd)' )
    # p.add_option('--grid'  ,action='store_true',default=False  ,dest='grid',help='send to grid (d3pd)' )
    # p.add_option('--submit',action='store_true',default=False  ,dest='submit',help='Submit to grid (d3pd)' )
    # p.add_option('--ntuple',action='store_true',default=False  ,dest='ntuple',help='write an ntuple' )
    # p.add_option('--condor',action='store_true',default=False  ,dest='condor',help='use condor' )
    p.add_option('--sge',action='store_true',default=False  ,dest='sge',help='use SGE driver' )
    # p.add_option('--gridsamples',type ='string',default='GridSamples.txt',dest='gridsamples',help='Grid samples text file' )
    # p.add_option('--tag',type  ='string'    ,default='dc14_ew01'   ,dest='tag',help='dataset tag' )
    # p.add_option('--truth'  ,action='store_true',default=False  ,dest='truth',help='truth level analysis on truth DAODs' )
    # p.add_option('--susy'  ,action='store_true',default=False  ,dest='susy',help='Use susy object selection (instead of WZ object selection)' )
    # p.add_option('--susy2016'  ,action='store_true',default=False  ,dest='susy2016',help='Use susy2016 object selection (instead of WZ object selection)' )
    # p.add_option('--systematics'  ,action='store_true',default=False  ,dest='systematics',help='Run all systematic variations' )

    options,args = p.parse_args()
    # if options.grid :
    #    options.skim = True

    # if options.systematics and not options.condor :
    #     print 'You are trying to run all systematics locally. Please use --condor.'
    #     import sys
    #     sys.exit()

    main(options,args)
