#ifndef brendlingerHiggsTestbed_VARIABLES_H
#define brendlingerHiggsTestbed_VARIABLES_H

/**********************************************************************************
 * @Package: MonojetSoftLepton
 * @Class  : Sample
 * @Author : Rustem Ospanov, Doug Schaefer
 *
 * @Brief  :
 * 
 *  Enum for dataset keys (samples) and helper class for a set of samples
 * 
 * To add a variable:
 *  - Add it to the enum Variable
 *  - Update ConvertToVariable
 *  - Update ConvertVarToStr
 *  - If it's an int update VariableIsInt
 *  - Add implementation to xAOD/D3PDWrapper as well as to GetEventVariable
 * 
 **********************************************************************************/

// C/C++
#include <vector>
#include <string>

#include <TH1.h>
#include <TH2.h>

// For the accessors / decorators.
#include "AthContainers/AuxElement.h"

/* #include "brendlingerHiggsTestbed/switch_d3pd_xaod.h" */
/* #ifndef SKIP_XAOD_COMPILATION */
/* #include "xAODPrimitives/IsolationType.h" */
/* #include "xAODMuon/Muon.h" */
/* #endif // SKIP_XAOD_COMPILATION */

// Compatibility if you are compiling in standalone mode
/* #ifdef SKIP_XAOD_COMPILATION */
/* namespace xAOD { */
/*   namespace Muon { */
/*     enum Quality { Tight, /// Highest purity, but lower efficiency */
/*                    Medium, /// Usual recommended wp - a good balance between purity and efficiency */
/*                    Loose, /// Adds segment tagged and calo tagged muons. */
/*                    VeryLoose}; /// Low purity. */
/*   } */
/* } */
/* #endif // SKIP_XAOD_COMPILATION */

/** \brief The KTB namespace */
namespace KTB
{
  namespace ObjType {
    enum ObjType {
      None,
      Electron,
      Muon,
      Tau,
      Jet,
      Photon
    };
  }

  namespace LeptonChannel {
    enum LeptonChannel {
      none = 0
      ,lep0= 1
      ,e   = 2
      ,mu  = 3
      ,ee  = 4
      ,emu = 5
      ,mumu= 6
      ,eee = 7
      ,eem = 8
      ,emm = 9
      ,mmm = 10
      ,eeee = 11
      ,eeem = 12
      ,eemm = 13
      ,emmm = 14
      ,mmmm = 15
      ,gt4leps = 16
    }; 
  }

