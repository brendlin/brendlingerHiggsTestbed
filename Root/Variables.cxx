#include "brendlingerHiggsTestbed/Variables.h"

#include <iomanip>
#include <iostream>

#include <brendlingerHiggsTestbed/Messaging.h>
#include "brendlingerHiggsTestbed/UtilCore.h"
#include <brendlingerHiggsTestbed/Sample.h>

const std::vector<KTB::evtvar_props> KTB::GetAllEvtVariableProperties(){
  static std::vector<KTB::evtvar_props> p;
  if (p.empty()){
    //                    enum                   name in c++             axis label             nbins,  xdn,  xup, is_int
    p.push_back(evtvar_props(vNone                 ,"None"                 ,"None"                 ,   2,    0,    2,true));
    p.push_back(evtvar_props(vGRL                  ,"GRL"                  ,"GRL"                  ,   2,    0,    2,true));
    p.push_back(evtvar_props(vSample               ,"Sample"               ,"Sample"               ,  kEndOfNonOverlapping,0,kEndOfNonOverlapping,true));
    p.push_back(evtvar_props(vm_yy                 ,"m_yy"                 ,"m_{#gamma#gamma}"     , 100,  100000,  160000,false));
    // p.push_back(evtvar_props(vpassLarError         ,"passLarError"         ,"passLarError"         ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassTileError        ,"passTileError"        ,"passTileError"        ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassSctError         ,"passSctError"         ,"passSctError"        ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassCoreBit          ,"passCoreBit"          ,"passCoreBit"          ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassPrimaryVtx       ,"passPrimaryVtx"       ,"passPrimaryVtx"       ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vNPV                  ,"NPV"                  ,"NPV"                  ,   50,   0,   50,true));
    // p.push_back(evtvar_props(vAverageInteractionsPerCrossing,"AverageInteractionsPerCrossing","AverageInteractionsPerCrossing",50,0,50));
    // p.push_back(evtvar_props(vActualInteractionsPerCrossing,"ActualInteractionsPerCrossing","ActualInteractionsPerCrossing",50,0,50));
    // p.push_back(evtvar_props(vpassCosmicMuon       ,"passCosmicMuon"       ,"passCosmicMuon"       ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassTileTripReader   ,"passTileTripReader"   ,"passTileTripReader"   ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassIncompleteEvents ,"passIncompleteEvents" ,"passIncompleteEvents" ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassTileCalHotSpot   ,"passTileCalHotSpot"   ,"passTileCalHotSpot"   ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassBadJet           ,"passBadJet"           ,"passBadJet"           ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassCaloJet          ,"passCaloJet"          ,"passCaloJet"          ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassBadMuon          ,"passBadMuon"          ,"passBadMuon"          ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassHFOR             ,"passHFOR"             ,"passHFOR"             ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassMCOverlap        ,"passMCOverlap"        ,"passMCOverlap"        ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vpassBCH              ,"passBCH"              ,"passBCH"              ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vMuIsValid            ,"MuIsValid"            ,"MuIsValid"            ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vnBaselineLeptons     ,"nBaselineLeptons"     ,"nBaselineLeptons"     ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnBaselineMuons       ,"nBaselineMuons"       ,"nBaselineMuons"       ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnBaselineElectrons   ,"nBaselineElectrons"   ,"nBaselineElectrons"   ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnSignalLeptons       ,"nSignalLeptons"       ,"nSignalLeptons"       ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnSignalMuons         ,"nSignalMuons"         ,"nSignalMuons"         ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnSignalElectrons     ,"nSignalElectrons"     ,"nSignalElectrons"     ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vChanFlavor           ,"ChanFlavor"           ,"ChanFlavor"           ,  17,    0,   17,true));
    // p.push_back(evtvar_props(vSameSign             ,"SameSign"             ,"SameSign"             ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vNSignalTaus          ,"NSignalTaus"          ,"NSignalTaus"          ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vmet_Et               ,"met_Et"               ,"E_{T}^{miss} [GeV]"   , 400,    0,  400));
    // p.push_back(evtvar_props(vmet_phi              ,"met_phi"              ,"met_phi"              , 100,   -4,    4));
    // p.push_back(evtvar_props(vmet_sumet            ,"met_sumet"            ,"met_sumet"            , 100,    0, 1800));
    // p.push_back(evtvar_props(vrefEle               ,"refEle"               ,"refEle"               , 100,    0,  500));
    // p.push_back(evtvar_props(vrefEle_etx           ,"refEle_etx"           ,"refEle_etx"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefEle_ety           ,"refEle_ety"           ,"refEle_ety"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefEle_sumet         ,"refEle_sumet"         ,"refEle_sumet"         , 100,    0,  500));
    // p.push_back(evtvar_props(vrefMuo               ,"refMuo"               ,"refMuo"               , 100,    0,  500));
    // p.push_back(evtvar_props(vrefMuo_etx           ,"refMuo_etx"           ,"refMuo_etx"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefMuo_ety           ,"refMuo_ety"           ,"refMuo_ety"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefMuo_sumet         ,"refMuo_sumet"         ,"refMuo_sumet"         , 100,    0,  500));
    // p.push_back(evtvar_props(vrefJet               ,"refJet"               ,"refJet"               , 100,    0,  500));
    // p.push_back(evtvar_props(vrefJet_etx           ,"refJet_etx"           ,"refJet_etx"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefJet_ety           ,"refJet_ety"           ,"refJet_ety"           , 100, -500,  500));
    // p.push_back(evtvar_props(vrefJet_sumet         ,"refJet_sumet"         ,"refJet_sumet"         , 100,    0,  500));
    // p.push_back(evtvar_props(vrefGamma             ,"refGamma"             ,"refGamma"             , 100,    0,  150));
    // p.push_back(evtvar_props(vrefGamma_etx         ,"refGamma_etx"         ,"refGamma_etx"         , 100, -150,  150));
    // p.push_back(evtvar_props(vrefGamma_ety         ,"refGamma_ety"         ,"refGamma_ety"         , 100, -150,  150));
    // p.push_back(evtvar_props(vrefGamma_sumet       ,"refGamma_sumet"       ,"refGamma_sumet"       , 100,    0,  150));
    // p.push_back(evtvar_props(vsoftTerm             ,"softTerm"             ,"softTerm"             , 100,    0,  100));
    // p.push_back(evtvar_props(vsoftTerm_etx         ,"softTerm_etx"         ,"softTerm_etx"         , 100, -100,  100));
    // p.push_back(evtvar_props(vsoftTerm_ety         ,"softTerm_ety"         ,"softTerm_ety"         , 100, -100,  100));
    // p.push_back(evtvar_props(vsoftTerm_sumet       ,"softTerm_sumet"       ,"softTerm_sumet"       , 100,    0, 1500));
    // p.push_back(evtvar_props(vSFOS                 ,"SFOS"                 ,"SFOS"                 ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vnBjets               ,"nBjets"               ,"nBjets"               ,  11,    -0.5,   10.5,true));
    // p.push_back(evtvar_props(vjet0_index           ,"jet0_index"           ,"j0"                   ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vjet1_index           ,"jet1_index"           ,"j1"                   ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlep0_index           ,"lep0_index"           ,"l0"                   ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlep1_index           ,"lep1_index"           ,"l1"                   ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlep2_index           ,"lep2_index"           ,"l2"                   ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepleadZ_index         ,"lepleadZ_index"          ,"l_{0}(Z)"        ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepsubleadZ_index      ,"lepsubleadZ_index"       ,"l_{1}(Z)"        ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepW_index             ,"lepW_index"              ,"l(W)"            ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepleadMinSFOS_index   ,"lepleadMinSFOS_index"    ,"l_{0}(min(m_{sfos}))",   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepsubleadMinSFOS_index,"lepsubleadMinSFOS_index" ,"l_{1}(min(m_{sfos}))",   5,    0,    5,true));
    // p.push_back(evtvar_props(vlepWMinSFOS_index      ,"lepWMinSFOS_index"       ,"l(W)(min(m_{sfos}))" ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vantilep0_index       ,"antilep0_index"       ,"l_{0}(anti-id)"           ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vPtll                 ,"Ptll"                 ,"p_{T}^{ll}"           , 400,    0,  400));
    // p.push_back(evtvar_props(vPt3l                 ,"Pt3l"                 ,"p_{T}^{3l}"           , 400,    0,  400));
    // p.push_back(evtvar_props(vPtllZ                ,"PtllZ"                ,"p_{T}^{ll(Z)}"        , 400,    0,  400));
    // p.push_back(evtvar_props(vPtllZmin             ,"PtllZmin"             ,"p_{T}^{ll(Zmin)}"     , 400,    0,  400));
    // p.push_back(evtvar_props(vMll                  ,"Mll"                  ,"M_{ll} [GeV]"         , 500,    0,  500));
    // p.push_back(evtvar_props(vMll_alt              ,"Mll_alt"              ,"M_{ll}(alt) [GeV]"    , 500,    0,  500));
    // p.push_back(evtvar_props(vMll_ss               ,"Mll_ss"               ,"M_{ll}(ss) [GeV]"     , 500,    0,  500));
    // p.push_back(evtvar_props(vMWjj                 ,"MWjj"                 ,"M_{jj}^{W}"           , 500,    0,  500));
    // p.push_back(evtvar_props(vMjjMin                 ,"MjjMin"                 ,"M_{jj}^{min}"           , 500,    0,  500));
    // p.push_back(evtvar_props(vMinMll               ,"MinMll"               ,"min(m_{ll})"          , 500,    0,  500));
    // p.push_back(evtvar_props(vMTW                  ,"MTW"                  ,"M_{T}^{W} [GeV]"      , 500,    0,  500));
    // p.push_back(evtvar_props(vMTWmin               ,"MTWmin"               ,"MTWmin"               , 500,    0,  500));
    // p.push_back(evtvar_props(vNJets                ,"NJets"                ,"NJets"                ,  11,    -0.5,   10.5,true));
    // p.push_back(evtvar_props(vNCentralJets         ,"NCentralJets"         ,"NCentralJets"         ,  11,    -0.5,   10.5,true));
    // p.push_back(evtvar_props(vNForwardJets         ,"NForwardJets"         ,"NForwardJets"         ,  11,    -0.5,   10.5,true));
    // p.push_back(evtvar_props(vDeltaRll             ,"DeltaRll"             ,"DeltaRll"             , 100,    0,    4));
    // p.push_back(evtvar_props(vDeltaRllZ            ,"DeltaRllZ"            ,"DeltaRllZ"            , 100,    0,    4));
    // p.push_back(evtvar_props(vDeltaRllZmin         ,"DeltaRllZmin"         ,"DeltaRllZmin"         , 100,    0,    4));
    // p.push_back(evtvar_props(vMEToverPtj0          ,"METoverPtj0"          ,"METoverPtj0"          , 100,    0,   10));
    // p.push_back(evtvar_props(vPtlloverMET          ,"PtlloverMET"          ,"PtlloverMET"          , 100,    0,    5));
    // p.push_back(evtvar_props(vPtllZoverMET         ,"PtllZoverMET"         ,"PtllZoverMET"         , 100,    0,    5));
    // p.push_back(evtvar_props(vPtllZminoverMET      ,"PtllZminoverMET"      ,"PtllZminoverMET"      , 100,    0,    5));
    // p.push_back(evtvar_props(vMinDeltaPhilMET      ,"MinDeltaPhilMET"      ,"MinDeltaPhilMET"      , 100,    0,3.142));
    // p.push_back(evtvar_props(vMinDeltaPhi3LMET     ,"MinDeltaPhi3LMET"     ,"MinDeltaPhi3LMET"     , 100,    0,3.142));
    // p.push_back(evtvar_props(vMaxDeltaPhi3LMET     ,"MaxDeltaPhi3LMET"     ,"MaxDeltaPhi3LMET"     , 100,    0,3.142));
    // p.push_back(evtvar_props(vMaxDeltaPhilJet      ,"MaxDeltaPhilJet"      ,"MaxDeltaPhilJet"      , 100,    0,3.142));
    // p.push_back(evtvar_props(vMaxDeltaPhi3LJet     ,"MaxDeltaPhi3LJet"     ,"MaxDeltaPhi3LJet"     , 100,    0,3.142));
    // p.push_back(evtvar_props(vMinDeltaPhi3LJet     ,"MinDeltaPhi3LJet"     ,"MinDeltaPhi3LJet"     , 100,    0,3.142));
    // p.push_back(evtvar_props(vDeltaPhi3LJet        ,"DeltaPhi3LJet"        ,"DeltaPhi3LJet"        , 100,    0,3.142));
    // p.push_back(evtvar_props(vDeltaPhi3LMET        ,"DeltaPhi3LMET"        ,"DeltaPhi3LMET"        , 100,    0,3.142));
    // p.push_back(evtvar_props(vDeltaPhiMETJet       ,"DeltaPhiMETJet"       ,"DeltaPhiMETJet"       , 100,    0,3.142));
    // p.push_back(evtvar_props(vPassTrigger          ,"PassTrigger"          ,"PassTrigger"          ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vLumiBlockMu          ,"LumiBlockMu"          ,"LumiBlockMu"          ,  50,    0,   50));
    // p.push_back(evtvar_props(vMt                   ,"Mt"                   ,"Mt"                   , 300,    0,  300));
    // p.push_back(evtvar_props(vM3l                  ,"M3l"                  ,"M3l"                  , 900,    0,  900));
    // p.push_back(evtvar_props(vMll_Upsilon          ,"Mll_Upsilon"          ,"Mll_Upsilon"          , 100,    0,   50));
    // p.push_back(evtvar_props(vtruthjet0Pt           ,"truthjet0Pt"         ,"truthjet0Pt"           ,1000,    0, 2500));
    // p.push_back(evtvar_props(vtruthjet1Pt           ,"truthjet1Pt"         ,"truthjet1Pt"           ,1000,    0, 2500));
    // p.push_back(evtvar_props(vnVetoLeptons          ,"nVetoLeptons"        ,"nVetoLeptons"          ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vTotalWeight           ,"TotalWeight"         ,"TotalWeight"           ,  10,   -5,    5));
    // p.push_back(evtvar_props(vTotalWeightNoSF       ,"TotalWeightNoSF"     ,"TotalWeightNoSF"       ,  10,   -5,    5));
    // p.push_back(evtvar_props(vTotalWeightNoPupNoSF  ,"TotalWeightNoPupNoSF","TotalWeightNoPupNoSF"  ,  10,   -5,    5));
    // p.push_back(evtvar_props(vmc_channel_number     ,"mc_channel_number"   ,"mc_channel_number"     ,   1,    0,    1,true));
    // p.push_back(evtvar_props(vptAvg                 ,"ptAvg"               ,"ptAvg"                 ,1000,    0, 2500));
    // p.push_back(evtvar_props(vtruthptAvg            ,"truthptAvg"          ,"truthptAvg"            ,1000,    0, 2500));
    // p.push_back(evtvar_props(vptAvgOverTruthjet0Pt  ,"ptAvgOverTruthjet0Pt","ptAvgOverTruthjet0Pt"  ,1000,    0,   20));
    // p.push_back(evtvar_props(vDeltaPhill            ,"DeltaPhill"          ,"DeltaPhill"            , 100,    0,3.142));
    // p.push_back(evtvar_props(vWlepPassWSelection    ,"WlepPassWSelection"  ,"WlepPassWSelection"    ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vDeltaPhiLeadZWLep     ,"DeltaPhiLeadZWLep"     ,"DeltaPhiLeadZWLep"     ,100,     0,3.142));
    // p.push_back(evtvar_props(vDeltaPhiZLeps         ,"DeltaPhiZLeps"         ,"DeltaPhiZLeps"         ,100,     0,3.142));
    // p.push_back(evtvar_props(vDeltaPhiZWLep         ,"DeltaPhiZWLep"         ,"DeltaPhiZWLep"         ,100,     0,3.142));
    // p.push_back(evtvar_props(vDeltaPhiZMet          ,"DeltaPhiZMet"          ,"DeltaPhiZMet"          ,100,     0,3.142));
    // p.push_back(evtvar_props(vDeltaPhiZWSyst        ,"DeltaPhiZWSyst"        ,"DeltaPhiZWSyst"        ,100,     0,3.142));
    // p.push_back(evtvar_props(vPt3lPlusMet           ,"Pt3lPlusMet"           ,"Pt3lPlusMet"           ,900,     0, 900));
    // p.push_back(evtvar_props(vPassTriggerEle        ,"PassTriggerEle"      ,"PassTriggerEle"        ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vPassTriggerMu         ,"PassTriggerMu"       ,"PassTriggerMu"         ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vPassTriggerMatch      ,"PassTriggerMatch"    ,"PassTriggerMatch"      ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vRunNumber             ,"RunNumber"           ,"RunNumber"             , 100,    0,  100,true)); 
    // p.push_back(evtvar_props(vPtW                   ,"PtW"                 ,"Ptw"                   , 500,    0,   500));
    // p.push_back(evtvar_props(vMtWZ                  ,"MtWZ"                ,"MtWZ"                  , 900,    0,   900));
    // p.push_back(evtvar_props(vYZminusYlW            ,"YZminusYlW"          ,"YZminusYlW"            , 100,   -5,     5));
    // p.push_back(evtvar_props(vMtZ                   ,"MtZ"                 ,"MtZ"                   , 500,    0,   500));
    // p.push_back(evtvar_props(vPtWZ                  ,"PtWZ"                ,"PtWZ"                  , 900,    0,   900));
    // p.push_back(evtvar_props(vEvtTrigSF             ,"EvtTrigSF"           ,"EvtTrigSF"             , 100,    0,     2));
    // p.push_back(evtvar_props(vAntiIDSF_lep3         ,"AntiIDSF_lep3"       ,"AntiIDSF_lep3"         , 100,    0,     2));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_pt      ,"AntiIDSF_lep3_pt"    ,"AntiIDSF_lep3_pt"      , 500,    0,  500));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_eta     ,"AntiIDSF_lep3_eta"   ,"AntiIDSF_lep3_eta"     , 240, -6.0,  6.0));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_phi     ,"AntiIDSF_lep3_phi"   ,"AntiIDSF_lep3_phi"     , 100,   -4,    4));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_flavor  ,"AntiIDSF_lep3_flavor","AntiIDSF_lep3_flavor"  ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_pt_reco     ,"AntiIDSF_lep3_pt_reco"     ,"AntiIDSF_lep3_pt_reco"     , 500,    0,  500));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_eta_reco    ,"AntiIDSF_lep3_eta_reco"    ,"AntiIDSF_lep3_eta_reco"    , 240, -6.0,  6.0));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_phi_reco    ,"AntiIDSF_lep3_phi_reco"    ,"AntiIDSF_lep3_phi_reco"    , 100,   -4,    4));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_flavor_reco ,"AntiIDSF_lep3_flavor_reco" ,"AntiIDSF_lep3_flavor_reco" ,   5,    0,    5,true));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_match_DR    ,"AntiIDSF_lep3_match_DR"    ,"AntiIDSF_lep3_match_DR"    , 100,    0,    4));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_origin      ,"AntiIDSF_lep3_origin"      ,"AntiIDSF_lep3_origin"      ,  20,    0,   20));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_type        ,"AntiIDSF_lep3_type"        ,"AntiIDSF_lep3_type"        ,  20,    0,   20));
    // p.push_back(evtvar_props(vNlepsFromZ                ,"NlepsfromZ"                 ,"NlepsFromZ"                ,   5,    0,    5));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_truth_origin ,"AntiIDSF_lep3_truth_origin","AntiIDSF_lep3_truth_origin",  20,    0,   20));
    // p.push_back(evtvar_props(vAntiIDSF_lep3_truth_type   ,"AntiIDSF_lep3_truth_type" ,"AntiIDSF_lep3_truth_type"   ,  20,    0,   20));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_pt    ,"XCheckAntiIDSF_lep3_pt"   ,"XCheckAntiIDSF_lep3_pt"    , 500,   0,  500));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_eta   ,"XCheckAntiIDSF_lep3_eta"  ,"XCheckAntiIDSF_lep3_eta"   , 240,-6.0,  6.0));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_phi   ,"XCheckAntiIDSF_lep3_phi"  ,"XCheckAntiIDSF_lep3_phi"   , 100,  -4,    4));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_flavor,"XCheckAntiIDSF_lep3_flavor","XCheckAntiIDSF_lep3_flavor",  5,   0,    5));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_origin,"XCheckAntiIDSF_lep3_origin","XCheckAntiIDSF_lep3_origin", 20,   0,   20));
    // p.push_back(evtvar_props(vXCheckAntiIDSF_lep3_type  ,"XCheckAntiIDSF_lep3_type"  ,"XCheckAntiIDSF_lep3_type"  , 20,   0,   20));
    // p.push_back(evtvar_props(vnBaselineJet              ,"nBaselineJets"             ,"nBaselineJets"             ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vnSignalJet                ,"nSignalJets"               ,"nSignalJets"               ,  10,    0,   10,true));
    // p.push_back(evtvar_props(vLt                        ,"Lt"                        ,"L_{T} [GeV]"               , 500,    0,  500));
    // p.push_back(evtvar_props(vMeff                      ,"Meff"                      ,"M_{eff}^{L} [GeV]"         , 500,    0,  500));
    // p.push_back(evtvar_props(vMetOverMeff               ,"MetOverMeff"               ,"E_{T}^{miss}/M_{eff}"      , 100,    0,  5));
    // p.push_back(evtvar_props(vHLT_xe110_mht_xe70_L1XE50 ,"HLT_xe110_mht_xe70_L1XE50" ,"HLT_xe110_mht_xe70_L1XE50" ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vHLT_xe110_mht_xe75_L1XE50 ,"HLT_xe110_mht_xe75_L1XE50" ,"HLT_xe110_mht_xe75_L1XE50" ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vHLT_xe110_mht_L1XE50       ,"HLT_xe110_mht_L1XE50"      ,"HLT_xe110_mht_L1XE50"      ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vHLT_xe130_mht_L1XE50      ,"HLT_xe130_mht_L1XE50"      ,"HLT_xe130_mht_L1XE50"      ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vcell_xe70                 ,"cell_xe70"                 ,"cell_xe70"                 ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vcell_xe75                 ,"cell_xe75"                 ,"cell_xe75"                 ,   2,    0,    2,true));
    // p.push_back(evtvar_props(vtruthmet_Et               ,"truthmet_Et"               ,"E_{T}^{miss} [GeV]"   , 400,    0,  400));
    // p.push_back(evtvar_props(vtruthmet_phi              ,"truthmet_phi"              ,"met_phi"              , 100,   -4,    4));
  } // Add_new_variables_here
  return p;
}

