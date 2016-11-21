#ifndef brendlingerHiggsTestbed_SAMPLE_H
#define brendlingerHiggsTestbed_SAMPLE_H

/**********************************************************************************
 * @Package: MonojetSoftLepton
 * @Class  : Sample
 * @Author : Rustem Ospanov, Doug Schaefer
 *
 * @Brief  :
 * 
 *  Enum for dataset keys (samples) and helper class for a set of samples
 * 
 **********************************************************************************/

// C/C++
#include <vector>
#include <string>

#include "brendlingerHiggsTestbed/Variables.h"

/** \brief The KTB namespace */
namespace KTB
{
  //* \brief Enums for unique dataset samples. Used for naming and stuff. After a point they are overlapping. */
  enum Sample {
    knone,
    kdata,
    kunlabeled,
    kggh,
    ktth,
    ktwh,
    kbbh,
    kthjb,
    kttgamma,
    kvbfh,
    kwh,
    kzh,
    kEndOfNonOverlapping, // end of non-overlapping! All samples after this have a special treatment
    kall,
    khiggs,
  };
  
  class sample_props{
  public:
    Sample first; // sample
    std::string second; // name
    std::string human_readable; // human-readable name
    std::string tex_label;
    int powheg_runnumber;
    int sherpa_runnumber;
    int madgraph_runnumber;

    sample_props(){};
    sample_props(Sample s,std::string nm,std::string hum_read){
      first = s;
      second = nm;
      human_readable = hum_read;
      powheg_runnumber = 0;
      sherpa_runnumber = 0;
      madgraph_runnumber = 0;
      //tex_label = lab;
    };

    sample_props(Sample s,std::string nm,std::string hum_read,int powheg,int sherpa, int madgraph){
      first = s;
      second = nm;
      human_readable = hum_read;
      powheg_runnumber = powheg;
      sherpa_runnumber = sherpa;
      madgraph_runnumber = madgraph;
      //tex_label = lab;
    };
  };

  const std::vector<KTB::sample_props> GetSampleProperties();
  //const std::vector<std::pair<KTB::Sample,std::string> > GetSampleStringPairs(void);
  
  std::string ConvertSampleToStr(Sample s);
  //std::string ConvertSampleToTex(Sample s);
  Sample ConvertToSample(const std::string &s);
  Sample ConvertToSample(int mc_channel_number);
  
  std::vector<KTB::Sample> GetAllSamples(bool do_overlapping_samples=true);
  std::vector<KTB::Sample> GetAllSamplesDetailed();
  std::vector<std::string> GetAllSampleStrings(bool do_overlapping_samples=true);
  std::vector<std::string> GetAllSampleStringsDetailed();
  
  std::vector<KTB::Sample> PrettyConvert(Sample s1, Sample s2=KTB::knone,
                                         Sample s3=KTB::knone, Sample s4=KTB::knone
                                         ,Sample s5=KTB::knone,Sample s6=KTB::knone
                                         ,Sample s7=KTB::knone,Sample s8=KTB::knone);
  
  //* \brief To be able to have composite sample sets */
  std::vector<KTB::Sample> ConvertSampleToSampleVec(Sample s);
  std::vector<std::string> ConvertSampleToSampleVec(std::string s);
  
  /** \brief Match samples to each other */
  bool MatchSample(Sample s1, Sample s2);
  void PrintSample(Sample s);
  void PrintSamples(std::vector<Sample> s);

  std::string GetHistogramLocation(std::string classname,std::string instname,Sample s,std::string name);
  std::string GetHistogramLocation(std::string classname,std::string instname,Sample s,Variable v);
  
}

#endif // brendlingerHiggsTestbed_SAMPLE_H
