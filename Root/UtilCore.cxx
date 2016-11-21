#include <brendlingerHiggsTestbed/UtilCore.h>

#include <SampleHandler/MetaFields.h>
#include <SampleHandler/MetaVector.h>

#include <SampleHandler/SampleHandler.h>
#include <SampleHandler/SampleLocal.h>


//-----------------------------------------------------------------------------
// void KTB::SetSHSampleEntries(SH::Sample& samp,int n,Double_t* entries){
//   std::vector<Long64_t> entries1;
//   for (Int_t i = 0; i < n; i++) {
//     entries1.push_back((int)entries[i]);
//   }
//   samp.addReplaceMeta (new SH::MetaVector<Long64_t>(SH::MetaFields::numEventsPerFile, entries1));
//   return;
// }

//-----------------------------------------------------------------------------
std::vector<double> KTB::GetDerivationSkimOriginalSumw(TFile* file){
  // Initial weighted
  // Final nevents
  // Initial events
  // Final weighted
  TTree *MetaData = dynamic_cast<TTree*>(file->Get("MetaData"));
  std::vector<double> ret;
  if (!MetaData) {
    ret.push_back(-1.);
    ret.push_back(-1.);
    ret.push_back(-1.);
    ret.push_back(-1.);
    MSG_INFO("Error! File does not have Derivation Framework skim metadata!");
    return ret;
  }
  // extract the information from the EventBookkeepers branch
  TTreeFormula tf("tf","EventBookkeepers.m_nWeightedAcceptedEvents",MetaData);
  TTreeFormula tf2("tf","EventBookkeepers.m_nAcceptedEvents",MetaData);
  MetaData->LoadTree(0);
  tf.UpdateFormulaLeaves();
  tf.GetNdata();
  tf2.UpdateFormulaLeaves();
  tf2.GetNdata();
  double initialSumOfWeightsInThisFile = tf.EvalInstance(0);
  double finalSumOfWeightsInThisFile = tf.EvalInstance(1);
  double initialEvents = tf2.EvalInstance(0);
  double finalNevents = tf2.EvalInstance(1);
  ret.push_back(initialSumOfWeightsInThisFile);
  ret.push_back(finalNevents);
  ret.push_back(initialEvents);
  ret.push_back(finalSumOfWeightsInThisFile);
  return ret;
}

//-----------------------------------------------------------------------------
void KTB::PrintJobAlgorithms(EL::Job job){
  std::cout << "Job Algorithms:" << std::endl;
  for (EL::Job::algsIter alg = job.algsBegin(), end = job.algsEnd(); alg != end; ++ alg){
    std::cout << " " << (*alg)->GetName() << std::endl;
  }
  return;
}

//-----------------------------------------------------------------------------
double KTB::GetDeltaR(double eta1,double phi1,double eta2,double phi2){
  double d1 = eta1-eta2;
  double d2 = TVector2::Phi_mpi_pi(phi1-phi2);
  return sqrt(d1*d1+d2*d2);
}

//-----------------------------------------------------------------------------
std::vector<int> KTB::check_overlap (    std::vector<TLorentzVector> tlv1,
                                	 std::vector<int> obj1,
                                	 std::vector<TLorentzVector> tlv2,
                                	 std::vector<int> obj2,
                                	 double dr ) {
  std::vector<int> obj3; 
  obj3.clear();
  bool overlap;
  for(unsigned int i=0;i<obj1.size();++i){
    overlap = false;
    for(unsigned int j=0;j<obj2.size();++j){
      if (KTB::GetDeltaR(tlv1[obj1[i]].Eta(),tlv1[obj1[i]].Phi(),tlv2[obj2[j]].Eta(),tlv2[obj2[j]].Phi())<dr) overlap = true;
    }
    if (!overlap) obj3.push_back(obj1[i]);
    else MSG_INFO ("Overlapping!");
  }
  return obj3;
}

//-----------------------------------------------------------------------------
std::vector<int> KTB::check_overlap_pt ( std::vector<TLorentzVector> tlv1,
                                	 std::vector<int> obj1,
                                	 std::vector<TLorentzVector> tlv2,
                                	 std::vector<int> obj2,
                                	 double dr ) {
  // different objects e.g. "anti-id vs id" or "id vs anti-id"
  std::vector<int> obj3; 
  obj3.clear();
  bool overlap;
  for(unsigned int i=0;i<obj1.size();++i){
    overlap = false;
    for(unsigned int j=0;j<obj2.size();++j){
      if (obj1[i] == obj2[j]) continue; // make sure that those are different objects
      if (KTB::GetDeltaR(tlv1[obj1[i]].Eta(),tlv1[obj1[i]].Phi(),tlv2[obj2[j]].Eta(),tlv2[obj2[j]].Phi())>dr) continue;
      if (tlv1[obj1[i]].Pt()<tlv2[obj2[j]].Pt()) overlap = true;
    }
    if (!overlap) obj3.push_back(obj1[i]);
    else MSG_INFO ("Overlapping!");
  }
  return obj3;
}

