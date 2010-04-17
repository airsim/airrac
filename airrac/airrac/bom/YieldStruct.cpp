// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
// StdAir
#include <stdair/basic/BasConst_General.hpp>
#include <stdair/service/Logger.hpp>
// AIRRAC
#include <airrac/AIRRAC_Types.hpp>
#include <airrac/bom/YieldStruct.hpp>

namespace AIRRAC {

  // //////////////////////////////////////////////////////////////////////
  YieldStruct_T::YieldStruct_T ()
    : _yield (stdair::DEFAULT_DATE), _itSeconds (0) {
  }

  // //////////////////////////////////////////////////////////////////////
  stdair::Date_T YieldStruct_T::getDate() const {
    return stdair::Date_T (_itYear + 2000, _itMonth, _itDay);
  }

  // //////////////////////////////////////////////////////////////////////
  stdair::Duration_T YieldStruct_T::getTime() const {
    return boost::posix_time::hours (_itHours)
      + boost::posix_time::minutes (_itMinutes)
      + boost::posix_time::seconds (_itSeconds);
  }
  
  // //////////////////////////////////////////////////////////////////////
  const std::string YieldStruct_T::describe() const {
    std::ostringstream ostr;
    ostr << _airlineCode << std::endl;
    return ostr.str();
  }

}
