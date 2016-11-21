#include "brendlingerHiggsTestbed/Sample.h"

#include <iomanip>
#include <iostream>

#include <brendlingerHiggsTestbed/Messaging.h>
#include <brendlingerHiggsTestbed/UtilCore.h>

//-----------------------------------------------------------------------------
const std::vector<KTB::sample_props> KTB::GetSampleProperties(){
  static std::vector<sample_props> s_props;
  if (s_props.empty()){
    //                             ENUM       code-readable human-readable powheg sherpa madgraph
    s_props.push_back(sample_props(knone      ,"none"      ,"None"       ,      0,      0,      0));
    s_props.push_back(sample_props(kdata      ,"data"      ,"Data"       ,      0,      0,      0));
    s_props.push_back(sample_props(kunlabeled ,"unlabeled" ,"Unlabeled"  ,      0,      0,      0));
    s_props.push_back(sample_props(kggh       ,"ggh"       ,"ggh"        , 341000,      0,      0));
    s_props.push_back(sample_props(ktth       ,"tth"       ,"tth"        ,      0,      0,      0));
    s_props.push_back(sample_props(ktwh       ,"twh"       ,"twh"        ,      0,      0,      0));
    s_props.push_back(sample_props(kbbh       ,"bbh"       ,"bbh"        ,      0,      0,      0));
    s_props.push_back(sample_props(kthjb      ,"thjb"      ,"thjb"       ,      0,      0,      0));
    s_props.push_back(sample_props(kttgamma   ,"ttgamma"   ,"ttgamma"    ,      0,      0,      0));
    s_props.push_back(sample_props(kvbfh      ,"vbfh"      ,"vbfh"       ,      0,      0,      0));
    s_props.push_back(sample_props(kwh        ,"wh"        ,"zh"         ,      0,      0,      0));
    s_props.push_back(sample_props(kzh        ,"zh"        ,"zh"         ,      0,      0,      0));
    s_props.push_back(sample_props(kEndOfNonOverlapping,"error","Error"  ));
    s_props.push_back(sample_props(kall       ,"all"       ,"All"        ));
    s_props.push_back(sample_props(khiggs     ,"higgs"     ,"Higgs"      ));
  }
  return s_props;
}

//-----------------------------------------------------------------------------
KTB::Sample KTB::ConvertToSample(const std::string &s){
  // do not do this during a loop
  static std::vector<sample_props> props = GetSampleProperties();
  for (unsigned int i=0;i<props.size();++i){
    if (s == props[i].second) return props[i].first;
  }
  MSG_INFO("Error! Sample.cxx Cannot find sample enum for " << s);
  exit(1);
  return knone;
}

//-----------------------------------------------------------------------------
KTB::Sample KTB::ConvertToSample(int mc_channel_number){
  // do not do this during a loop
  static std::vector<sample_props> props = GetSampleProperties();
  for (unsigned int i=0;i<props.size();++i){
    if (mc_channel_number == props[i].powheg_runnumber  ) return props[i].first;
    if (mc_channel_number == props[i].sherpa_runnumber  ) return props[i].first;
    if (mc_channel_number == props[i].madgraph_runnumber) return props[i].first;
  }
  MSG_INFO("Error! Sample.cxx Cannot find sample enum for " << mc_channel_number);
  exit(1);
  return knone;
}

//-----------------------------------------------------------------------------
std::string KTB::ConvertSampleToStr(Sample s) {
  return ConvertToStr(s,GetSampleProperties(),"Sample");
}

//-----------------------------------------------------------------------------
std::vector<KTB::Sample> KTB::GetAllSamples(bool do_overlapping_samples){
  std::vector<Sample> samples;
  std::vector<Sample> samples_covered;
  static std::vector<sample_props> props = GetSampleProperties();
  unsigned int start = kEndOfNonOverlapping;
  if (do_overlapping_samples) start = props.size();
  for (unsigned int i=start; i>0; --i) {
    Sample s = static_cast<KTB::Sample>(i-1);
    if (s == knone) continue;
    if (s == kdata) continue;
    if (s == kunlabeled) continue;
    if (s == kEndOfNonOverlapping) continue;
    if (s == kall) continue;
    if (std::find(samples_covered.begin(),samples_covered.end(),s) != samples_covered.end())
      continue;
    samples.push_back(s);
    std::vector<Sample> tmp = ConvertSampleToSampleVec(s);
    for (unsigned int j=0;j<tmp.size();++j){
      samples_covered.push_back(tmp[j]);
    }
  }
  std::reverse(samples.begin(),samples.end());
  return samples;
}
//-----------------------------------------------------------------------------
std::vector<KTB::Sample> KTB::GetAllSamplesDetailed(){
  return GetAllSamples(false);
}

