#ifndef brendlingerHiggsTestbed_Utils_H
#define brendlingerHiggsTestbed_Utils_H

#include "AsgTools/MessageCheck.h"
#include "xAODRootAccess/TEvent.h"
#include "EventLoop/StatusCode.h"
#include "xAODCore/AuxInfoBase.h"
#include <iostream>

namespace kurt {

  template <class T>
  EL::StatusCode recordInfo(xAOD::TEvent& inEvent, xAOD::TEvent& outEvent, std::string name)
  {
    ANA_CHECK_SET_TYPE( EL::StatusCode );
    
    const T *orig = nullptr;
    if (!inEvent.retrieve(orig, name).isSuccess()) return EL::StatusCode::FAILURE;
    
    T *copy = new T();
    xAOD::AuxInfoBase *copyAux = new xAOD::AuxInfoBase();
    copy->setStore(copyAux);
    
    *copy = *orig;
    
    if (!outEvent.record(copy, name).isSuccess()) return EL::StatusCode::FAILURE;
    name += "Aux.";
    if (!outEvent.record(copyAux, name).isSuccess()) return EL::StatusCode::FAILURE;

    return EL::StatusCode::SUCCESS;
  }

} // namespace kurt

#endif // brendlingerHiggsTestbed_Utils_H
