#ifndef __AIRRAC_AIRRAC_TYPES_HPP
#define __AIRRAC_AIRRAC_TYPES_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <vector>
#include <string>
// Boost
#include <boost/shared_ptr.hpp>
// StdAir
#include <stdair/stdair_exceptions.hpp>
#include <stdair/stdair_file.hpp>

namespace AIRRAC {

  // ///////// Exceptions ///////////
  class AirportPairNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    AirportPairNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };

  class PosOrChannelNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    PosOrChannelNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };

  class FlightDateNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    FlightDateNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };

  class FlightTimeNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    FlightTimeNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };

  class FeaturesNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    FeaturesNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };
  
  class AirlineNotFoundException : public stdair::ObjectNotFoundException {
  public:
    /** Constructor. */
    AirlineNotFoundException (const std::string& iWhat)
      : stdair::ObjectNotFoundException (iWhat) {}
  };

  class YieldInputFileNotFoundException : public stdair::FileNotFoundException {
  public:
    /** Constructor. */
    YieldInputFileNotFoundException (const std::string& iWhat)
      : stdair::FileNotFoundException (iWhat) {}
  };

  class YieldFileParsingFailedException : public stdair::ParsingFileFailedException {
  public:
    /** Constructor. */
    YieldFileParsingFailedException (const std::string& iWhat)
      : stdair::ParsingFileFailedException (iWhat) {}
  };

  class QuotingException : public stdair::RootException {
  };	

  // ///////// Files ///////////
  /**
   * Yield input file.
   */
  class YieldFilePath : public stdair::InputFilePath {
  public:
    /**
     * Constructor.
     */
    explicit YieldFilePath (const stdair::Filename_T& iFilename)
      : stdair::InputFilePath (iFilename) {}
  };

  // //////// Type definitions specific to AirRAC /////////
  /**
   * Pointer on the AIRRAC Service handler.
   */
  class AIRRAC_Service;
  typedef boost::shared_ptr<AIRRAC_Service> AIRRAC_ServicePtr_T;


  /**
   * ID for the Yield Quote system.
   */
  typedef unsigned int YieldID_T;
}
#endif // __AIRRAC_AIRRAC_TYPES_HPP

