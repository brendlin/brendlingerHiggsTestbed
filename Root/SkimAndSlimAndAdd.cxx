#include "brendlingerHiggsTestbed/SkimAndSlimAndAdd.h"
#include "HGamAnalysisFramework/HgammaIncludes.h"
#include "HGamAnalysisFramework/HGamVariables.h"
#include "brendlingerHiggsTestbed/NewHGamVariables.h"
#include "brendlingerHiggsTestbed/Utils.h"
#include <EventLoop/Worker.h>

//#include "xAODCutFlow/CutBookkeeper.h"
//#include "xAODCutFlow/CutBookkeeperContainer.h"

//#include "PhotonVertexSelection/PhotonPointingTool.h"

// this is needed to distribute the algorithm to the workers
ClassImp(SkimAndSlimAndAdd)

SG::AuxElement::Decorator<float> SkimAndSlimAndAdd::randomvarc("randomvarc");

SG::AuxElement::Accessor<float> SkimAndSlimAndAdd::randomvarc_acc("randomvarc");

SkimAndSlimAndAdd::SkimAndSlimAndAdd(const char *name)
: HgammaAnalysis(name) { }

SkimAndSlimAndAdd::~SkimAndSlimAndAdd() {}

EL::StatusCode SkimAndSlimAndAdd::createOutput() {

  Info("initialize","Beginning of createoutput");

  //HgammaAnalysis::initialize();

  // Setup TEvent and TStore pointers... apparently these are private. WTF.
  //m_event = wk()->xaodEvent();
  //m_store = wk()->xaodStore();

  event()->setAuxItemList("HGamMicroPhotonsAux.","pt.eta.phi.m.zvertex");
  event()->setAuxItemList("HGamPhotonsAux.","pt.eta.phi.m.zvertex");
  event()->setAuxItemList("EventInfoAux.","bcid.eventTypeBitmask.runNumber.lumiBlock.kurtvar.randomvar.randomvarb.m_yy.randomvarc");
  event()->setAuxItemList("HGamMicroEventInfoAux.","runNumber.kurtvar.randomvar.randomvarb.m_yy.numberOfPrimaryVertices");
   
  // Setup output TEvent and file
//   TFile *file = wk()->getOutputFile("MxAOD");
//   m_outEvent = new xAOD::TEvent(xAOD::TEvent::kClassAccess);
//   ANA_CHECK( m_outEvent->writeTo(file) );

  // pick up the pointer? So we get a chance to mess with it?
  // m_outEvent = wk()->getOutputFile("MxAOD");

//   m_outEvent = wk()->xaodEvent();

  Info("initialize","End of createoutput");
  return EL::StatusCode::SUCCESS;
}

// EL::StatusCode SkimAndSlimAndAdd::fileExecute() {
//   Info("fileExecute","Beginning of fileExecute");
//   HgammaAnalysis::fileExecute();
//   Info("fileExecute","End of fileExecute");
//   return EL::StatusCode::SUCCESS;
// }

EL::StatusCode SkimAndSlimAndAdd::execute() {
  //Info("execute","Beginning of execute");
  ANA_CHECK_SET_TYPE( EL::StatusCode );

  HgammaAnalysis::execute();

  // Record a container and its aux...?
//   ANA_CHECK(kurt::recordInfo<xAOD::EventInfo>(*(wk()->xaodEvent()),*m_outEvent,"EventInfo"));

//   std::cout << "mu: " << eventHandler()->mu() << std::endl;
//   //eventHandler()->getVar<int>("N_j_btag");

  //eventHandler()->storeVariable("randomvar",99.); // This saves the info to EventInfo
  float randomvarb = 99.;
  eventHandler()->storeVar<float>("randomvarb",randomvarb); // Saves info to HGamMicroEventInfo
  //std::cout << var::m_yy() << std::endl;
  var::m_yy.addToStore(/*truth*/false);
  var::kurtvar.addToStore(/**/false);
  eventHandler()->runNumber();
  //eventHandler()->numberOfPrimaryVertices();


  // This works!!!
  const xAOD::EventInfo* eventInfoEvent;
  event()->retrieve(eventInfoEvent,"EventInfo");
  
  if (!randomvarc_acc.isAvailable(*eventInfoEvent)) {
    std::cout << "randomvarc does not seem like it is here." << std::endl;
    randomvarc(*eventInfoEvent) = 77.;
  }
  else {
    std::cout << "randomvarc is here!." << std::endl;
  }

  //eventHandler()->storeVar(randomvarc,77.);

  xAOD::PhotonContainer photons = photonHandler()->getCorrectedContainer();

  event()->copy("HGamPhotons");
  //photonHandler()->writeContainer(photons,"HGamMicroPhotons");
  // uhh the nominal event handler gets written or something.
  eventHandler()->write(); // this is like the nominal EventInfo...
  // Adds all event variables (weight, category, isPassed, and pT_yy etc.)
  // to the TEvent output stream
  // HG::VarHandler::getInstance()->write(); // yeah this does not work because there is no way to rename the output container.
  //ANA_CHECK(kurt::recordInfo<xAOD::EventInfo>(*(event()),"HGamMicroEventInfo")); // also not quite right. More intended for particle containers.

  // sketch out EventInfo "write" here
  // Probably not necessary anymore... yay!
//   xAOD::EventInfo* eventInfo = HG::VarHandler::getInstance()->getEventInfoFromStore();
//   xAOD::EventInfo *copy = new xAOD::EventInfo();
//   xAOD::AuxInfoBase *copyAux = new xAOD::AuxInfoBase();
//   copy->setStore(copyAux);
//   *copy = *eventInfo;
//   std::string name = "HGamMicroEventInfo"; // getEventInfoName();
//   if (!event()->record(copy, name)) return EL::StatusCode::FAILURE;
//   name += "Aux.";
//   if (!event()->record(copyAux, name)) return EL::StatusCode::FAILURE;

  event()->fill();

//   // Save output
  // m_outEvent->fill();

//   Info("execute","End of execute");
  return EL::StatusCode::SUCCESS;
}

// EL::StatusCode SkimAndSlimAndAdd::finalize() {

//   Info("finalize","Beginning of finalize");

//   // Finish writing output xAOD
//   TFile *file = wk()->getOutputFile("MxAOD");
//   ANA_CHECK( m_outEvent->finishWritingTo(file) );
//   SafeDelete( m_outEvent );

//   Info("finalize","End of finalize");
  
//   return EL::StatusCode::SUCCESS;
// }
