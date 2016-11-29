#ifndef brendlingerHiggsTestbed_JobHelperNaf_H
#define brendlingerHiggsTestbed_JobHelperNaf_H

#include "HGamAnalysisFramework/HgammaIncludes.h"
#include "HGamAnalysisFramework/HgammaAnalysis.h"

#include "EventLoop/DirectDriver.h"
#include "EventLoop/Job.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "xAODRootAccess/Init.h"
#include <TSystem.h>
#include <iostream>
#include <string>


//! \brief Hgamma namespace
namespace HG {

  //! \name   A few general helper methods and definitions
  //! \author Dag Gillberg
  //@{

  void runJobNaf(HgammaAnalysis *alg, int argc, char** argv);
  
  //@}
}

#endif
