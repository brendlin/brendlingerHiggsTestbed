#ifndef brendlingerHiggsTestbed_SkimAndSlimAndAdd_H
#define brendlingerHiggsTestbed_SkimAndSlimAndAdd_H

#include "HGamAnalysisFramework/HgammaAnalysis.h"

class SkimAndSlimAndAdd : public HgammaAnalysis
{
public:

private:
  xAOD::TEvent *m_outEvent; //!

public:

  SkimAndSlimAndAdd() { }
  SkimAndSlimAndAdd(const char *name);
  virtual ~SkimAndSlimAndAdd();

  // these are the functions inherited from HgammaAnalysis
  //virtual EL::StatusCode initialize();
  virtual EL::StatusCode createOutput();
  virtual EL::StatusCode execute();
/*   virtual EL::StatusCode finalize(); */
/*   virtual EL::StatusCode fileExecute(); */

 public:
  static SG::AuxElement::Decorator<float> randomvarc;
  static SG::AuxElement::Accessor<float> randomvarc_acc;

  // this is needed to distribute the algorithm to the workers
  ClassDef(SkimAndSlimAndAdd, 1);
};

#endif // HGamTools_SkimAndSlimAndAdd_H
