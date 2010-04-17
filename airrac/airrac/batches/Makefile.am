# airrac/batches
include $(top_srcdir)/Makefile.common

## Source directory

MAINTAINERCLEANFILES = Makefile.in


# Binaries (batches)
bin_PROGRAMS = airrac

#
airrac_SOURCES = airrac.cpp
airrac_CXXFLAGS = $(BOOST_CFLAGS)
airrac_LDADD =
airrac_LDFLAGS = $(BOOST_PROGRAM_OPTIONS_LIB) \
	$(top_builddir)/stdair/core/libstdair.la \
	$(top_builddir)/airrac/core/libairrac.la
