// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
// Airrac
#include <airrac/basic/BasConst_AIRRAC_Service.hpp>
#include <airrac/service/AIRRAC_ServiceContext.hpp>

namespace AIRRAC {
  
  // //////////////////////////////////////////////////////////////////////
  AIRRAC_ServiceContext::AIRRAC_ServiceContext() : _ownStdairService (false) {
  }

  // //////////////////////////////////////////////////////////////////////
  AIRRAC_ServiceContext::AIRRAC_ServiceContext (const AIRRAC_ServiceContext&)
    : _ownStdairService (false) {
    assert (false);
  }

  // //////////////////////////////////////////////////////////////////////
  AIRRAC_ServiceContext::~AIRRAC_ServiceContext() {
  }
  
  // //////////////////////////////////////////////////////////////////////
  const std::string AIRRAC_ServiceContext::shortDisplay() const {
    std::ostringstream oStr;
    oStr << "AIRRAC_ServiceContext -- Owns StdAir service: "
         << _ownStdairService;
    return oStr.str();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string AIRRAC_ServiceContext::display() const {
    std::ostringstream oStr;
    oStr << shortDisplay();
    return oStr.str();
  }
  // //////////////////////////////////////////////////////////////////////
  const std::string AIRRAC_ServiceContext::describe() const {
    return shortDisplay();
  }

  // //////////////////////////////////////////////////////////////////////
  void AIRRAC_ServiceContext::reset() {
    
    // The shared_ptr<>::reset() method drops the refcount by one.
    // If the count result is dropping to zero, the resource pointed to
    // by the shared_ptr<> will be freed.
    
    // Reset the stdair shared pointer
    _stdairService.reset();
  }

}
