// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
// AIRRAC Common
#include <airrac/factory/FacSupervisor.hpp>
#include <airrac/factory/FacAirracServiceContext.hpp>
#include <airrac/service/AIRRAC_ServiceContext.hpp>

namespace AIRRAC {

  FacAirracServiceContext* FacAirracServiceContext::_instance = NULL;

  // //////////////////////////////////////////////////////////////////////
  FacAirracServiceContext::~FacAirracServiceContext () {
    _instance = NULL;
  }

  // //////////////////////////////////////////////////////////////////////
  FacAirracServiceContext& FacAirracServiceContext::instance () {

    if (_instance == NULL) {
      _instance = new FacAirracServiceContext();
      assert (_instance != NULL);
      
      FacSupervisor::instance().registerServiceFactory (_instance);
    }
    return *_instance;
  }

  // //////////////////////////////////////////////////////////////////////
  AIRRAC_ServiceContext& FacAirracServiceContext::
  create (const std::string& iTravelDatabaseName,
          stdair::Yield& ioYieldStore) {
    AIRRAC_ServiceContext* aAIRRAC_ServiceContext_ptr = NULL;

    aAIRRAC_ServiceContext_ptr =
      new AIRRAC_ServiceContext (iTravelDatabaseName, ioIventory);
    assert (aAIRRAC_ServiceContext_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aAIRRAC_ServiceContext_ptr);

    return *aAIRRAC_ServiceContext_ptr;
  }

}
