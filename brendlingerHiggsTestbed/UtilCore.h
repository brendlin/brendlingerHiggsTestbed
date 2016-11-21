#ifndef brendlingerHiggsTestbed_UtilCore_H
#define brendlingerHiggsTestbed_UtilCore_H

#include <vector>
#include <string>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TTreeFormula.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include "brendlingerHiggsTestbed/Messaging.h"

#include "EventLoop/Job.h"
#include "EventLoop/Algorithm.h"


namespace KTB
{
  /* void SetSHSampleEntries(SH::Sample& sample,int n,Double_t* entries); */
  std::vector<double> GetDerivationSkimOriginalSumw(TFile* file);
  void PrintJobAlgorithms(EL::Job job);

  void StringTok(std::vector<std::string>& out,
		 const std::string& in,
		 const std::string& sep_token);

  double GetDeltaR(double eta1,double phi1,double eta2,double phi2);

  std::vector<int> check_overlap (std::vector<TLorentzVector> tlv1,
                         	  std::vector<int> obj1,
                         	  std::vector<TLorentzVector> tlv2,
                         	  std::vector<int> obj2,
                         	  double dr
                        	 );

  std::vector<int> check_overlap_pt (std::vector<TLorentzVector> tlv1,
                         	     std::vector<int> obj1,
                         	     std::vector<TLorentzVector> tlv2,
                         	     std::vector<int> obj2,
                         	     double dr
                        	    );

  std::vector<int> check_overlap_pt (std::vector<TLorentzVector> tlv1,
                         	     std::vector<int> obj1,
                         	     double dr
                        	    );

  template <class T,class U>
    std::string ConvertToStr(T the_enum_item,U pairs,std::string the_type){
    if (the_enum_item == pairs[the_enum_item].first) {
      return pairs[the_enum_item].second;
    }
    MSG_INFO("Error! Cannot find string name for enum " << the_enum_item << " of type " << the_type);
    MSG_INFO("Check to make sure the order of your properties in Variables.cxx is the same as the enum in Variables.h");
    for (unsigned int i=0;i<pairs.size();++i){
      MSG_INFO(" - " << pairs[i].second);
    }
    exit(1);
    return "None";
  }

  template <class T>
    T ConvertToEnum(const std::string& item,std::vector<std::pair<T,std::string> > pairs,bool fatal=false){
    for (unsigned int i=0;i<pairs.size();++i){
      if (item == pairs[i].second) return pairs[i].first;
    }
    if (fatal){
      MSG_INFO("Error! Cannot find enum for string " << item << ". Please pick from the following:");
      for (unsigned int i=0;i<pairs.size();++i){
        MSG_INFO(" - " << pairs[i].second);
      }
      exit(1);
    }
    return static_cast<T>(0);
  }

  //-----------------------------------------------------------------------------
  std::string GetIndices(std::vector<int> indices);

  void TransferIndexFromVecToVec(int i,std::vector<int>& vfrom, std::vector<int>& vto);
  //-----------------------------------------------------------------------------

  std::string GetHistogramLocation(std::string classname,std::string instname,std::string name);

}
#endif // brendlingerHiggsTestbed_UtilCore_H

