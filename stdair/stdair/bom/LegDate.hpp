#ifndef __STDAIR_BOM_LEGDATE_HPP
#define __STDAIR_BOM_LEGDATE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STDAIR 
#include <stdair/bom/LegDateContent.hpp>
#include <stdair/bom/LegDateTypes.hpp>
#include <stdair/bom/LegCabinTypes.hpp>
#include <stdair/bom/SegmentDateTypes.hpp>

namespace stdair {
  // Forward declarations
  class FlightDate;
  class LegCabin;
  class SegmentDate;

  /** Class representing the actual functional/business content for a
      leg-date. */
  class LegDate : public LegDateContent {
    friend class FacBomContent;

  public:
    // //////////////////////////////////////////////////////////////////
    // See the explanations, within the BomRoot class, for all
    // the types which require to be specified below
    // //////////////////////////////////////////////////////////////////
    /** Definition allowing to retrieve the associated BOM structure type. */
    typedef LegDateStructure_T Structure_T;
    
    /** Definition allowing to retrieve the associated parent
        BOM content type. */
    typedef FlightDate Parent_T;

    /** Define the list of children holder types. */
    typedef boost::fusion::map<
      boost::fusion::pair<LegCabin, LegCabinHolder_T*>,
      boost::fusion::pair<SegmentDate, SegmentDateHolder_T*>
      > ChildrenHolderMap_T;
    // //////////////////////////////////////////////////////////////////
    
  public:
    // /////////// Getters //////////// 
    /** Get a list or map of a children type for iteration methods. */
    LegCabinList_T getLegCabinList () const;
    LegCabinMap_T getLegCabinMap () const;
   
    /** Retrieve, if existing, the LegCabin corresponding to the
        given cabin code.
        <br>If not existing, return the NULL pointer. */
    LegCabin* getLegCabin (const CabinCode_T&) const;
    
  public:
    // /////////// Display support methods /////////
    /** Dump a Business Object into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a Business Object from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream& ioIn);

   /** Get the serialised version of the Business Object. */
    std::string toString() const;
    
    /** Get a string describing the whole key (differentiating two objects
        at any level). */
    const std::string describeKey() const;

  protected:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Constructors. */
    LegDate (const Key_T&, Structure_T&);
    /** Destructor. */
    ~LegDate();
    /** Default constructors. */
    LegDate ();
    LegDate (const LegDate&);

  protected:
    // Attributes
    /** Reference structure. */
    Structure_T& _structure;
  };

}
#endif // __STDAIR_BOM_LEGDATE_HPP