//-----------------------------------------------------------------------------
const std::vector<KTB::lepvar_props> KTB::GetAllLepVariableProperties(){
  static std::vector<KTB::lepvar_props> p_var;
  if (p_var.empty()){
    //                           enum                 name in c++             axis label              nbins,  xdn,  xup, is_int
    p_var.push_back(lepvar_props(lepNone            ,"lepNone"               ,"lepNone"               ,   2,    0,    2,true));
    p_var.push_back(lepvar_props(lepFlavor          ,"lepFlavor"             ,"Flavor"                ,   5,    0,    5,true));
    p_var.push_back(lepvar_props(lepPt              ,"lepPt"                 ,"p_{T} [GeV]"           , 400,    0,  400));
    p_var.push_back(lepvar_props(lepEta             ,"lepEta"                ,"#eta"                  , 100, -2.5,  2.5));
    p_var.push_back(lepvar_props(lepPhi             ,"lepPhi"                ,"#phi"                  , 100,   -4,    4));
    p_var.push_back(lepvar_props(lepD0Significance  ,"lepD0Significance"     ,"d0/#sigma(d0)"         , 100,    0,    8));
    p_var.push_back(lepvar_props(lepZ0SinTheta      ,"lepZ0SinTheta"         ,"Z0sin(#theta)"         , 100,    0,    3));
    p_var.push_back(lepvar_props(lepTrkIso          ,"lepTrkIso"             ,"Track Isolation"       , 100,    0,    1));
    p_var.push_back(lepvar_props(lepCaloIso         ,"lepCaloIso"            ,"Calo Isolation"        , 100,    0,    1));
    p_var.push_back(lepvar_props(lepTruthDetailed   ,"lepTruthDetailed"      ,"Detailed Truth"        ,  27,    0,   27,true));
    p_var.push_back(lepvar_props(lepSFRecoIdIso     ,"lepSFRecoIdIso"        ,"lepSFRecoIdIso"        , 100,    0,    2));
    p_var.push_back(lepvar_props(lepSFTrigger       ,"lepSFTrigger"          ,"lepSFTrigger"          , 100,    0,    2));
    p_var.push_back(lepvar_props(lepD0              ,"lepD0"                 ,"lepD0"                 , 100,    0,    3));
    p_var.push_back(lepvar_props(lepCharge          ,"lepCharge"             ,"lepCharge"             ,   3,   -1,    2,true));
    p_var.push_back(lepvar_props(lepElectronID      ,"lepElectronID"         ,"lepElectronID"         ,   6,    0,    6,true));
    p_var.push_back(lepvar_props(lepMuonID          ,"lepMuonID"             ,"lepMuonID"             ,   5,    0,    5,true));
    p_var.push_back(lepvar_props(lepMt              ,"lepMt"                 ,"lepMt [GeV]"           , 200,    0,  200));
    p_var.push_back(lepvar_props(lepMll             ,"lepMll"                ,"lepMll [GeV]"          , 200,    0,  200));
    p_var.push_back(lepvar_props(lepPassOR          ,"lepPassOR"             ,"lepPassOR"             ,   2,    0,    2,true));
    p_var.push_back(lepvar_props(lepPassBlayer      ,"lepPassBlayer"         ,"lepPassBlayer"         ,   2,    0,    2,true));
    p_var.push_back(lepvar_props(lepEleEtaBE        ,"lepEleEtaBE"           ,"#eta(BE)"              , 100, -2.5,  2.5));
    p_var.push_back(lepvar_props(lepMatchesTrigger  ,"lepMatchesTrigger"     ,"lepMatchesTrigger"     ,   2,    0,    2,true));
    p_var.push_back(lepvar_props(lepOrigin          ,"lepOrigin"             ,"lepOrigin"             ,  20,    0,   20,true));
    p_var.push_back(lepvar_props(lepType            ,"lepType"               ,"lepType"               ,  20,    0,   20,true));
  }
  return p_var;
}

