#ifndef brendlingerHiggsTestbed_Plots_H
#define brendlingerHiggsTestbed_Plots_H

#include <brendlingerHiggsTestbed/Sample.h>
#include <brendlingerHiggsTestbed/UtilCore.h>
#include <brendlingerHiggsTestbed/Variables.h>
/* #include <brendlingerHiggsTestbed/CutItem.h> */
//#include <brendlingerHiggsTestbed/XSUSYObjDefAlgExpert.h>
#include "xAODEventInfo/EventInfo.h"

#include <vector>
#include "TObject.h"
#include <EventLoop/Worker.h>

namespace KTB
{

  class Plots : public TNamed
  {
    // put your configuration variables here as public variables.
    // that way they can be set directly from CINT and python.
  public:
    Sample m_currentSample; //!
    std::vector<Variable> m_variables; // configurable

    std::vector<KTB::Sample> Samples; // configurable
    void set_Samples(std::string s); // converts to sample and puts in a vector
    std::vector<std::string> get_Samples(void);

    // variables that don't get filled at submission time should be
    // protected from being send from the submission node to the worker
    // node (done by the //!)
  public:

    // this is a standard constructor
    Plots();
    Plots(const char* name);
    ~Plots(){};
    //
    virtual bool init(void);
    void FillVariableHistograms(const xAOD::EventInfo& ei,Sample s,double weight);
    void PrintConfiguration(void);
    void SaveAllNonEmptyHistograms(EL::Worker& wk);

  private:
    std::vector<std::vector<TH1*> > m_VariablesBySample; //! // sample var

  public:
    // this is needed to distribute the algorithm to the workers
    ClassDef(Plots, 1);
  };
  
}
#endif