  //* \brief Enums for variables. */
  enum Variable{
    vNone
    ,vGRL
    ,vSample
    ,vm_yy
    /* ,vpassLarError */
    /* ,vpassTileError */
    /* ,vpassSctError */
    /* ,vpassCoreBit */
    /* ,vpassPrimaryVtx */
    /* ,vNPV */
    /* ,vAverageInteractionsPerCrossing */
    /* ,vActualInteractionsPerCrossing */
    /* ,vpassCosmicMuon */
    /* ,vpassTileTripReader */
    /* ,vpassIncompleteEvents */
    /* ,vpassTileCalHotSpot */
    /* ,vpassBadJet */
    /* ,vpassCaloJet */
    /* ,vpassBadMuon */
    /* ,vpassHFOR */
    /* ,vpassMCOverlap */
    /* ,vpassBCH */
    /* ,vMuIsValid */
    /* ,vnBaselineLeptons */
    /* ,vnBaselineMuons */
    /* ,vnBaselineElectrons */
    /* ,vnSignalLeptons */
    /* ,vnSignalMuons */
    /* ,vnSignalElectrons */
    /* ,vChanFlavor */
    /* ,vSameSign */
    /* ,vNSignalTaus */
    /* ,vmet_Et */
    /* ,vmet_phi */
    /* ,vmet_sumet */
    /* ,vrefEle */
    /* ,vrefEle_etx */
    /* ,vrefEle_ety */
    /* ,vrefEle_sumet */
    /* ,vrefMuo */
    /* ,vrefMuo_etx */
    /* ,vrefMuo_ety */
    /* ,vrefMuo_sumet */
    /* ,vrefJet */
    /* ,vrefJet_etx */
    /* ,vrefJet_ety */
    /* ,vrefJet_sumet */
    /* ,vrefGamma */
    /* ,vrefGamma_etx */
    /* ,vrefGamma_ety */
    /* ,vrefGamma_sumet */
    /* ,vsoftTerm */
    /* ,vsoftTerm_etx */
    /* ,vsoftTerm_ety */
    /* ,vsoftTerm_sumet */
    /* ,vSFOS */
    /* ,vnBjets */
    /* ,vjet0_index */
    /* ,vjet1_index */
    /* ,vlep0_index */
    /* ,vlep1_index */
    /* ,vlep2_index */
    /* ,vlepleadZ_index */
    /* ,vlepsubleadZ_index */
    /* ,vlepW_index */
    /* ,vlepleadMinSFOS_index */
    /* ,vlepsubleadMinSFOS_index */
    /* ,vlepWMinSFOS_index */
    /* ,vantilep0_index */
    /* ,vPtll */
    /* ,vPt3l */
    /* ,vPtllZ */
    /* ,vPtllZmin */
    /* ,vMll */
    /* ,vMll_alt */
    /* ,vMll_ss */
    /* ,vMWjj */
    /* ,vMjjMin */
    /* ,vMinMll */
    /* ,vMTW */
    /* ,vMTWmin */
    /* ,vNJets */
    /* ,vNCentralJets */
    /* ,vNForwardJets */
    /* ,vDeltaRll */
    /* ,vDeltaRllZ */
    /* ,vDeltaRllZmin */
    /* ,vMEToverPtj0 */
    /* ,vPtlloverMET */
    /* ,vPtllZoverMET */
    /* ,vPtllZminoverMET */
    /* ,vMinDeltaPhilMET */
    /* ,vMinDeltaPhi3LMET */
    /* ,vMaxDeltaPhi3LMET */
    /* ,vMaxDeltaPhilJet */
    /* ,vMaxDeltaPhi3LJet */
    /* ,vMinDeltaPhi3LJet */
    /* ,vDeltaPhi3LJet  */
    /* ,vDeltaPhi3LMET  */
    /* ,vDeltaPhiMETJet */
    /* ,vPassTrigger */
    /* ,vLumiBlockMu */
    /* ,vMt */
    /* ,vM3l */
    /* ,vMll_Upsilon */
    /* ,vtruthjet0Pt */
    /* ,vtruthjet1Pt */
    /* ,vnVetoLeptons */
    /* ,vTotalWeight */
    /* ,vTotalWeightNoSF */
    /* ,vTotalWeightNoPupNoSF */
    /* ,vmc_channel_number */
    /* ,vptAvg */
    /* ,vtruthptAvg */
    /* ,vptAvgOverTruthjet0Pt */
    /* ,vDeltaPhill */
    /* ,vWlepPassWSelection */
    /* ,vDeltaPhiLeadZWLep */
    /* ,vDeltaPhiZLeps */
    /* ,vDeltaPhiZWLep */
    /* ,vDeltaPhiZMet */
    /* ,vDeltaPhiZWSyst */
    /* ,vPt3lPlusMet */
    /* ,vPassTriggerEle */
    /* ,vPassTriggerMu */
    /* ,vPassTriggerMatch */
    /* ,vRunNumber */
    /* ,vPtW */
    /* ,vMtWZ */
    /* ,vYZminusYlW */
    /* ,vMtZ */
    /* ,vPtWZ */
    /* ,vEvtTrigSF */
    /* ,vAntiIDSF_lep3 */
    /* ,vAntiIDSF_lep3_pt */
    /* ,vAntiIDSF_lep3_eta */
    /* ,vAntiIDSF_lep3_phi */
    /* ,vAntiIDSF_lep3_flavor */
    /* ,vAntiIDSF_lep3_pt_reco */
    /* ,vAntiIDSF_lep3_eta_reco */
    /* ,vAntiIDSF_lep3_phi_reco */
    /* ,vAntiIDSF_lep3_flavor_reco */
    /* ,vAntiIDSF_lep3_match_DR */
    /* ,vAntiIDSF_lep3_origin */
    /* ,vAntiIDSF_lep3_type */
    /* ,vNlepsFromZ */
    /* ,vAntiIDSF_lep3_truth_origin */
    /* ,vAntiIDSF_lep3_truth_type */
    /* ,vXCheckAntiIDSF_lep3_pt */
    /* ,vXCheckAntiIDSF_lep3_eta */
    /* ,vXCheckAntiIDSF_lep3_phi */
    /* ,vXCheckAntiIDSF_lep3_flavor */
    /* ,vXCheckAntiIDSF_lep3_origin */
    /* ,vXCheckAntiIDSF_lep3_type */
    /* ,vnBaselineJet */
    /* ,vnSignalJet */
    /* ,vLt */
    /* ,vMeff */
    /* ,vMetOverMeff */
    /* ,vHLT_xe110_mht_xe70_L1XE50 */
    /* ,vHLT_xe110_mht_xe75_L1XE50 */
    /* ,vHLT_xe110_mht_L1XE50 */
    /* ,vHLT_xe130_mht_L1XE50 */
    /* ,vcell_xe70 */
    /* ,vcell_xe75 */
    /* ,vtruthmet_Et */
    /* ,vtruthmet_phi */
    // Add_new_variables_here
    ,N_VARIABLES
  };
  // PLEASE DO NOT EDIT THE LINE JUST ABOVE WHICH SAYS Add_new_variables_here

//-----------------------------------------------------------------------------
  enum LepVariable{
    lepNone
    ,lepFlavor
    ,lepPt
    ,lepEta
    ,lepPhi
    ,lepD0Significance
    ,lepZ0SinTheta
    ,lepTrkIso
    ,lepCaloIso
    ,lepTruthDetailed
    ,lepSFRecoIdIso
    ,lepSFTrigger
    ,lepD0
    ,lepCharge
    ,lepElectronID
    ,lepMuonID
    ,lepMt
    ,lepMll
    ,lepPassOR
    ,lepPassBlayer
    ,lepEleEtaBE
    ,lepMatchesTrigger
    ,lepOrigin
    ,lepType
    // Add_new_lepvariables_here
    ,N_LEPVARIABLES
  };
//-----------------------------------------------------------------------------
  enum JetVariable{
    jetNone
    ,jetPt
    ,jetEta
    ,jetPhi
    ,jetE
    // Add_new_jetvariables_here
    ,N_JETVARIABLES
  };

//-----------------------------------------------------------------------------