//-----------------------------------------------------------------------------
const std::vector<KTB::jetvar_props> KTB::GetAllJetVariableProperties(){
  static std::vector<KTB::jetvar_props> p_var;
  if (p_var.empty()){
    //                           enum                 name in c++             axis label              nbins,  xdn,  xup, is_int
    p_var.push_back(jetvar_props(jetNone            ,"jetNone"               ,"jetNone"               ,   2,    0,    2,true));
    p_var.push_back(jetvar_props(jetPt              ,"jetPt"                 ,"p_{T} [GeV]"           , 400,    0,  400));
    p_var.push_back(jetvar_props(jetEta             ,"jetEta"                ,"#eta"                  , 100, -2.5,  2.5));
    p_var.push_back(jetvar_props(jetPhi             ,"jetPhi"                ,"#phi"                  , 100,   -4,    4));
    p_var.push_back(jetvar_props(jetE               ,"jetE"                  ,"E [GeV]"               , 300,    0,  300));
  }
  return p_var;
}

//-----------------------------------------------------------------------------
int KTB::ConvertToInt(std::string s){
  int result;
  result = (int)ConvertToEnum(s,GetElectronIDStringPairs(),false);
  if (result != 0) return result;
  result = (int)ConvertToEnum(s,GetLeptonTruthLabelStringPairs(),false);
  if (result != 0) return result;
  MSG_INFO("Error! Cannot find enum for string " << s);
  exit(1);
  return result;
}

