## test/airrac sub-directory
include $(top_srcdir)/Makefile.common

MAINTAINERCLEANFILES = Makefile.in

##
SUBDIRS =

EXTRA_DIST =

##
check_PROGRAMS = YieldTestSuite
TESTS = $(check_PROGRAMS)
XFAIL_TESTS = #

YieldTestSuite_SOURCES = YieldTestSuite.hpp YieldTestSuite.cpp
YieldTestSuite_CXXFLAGS= $(CPPUNIT_CFLAGS) $(BOOST_CFLAGS)
YieldTestSuite_LDADD =
YieldTestSuite_LDFLAGS = \
		$(BOOST_LIBS) $(CPPUNIT_LIBS) \
		$(top_builddir)/extracppunit/libextracc-extracppunit.la \
		$(top_builddir)/stdair/core/libstdair.la \
		$(top_builddir)/airrac/core/libairrac.la