  class var_props{
  public:
    // T first; // variable enum. Make a new class that inherits from this.
    //
    std::string second; // name
    std::string label;
    int nbins;
    double xlow;
    double xup;
    bool is_int;
    SG::AuxElement::Decorator<float>* decorator;
    SG::AuxElement::Accessor<float>* accessor;
    
    std::string GetXaxisLabel(){return label;};
    bool IsInt(){return is_int;};

    var_props(){
      second = "unknown";
      label = "unknown";
      nbins = 10;
      xlow = 0;
      xup = 1;
      is_int = false;
      decorator = 0;
      accessor = 0;
    };

    var_props(std::string nm,std::string lab,int nb,double lo,double up, bool isint=false){
      second = nm;
      label = lab;
      nbins = nb;
      xlow = lo;
      xup = up;
      is_int = isint;
      decorator = new SG::AuxElement::Decorator<float>(nm);
      accessor = new SG::AuxElement::Accessor<float>(nm);
    };
  };

  template<class T>
  class Tvar_props : public var_props{
  public:
    T first; // the enum
  Tvar_props(T v,std::string nm,std::string lab,int nb,double lo,double up, bool isint=false)
    : var_props(nm,lab,nb,lo,up,isint)
    {
      first = v;
    };
  };

  typedef Tvar_props<KTB::Variable> evtvar_props;
  typedef Tvar_props<KTB::LepVariable> lepvar_props;
  typedef Tvar_props<KTB::JetVariable> jetvar_props;

  const std::vector<KTB::evtvar_props > GetAllEvtVariableProperties();
  const std::vector<KTB::lepvar_props > GetAllLepVariableProperties();
  const std::vector<KTB::jetvar_props > GetAllJetVariableProperties();

  // template
  // GetAllVariableProperties
  // MakeVariableTH1F
  // 

  var_props GetVariableProperties(const std::string& v);
  var_props GetVariableProperties(Variable v);
  var_props GetVariableProperties(LepVariable v);
  var_props GetVariableProperties(JetVariable v);
  /* var_props GetVariableProperties() */

  SG::AuxElement::Accessor<float>* GetAccessor(Variable v);
  SG::AuxElement::Decorator<float>* GetDecorator(Variable v);

