#include "HGamTools/SkimAndSlim.h"
#include "brendlingerHiggsTestbed/RunUtilsNaf.h"

int main(int argc, char *argv[])
{
  // Set up the job for xAOD access
  xAOD::Init().ignore();

  // Create our algorithm
  SkimAndSlim *alg = new SkimAndSlim("SkimAndSlim");

  // Use helper to start the job
  HG::runJobNaf(alg, argc, argv);

  return 0;
}