std::vector<int> KTB::check_overlap_pt ( std::vector<TLorentzVector> tlv1,
                                	 std::vector<int> obj1,
                                 	 double dr ) {
  // same objects i.e. "id vs id" or "anti-id vs anti-id"
  std::vector<int> obj2; 
  obj2.clear();
  bool overlap;
  for(unsigned int i=0;i<obj1.size();++i){
    overlap = false;
    for(unsigned int j=0;j<obj1.size();++j){
      if (obj1[i] <= obj1[j]) continue; // make sure that those are different objects
      if (KTB::GetDeltaR(tlv1[obj1[i]].Eta(),tlv1[obj1[i]].Phi(),tlv1[obj1[j]].Eta(),tlv1[obj1[j]].Phi())>dr) continue;
      if (tlv1[obj1[i]].Pt()<tlv1[obj1[j]].Pt()) overlap = true;
    }
    if (!overlap) obj2.push_back(obj1[i]);
    else MSG_INFO ("Overlapping!");
  }
  return obj2;
}

//-----------------------------------------------------------------------------
void KTB::StringTok(std::vector<std::string>& ls,
		    const std::string& str,
		    const std::string& tok)
{
  //======================================================================
  // Split a long string into a set of shorter strings spliting along
  // divisions makers by the characters listed in the token string
  //======================================================================
  const std::string::size_type S = str.size();
  std::string::size_type  i = 0;  

  while (i < S) {
    // eat leading whitespace
    while (i < S && tok.find(str[i]) != std::string::npos) {
      ++i;
    }
    if (i == S) break;  // nothing left but WS
    
    // find end of word
    std::string::size_type  j = i+1;
    while (j < S && tok.find(str[j]) == std::string::npos) {
      ++j;
    }
    
    // add word
    ls.push_back(str.substr(i,j-i));
    
    // set up for next loop
    i = j+1;
  }  
}

//-----------------------------------------------------------------------------
std::string KTB::GetIndices(std::vector<int> indices){
  std::string out;
  for(unsigned int i=0;i<indices.size();++i){
    out += std::to_string(indices[i]);
    out += " ";
  }
  return out;
}

//-----------------------------------------------------------------------------
void KTB::TransferIndexFromVecToVec(int i,std::vector<int>& vfrom, std::vector<int>& vto){
  vfrom.erase(std::remove(vfrom.begin(), vfrom.end(), i),vfrom.end());
  vto.push_back(i);
}

//-----------------------------------------------------------------------------
std::string KTB::GetHistogramLocation(std::string classname,std::string instname,std::string name){
  std::string location = classname+"_"+instname;
  location += "/";
  location += classname+"_"+instname;
  location += "_"+name;
  return location;
}
//-----------------------------------------------------------------------------
// std::string PSL::AlgBase::GetHistogramLocation(std::string classname,std::string instname,Sample s,LepVariable v,Variable lep_index){
//   std::string samplename = ConvertSampleToStr(s);
//   std::string varname = ConvertLepVarToStr(v);
//   std::string indexname = ConvertVarToStr(lep_index);
//   std::string location = classname+"_"+instname;
//   location += "/";
//   location += classname+"_"+instname;
//   location += "_"+samplename+"_"+varname+"_"+indexname;
//   return location;
// }
//-----------------------------------------------------------------------------
// std::string PSL::AlgBase::GetHistogramLocation(std::string classname,std::string instname,Sample s,LepVariable v){
//   std::string samplename = ConvertSampleToStr(s);
//   std::string varname = ConvertLepVarToStr(v);
//   std::string location = classname+"_"+instname;
//   location += "/";
//   location += classname+"_"+instname;
//   location += "_"+samplename+"_"+varname;
//   return location;
// }

// //-----------------------------------------------------------------------------
// std::string PSL::AlgBase::GetHistogramLocation(std::string classname,std::string instname,Sample s,JetVariable v){
//   std::string samplename = ConvertSampleToStr(s);
//   std::string varname = ConvertJetVarToStr(v);
//   std::string location = classname+"_"+instname;
//   location += "/";
//   location += classname+"_"+instname;
//   location += "_"+samplename+"_"+varname;
//   return location;
// }
