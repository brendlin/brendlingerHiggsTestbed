#include <brendlingerHiggsTestbed/Plots.h>
//#include <EventLoop/Worker.h>

// this is needed to distribute the algorithm to the workers
ClassImp(KTB::Plots)

//-----------------------------------------------------------------------------
KTB::Plots::Plots()
{
  MSG_DEBUG("Constructor");
}

//-----------------------------------------------------------------------------
KTB::Plots::Plots(const char* name)
{
  SetName(name);
  MSG_DEBUG("Constructor");
}

//-----------------------------------------------------------------------------
bool KTB::Plots::init(void)
{
  MSG_DEBUG("Plots algbase name is " << GetName());

  //
  // even if there are no cuts, we need one dummy bin.
  // Likewise, we want an "all" bin for samples
  // Yah ok this is sort-of done twice. It is ok though.
  //
  bool has_all = false;
  bool has_data = false;
  for(unsigned int i=0;i<Samples.size();i++){
    if (Samples[i] == kall) has_all = true;
    if (Samples[i] == kdata) has_data = true;
  }
  if(!has_all) Samples.push_back(kall);
  if(!has_data) Samples.push_back(kdata);

  // Unless otherwise specified, save all of the variables from Variables.h
  if (!m_variables.size()) m_variables = GetAllVariables();

  // Set up variable histograms by sample
  m_VariablesBySample.clear();
  std::string name;
  for (unsigned int i=0;i<Samples.size();++i){
    std::vector<TH1*> varvec;
    for (unsigned int j=0;j<m_variables.size();++j){
      name = GetHistogramLocation("Plots",GetName(),Samples[i],m_variables[j]);
      TH1F* tmphist = MakeVariableTH1F(name,m_variables[j]);
      //tmphist->SetDirectory(0); // done in MakeVariableTH1F
      //tmphist->Sumw2(); // done in MakeVariableTH1F
      //tmphist->GetXaxis()->SetRange(0,tmphist->GetNbinsX()+1);
      varvec.push_back(tmphist);
      // Make sure (in EventLoop) that the new call and the setHistogramOutput bit are in the same step
      //setHistogramOutput(tmphist);
    }
    m_VariablesBySample.push_back(varvec);
  }

  PrintConfiguration();
  return true;
}

//-----------------------------------------------------------------------------
void KTB::Plots::SaveAllNonEmptyHistograms(EL::Worker& wk){
  MSG_DEBUG("finish.");
  //
  // Only save a histogram if it has entries
  //
  for (unsigned int i=0;i<Samples.size();++i){
    for (unsigned int j=0;j<m_variables.size();++j){
      // GetSumw2N is for whether Sumw2 has been called.
      // We set the range already to include first and last bins
      int nbins = m_VariablesBySample[i][j]->GetNbinsX();
      if (m_VariablesBySample[i][j]->Integral() ||
          m_VariablesBySample[i][j]->GetBinContent(0) ||
          m_VariablesBySample[i][j]->GetBinContent(nbins+1)
          )
        wk.addOutput(m_VariablesBySample[i][j]);
      else delete m_VariablesBySample[i][j];
    }
  }

  MSG_DEBUG("finish done.");
  return;
}

//-----------------------------------------------------------------------------
std::vector<std::string> KTB::Plots::get_Samples(void){
  std::vector<std::string> tmp;
  for (unsigned int i=0;i<Samples.size();++i){
    tmp.push_back(ConvertSampleToStr(Samples[i]));
  }
  return tmp;
}

//-----------------------------------------------------------------------------
void KTB::Plots::FillVariableHistograms(const xAOD::EventInfo& ei, Sample s,double weight){
  MSG_DEBUG("FillVariableHistograms begin");

  for (unsigned int i=0;i<Samples.size();++i){
    if (!MatchSample(Samples[i],s)) 
      continue;
    for (unsigned int j=0;j<m_variables.size();++j){
      // if (!m_EDM->VariableExists(m_variables[j])) continue;
      MSG_DEBUG("FillVariableHistograms: Filling " << 
                ConvertSampleToStr(Samples[i]) << " " << ConvertVarToStr(m_variables[j])
                << " with value " << 125.);
      m_VariablesBySample[i][j]->Fill((*GetAccessor(m_variables[j]))(ei),weight);
    }
  }
  MSG_DEBUG("FillVariableHistograms end");
}

//-----------------------------------------------------------------------------
void KTB::Plots::PrintConfiguration(void){
  MSG_INFO("-------------------------------Plots Configuration:--------------------------------");
  MSG_INFO("This Instance Name      : " << GetName()              );
  for (unsigned int i=0;i<Samples.size();++i){
    if (i == 0) {
      MSG_INFO("Samples                 : " << ConvertSampleToStr(Samples[i]));
    }
    else MSG_INFO("                          " << ConvertSampleToStr(Samples[i]));
  }
  std::string tmp;
  for (unsigned int i=0;i<m_variables.size();++i){
    tmp += ConvertVarToStr(m_variables[i]);
    tmp += " ";
  }
  MSG_INFO("Variables               : " << tmp                    );
  MSG_INFO("---------------------------------------------------------------------------------------");
}

//-----------------------------------------------------------------------------
void KTB::Plots::set_Samples(std::string s){
  MSG_DEBUG("setting samples to " << s);
  std::vector<std::string> samples_str_tmp;
  Samples.clear();
  KTB::StringTok(samples_str_tmp,s," ");
  for(unsigned int i=0;i<samples_str_tmp.size();i++){
    //MSG_INFO(" " << samples_str_tmp.at(i));
    KTB::Sample samp = KTB::ConvertToSample(samples_str_tmp.at(i));
    if (!std::count(Samples.begin(),Samples.end(),samp)) Samples.push_back(samp);
  }
}