  template<class T>
    void SetAccessorIfEmpty(Variable v,T& container,float value){
    if (!(*GetAccessor(v)).isAvailable(*container)) (*GetDecorator(v))(*container) = value;
  }

  /* template<class T> */
  /* const std::vector<T>GetProperties(){ */
  /*   static std::vector<T> props_unused; */
  /*   // specialized instances of this are done elsewhere */
  /*   return props_unused; */
  /* } */

  std::string ConvertVarToStr(Variable v);
  std::string ConvertLepVarToStr(LepVariable v);
  std::string ConvertJetVarToStr(JetVariable v);
  Variable ConvertToVariable(const std::string &v,bool fatal=true);
  LepVariable ConvertToLepVariable(const std::string &v,bool fatal=true);
  JetVariable ConvertToJetVariable(const std::string &v,bool fatal=true);
  int ConvertToInt(std::string s);
  const std::vector<KTB::Variable>& GetAllVariables();
  const std::vector<std::string>& GetAllVariableStrings();
  const std::vector<KTB::LepVariable>& GetAllLepVariables();
  const std::vector<std::string>& GetAllLepVariableStrings();
  const std::vector<KTB::JetVariable>& GetAllJetVariables();
  const std::vector<std::string>& GetAllJetVariableStrings();
  std::string GetXaxisLabel(std::string v);
  std::vector<float> GetVariableHistArgs(std::string v);

  template <class T>
  TH1F* MakeVariableTH1F(std::string hist_location,T v);
  void SetBinLabels(Variable v,TAxis* axis);
  void SetBinLabels(LepVariable v,TAxis* axis);
  void SetBinLabels(JetVariable v,TAxis* axis);
  void SetBinLabels(std::string v,TH1F* hist);
  void SetBinLabels(std::string v1,std::string v2,TH2F* hist);

  template <class T>
  bool VariableIsInt(T v);
  bool VariableIsInt(std::string v);
  
  //void PrintVariable(Sample s);
  //void PrintVariables(std::vector<Sample> s);


//-----------------------------------------------------------------------------
  namespace ElectronID {
    enum ElectronID {
      None
      ,TightLLH
      ,MediumLLH
#ifndef BEFORE_SUSYTOOLS_000611
      ,LooseAndBLayerLLH
#endif // BEFORE_SUSYTOOLS_000611
      ,LooseLLH
      ,VeryLooseLLH
      ,N_ELECTRONID
    };
  }
  std::string ConvertElectronIDToStr(ElectronID::ElectronID e);
  ElectronID::ElectronID ConvertToElectronID(const std::string& e);
  const std::vector<std::pair<KTB::ElectronID::ElectronID,std::string> > GetElectronIDStringPairs(void);
  const std::vector<std::string>& GetAllElectronIDStrings();

  enum ElectronSF {
    ElectronSF_RecoTrk,
    ElectronSF_LooseAndBLayerLLH,
    ElectronSF_LooseAndBLayerLLH_d0z0,
    ElectronSF_TightLLH_d0z0,
    ElectronSF_MediumLLH_d0z0,
    ElectronIsoSF_MediumLLH_d0z0_v8_isolGradientLoose,
    ElectronIsoSF_TightLLH_d0z0_v8_isolGradient,
    ElectronIsoSF_LooseAndBLayerLLH_d0z0_v8_isolLooseTrackOnly,
    // the full analysis scale factors
    EleFullSF_Reco_LooseAndBLayerLLH_d0z0_isolLooseTrackOnly,
    EleFullSF_Reco_MediumLLH_d0z0_v8_isolGradientLoose,
    EleFullSF_Reco_TightLLH_d0z0_v8_isolGradient,
    // electron trigger scale factors for smwz
    ElectronSF_Trigger_MediumLLH_isolGradientLoose,
    ElectronSF_Trigger_TightLLH_isolGradient,
    ElectronSF_TriggerMC_MediumLLH_isolGradientLoose,
    ElectronSF_TriggerMC_TightLLH_isolGradient,
    PhilipAntiID,
    N_ELESF
  };

//-----------------------------------------------------------------------------

  /* const std::vector<std::pair<xAOD::Muon::Quality,std::string> > GetMuonIDStringPairs(void); */
  /* std::string ConvertMuonIDToStr(xAOD::Muon::Quality e); */
  /* xAOD::Muon::Quality ConvertToMuonID(const std::string& e); */

