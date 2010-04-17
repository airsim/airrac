# core
include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

## Source directory

MAINTAINERCLEANFILES = Makefile.in

SUBDIRS =


# Library
lib_LTLIBRARIES = libairrac.la

libairrac_la_SOURCES = $(service_h_sources) $(service_cc_sources)
libairrac_la_LIBADD = \
	$(top_builddir)/airrac/basic/libbas.la \
	$(top_builddir)/airrac/bom/libbom.la \
	$(top_builddir)/airrac/factory/libfac.la \
	$(top_builddir)/airrac/command/libcmd.la \
	$(top_builddir)/airrac/service/libsvc.la
libairrac_la_LDFLAGS = \
	$(BOOST_DATE_TIME_LIB) $(BOOST_PROGRAM_OPTIONS_LIB) \
	$(top_builddir)/stdair/core/libstdair.la \
	-version-info $(GENERIC_LIBRARY_VERSION)
