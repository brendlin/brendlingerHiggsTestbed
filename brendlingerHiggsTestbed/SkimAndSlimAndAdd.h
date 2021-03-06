#ifndef brendlingerHiggsTestbed_SkimAndSlimAndAdd_H
#define brendlingerHiggsTestbed_SkimAndSlimAndAdd_H

#include "HGamAnalysisFramework/HgammaAnalysis.h"
#include "brendlingerHiggsTestbed/Plots.h"
#include "brendlingerHiggsTestbed/Sample.h"
#include "brendlingerHiggsTestbed/Variables.h"

class SkimAndSlimAndAdd : public HgammaAnalysis
{
public:

private:
  KTB::Sample m_currentsample; //!

public:

  SkimAndSlimAndAdd() { }
  SkimAndSlimAndAdd(const char *name);
  virtual ~SkimAndSlimAndAdd();

  // these are the functions inherited from HgammaAnalysis
  virtual EL::StatusCode initialize();
  virtual EL::StatusCode createOutput();
  virtual EL::StatusCode execute();
  virtual EL::StatusCode finalize();
  virtual EL::StatusCode fileExecute();

 public:

  KTB::Plots* m_plots; //!

  // this is needed to distribute the algorithm to the workers
  ClassDef(SkimAndSlimAndAdd, 1);
};

#endif // HGamTools_SkimAndSlimAndAdd_H