  enum MuonSF {
    MuonSF_Medium,
    MuonSF_Loose,
    MuonSF_Loose_NOSYST,
    MuonSF_isolGradientLoose,
    MuonSF_isolLooseTrackOnly,
    MuonSF_isolLooseTrackOnly_NOSYST,
    MuonSF_TTVA,
    MuonSF_TTVA_NOSYST,
    // 
    MuFullSF_Medium_d0z0_isolGradientLoose,
    MuFullSF_Loose_d0z0_isolLooseTrackOnly,
    N_MUSF
  };

//-----------------------------------------------------------------------------

  enum LeptonTruthLabel {
    NoTruthLabel
    ,LeptonW
    ,LeptonZ
    ,LeptonSUSY
    ,LeptonTtbar
    ,LeptonJpsi
    ,LeptonUnknown
    ,LeptonTau
    ,PhotonOrPi0
    ,PhotonOrPi0Leptonic
    ,PiPlusMinusHadronic
    ,PiPlusMinusLeptonic
    ,KaonHadronic
    ,KaonLeptonic
    ,CjetHadronic
    ,CjetLeptonic
    ,BjetHadronic
    ,BjetLeptonic
    ,LightjetHadronic
    ,LightjetLeptonic
    ,NonPrimary
    ,ElectronAsMuon
    ,ElMagProc
    ,PhotonInMeson
    ,IsoElectronFromCCbar
    ,IsoElectronFromBBbar
    ,PhotonOrElectronAmbiguous
  };
  
