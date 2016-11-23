#include "brendlingerHiggsTestbed/SkimAndSlimAndAdd.h"
#include "HGamAnalysisFramework/HgammaIncludes.h"
#include "HGamAnalysisFramework/HGamVariables.h"
#include "brendlingerHiggsTestbed/NewHgamVariables.h"
#include <EventLoop/Worker.h>

// this is needed to distribute the algorithm to the workers
ClassImp(SkimAndSlimAndAdd)

SkimAndSlimAndAdd::SkimAndSlimAndAdd(const char *name)
  : HgammaAnalysis(name),
    m_plots(0)
{ }

SkimAndSlimAndAdd::~SkimAndSlimAndAdd() {}

EL::StatusCode SkimAndSlimAndAdd::initialize() {
  HgammaAnalysis::initialize();

  m_plots = new KTB::Plots("KurtPlots");  
  if (config()->isDefined("SkimAndSlimAndAdd.Samples"))
    m_plots->set_Samples(config()->getStr("SkimAndSlimAndAdd.Samples","").Data());
  m_plots->init();
  m_plots->PrintConfiguration();

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode SkimAndSlimAndAdd::createOutput() {

  Info("initialize","Beginning of createoutput");

  event()->setAuxItemList("HGamPhotonsAux.","pt.eta.phi.m.zvertex");
  event()->setAuxItemList("EventInfoAux.","bcid.eventTypeBitmask.runNumber.lumiBlock");
  event()->setAuxItemList("HGamEventInfoAux.","m_yy");
   
  Info("initialize","End of createoutput");
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode SkimAndSlimAndAdd::execute() {
  //Info("execute","Beginning of execute");
  //ANA_CHECK_SET_TYPE( EL::StatusCode );

  HgammaAnalysis::execute();

  // set current sample.
  
  if (m_currentsample == KTB::kunlabeled) {
    if (isMC()) m_currentsample = KTB::ConvertToSample(eventInfo()->mcChannelNumber());
    else m_currentsample = KTB::kdata;
  }

  if ( !( 100000. < var::m_yy() && var::m_yy() < 165000.) ) return EL::StatusCode::SUCCESS;

  // This works!!!
  const xAOD::EventInfo* hgamEI;
  event()->retrieve(hgamEI,"HGamEventInfo");
  
  // actually not necessary to do the copy.
  //xAOD::PhotonContainer photons = photonHandler()->getCorrectedContainer();

  //if (!(*GetAccessor(KTB::vGRL)).isAvailable(*hgamEI)) (*GetDecorator(KTB::vGRL))(*hgamEI) = 1;
  SetAccessorIfEmpty(KTB::vGRL,hgamEI,1);
  SetAccessorIfEmpty(KTB::vSample,hgamEI,m_currentsample);

  double weight = 1;
  m_plots->FillVariableHistograms(*hgamEI,m_currentsample,weight);
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

EL::StatusCode SkimAndSlimAndAdd::finalize() {

  // 
  m_plots->SaveAllNonEmptyHistograms(*wk());

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode SkimAndSlimAndAdd::fileExecute() {
  m_currentsample = KTB::kunlabeled;
  return EL::StatusCode::SUCCESS;
}