//-----------------------------------------------------------------------------
std::vector<std::string> KTB::GetAllSampleStrings(bool do_overlapping_samples){
  std::vector<Sample> samples = GetAllSamples(do_overlapping_samples);
  std::vector<std::string> tmp;
  for (unsigned int i=0;i<samples.size();++i){
    tmp.push_back(ConvertSampleToStr(samples[i]));
  }
  return tmp;
}

//-----------------------------------------------------------------------------
std::vector<std::string> KTB::GetAllSampleStringsDetailed(){
  return GetAllSampleStrings(false);
}

//-----------------------------------------------------------------------------
std::vector<KTB::Sample> KTB::ConvertSampleToSampleVec(Sample s){
  // If non-overlapping / unique, return itself
  if (s < kEndOfNonOverlapping) return std::vector<KTB::Sample>(1,s);
  // All is all
  if (s == kall) {
    std::vector<KTB::Sample> vec;
    for (unsigned int i=0;i<kEndOfNonOverlapping;i++){
      if (i == knone) continue;
      if (i == kdata) continue;
      vec.push_back(static_cast<KTB::Sample>(i));
    }
    return vec;
  }
  // Composites - SMWW, top, Zjet
  if (s == khiggs) return PrettyConvert(kggh,ktth,ktwh,kbbh,kthjb,kvbfh,kwh,kzh);
  // Return empty vector.
  MSG_INFO("Error! Could not convert sample to sample vector!");
  exit(1);
  return std::vector<KTB::Sample>();
}

//-----------------------------------------------------------------------------
std::vector<std::string> KTB::ConvertSampleToSampleVec(std::string s){
  std::vector<KTB::Sample> vec = ConvertSampleToSampleVec(ConvertToSample(s));
  std::vector<std::string> tmp;
  for (unsigned int i=0;i<vec.size();++i){
    tmp.push_back(ConvertSampleToStr(vec[i]));
  }
  return tmp;
}

//-----------------------------------------------------------------------------
std::vector<KTB::Sample> KTB::PrettyConvert(Sample s1,Sample s2,
                                            Sample s3,Sample s4,Sample s5,Sample s6,
                                            Sample s7,Sample s8){
  std::vector<KTB::Sample> tmp;
  if(s1 != knone) tmp.push_back(s1);
  if(s2 != knone) tmp.push_back(s2);
  if(s3 != knone) tmp.push_back(s3);
  if(s4 != knone) tmp.push_back(s4);
  if(s5 != knone) tmp.push_back(s5);
  if(s6 != knone) tmp.push_back(s6);
  if(s7 != knone) tmp.push_back(s7);
  if(s8 != knone) tmp.push_back(s8);
  return tmp;
}

//-----------------------------------------------------------------------------
bool KTB::MatchSample(Sample s1, Sample s2){
  if (s1 == s2) return true;
  std::vector<KTB::Sample> svec1 = ConvertSampleToSampleVec(s1);
  std::vector<KTB::Sample> svec2 = ConvertSampleToSampleVec(s2);
  for (unsigned int i=0;i<svec1.size();++i){
    for (unsigned int j=0;j<svec2.size();++j){
      //
      // in all logical cases one of these samples will be a unique sample, and have a length of 1.
      // So this checks if any of the unique samples overlap with each other.
      if (svec1.at(i) == svec2.at(j)) return true;
    }
  }
  return false;
}

//-----------------------------------------------------------------------------
void KTB::PrintSample(Sample s){
  std::cout << "   " << ConvertSampleToStr(s) << ":" << std::endl;
  std::vector<KTB::Sample> subsamples = ConvertSampleToSampleVec(s);
  for (unsigned int j=0;j<subsamples.size();++j){
    std::cout << "      " << ConvertSampleToStr(subsamples.at(j)) << std::endl;
  }
  return;
}

//-----------------------------------------------------------------------------
void KTB::PrintSamples(std::vector<KTB::Sample> s){
  for(unsigned i = 0; i < s.size(); ++i) { 
    PrintSample(s.at(i));
  }
  return;
}

//-----------------------------------------------------------------------------
std::string KTB::GetHistogramLocation(std::string classname,std::string instname,Sample s,std::string name){
  std::string samplename = ConvertSampleToStr(s);
  std::string location = classname+"_"+instname;
  location += "/";
  location += samplename;
  location += "/";
  location += classname+"_"+instname+"_"+samplename+"_"+name;
  return location;
}

//-----------------------------------------------------------------------------
std::string KTB::GetHistogramLocation(std::string classname,std::string instname,Sample s,Variable v){
  std::string samplename = ConvertSampleToStr(s);
  std::string varname = ConvertVarToStr(v);
  std::string location = classname+"_"+instname;
  location += "/";
  location += samplename;
  location += "/";
  location += classname+"_"+instname+"_"+samplename+"_"+varname;
  return location;
}