  bool IsRealLepton(LeptonTruthLabel l);
  const std::vector<std::pair<KTB::LeptonTruthLabel,std::string> > GetLeptonTruthLabelStringPairs(void);
  const std::vector<std::string>& GetAllLeptonTruthLabelStrings();

//-----------------------------------------------------------------------------
  namespace AnaIso {
    enum AnaIso {
      None
      ,etcone20
      ,etcone30
      ,etcone40
      ,ptcone20
      ,ptcone30
      ,ptcone40
      ,ptvarcone20
      ,ptvarcone30
      ,ptvarcone40
      ,topoetcone20
      ,topoetcone30
      ,topoetcone40
      ,N_NONRELATIVE
      ,etcone20overPt
      ,etcone30overPt
      ,etcone40overPt
      ,ptcone20overPt
      ,ptcone30overPt
      ,ptcone40overPt
      ,ptvarcone20overPt
      ,ptvarcone30overPt
      ,ptvarcone40overPt
      ,topoetcone20overPt
      ,topoetcone30overPt
      ,topoetcone40overPt
      ,N_NONWP
#ifdef BEFORE_SUSYTOOLS_000611
      ,VeryLooseTrackOnly
      ,VeryLoose
#endif
      ,Loose
      ,Tight
      ,Gradient
      ,GradientLoose
      ,LooseTrackOnly
      ,UserDefined
      ,N_ISOLATION
    };
  }
  std::string ConvertAnaIsoToStr(AnaIso::AnaIso a);
  AnaIso::AnaIso ConvertToAnaIso(const std::string& a);
  const std::vector<std::pair<KTB::AnaIso::AnaIso,std::string> > GetAnaIsoStringPairs(void);
  const std::vector<KTB::AnaIso::AnaIso>& GetAllIsolationVariables();

/* #ifndef SKIP_XAOD_COMPILATION */
/*   xAOD::Iso::IsolationType IsoType(AnaIso::AnaIso iso); */
/* #endif // SKIP_XAOD_COMPILATION */
  
//-----------------------------------------------------------------------------
  enum Trigger2015 {
     tNone
     // single-electron
     ,tHLT_e24_lhmedium_iloose
     ,tHLT_e24_lhmedium_iloose_L1EM18VH
     ,tHLT_e24_lhmedium_iloose_L1EM20VH
     ,tHLT_e28_lhtight_iloose
     ,tHLT_e60_lhmedium
     ,tHLT_e24_lhmedium_L1EM20VH
     ,tHLT_e24_lhmedium_L1EM18VH
     ,tHLT_e120_lhloose
     // single-e cut-based (taken from SUSY2)
     ,tHLT_e24_medium_iloose
     ,tHLT_e24_tight_L1EM20V
     ,tHLT_e28_tight_iloose
     ,tHLT_e60_medium
     ,tHLT_e55_loose1
     ,tHLT_e120_loose1
     ,tHLT_e45_loose1
     ,tHLT_e7_medium1
     ,tHLT_e12_medium1
     ,tHLT_e17_medium1
     // di-electron
     ,tHLT_2e17_lhloose
     ,tHLT_e28_lhloose_iloose_e12_lhloose_L1EM3
     // di-electron cut-based (taken from SUSY2)
     ,tHLT_2e12_loose1
     ,tHLT_2e17_loose1
     // tri-electron
     ,tHLT_e18_lhloose_2e9_lhloose_L1EM7V
     // electron supporting
     // electron muon LH based - needs updating in Rel 20
     // electron muon cut-based
     ,tHLT_e17_medium1_mu12
     ,tHLT_e7_medium1_mu24
     // single-muon
     ,tHLT_mu24
     ,tHLT_mu26
     ,tHLT_mu24_imedium
     ,tHLT_mu26_imedium
     ,tHLT_mu50
     ,tHLT_mu60_0eta105_msonly
     ,tHLT_mu20_iloose_L1MU15
     // di-muon
     ,tHLT_2mu10
     ,tHLT_2mu14
     ,tHLT_mu24_mu8noL1
     ,tHLT_mu14_iloose_mu14
     ,tHLT_mu20_imedium_mu8noL1
     ,tHLT_mu20_iloose_mu8noL1
     ,tHLT_mu18_mu8noL1
     ,tHLT_mu20_mu8noL1
     ,tHLT_mu22_mu8noL1
     // tri-muon
     ,tHLT_3mu6
     // Etmiss
     ,tHLT_xe50 // prescaled
     ,tHLT_xe50_cell // prescaled
     ,tHLT_xe50_pueta // prescaled
     ,tHLT_xe70 // prescaled
     ,tHLT_xe70_cell // prescaled
     ,tHLT_xe70_pueta // prescaled
     ,tHLT_xe100
     ,tHLT_xe100_cell
     ,tHLT_xe100_pueta
     // jet-MET
     ,tHLT_j100_xe80noL1
     ,tHLT_j80_xe80noL1 // prescaled?
     // muon-MET
     ,tHLT_mu24_xe100noL1_wEFMu
     // electron-MET
     ,tHLT_e28_tight1_iloose_xe100noL1
     ,tHLT_2e12_lhloose_L12EM10VH        
     ,tHLT_e17_lhloose_2e9_lhloose       
     ,tHLT_mu18_2mu4noL1                 
     ,tHLT_e17_loose_mu14                
     ,tHLT_e24_medium_L1EM20VHI_mu8noL1  
     ,tHLT_e7_medium_mu24                
     ,tHLT_e12_loose_2mu10               
     ,tHLT_2e12_loose_mu10               
     ,tHLT_e24_lhtight_iloose            
     ,tHLT_e26_lhtight_iloose            
     ,tHLT_mu24_iloose_L1MU15
     ,tHLT_2e15_lhloose_L12EM13VH
     ,tHLT_e17_lhloose_nod0_mu14
     ,tHLT_2e15_lhvloose_nod0_L12EM13VH
     // lep-jet-MET ?
     // Supporting triggers!
     ,tHLT_e5_lhvloose
     ,tHLT_e10_lhvloose_L1EM7
     ,tHLT_e15_lhvloose_L1EM7
     ,tHLT_e24_lhvloose_L1EM18VH
     ,tHLT_e50_lhvloose_L1EM15
     ,tHLT_e70_lhvloose
     ,tHLT_e100_lhvloose
     ,tHLT_mu4
     ,tHLT_mu14
     ,tHLT_mu18 
     //e-mu trigger
     ,tHLT_e17_lhloose_mu14
     ,tHLT_xe100_mht_L1XE50
     ,N_TRIGGERS
  };

  std::string ConvertTrigToStr(Trigger2015 t);
  Trigger2015 ConvertToTrigger(const std::string& t);
  const std::vector<KTB::Trigger2015>& GetAllTriggers();
  const std::vector<std::pair<KTB::Trigger2015,std::string> > GetTriggerProperties();

}

#endif // brendlingerHiggsTestbed_VARIABLES_H
