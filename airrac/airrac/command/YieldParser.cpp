// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <string>
// StdAir
#include <stdair/basic/DictionaryManager.hpp>
// Airrac
#include <airrac/command/YieldParserHelper.hpp>
#include <airrac/command/YieldParser.hpp>

namespace AIRRAC {

  // //////////////////////////////////////////////////////////////////////
  void YieldParser::
  generateYieldStore (const stdair::Filename_T& iFilename,
                  stdair::BomRoot& ioBomRoot) {
    // Initialise the yield file parser.
    YieldFileParser lYieldParser (ioBomRoot, iFilename);

    // Parse the CSV-formatted yield store input file, and generate the
    // corresponding Yield-related objects.
    lYieldParser.generateYieldStore ();
  }

}
