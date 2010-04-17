#ifndef __AIRRAC_BOM_YIELDSTRUCT_HPP
#define __AIRRAC_BOM_YIELDSTRUCT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// StdAir
#include <stdair/STDAIR_Types.hpp>
#include <stdair/basic/StructAbstract.hpp>
#include <stdair/bom/DoWStruct.hpp>
// Airrac

namespace AIRRAC {

  /** Utility Structure for the parsing of Flight-Date structures. */
  struct YieldStruct_T : public stdair::StructAbstract {
    
    /** Set the date from the staging details. */
    stdair::Date_T getDate() const;

    /** Set the time from the staging details. */
    stdair::Duration_T getTime() const;
  
    /** Give a description of the structure (for display purposes). */
    const std::string describe() const;

    /** Constructor. */
    YieldStruct_T ();

    // Attributes
    stdair::AirlineCode_T _airlineCode;
    stdair::Date_T _yield;

    /** Staging Date. */
    unsigned int _itYear;
    unsigned int _itMonth;
    unsigned int _itDay;
    int _dateOffSet;
      
    /** Staging Time. */
    long _itHours;
    long _itMinutes;
    long _itSeconds;
  };

}
#endif // __AIRRAC_BOM_YIELDSTRUCT_HPP
