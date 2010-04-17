#ifndef __AIRRAC_CMD_YIELDMANAGER_HPP
#define __AIRRAC_CMD_YIELDMANAGER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STDAIR
#include <stdair/STDAIR_Types.hpp>

// Forward declarations
namespace stdair {
  class YieldStore;
  struct TravelSolutionStruct;
}

namespace AIRRAC {

  /** Command wrapping the travel request process. */
  class YieldManager {
    friend class AIRRAC_Service;
  private:

    /** Calculate/retrieve the yield for a given travel solution. */
    static void calculateYield (stdair::YieldStore&,
                                const stdair::TravelSolutionStruct&);

  private:
    /** Constructors. */
    YieldManager() {}
    YieldManager(const YieldManager&) {}
    /** Destructor. */
    ~YieldManager() {}
  };

}
#endif // __AIRRAC_CMD_YIELDMANAGER_HPP
