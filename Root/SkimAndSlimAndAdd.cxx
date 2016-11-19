#include "brendlingerHiggsTestbed/SkimAndSlimAndAdd.h"
#include "HGamAnalysisFramework/HgammaIncludes.h"
#include "HGamAnalysisFramework/HGamVariables.h"
#include "brendlingerHiggsTestbed/NewHGamVariables.h"
#include "brendlingerHiggsTestbed/Utils.h"
#include <EventLoop/Worker.h>

// this is needed to distribute the algorithm to the workers
ClassImp(SkimAndSlimAndAdd)

SG::AuxElement::Decorator<float> SkimAndSlimAndAdd::randomvarc("randomvarc");

SG::AuxElement::Accessor<float> SkimAndSlimAndAdd::randomvarc_acc("randomvarc");

SkimAndSlimAndAdd::SkimAndSlimAndAdd(const char *name)
: HgammaAnalysis(name) { }

SkimAndSlimAndAdd::~SkimAndSlimAndAdd() {}

EL::StatusCode SkimAndSlimAndAdd::createOutput() {

  Info("initialize","Beginning of createoutput");

  event()->setAuxItemList("HGamPhotonsAux.","pt.eta.phi.m.zvertex");
  event()->setAuxItemList("EventInfoAux.","bcid.eventTypeBitmask.runNumber.lumiBlock.randomvarc");
  event()->setAuxItemList("HGamEventInfoAux.","m_yy.randomvarc");
   
  Info("initialize","End of createoutput");
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode SkimAndSlimAndAdd::execute() {
  //Info("execute","Beginning of execute");
  ANA_CHECK_SET_TYPE( EL::StatusCode );

  HgammaAnalysis::execute();

  if ( !( 100000. < var::m_yy() && var::m_yy() < 165000.) ) return EL::StatusCode::SUCCESS;

  // This works!!!
  const xAOD::EventInfo* hgamEI;
  event()->retrieve(hgamEI,"HGamEventInfo");
  
  if (!randomvarc_acc.isAvailable(*hgamEI)) randomvarc(*hgamEI) = 77.;

  // actually not necessary to do the copy.
  //xAOD::PhotonContainer photons = photonHandler()->getCorrectedContainer();

  eventHandler()->write(); // this is like the nominal EventInfo...
  event()->copy("HGamPhotons");
  event()->copy("HGamElectrons");
  event()->copy("HGamMuons");
  event()->copy("HGamAntiKt4EMTopoJets");
  event()->copy("HGamMET_Reference_AntiKt4EMTopo");
  event()->copy("HGamEventInfo");
  event()->fill();

//   Info("execute","End of execute");
  return EL::StatusCode::SUCCESS;
}
