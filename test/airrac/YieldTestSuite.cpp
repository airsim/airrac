/*!
 * \page YieldTestSuite_cpp Command-Line Test to Demonstrate How To Test the AirRAC Project
 * \code
 */
// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <sstream>
#include <fstream>
#include <string>
// Boost Unit Test Framework (UTF)
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE YieldTestSuite
#include <boost/test/unit_test.hpp>
// StdAir
#include <stdair/basic/BasLogParams.hpp>
#include <stdair/basic/BasDBParams.hpp>
#include <stdair/basic/BasFileMgr.hpp>
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/service/Logger.hpp>
// Airrac
#include <airrac/AIRRAC_Service.hpp>
#include <airrac/config/airrac-paths.hpp>

namespace boost_utf = boost::unit_test;

// (Boost) Unit Test XML Report
std::ofstream utfReportStream ("YieldTestSuite_utfresults.xml");

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    boost_utf::unit_test_log.set_stream (utfReportStream);
    boost_utf::unit_test_log.set_format (boost_utf::XML);
    boost_utf::unit_test_log.set_threshold_level (boost_utf::log_test_units);
    //boost_utf::unit_test_log.set_threshold_level (boost_utf::log_successful_tests);
  }

  /** Destructor. */
  ~UnitTestConfig() {
  }
};

// //////////////////////////////////////////////////////////////////////

/**
 * Build and search yields for a default list of travel solutions
 */
void testYieldQuoterHelper (const unsigned short iTestFlag,
                            const stdair::Filename_T iYieldInputFilename,
                            const bool isBuiltin) {

  // Output log File
  std::ostringstream oStr;
  oStr << "FQTTestSuite_" << iTestFlag << ".log";
  const stdair::Filename_T lLogFilename (oStr.str());

  // Set the log parameters
  std::ofstream logOutputFile;
  // Open and clean the log outputfile
  logOutputFile.open (lLogFilename.c_str());
  logOutputFile.clear();
    
  // Initialise the AirRAC service object
  const stdair::BasLogParams lLogParams (stdair::LOG::DEBUG,
                                         logOutputFile);
  
  // Initialise the AirRAC service object
  AIRRAC::AIRRAC_Service airracService (lLogParams);
  
  // Build a sample list of travel solutions
  stdair::TravelSolutionList_T lTravelSolutionList;
  airracService.buildSampleTravelSolutions (lTravelSolutionList);

  // Check whether or not a (CSV) input file should be read
  if (isBuiltin == true) {

    // Build the default sample BOM tree (filled with yields) for AirRAC
    airracService.buildSampleBom();

  } else {

    // Build the BOM tree from parsing the yield input file    
    AIRRAC::YieldFilePath lYieldFilePath (iYieldInputFilename);
    airracService.parseAndLoad (lYieldFilePath);
  }

  // Calculate the yields for the given travel solution
  airracService.calculateYields (lTravelSolutionList);

  // Close the log file
  logOutputFile.close();

}


// /////////////// Main: Unit Test Suite //////////////

// Set the UTF configuration (re-direct the output to a specific file)
BOOST_GLOBAL_FIXTURE (UnitTestConfig);

// Start the test suite
BOOST_AUTO_TEST_SUITE (master_test_suite)

/**
 * Test a simple yield search with an input file.
 */
BOOST_AUTO_TEST_CASE (airrac_simple_yield) {

  // Input file name
  const stdair::Filename_T lYieldInputFilename (STDAIR_SAMPLE_DIR "/yieldstore01.csv");

  // State whether the BOM tree should be built-in or parsed from an input file
  const bool isBuiltin = false;

  // Try to yieldQuote the sample default list of travel solutions
  BOOST_CHECK_NO_THROW (testYieldQuoterHelper (0, lYieldInputFilename, isBuiltin));
  
}

/**
 * Test an error detection functionality
 * Expected to throw AIRRAC::FareFileParsingFailedException
 */
BOOST_AUTO_TEST_CASE (airrac_error_parsing_input_file) {

  // Input file name
  const stdair::Filename_T lYieldInputFilename (STDAIR_SAMPLE_DIR "/yieldstoreError01.csv");

  // State whether the BOM tree should be built-in or parsed from an input file
  const bool isBuiltin = false;
    
  // Try to yield quote the sample default list of travel solutions
  BOOST_CHECK_THROW (testYieldQuoterHelper (1, lYieldInputFilename, isBuiltin),
                     AIRRAC::YieldFileParsingFailedException);
}

/**
 * Test an error detection functionality
 * Expected to throw AIRRAC::YieldInputFileNotFoundException
 */
BOOST_AUTO_TEST_CASE (airrac_error_missing_input_file) {

  // Input file name
  const stdair::Filename_T lYieldInputFilename (STDAIR_SAMPLE_DIR "/missingFile.csv");

  // State whether the BOM tree should be built-in or parsed from an input file
  const bool isBuiltin = false;
    
  // Try to yield quote the sample default list of travel solutions
  BOOST_CHECK_THROW (testYieldQuoterHelper (2, lYieldInputFilename, isBuiltin),
                     AIRRAC::YieldInputFileNotFoundException);
}

/**
 * Test a simple yield search with a default BOM tree.
 */
BOOST_AUTO_TEST_CASE (airrac_simple_yield_built_in) {

  // State whether the BOM tree should be built-in or parsed from an input file
  const bool isBuiltin = true;

  // Try to yield quote the sample default list of travel solutions
  BOOST_CHECK_NO_THROW (testYieldQuoterHelper (3, " ", isBuiltin));
  
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()

/*!
 * \endcode
 */