//-----------------------------------------------------------------------------
KTB::var_props KTB::GetVariableProperties(const std::string &v){
  // works for Variable, LepVariable
  std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
  for (unsigned int i=0;i<props.size();++i){
    if (v == props[i].second) {
      var_props result = (KTB::var_props)(props[i]);
      return result;
    }
  }
  std::vector<KTB::lepvar_props> lprops = KTB::GetAllLepVariableProperties();
  for (unsigned int i=0;i<lprops.size();++i){
    if (v == lprops[i].second) {
      var_props result = (KTB::var_props)(lprops[i]);
      return result;
    }
  }
  std::vector<KTB::jetvar_props> jprops = KTB::GetAllJetVariableProperties();
  for (unsigned int i=0;i<jprops.size();++i){
    if (v == jprops[i].second) {
      var_props result = (KTB::var_props)(jprops[i]);
      return result;
    }
  }
  MSG_INFO("Error! Variables.cxx Cannot find Variable / LepVariable / JetVariable properties for " << v);
  var_props result = var_props();
  result.second = v;
  result.label = v;
  return result;
}

//-----------------------------------------------------------------------------
KTB::var_props KTB::GetVariableProperties(Variable v){
  std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
  if (v == props[v].first) { // assertion
    var_props result = (KTB::var_props)(props[v]);
    return result;
  }
  MSG_INFO("Error! Variables.cxx Cannot find Variable properties for " << v
           << " (perhaps the properties vector is out of order!)");
  exit(1);
  return var_props();  
}

//-----------------------------------------------------------------------------
KTB::var_props KTB::GetVariableProperties(LepVariable v){
  std::vector<KTB::lepvar_props> lprops = KTB::GetAllLepVariableProperties();
  if (v == lprops[v].first) { // assertion
    var_props result = (KTB::var_props)(lprops[v]);
    return result;
  }
  MSG_INFO("Error! Variables.cxx Cannot find LepVariable properties for " << v 
           << " (perhaps the properties vector is out of order!)");
  exit(1);
  return var_props();
}

//-----------------------------------------------------------------------------
KTB::var_props KTB::GetVariableProperties(JetVariable v){
  std::vector<KTB::jetvar_props> jprops = KTB::GetAllJetVariableProperties();
  if (v == jprops[v].first) { // assertion
    var_props result = (KTB::var_props)(jprops[v]);
    return result;
  }
  MSG_INFO("Error! Variables.cxx Cannot find JetVariable properties for " << v 
           << " (perhaps the properties vector is out of order!)");
  exit(1);
  return var_props();
}

