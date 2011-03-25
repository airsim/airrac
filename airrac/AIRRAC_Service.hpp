#ifndef __AIRRAC_SVC_AIRRAC_SERVICE_HPP
#define __AIRRAC_SVC_AIRRAC_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// StdAir
#include <stdair/stdair_basic_types.hpp>
#include <stdair/stdair_service_types.hpp>
#include <stdair/bom/TravelSolutionTypes.hpp>
// AirRAC
#include <airrac/AIRRAC_Types.hpp>

// Forward declarations.
namespace stdair {
  struct BasLogParams;
  struct BasDBParams;
}

namespace AIRRAC {

  /// Forward declaration
  class AIRRAC_ServiceContext;

  /**
   * @brief Interface for the AIRRAC Services.
   */
  class AIRRAC_Service {  
  public:
    // ////////////////// Constructors and Destructors //////////////////

    /**
     * Constructor.
     *
     * The initAirracService() method is called; see the corresponding
     * documentation for more details.
     *
     * A reference on an output stream is given, so that log outputs
     * can be directed onto that stream.
     *
     * @param const stdair::BasLogParams& Parameters for the output log stream.
     */
    AIRRAC_Service (const stdair::BasLogParams&);
    
    /** Constructor.
        <br>The init() method is called; see the corresponding documentation
        for more details.
        <br>A reference on an output stream is given, so that log
        outputs can be directed onto that stream.
        <br>Moreover, database connection parameters are given, so that a
        session can be created on the corresponding database.
        @param const stdair::BasLogParams& Parameters for the output log stream.
        @param const stdair::BasDBParams& Parameters for the database access.
        @param const stdair::Filename_T& Filename of the input yield file. */
    AIRRAC_Service (const stdair::BasLogParams&, const stdair::BasDBParams&,
                    const stdair::Filename_T& iYieldInputFilename);

    /** Constructor.
        <br>The init() method is called; see the corresponding documentation
        for more details.
        <br>Moreover, a reference on an output stream is given, so
        that log outputs can be directed onto that stream.       
        @param const stdair::BasLogParams& Parameters for the output log stream.
        @param const stdair::Date_T& Date for the beginning of analysis.
        @param const stdair::Filename_T& Filename of the input yield file. */
    AIRRAC_Service (const stdair::BasLogParams&,
                    const stdair::Filename_T& iYieldInputFilename);

    /** Constructor.
        <br>The init() method is called; see the corresponding documentation
        for more details.
        <br>Moreover, as no reference on any output stream is given,
        it is assumed that the StdAir log service has already been
        initialised with the proper log output stream by some other
        methods in the calling chain (for instance, when the AIRRAC_Service
        is itself being initialised by another library service such as
        SIMCRS_Service).
        @param stdair::STDAIR_ServicePtr_T Reference on the STDAIR service.
        @param const stdair::Filename_T& Filename of the input yield file. */
    AIRRAC_Service (stdair::STDAIR_ServicePtr_T ioSTDAIR_ServicePtr,
                    const stdair::Filename_T& iYieldInputFilename);

    /** Destructor. */
    ~AIRRAC_Service();

  public:
    // /////////// Business Methods /////////////
    /**
     * Calculate/retrieve a yield.
     */
    void calculateYields (stdair::TravelSolutionList_T&);

    void buildSampleBom ();

  public:
    // //////////////// Display support methods /////////////////
    /**
     * Recursively display (dump in the returned string) the objects
     * of the BOM tree.
     *
     * @return std::string Output string in which the BOM tree is
     *        logged/dumped.
     */
    std::string csvDisplay() const;

  private:
    // /////// Construction and Destruction helper methods ///////
    /**
     * Default constructor.
     */
    AIRRAC_Service ();
    /**
     * Copy constructor.
     */
    AIRRAC_Service (const AIRRAC_Service&);

    /**
     * Initialise the (AIRRAC) service context (i.e., the
     * AIRRAC_ServiceContext object).
     */
    void initServiceContext ();

    /**
     * Initialise the STDAIR service (including the log service).
     *
     * A reference on the root of the BOM tree, namely the BomRoot object,
     * is stored within the service context for later use.
     *
     * @param const stdair::BasLogParams& Parameters for the output log stream.
     * @param const stdair::BasDBParams& Parameters for the database access.
     */
    stdair::STDAIR_ServicePtr_T initStdAirService (const stdair::BasLogParams&,
                                                   const stdair::BasDBParams&);
    
    /**
     * Initialise the STDAIR service (including the log service).
     *
     * A reference on the root of the BOM tree, namely the BomRoot object,
     * is stored within the service context for later use.
     *
     * @param const stdair::BasLogParams& Parameters for the output log stream.
     */
    stdair::STDAIR_ServicePtr_T initStdAirService (const stdair::BasLogParams&);

    /**
     * Attach the STDAIR service (holding the log and database services) to
     * the AIRRAC_Service.
     *
     * @param stdair::STDAIR_ServicePtr_T Reference on the STDAIR service.
     */
    void addStdAirService (stdair::STDAIR_ServicePtr_T);
    
    /**
     * Initialise.
     *
     * Nothing is being done at that stage. The buildSampleBom() method may
     * be called later.
     */
    void initAirracService();

    /**
     * Initialise.
     *
     * <ol>
     *  <li>Firstly, the buildSampleBom() method is called, for AIRRAC and with
     *      the given cabin capacity, in order to build a sample BOM
     *      tree.
     *  </li>
     *  <li>Secondly, the filename of a CSV file is given as parameter.
     *      That file describes the problem to be optimised, i.e.:
     *      <ul>
     *        <li>the demand specifications for all the booking classes
     *            (mean and standard deviations for the demand distribution);
     *        </li>the yields corresponding to those booking classes.
     *      </ul>
     *      That CSV file is parsed and instantiated in memory accordingly.
     *      The capacity is that given above.
     *  </li>
     * </ol>
     *
     * @param const stdair::Filename_T& Filename of the input demand file.
     */
    void initAirracService (const stdair::Filename_T& iYieldInputFilename);

    /**
     * Finalise.
     */
    void finalise ();
    
  private:
    // ///////// Service Context /////////
    /** AirRAC context. */
    AIRRAC_ServiceContext* _airracServiceContext;
  };
}
#endif // __AIRRAC_SVC_AIRRAC_SERVICE_HPP
