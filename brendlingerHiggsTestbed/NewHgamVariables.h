#ifndef brendlingerHiggsTestbed_NewHgamVariables_H
#define brendlingerHiggsTestbed_NewHgamVariables_H

#include "HGamAnalysisFramework/VarHandler.h"
#include "HGamAnalysisFramework/HgammaIncludes.h"

namespace HG {

  //____________________________________________________________________________
  class kurtvar : public VarBase<float> {
  public:
    kurtvar() : VarBase("kurtvar") { m_default = -99; }
    ~kurtvar() { }

    float calculateValue(bool truth)
    {
       (void)truth;
      return m_default;
    }
  };


}

namespace var {
  extern HG::kurtvar kurtvar;

}

#endif // brendlingerHiggsTestbed_NewHgamVariables_H