//-----------------------------------------------------------------------------
std::string KTB::GetXaxisLabel(std::string v){
  return GetVariableProperties(v).GetXaxisLabel();
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertVarToStr(Variable v)
{
  return ConvertToStr(v,GetAllEvtVariableProperties(),"Variable");
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertLepVarToStr(LepVariable v)
{
  return ConvertToStr(v,GetAllLepVariableProperties(),"LepVariable");
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertJetVarToStr(JetVariable v)
{
  return ConvertToStr(v,GetAllJetVariableProperties(),"JetVariable");
}

//-----------------------------------------------------------------------------
KTB::Variable KTB::ConvertToVariable(const std::string &v,bool fatal){
  //return ConvertToEnum(v,GetEvtVariableProperties());
  std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
  for (unsigned int i=0;i<props.size();++i){
    if (v == props[i].second) return props[i].first;
  }
  if (fatal) MSG_INFO("Error! Variables.cxx Cannot find Variable enum for " << v);
  if (fatal) exit(1);
  return vNone;
}

//-----------------------------------------------------------------------------
KTB::LepVariable KTB::ConvertToLepVariable(const std::string &v,bool fatal){
  //return ConvertToEnum(v,GetEvtVariableProperties());
  std::vector<KTB::lepvar_props> lprops = KTB::GetAllLepVariableProperties();
  for (unsigned int i=0;i<lprops.size();++i){
    if (v == lprops[i].second) return lprops[i].first;
  }
  if (fatal) MSG_INFO("Error! Variables.cxx Cannot find LepVariable enum for " << v);
  if (fatal) exit(1);
  return lepNone;
}

//-----------------------------------------------------------------------------
KTB::JetVariable KTB::ConvertToJetVariable(const std::string &v,bool fatal){
  //return ConvertToEnum(v,GetEvtVariableProperties());
  std::vector<KTB::jetvar_props> jprops = KTB::GetAllJetVariableProperties();
  for (unsigned int i=0;i<jprops.size();++i){
    if (v == jprops[i].second) return jprops[i].first;
  }
  if (fatal) MSG_INFO("Error! Variables.cxx Cannot find JetVariable enum for " << v);
  if (fatal) exit(1);
  return jetNone;
}

//-----------------------------------------------------------------------------
SG::AuxElement::Accessor<float>* KTB::GetAccessor(Variable v){
  std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
  if (v == props[v].first) return props[v].accessor;
  MSG_INFO("Error! Cannot find accessor name for enum " << v << ".");
  MSG_INFO("Check to make sure the order of your properties in Variables.cxx is the same as the enum in Variables.h");
  exit(1);
  //return new ST::AuxElement::Accessor<float>("");
}

//-----------------------------------------------------------------------------
SG::AuxElement::Decorator<float>* KTB::GetDecorator(Variable v){
  std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
  if (v == props[v].first) return props[v].decorator;
  MSG_INFO("Error! Cannot find decorator name for enum " << v << ".");
  MSG_INFO("Check to make sure the order of your properties in Variables.cxx is the same as the enum in Variables.h");
  exit(1);
  //return new ST::AuxElement::Accessor<float>("");
}

//-----------------------------------------------------------------------------
template <class T>
bool KTB::VariableIsInt(T v){
  return GetVariableProperties(v).IsInt();
}
template bool KTB::VariableIsInt<KTB::Variable>(Variable);
template bool KTB::VariableIsInt<KTB::LepVariable>(LepVariable);
template bool KTB::VariableIsInt<KTB::JetVariable>(JetVariable);

//-----------------------------------------------------------------------------
bool KTB::VariableIsInt(std::string v){
  return GetVariableProperties(v).IsInt();
}

//-----------------------------------------------------------------------------
std::vector<float> KTB::GetVariableHistArgs(std::string v){
  var_props props = GetVariableProperties(v);
  std::vector<float> args;
  args.push_back(props.nbins); 
  args.push_back(props.xlow); 
  args.push_back(props.xup); 
  return args;
}

//-----------------------------------------------------------------------------
const std::vector<KTB::Variable>& KTB::GetAllVariables(){
  static std::vector<KTB::Variable> vars;
  
  if(vars.empty()) {
    std::vector<KTB::evtvar_props> props = KTB::GetAllEvtVariableProperties();
    for (unsigned int i=0;i<props.size();++i){
      if (props[i].first == vNone) continue;
      MSG_DEBUG(props[i].second);
      vars.push_back(props[i].first);
    }
  }
  return vars;
}

//-----------------------------------------------------------------------------
const std::vector<std::string>& KTB::GetAllVariableStrings(){
  static std::vector<std::string> vars_str;
  if(vars_str.empty()) {
    std::vector<KTB::Variable> vars = GetAllVariables();
    for (unsigned int i=0;i<vars.size();++i){
      vars_str.push_back(ConvertVarToStr(vars[i]));
    }
  }
  return vars_str;
}

//-----------------------------------------------------------------------------
const std::vector<KTB::LepVariable>& KTB::GetAllLepVariables(){
  static std::vector<KTB::LepVariable> vars;
  
  if(vars.empty()) {
    std::vector<KTB::lepvar_props> props = KTB::GetAllLepVariableProperties();
    for (unsigned int i=0;i<props.size();++i){
      if (props[i].first == lepNone) continue;
      MSG_DEBUG(props[i].second);
      vars.push_back(props[i].first);
    }
  }
  return vars;
}

//-----------------------------------------------------------------------------
const std::vector<KTB::JetVariable>& KTB::GetAllJetVariables(){
  static std::vector<KTB::JetVariable> vars;
  
  if(vars.empty()) {
    std::vector<KTB::jetvar_props> props = KTB::GetAllJetVariableProperties();
    for (unsigned int i=0;i<props.size();++i){
      if (props[i].first == jetNone) continue;
      MSG_DEBUG(props[i].second);
      vars.push_back(props[i].first);
    }
  }
  return vars;
}

//-----------------------------------------------------------------------------
const std::vector<std::string>& KTB::GetAllLepVariableStrings(){
  static std::vector<std::string> vars_str;
  if(vars_str.empty()) {
    std::vector<KTB::LepVariable> vars = GetAllLepVariables();
    for (unsigned int i=0;i<vars.size();++i){
      vars_str.push_back(ConvertLepVarToStr(vars[i]));
    }
  }
  return vars_str;
}

//-----------------------------------------------------------------------------
const std::vector<std::string>& KTB::GetAllJetVariableStrings(){
  static std::vector<std::string> vars_str;
  if(vars_str.empty()) {
    std::vector<KTB::JetVariable> vars = GetAllJetVariables();
    for (unsigned int i=0;i<vars.size();++i){
      vars_str.push_back(ConvertJetVarToStr(vars[i]));
    }
  }
  return vars_str;
}

//-----------------------------------------------------------------------------
const std::vector<std::string>& KTB::GetAllLeptonTruthLabelStrings(){
  static std::vector<std::string> truth_str;
  if(truth_str.empty()) {
    for (auto truth : GetLeptonTruthLabelStringPairs()) {
      if (truth.first == NoTruthLabel) continue;
      truth_str.push_back(truth.second);
    }
  }
  return truth_str;
}

//-----------------------------------------------------------------------------
template <class T>
TH1F* KTB::MakeVariableTH1F(std::string hist_location,T v){
  var_props props = GetVariableProperties(v);
  TH1F* hist = new TH1F(hist_location.c_str(),hist_location.c_str()
                        ,props.nbins,props.xlow,props.xup);
  SetBinLabels(v,hist->GetXaxis());
  hist->GetXaxis()->SetTitle(props.label.c_str());
  hist->GetYaxis()->SetTitle("entries");
  hist->SetDirectory(0);
  hist->Sumw2();
  return hist;
}
// Need these lines for correct linking
template TH1F* KTB::MakeVariableTH1F<KTB::Variable>(std::string,Variable);
template TH1F* KTB::MakeVariableTH1F<KTB::LepVariable>(std::string,LepVariable);
template TH1F* KTB::MakeVariableTH1F<KTB::JetVariable>(std::string,JetVariable);

//-----------------------------------------------------------------------------
void KTB::SetBinLabels(Variable v,TAxis* axis){
  // if (v == vChanFlavor) {
  //   axis->SetBinLabel(1,"None");
  //   axis->SetBinLabel(2,"0 leptons");
  //   axis->SetBinLabel(3,"e");
  //   axis->SetBinLabel(4,"#mu");
  //   axis->SetBinLabel(5,"ee");
  //   axis->SetBinLabel(6,"e#mu");
  //   axis->SetBinLabel(7,"#mu#mu");
  //   axis->SetBinLabel(8,"eee");
  //   axis->SetBinLabel(9,"ee#mu");
  //   axis->SetBinLabel(10,"e#mu#mu");
  //   axis->SetBinLabel(11,"#mu#mu#mu");
  //   axis->SetBinLabel(12,"eeee");
  //   axis->SetBinLabel(13,"eee#mu");
  //   axis->SetBinLabel(14,"ee#mu#mu");
  //   axis->SetBinLabel(15,"e#mu#mu#mu");
  //   axis->SetBinLabel(16,"#mu#mu#mu#mu");
  //   axis->SetBinLabel(17,">4 leptons");
  // }
  if (v == vSample) {
    for (int i=0;i<kEndOfNonOverlapping;++i){
      axis->SetBinLabel(i+1,ConvertSampleToStr(static_cast<KTB::Sample>(i)).c_str());
    }
  }
  return;
}

//-----------------------------------------------------------------------------
void KTB::SetBinLabels(LepVariable v,TAxis* axis){
  if (v == lepFlavor) {
    axis->SetBinLabel(1,"None");
    axis->SetBinLabel(2,"e");
    axis->SetBinLabel(3,"#mu");
    axis->SetBinLabel(4,"tau");
    axis->SetBinLabel(5,"jet");    
  }
  if (v == lepTruthDetailed) {
    axis->SetBinLabel( 1,"None"               );
    axis->SetBinLabel( 2,"LeptonW"            );
    axis->SetBinLabel( 3,"LeptonZ"            );
    axis->SetBinLabel( 4,"LeptonSUSY"         );
    axis->SetBinLabel( 5,"LeptonTtbar"        );
    axis->SetBinLabel( 6,"LeptonJpsi"         );
    axis->SetBinLabel( 7,"LeptonUnknown"      );
    axis->SetBinLabel( 8,"LeptonTau"          );
    axis->SetBinLabel( 9,"PhotonOrPi0"        );
    axis->SetBinLabel(10,"PhotonOrPi0Leptonic");
    axis->SetBinLabel(11,"PiPlusMinusHadronic");
    axis->SetBinLabel(12,"PiPlusMinusLeptonic");
    axis->SetBinLabel(13,"KaonHadronic"       );
    axis->SetBinLabel(14,"KaonLeptonic"       );
    axis->SetBinLabel(15,"CjetHadronic"       );
    axis->SetBinLabel(16,"CjetLeptonic"       );
    axis->SetBinLabel(17,"BjetHadronic"       );
    axis->SetBinLabel(18,"BjetLeptonic"       );
    axis->SetBinLabel(19,"LightjetHadronic"   );
    axis->SetBinLabel(20,"LightjetLeptonic"   );
    axis->SetBinLabel(21,"NonPrimary"         );
    axis->SetBinLabel(22,"ElectronAsMuon"     );
    axis->SetBinLabel(23,"ElMagProc"          );
    axis->SetBinLabel(24,"PhotonInMeson"      );
    axis->SetBinLabel(25,"IsoElectronFromCCbar");
    axis->SetBinLabel(26,"IsoElectronFromBBbar");
    axis->SetBinLabel(27,"PhotonOrElectronAmbiguous");    
  }
  if (v == lepElectronID) {
#ifdef BEFORE_SUSYTOOLS_000611
    axis->SetBinLabel(1,"TightLLH");
    axis->SetBinLabel(2,"MediumLLH");
    axis->SetBinLabel(3,"LooseLLH");
    axis->SetBinLabel(4,"VeryLooseLLH");
    axis->SetBinLabel(5,"FailAll");
#else // BEFORE_SUSYTOOLS_000611
    axis->SetBinLabel(1,"TightLLH");
    axis->SetBinLabel(2,"MediumLLH");
    axis->SetBinLabel(3,"LooseAndBLayerLLH");
    axis->SetBinLabel(4,"LooseLLH");
    axis->SetBinLabel(5,"VeryLooseLLH");
    axis->SetBinLabel(6,"FailAll");
#endif // BEFORE_SUSYTOOLS_000611
  }

  if (v == lepMuonID) {
    axis->SetBinLabel(1,"Tight");
    axis->SetBinLabel(2,"Medium");
    axis->SetBinLabel(3,"Loose");
    axis->SetBinLabel(4,"VeryLoose");
    axis->SetBinLabel(5,"FailAll");
  }
  return;
}

//-----------------------------------------------------------------------------
bool KTB::IsRealLepton(LeptonTruthLabel l){
  return (l == LeptonW ||
          l == LeptonZ ||
          l == LeptonSUSY ||
          l == LeptonTtbar ||
          l == LeptonJpsi ||
          l == LeptonUnknown ||
          l == LeptonTau
          );
}

//-----------------------------------------------------------------------------
const std::vector<std::pair<KTB::LeptonTruthLabel,std::string> > KTB::GetLeptonTruthLabelStringPairs(void){
  static std::vector<std::pair<KTB::LeptonTruthLabel,std::string> > truth_pairs;
  if (truth_pairs.empty()){
    truth_pairs.push_back(std::make_pair(NoTruthLabel            ,"NoTruthLabel"       ));
    truth_pairs.push_back(std::make_pair(LeptonW                 ,"LeptonW"            ));
    truth_pairs.push_back(std::make_pair(LeptonZ                 ,"LeptonZ"            ));
    truth_pairs.push_back(std::make_pair(LeptonSUSY              ,"LeptonSUSY"         ));
    truth_pairs.push_back(std::make_pair(LeptonTtbar             ,"LeptonTtbar"        ));
    truth_pairs.push_back(std::make_pair(LeptonJpsi              ,"LeptonJpsi"         ));
    truth_pairs.push_back(std::make_pair(LeptonUnknown           ,"LeptonUnknown"      ));
    truth_pairs.push_back(std::make_pair(LeptonTau               ,"LeptonTau"          ));
    truth_pairs.push_back(std::make_pair(PhotonOrPi0             ,"PhotonOrPi0"        ));
    truth_pairs.push_back(std::make_pair(PhotonOrPi0Leptonic     ,"PhotonOrPi0Leptonic"));
    truth_pairs.push_back(std::make_pair(PiPlusMinusHadronic     ,"PiPlusMinusHadronic"));
    truth_pairs.push_back(std::make_pair(PiPlusMinusLeptonic     ,"PiPlusMinusLeptonic"));
    truth_pairs.push_back(std::make_pair(KaonHadronic            ,"KaonHadronic"       ));
    truth_pairs.push_back(std::make_pair(KaonLeptonic            ,"KaonLeptonic"       ));
    truth_pairs.push_back(std::make_pair(CjetHadronic            ,"CjetHadronic"       ));
    truth_pairs.push_back(std::make_pair(CjetLeptonic            ,"CjetLeptonic"       ));
    truth_pairs.push_back(std::make_pair(BjetHadronic            ,"BjetHadronic"       ));
    truth_pairs.push_back(std::make_pair(BjetLeptonic            ,"BjetLeptonic"       ));
    truth_pairs.push_back(std::make_pair(LightjetHadronic        ,"LightjetHadronic"   ));
    truth_pairs.push_back(std::make_pair(LightjetLeptonic        ,"LightjetLeptonic"   ));
    truth_pairs.push_back(std::make_pair(NonPrimary              ,"NonPrimary"         ));
    truth_pairs.push_back(std::make_pair(ElectronAsMuon          ,"ElectronAsMuon"     ));
    truth_pairs.push_back(std::make_pair(ElMagProc               ,"ElMagProc"          ));
  }
  return truth_pairs;
}

//-----------------------------------------------------------------------------
void KTB::SetBinLabels(JetVariable v,TAxis* axis){
  (void)v;
  (void)axis;
  return;
}

//-----------------------------------------------------------------------------
void KTB::SetBinLabels(std::string s,TH1F* hist){
  Variable v = ConvertToVariable(s,false);
  if (v != vNone) return SetBinLabels(v,hist->GetXaxis());
  LepVariable lv = ConvertToLepVariable(s,false);
  if (lv != lepNone) return SetBinLabels(lv,hist->GetXaxis());
  JetVariable jv = ConvertToJetVariable(s,false);
  if (jv != jetNone) return SetBinLabels(jv,hist->GetXaxis());
  return;
}

//-----------------------------------------------------------------------------
void KTB::SetBinLabels(std::string s1,std::string s2,TH2F* hist){
  Variable v = ConvertToVariable(s1,false);
  LepVariable lv = ConvertToLepVariable(s1,false);
  JetVariable jv = ConvertToJetVariable(s1,false);
  if (v != vNone) SetBinLabels(v,hist->GetXaxis());
  else if (lv != lepNone) SetBinLabels(lv,hist->GetXaxis());
  else if (jv != jetNone) SetBinLabels(jv,hist->GetXaxis());
  //
  Variable v2 = ConvertToVariable(s2,false);
  LepVariable lv2 = ConvertToLepVariable(s2,false);
  JetVariable jv2 = ConvertToJetVariable(s2,false);
  if (v != vNone) SetBinLabels(v2,hist->GetYaxis());
  else if (lv != lepNone) SetBinLabels(lv2,hist->GetYaxis());
  else if (jv != jetNone) SetBinLabels(jv2,hist->GetYaxis());
  return;
}

//-----------------------------------------------------------------------------
const std::vector<std::pair<KTB::ElectronID::ElectronID,std::string> > KTB::GetElectronIDStringPairs(void){
  static std::vector<std::pair<KTB::ElectronID::ElectronID,std::string> > ele_pairs;
  if (ele_pairs.empty()){
    ele_pairs.push_back(std::make_pair(ElectronID::None        ,"None"        ));
    // This is due to the naming convention changing. It is very unfortunate but hopefully
    // we can remove it soon!
#ifdef BEFORE_SUSYTOOLS_000611
    ele_pairs.push_back(std::make_pair(ElectronID::TightLLH    ,"TightLLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::MediumLLH   ,"MediumLLH"   ));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseLLH    ,"LooseLLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::VeryLooseLLH,"VeryLooseLLH"));
    ele_pairs.push_back(std::make_pair(ElectronID::TightLLH    ,"TightLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::MediumLLH   ,"MediumLH"   ));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseLLH    ,"LooseLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::VeryLooseLLH,"VeryLooseLH"));
#else
    ele_pairs.push_back(std::make_pair(ElectronID::TightLLH    ,"TightLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::MediumLLH   ,"MediumLH"   ));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseAndBLayerLLH,"LooseAndBLayerLH"));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseLLH    ,"LooseLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::VeryLooseLLH,"VeryLooseLH"));
    ele_pairs.push_back(std::make_pair(ElectronID::TightLLH    ,"TightLLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::MediumLLH   ,"MediumLLH"   ));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseAndBLayerLLH,"LooseAndBLayerLLH"));
    ele_pairs.push_back(std::make_pair(ElectronID::LooseLLH    ,"LooseLLH"    ));
    ele_pairs.push_back(std::make_pair(ElectronID::VeryLooseLLH,"VeryLooseLLH"));
#endif
  }
  return ele_pairs;
}

//-----------------------------------------------------------------------------
const std::vector<std::string>& KTB::GetAllElectronIDStrings(){
  static std::vector<std::string> eleid_str;
  if(eleid_str.empty()) {
    for (auto eleid : GetElectronIDStringPairs()) {
      if (eleid.first == ElectronID::None) continue;
      eleid_str.push_back(eleid.second);
    }
  }
  return eleid_str;
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertElectronIDToStr(ElectronID::ElectronID e){
  return ConvertToStr(e,GetElectronIDStringPairs(),"ElectronID");
}

//-----------------------------------------------------------------------------
KTB::ElectronID::ElectronID KTB::ConvertToElectronID(const std::string& e){
  return ConvertToEnum(e,GetElectronIDStringPairs(),true);
}

// //-----------------------------------------------------------------------------
// const std::vector<std::pair<xAOD::Muon::Quality,std::string> > KTB::GetMuonIDStringPairs(void){
//   static std::vector<std::pair<xAOD::Muon::Quality,std::string> > mu_pairs;
//   if (mu_pairs.empty()){
//     mu_pairs.push_back(std::make_pair(xAOD::Muon::Tight    ,"Tight"    ));
//     mu_pairs.push_back(std::make_pair(xAOD::Muon::Medium   ,"Medium"   ));
//     mu_pairs.push_back(std::make_pair(xAOD::Muon::Loose    ,"Loose"    ));
//     mu_pairs.push_back(std::make_pair(xAOD::Muon::VeryLoose,"VeryLoose"));
//   }
//   return mu_pairs;
// }

// //-----------------------------------------------------------------------------
// std::string KTB::ConvertMuonIDToStr(xAOD::Muon::Quality e){
//   return ConvertToStr(e,GetMuonIDStringPairs(),"xAOD::Muon::Quality");
// }

// //-----------------------------------------------------------------------------
// xAOD::Muon::Quality KTB::ConvertToMuonID(const std::string& e){
//   return ConvertToEnum(e,GetMuonIDStringPairs(),true);
// }

//-----------------------------------------------------------------------------
const std::vector<std::pair<KTB::Trigger2015,std::string> > KTB::GetTriggerProperties(){
  static std::vector<std::pair<KTB::Trigger2015,std::string> > trig_pairs;
  if (trig_pairs.empty()){
    trig_pairs.push_back(std::make_pair(tNone                                     ,"None"                                     ));
    // single-electron
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhmedium_iloose                  ,"HLT_e24_lhmedium_iloose"                  ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhmedium_iloose_L1EM18VH         ,"HLT_e24_lhmedium_iloose_L1EM18VH"         ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhmedium_iloose_L1EM20VH           ,"HLT_e24_lhmedium_iloose_L1EM20VH"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e28_lhtight_iloose                   ,"HLT_e28_lhtight_iloose"                   ));
    trig_pairs.push_back(std::make_pair(tHLT_e60_lhmedium                         ,"HLT_e60_lhmedium"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhmedium_L1EM20VH                ,"HLT_e24_lhmedium_L1EM20VH"                ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhmedium_L1EM18VH                ,"HLT_e24_lhmedium_L1EM18VH"                ));
    trig_pairs.push_back(std::make_pair(tHLT_e120_lhloose                         ,"HLT_e120_lhloose"                         ));
    // single-e cut-based (taken from SUSY2)
    trig_pairs.push_back(std::make_pair(tHLT_e24_medium_iloose                    ,"HLT_e24_medium_iloose"                    ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_tight_L1EM20V                    ,"HLT_e24_tight_L1EM20V"                    ));
    trig_pairs.push_back(std::make_pair(tHLT_e28_tight_iloose                     ,"HLT_e28_tight_iloose"                     ));
    trig_pairs.push_back(std::make_pair(tHLT_e60_medium                           ,"HLT_e60_medium"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_e55_loose1                           ,"HLT_e55_loose1"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_e120_loose1                          ,"HLT_e120_loose1"                          ));
    trig_pairs.push_back(std::make_pair(tHLT_e45_loose1                           ,"HLT_e45_loose1"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_e7_medium1                           ,"HLT_e7_medium1"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_e12_medium1                          ,"HLT_e12_medium1"                          ));
    trig_pairs.push_back(std::make_pair(tHLT_e17_medium1                          ,"HLT_e17_medium1"                          ));
    // di-electron
    trig_pairs.push_back(std::make_pair(tHLT_2e17_lhloose                         ,"HLT_2e17_lhloose"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_e28_lhloose_iloose_e12_lhloose_L1EM3 ,"HLT_e28_lhloose_iloose_e12_lhloose_L1EM3" ));
    // di-electron cut-based (taken from SUSY2)
    trig_pairs.push_back(std::make_pair(tHLT_2e12_loose1                          ,"HLT_2e12_loose1"                          ));
    trig_pairs.push_back(std::make_pair(tHLT_2e17_loose1                          ,"HLT_2e17_loose1"                          ));
    // tri-electron
    trig_pairs.push_back(std::make_pair(tHLT_e18_lhloose_2e9_lhloose_L1EM7V       ,"HLT_e18_lhloose_2e9_lhloose_L1EM7V"       ));
    // electron supporting
    // electron muon LH based - needs updating in Rel 20
    // electron muon cut-based
    trig_pairs.push_back(std::make_pair(tHLT_e17_medium1_mu12                     ,"HLT_e17_medium1_mu12"                     ));
    trig_pairs.push_back(std::make_pair(tHLT_e7_medium1_mu24                      ,"HLT_e7_medium1_mu24"                      ));
    // single-muon
    trig_pairs.push_back(std::make_pair(tHLT_mu24                                 ,"HLT_mu24"                                 ));
    trig_pairs.push_back(std::make_pair(tHLT_mu26                                 ,"HLT_mu26"                                 ));
    trig_pairs.push_back(std::make_pair(tHLT_mu24_imedium                         ,"HLT_mu24_imedium"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_mu26_imedium                         ,"HLT_mu26_imedium"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_mu50                                 ,"HLT_mu50"                                 ));
    trig_pairs.push_back(std::make_pair(tHLT_mu60_0eta105_msonly                  ,"HLT_mu60_0eta105_msonly"                  ));
    trig_pairs.push_back(std::make_pair(tHLT_mu20_iloose_L1MU15                   ,"HLT_mu20_iloose_L1MU15"                   ));
    // di-muon
    trig_pairs.push_back(std::make_pair(tHLT_2mu10                                ,"HLT_2mu10"                                ));
    trig_pairs.push_back(std::make_pair(tHLT_2mu14                                ,"HLT_2mu14"                                ));
    trig_pairs.push_back(std::make_pair(tHLT_mu24_mu8noL1                         ,"HLT_mu24_mu8noL1"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_mu14_iloose_mu14                     ,"HLT_mu14_iloose_mu14"                     ));
    trig_pairs.push_back(std::make_pair(tHLT_mu20_imedium_mu8noL1                 ,"HLT_mu20_imedium_mu8noL1"                 ));
    trig_pairs.push_back(std::make_pair(tHLT_mu20_iloose_mu8noL1                  ,"HLT_mu20_iloose_mu8noL1"                  ));
    trig_pairs.push_back(std::make_pair(tHLT_mu18_mu8noL1                         ,"HLT_mu18_mu8noL1"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_mu20_mu8noL1                         ,"HLT_mu20_mu8noL1"                         ));
    trig_pairs.push_back(std::make_pair(tHLT_mu22_mu8noL1                         ,"HLT_mu22_mu8noL1"                         ));
    // tri-muon
    trig_pairs.push_back(std::make_pair(tHLT_3mu6                                 ,"HLT_3mu6"                                 ));
    // Etmiss
    trig_pairs.push_back(std::make_pair(tHLT_xe50                                 ,"HLT_xe50"                                 ));
    trig_pairs.push_back(std::make_pair(tHLT_xe50_cell                            ,"HLT_xe50_cell"                            ));
    trig_pairs.push_back(std::make_pair(tHLT_xe50_pueta                           ,"HLT_xe50_pueta"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_xe70                                 ,"HLT_xe70"                                 ));
    trig_pairs.push_back(std::make_pair(tHLT_xe70_cell                            ,"HLT_xe70_cell"                            ));
    trig_pairs.push_back(std::make_pair(tHLT_xe70_pueta                           ,"HLT_xe70_pueta"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_xe100                                ,"HLT_xe100"                                ));
    trig_pairs.push_back(std::make_pair(tHLT_xe100_cell                           ,"HLT_xe100_cell"                           ));
    trig_pairs.push_back(std::make_pair(tHLT_xe100_pueta                          ,"HLT_xe100_pueta"                          ));
    // jet-MET                                                                                            
    trig_pairs.push_back(std::make_pair(tHLT_j100_xe80noL1                        ,"HLT_j100_xe80noL1"                        ));
    trig_pairs.push_back(std::make_pair(tHLT_j80_xe80noL1                         ,"HLT_j80_xe80noL1"                         ));
    // muon-MET                                                                                          
    trig_pairs.push_back(std::make_pair(tHLT_mu24_xe100noL1_wEFMu                 ,"HLT_mu24_xe100noL1_wEFMu"                 ));
    // electron-MET                                                                                      
    trig_pairs.push_back(std::make_pair(tHLT_e28_tight1_iloose_xe100noL1          ,"HLT_e28_tight1_iloose_xe100noL1"          ));

    trig_pairs.push_back(std::make_pair(tHLT_2e12_lhloose_L12EM10VH                 ,"HLT_2e12_lhloose_L12EM10VH"               ));
    trig_pairs.push_back(std::make_pair(tHLT_e17_lhloose_2e9_lhloose                ,"HLT_e17_lhloose_2e9_lhloose"               ));
    trig_pairs.push_back(std::make_pair(tHLT_mu18_2mu4noL1                          ,"HLT_mu18_2mu4noL1"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e17_loose_mu14                         ,"HLT_e17_loose_mu14"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_medium_L1EM20VHI_mu8noL1           ,"HLT_e24_medium_L1EM20VHI_mu8noL1"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e7_medium_mu24                         ,"HLT_e7_medium_mu24"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e12_loose_2mu10                        ,"HLT_e12_loose_2mu10"          ));
    trig_pairs.push_back(std::make_pair(tHLT_2e12_loose_mu10                        ,"HLT_2e12_loose_mu10"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhtight_iloose                     ,"HLT_e24_lhtight_iloose"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e26_lhtight_iloose                     ,"HLT_e26_lhtight_iloose"          ));
    trig_pairs.push_back(std::make_pair(tHLT_mu24_iloose_L1MU15                     ,"HLT_mu24_iloose_L1MU15"          ));
    trig_pairs.push_back(std::make_pair(tHLT_2e15_lhloose_L12EM13VH                 ,"HLT_2e15_lhloose_L12EM13VH"               ));
    trig_pairs.push_back(std::make_pair(tHLT_e17_lhloose_nod0_mu14                  ,"HLT_e17_lhloose_nod0_mu14"));
    trig_pairs.push_back(std::make_pair(tHLT_2e15_lhvloose_nod0_L12EM13VH           ,"HLT_2e15_lhvloose_nod0_L12EM13VH"));

    trig_pairs.push_back(std::make_pair(tHLT_e5_lhvloose                            ,"HLT_e5_lhvloose"          ));
    trig_pairs.push_back(std::make_pair(tHLT_e10_lhvloose_L1EM7                     ,"HLT_e10_lhvloose_L1EM7"   ));
    trig_pairs.push_back(std::make_pair(tHLT_e15_lhvloose_L1EM7                     ,"HLT_e15_lhvloose_L1EM7"   ));
    trig_pairs.push_back(std::make_pair(tHLT_e24_lhvloose_L1EM18VH                  ,"HLT_e24_lhvloose_L1EM18VH"));
    trig_pairs.push_back(std::make_pair(tHLT_e50_lhvloose_L1EM15                    ,"HLT_e50_lhvloose_L1EM15"  ));
    trig_pairs.push_back(std::make_pair(tHLT_e70_lhvloose                           ,"HLT_e70_lhvloose"         ));
    trig_pairs.push_back(std::make_pair(tHLT_e100_lhvloose                          ,"HLT_e100_lhvloose"        ));
    trig_pairs.push_back(std::make_pair(tHLT_mu4                                    ,"HLT_mu4"                  ));
    trig_pairs.push_back(std::make_pair(tHLT_mu14                                   ,"HLT_mu14"                 ));
    trig_pairs.push_back(std::make_pair(tHLT_mu18                                   ,"HLT_mu18"                 ));
    trig_pairs.push_back(std::make_pair(tHLT_e17_lhloose_mu14                       ,"HLT_e17_lhloose_mu14"     ));
    trig_pairs.push_back(std::make_pair(tHLT_xe100_mht_L1XE50                       ,"HLT_xe100_mht_L1XE50"     ));
   }
  return trig_pairs;
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertTrigToStr(Trigger2015 t){
  return ConvertToStr(t,GetTriggerProperties(),"Trigger2015");
}

//-----------------------------------------------------------------------------
KTB::Trigger2015 KTB::ConvertToTrigger(const std::string &t){
  return ConvertToEnum(t,GetTriggerProperties(),true);
}

//-----------------------------------------------------------------------------
const std::vector<KTB::Trigger2015>& KTB::GetAllTriggers(){
  static std::vector<KTB::Trigger2015> trigs;  
  if(trigs.empty()) {
    std::vector<std::pair<KTB::Trigger2015,std::string> > trig_pairs = GetTriggerProperties(); 
    for (unsigned int i=0;i<trig_pairs.size();++i){
      if (trig_pairs[i].first == tNone) continue;
      MSG_DEBUG(trig_pairs[i].second);
      trigs.push_back(trig_pairs[i].first);
    }
  }
  return trigs;
}

//-----------------------------------------------------------------------------
const std::vector<std::pair<KTB::AnaIso::AnaIso,std::string> > KTB::GetAnaIsoStringPairs(void){
  static std::vector<std::pair<KTB::AnaIso::AnaIso,std::string> > iso_pairs;
  if (iso_pairs.empty()){
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::None              ,"None"           ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone20          ,"etcone20"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone30          ,"etcone30"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone40          ,"etcone40"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone20          ,"ptcone20"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone30          ,"ptcone30"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone40          ,"ptcone40"       ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone20       ,"ptvarcone20"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone30       ,"ptvarcone30"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone40       ,"ptvarcone40"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone20      ,"topoetcone20"   ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone30      ,"topoetcone30"   ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone40      ,"topoetcone40"   ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::N_NONRELATIVE     ,"N_NONRELATIVE"     ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone20overPt    ,"etcone20overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone30overPt    ,"etcone30overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::etcone40overPt    ,"etcone40overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone20overPt    ,"ptcone20overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone30overPt    ,"ptcone30overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptcone40overPt    ,"ptcone40overPt"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone20overPt ,"ptvarcone20overPt" ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone30overPt ,"ptvarcone30overPt" ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::ptvarcone40overPt ,"ptvarcone40overPt" ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone20overPt,"topoetcone20overPt"));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone30overPt,"topoetcone30overPt"));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::topoetcone40overPt,"topoetcone40overPt"));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::N_NONWP           ,"N_NONWP"           ));
#ifdef BEFORE_SUSYTOOLS_000611
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::VeryLooseTrackOnly,"VeryLooseTrackOnly"));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::VeryLoose         ,"VeryLoose"         ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Loose             ,"Loose"             ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Tight             ,"Tight"             ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Gradient          ,"Gradient"          ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::GradientLoose     ,"GradientLoose"     ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::UserDefined       ,"UserDefined"       ));
#else
    //iso_pairs.push_back(std::make_pair(KTB::AnaIso::VeryLooseTrackOnly,"VeryLooseTrackOnly"));
    //iso_pairs.push_back(std::make_pair(KTB::AnaIso::VeryLoose         ,"VeryLoose"         ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Loose             ,"Loose"             ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Tight             ,"Tight"             ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::Gradient          ,"Gradient"          ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::GradientLoose     ,"GradientLoose"     ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::LooseTrackOnly    ,"LooseTrackOnly"    ));
    iso_pairs.push_back(std::make_pair(KTB::AnaIso::UserDefined       ,"UserDefined"       ));
#endif
  }
  return iso_pairs;
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertAnaIsoToStr(AnaIso::AnaIso t){
  return ConvertToStr(t,GetAnaIsoStringPairs(),"AnaIso");
}

//-----------------------------------------------------------------------------
KTB::AnaIso::AnaIso KTB::ConvertToAnaIso(const std::string &t){
  return ConvertToEnum(t,GetAnaIsoStringPairs(),true);
}

//-----------------------------------------------------------------------------
const std::vector<KTB::AnaIso::AnaIso>& KTB::GetAllIsolationVariables(){
  static std::vector<KTB::AnaIso::AnaIso> vars;
  
  if(vars.empty()) {
    std::vector<std::pair<KTB::AnaIso::AnaIso,std::string> > props = GetAnaIsoStringPairs();
    for (unsigned int i=0;i<props.size();++i){
      if (props[i].first == AnaIso::None) continue;
      if (props[i].first == AnaIso::N_NONRELATIVE) continue;
      if (props[i].first == AnaIso::N_NONWP) continue;
      MSG_DEBUG(props[i].second);
      vars.push_back(props[i].first);
    }
  }
  return vars;
}

// #ifndef SKIP_XAOD_COMPILATION
// //-----------------------------------------------------------------------------
// xAOD::Iso::IsolationType KTB::IsoType(AnaIso::AnaIso iso){
//   switch (iso)
//   {
//   case AnaIso::etcone20          : return xAOD::Iso::etcone20    ;
//   case AnaIso::etcone30          : return xAOD::Iso::etcone30    ;
//   case AnaIso::etcone40          : return xAOD::Iso::etcone40    ;
//   case AnaIso::ptcone20          : return xAOD::Iso::ptcone20    ;
//   case AnaIso::ptcone30          : return xAOD::Iso::ptcone30    ;
//   case AnaIso::ptcone40          : return xAOD::Iso::ptcone40    ;
// #ifdef ISREL20
//   case AnaIso::ptvarcone20       : return xAOD::Iso::ptvarcone20 ;
//   case AnaIso::ptvarcone30       : return xAOD::Iso::ptvarcone30 ;
//   case AnaIso::ptvarcone40       : return xAOD::Iso::ptvarcone40 ;
// #endif
//   case AnaIso::topoetcone20      : return xAOD::Iso::topoetcone20;
//   case AnaIso::topoetcone30      : return xAOD::Iso::topoetcone30;
//   case AnaIso::topoetcone40      : return xAOD::Iso::topoetcone40;
//   // case AnaIso::N_NONRELATIVE     : return xAOD::Iso::;
//   case AnaIso::etcone20overPt    : return xAOD::Iso::etcone20    ;
//   case AnaIso::etcone30overPt    : return xAOD::Iso::etcone30    ;
//   case AnaIso::etcone40overPt    : return xAOD::Iso::etcone40    ;
//   case AnaIso::ptcone20overPt    : return xAOD::Iso::ptcone20    ;
//   case AnaIso::ptcone30overPt    : return xAOD::Iso::ptcone30    ;
//   case AnaIso::ptcone40overPt    : return xAOD::Iso::ptcone40    ;
// #ifdef ISREL20
//   case AnaIso::ptvarcone20overPt : return xAOD::Iso::ptvarcone20 ;
//   case AnaIso::ptvarcone30overPt : return xAOD::Iso::ptvarcone30 ;
//   case AnaIso::ptvarcone40overPt : return xAOD::Iso::ptvarcone40 ;
// #endif
//   case AnaIso::topoetcone20overPt: return xAOD::Iso::topoetcone20;
//   case AnaIso::topoetcone30overPt: return xAOD::Iso::topoetcone30;
//   case AnaIso::topoetcone40overPt: return xAOD::Iso::topoetcone40;
    
//   default: MSG_INFO("Error! Cannot find xAOD::Iso::IsolationType. Exiting.");
//   }
//   exit(1);
//   return xAOD::Iso::etcone20;
// }

// #endif // SKIP_XAOD_COMPILATION
