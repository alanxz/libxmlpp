ACLOCAL_AMFLAGS = -I macros ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

library_configdir = $(libdir)/libxml++-@LIBXMLXX_API_VERSION@/include
library_config_DATA = libxml++config.h

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = libxml++-@LIBXMLXX_API_VERSION@.pc

lib_LTLIBRARIES = libxml++/libxml++-@LIBXMLXX_API_VERSION@.la
libxml___libxml___@LIBXMLXX_API_VERSION@_la_LDFLAGS = \
	-version-info $(LIBXMLXX_SO_VERSION) -no-undefined
libxml___libxml___@LIBXMLXX_API_VERSION@_la_LIBADD = $(LIBXMLXX_LIBS)
libxml___libxml___@LIBXMLXX_API_VERSION@_la_SOURCES = $(cc_sources) $(h_sources_public)

if ENABLE_EXAMPLES
noinst_PROGRAMS = examples/dom_build/dom_build \
	examples/dom_parse_entities/dom_parse_entities \
	examples/dom_parser/dom_parser \
	examples/dom_parser_raw/dom_parser_raw \
	examples/dom_read_write/dom_read_write \
	examples/dom_xpath/dom_xpath \
	examples/dtdvalidation/dtdvalidation \
	examples/import_node/import_node \
	examples/sax_exception/sax_exception \
	examples/sax_parser/sax_parser \
	examples/sax_parser_build_dom/sax_parser_build_dom \
	examples/sax_parser_entities/sax_parser_entities \
	examples/schemavalidation/schemavalidation \
	examples/textreader/textreader
endif

AM_CPPFLAGS = -I$(top_builddir) -I$(top_srcdir) -I. $(LIBXMLXX_CFLAGS)
AM_CXXFLAGS = $(LIBXMLXX_WXXFLAGS)
DEFS = @DEFS@ -DLIBXMLPP_BUILD

h_root_sources_public = libxml++/libxml++.h \
	libxml++/attribute.h \
	libxml++/document.h \
	libxml++/dtd.h \
	libxml++/keepblanks.h \
	libxml++/noncopyable.h \
	libxml++/schema.h
h_exceptions_sources_public = libxml++/exceptions/exception.h \
	libxml++/exceptions/parse_error.h \
	libxml++/exceptions/validity_error.h \
	libxml++/exceptions/internal_error.h
h_io_sources_public = libxml++/io/istreamparserinputbuffer.h \
	libxml++/io/outputbuffer.h \
	libxml++/io/ostreamoutputbuffer.h \
	libxml++/io/parserinputbuffer.h
h_nodes_sources_public = libxml++/nodes/cdatanode.h \
	libxml++/nodes/commentnode.h \
	libxml++/nodes/contentnode.h \
	libxml++/nodes/element.h \
	libxml++/nodes/entityreference.h \
	libxml++/nodes/node.h \
	libxml++/nodes/processinginstructionnode.h \
	libxml++/nodes/textnode.h
h_parsers_sources_public = libxml++/parsers/parser.h \
	libxml++/parsers/saxparser.h \
	libxml++/parsers/domparser.h \
	libxml++/parsers/textreader.h
h_validators_sources_public = libxml++/validators/dtdvalidator.h \
	libxml++/validators/schemavalidator.h \
	libxml++/validators/validator.h
h_sources_public = $(h_root_sources_public) \
	$(h_exceptions_sources_public) \
	$(h_io_sources_public) \
	$(h_nodes_sources_public) \
	$(h_parsers_sources_public) \
	$(h_validators_sources_public)

cc_sources = libxml++/attribute.cc \
	libxml++/document.cc \
	libxml++/dtd.cc \
	libxml++/keepblanks.cc \
	libxml++/noncopyable.cc \
	libxml++/schema.cc \
	libxml++/exceptions/exception.cc \
	libxml++/exceptions/parse_error.cc \
	libxml++/exceptions/validity_error.cc \
	libxml++/exceptions/internal_error.cc \
	libxml++/io/istreamparserinputbuffer.cc \
	libxml++/io/outputbuffer.cc \
	libxml++/io/ostreamoutputbuffer.cc \
	libxml++/io/parserinputbuffer.cc \
	libxml++/nodes/cdatanode.cc \
	libxml++/nodes/commentnode.cc \
	libxml++/nodes/contentnode.cc \
	libxml++/nodes/entityreference.cc \
	libxml++/nodes/element.cc \
	libxml++/nodes/node.cc \
	libxml++/nodes/processinginstructionnode.cc \
	libxml++/nodes/textnode.cc \
	libxml++/parsers/parser.cc \
	libxml++/parsers/saxparser.cc \
	libxml++/parsers/domparser.cc \
	libxml++/parsers/textreader.cc \
	libxml++/validators/dtdvalidator.cc \
	libxml++/validators/schemavalidator.cc \
	libxml++/validators/validator.cc

library_includedir = $(includedir)/libxml++-$(LIBXMLXX_API_VERSION)/libxml++
library_exceptions_includedir = $(library_includedir)/exceptions
library_io_includedir = $(library_includedir)/io
library_nodes_includedir = $(library_includedir)/nodes
library_parsers_includedir = $(library_includedir)/parsers
library_validators_includedir = $(library_includedir)/validators

library_include_HEADERS = $(h_root_sources_public)
library_exceptions_include_HEADERS = $(h_exceptions_sources_public)
library_io_include_HEADERS = $(h_io_sources_public)
library_nodes_include_HEADERS = $(h_nodes_sources_public)
library_parsers_include_HEADERS = $(h_parsers_sources_public)
library_validators_include_HEADERS = $(h_validators_sources_public)

if ENABLE_EXAMPLES

examples_dom_build_dom_build_SOURCES = examples/dom_build/main.cc
examples_dom_parse_entities_dom_parse_entities_SOURCES = \
	examples/dom_parse_entities/main.cc
examples_dom_parser_dom_parser_SOURCES = examples/dom_parser/main.cc
examples_dom_parser_raw_dom_parser_raw_SOURCES = examples/dom_parser_raw/main.cc
examples_dom_read_write_dom_read_write_SOURCES = examples/dom_read_write/main.cc
examples_dom_xpath_dom_xpath_SOURCES = examples/dom_xpath/main.cc
examples_dtdvalidation_dtdvalidation_SOURCES = examples/dtdvalidation/main.cc
examples_import_node_import_node_SOURCES = examples/import_node/main.cc
examples_sax_exception_sax_exception_SOURCES = examples/sax_exception/main.cc \
	examples/sax_exception/myparser.cc \
	examples/sax_exception/myparser.h
examples_sax_parser_sax_parser_SOURCES = examples/sax_parser/main.cc \
	examples/sax_parser/myparser.cc \
	examples/sax_parser/myparser.h
examples_sax_parser_build_dom_sax_parser_build_dom_SOURCES = \
	examples/sax_parser_build_dom/main.cc \
	examples/sax_parser_build_dom/svgparser.cc \
	examples/sax_parser_build_dom/svgparser.h \
	examples/sax_parser_build_dom/svgdocument.cc \
	examples/sax_parser_build_dom/svgdocument.h \
	examples/sax_parser_build_dom/svgelement.cc \
	examples/sax_parser_build_dom/svgelement.h \
	examples/sax_parser_build_dom/svgpath.h \
	examples/sax_parser_build_dom/svggroup.h
examples_sax_parser_entities_sax_parser_entities_SOURCES = \
	examples/sax_parser_entities/main.cc \
	examples/sax_parser_entities/myparser.cc \
	examples/sax_parser_entities/myparser.h
examples_schemavalidation_schemavalidation_SOURCES = \
	examples/schemavalidation/main.cc
examples_textreader_textreader_SOURCES = examples/textreader/main.cc

examples_ldadd = libxml++/libxml++-$(LIBXMLXX_API_VERSION).la $(LIBXMLXX_LIBS)

examples_dom_build_dom_build_LDADD = \
	$(examples_ldadd)
examples_dom_parse_entities_dom_parse_entities_LDADD = \
	$(examples_ldadd)
examples_dom_parser_dom_parser_LDADD = \
	$(examples_ldadd)
examples_dom_parser_raw_dom_parser_raw_LDADD = \
	$(examples_ldadd)
examples_dom_read_write_dom_read_write_LDADD = \
	$(examples_ldadd)
examples_dom_xpath_dom_xpath_LDADD = \
	$(examples_ldadd)
examples_dtdvalidation_dtdvalidation_LDADD = \
	$(examples_ldadd)
examples_import_node_import_node_LDADD = \
	$(examples_ldadd)
examples_sax_exception_sax_exception_LDADD = \
	$(examples_ldadd)
examples_sax_parser_sax_parser_LDADD = \
	$(examples_ldadd)
examples_sax_parser_build_dom_sax_parser_build_dom_LDADD = \
	$(examples_ldadd)
examples_sax_parser_entities_sax_parser_entities_LDADD = \
	$(examples_ldadd)
examples_schemavalidation_schemavalidation_LDADD = \
	$(examples_ldadd)
examples_textreader_textreader_LDADD = \
	$(examples_ldadd)
endif # ENABLE_EXAMPLES

docs/manual/libxml++.xml: docs/manual/libxml++_without_code.xml docs/manual/insert_example_code.pl
	$(AM_V_GEN)$(PERL) -- docs/manual/insert_example_code.pl examples $< >$@

if ENABLE_DOCUMENTATION
book_name = $(LIBXMLXX_MODULE_NAME)
doc_input = $(h_sources_public)
doc_outdir = docs/reference
# Sets dist_noinst_DATA, DISTCLEANFILES and MAINTAINERCLEANFILES
include $(top_srcdir)/macros/doc-reference.am

manualdir = $(docdir)/manual
manual_htmldir = $(manualdir)/html
manual_html_files = $(wildcard docs/manual/html/*.html)

docs/manual/html/index.html: docs/manual/libxml++.xml docs/manual/docbook-customisation.xsl
	$(AM_V_at)rm -fr doc/manual/html
	$(AM_V_at)$(MKDIR_P) docs/manual/html
	$(AM_V_GEN)$(XSLTPROC) -o docs/manual/html/ --xinclude --catalogs \
		$(top_srcdir)/docs/manual/docbook-customisation.xsl $<

docs/manual/libxml++.pdf: docs/manual/libxml++.xml
	$(AM_V_GEN)$(DB2LATEX) -o $@ -O docs/manual -tpdf $<

validate_original_manual: docs/manual/libxml++_without_code.xml
	$(XMLLINT) --xinclude --postvalid --noout $<

validate_manual: docs/manual/libxml++.xml
	$(XMLLINT) --xinclude --postvalid --noout $<

all-local: docs/manual/html/index.html
else # !ENABLE_DOCUMENTATION
dist_noinst_DATA =
DISTCLEANFILES =
MAINTAINERCLEANFILES =
endif # ENABLE_DOCUMENTATION

dist_noinst_DATA += libxml++config.h.in \
	libxml++-$(LIBXMLXX_API_VERSION).pc.in \
	MAINTAINERS \
	docs/manual/docbook-customisation.xsl \
	$(manual_html_files) \
	docs/manual/libxml++.xml \
	docs/manual/libxml++_without_code.xml \
	examples/README \
	examples/dom_parser/example.xml \
	examples/dom_parser/example_with_namespace.xml \
	examples/dom_parser/example_invalid.xml \
	examples/dom_parser/example.dtd \
	examples/dom_parser_raw/example.xml \
	examples/dom_parser_raw/example.dtd \
	examples/dom_parse_entities/example.xml \
	examples/dom_parse_entities/example.dtd \
	examples/dom_read_write/README \
	examples/dom_read_write/example.xml \
	examples/dom_read_write/example.dtd \
	examples/dom_xpath/example.xml \
	examples/dtdvalidation/example.dtd \
	examples/import_node/example1.xml \
	examples/import_node/example2.xml \
	examples/sax_parser/example.xml \
	examples/sax_parser_entities/example.xml \
	examples/sax_exception/example.xml \
	examples/sax_parser_build_dom/README \
	examples/sax_parser_build_dom/example.xml \
	examples/schemavalidation/example.xml \
	examples/schemavalidation/example.xsd \
	examples/textreader/example.xml \
	MSVC_Net2005/blank.cpp \
	MSVC_Net2005/libxml++.sln \
	MSVC_Net2005/README \
	MSVC_Net2005/gendef/gendef.cc \
	MSVC_Net2005/gendef/gendef.vcproj \
	MSVC_Net2005/libxml++/libxml++.rc \
	MSVC_Net2005/libxml++/libxml++.vcproj \
	MSVC_Net2005/libxml++/libxml++config.h \
	MSVC_Net2005/examples/dom_build/dom_build.vcproj \
	MSVC_Net2005/examples/dom_parse_entities/dom_parse_entities.vcproj \
	MSVC_Net2005/examples/dom_parser/dom_parser.vcproj \
	MSVC_Net2005/examples/dom_parser_raw/dom_parser_raw.vcproj \
	MSVC_Net2005/examples/dom_read_write/dom_read_write.vcproj \
	MSVC_Net2005/examples/dom_xpath/dom_xpath.vcproj \
	MSVC_Net2005/examples/dtdvalidation/dtdvalidation.vcproj \
	MSVC_Net2005/examples/import_node/import_node.vcproj \
	MSVC_Net2005/examples/sax_exception/sax_exception.vcproj \
	MSVC_Net2005/examples/sax_parser/sax_parser.vcproj \
	MSVC_Net2005/examples/sax_parser_build_dom/sax_parser_build_dom.vcproj \
	MSVC_Net2005/examples/sax_parser_entities/sax_parser_entities.vcproj \
	MSVC_Net2005/examples/schemavalidation/schemavalidation.vcproj \
	MSVC_Net2005/examples/textreader/textreader.vcproj \
	MSVC_Net2008/blank.cpp \
	MSVC_Net2008/libxml++.sln \
	MSVC_Net2008/README \
	MSVC_Net2008/gendef/gendef.cc \
	MSVC_Net2008/gendef/gendef.vcproj \
	MSVC_Net2008/libxml++/libxml++.rc \
	MSVC_Net2008/libxml++/libxml++.vcproj \
	MSVC_Net2008/libxml++/libxml++config.h \
	MSVC_Net2008/examples/dom_build/dom_build.vcproj \
	MSVC_Net2008/examples/dom_parse_entities/dom_parse_entities.vcproj \
	MSVC_Net2008/examples/dom_parser/dom_parser.vcproj \
	MSVC_Net2008/examples/dom_parser_raw/dom_parser_raw.vcproj \
	MSVC_Net2008/examples/dom_read_write/dom_read_write.vcproj \
	MSVC_Net2008/examples/dom_xpath/dom_xpath.vcproj \
	MSVC_Net2008/examples/dtdvalidation/dtdvalidation.vcproj \
	MSVC_Net2008/examples/import_node/import_node.vcproj \
	MSVC_Net2008/examples/sax_exception/sax_exception.vcproj \
	MSVC_Net2008/examples/sax_parser/sax_parser.vcproj \
	MSVC_Net2008/examples/sax_parser_build_dom/sax_parser_build_dom.vcproj \
	MSVC_Net2008/examples/sax_parser_entities/sax_parser_entities.vcproj \
	MSVC_Net2008/examples/schemavalidation/schemavalidation.vcproj \
	MSVC_Net2008/examples/textreader/textreader.vcproj \
	MSVC_Net2010/libxml++.sln \
	MSVC_Net2010/README \
	MSVC_Net2010/gendef/gendef.cc \
	MSVC_Net2010/gendef/gendef.vcxproj \
	MSVC_Net2010/gendef/gendef.vcxproj.filters \
	MSVC_Net2010/libxml++/libxml++.rc \
	MSVC_Net2010/libxml++/libxml++.vcxproj \
	MSVC_Net2010/libxml++/libxml++.vcxproj.filters \
	MSVC_Net2010/libxml++/libxml++config.h \
	MSVC_Net2010/examples/dom_build/dom_build.vcxproj \
	MSVC_Net2010/examples/dom_build/dom_build.vcxproj.filters \
	MSVC_Net2010/examples/dom_parse_entities/dom_parse_entities.vcxproj \
	MSVC_Net2010/examples/dom_parse_entities/dom_parse_entities.vcxproj.filters \
	MSVC_Net2010/examples/dom_parser/dom_parser.vcxproj \
	MSVC_Net2010/examples/dom_parser/dom_parser.vcxproj.filters \
	MSVC_Net2010/examples/dom_parser_raw/dom_parser_raw.vcxproj \
	MSVC_Net2010/examples/dom_parser_raw/dom_parser_raw.vcxproj.filters \
	MSVC_Net2010/examples/dom_read_write/dom_read_write.vcxproj \
	MSVC_Net2010/examples/dom_read_write/dom_read_write.vcxproj.filters \
	MSVC_Net2010/examples/dom_xpath/dom_xpath.vcxproj \
	MSVC_Net2010/examples/dom_xpath/dom_xpath.vcxproj.filters \
	MSVC_Net2010/examples/dtdvalidation/dtdvalidation.vcxproj \
	MSVC_Net2010/examples/dtdvalidation/dtdvalidation.vcxproj.filters \
	MSVC_Net2010/examples/import_node/import_node.vcxproj \
	MSVC_Net2010/examples/import_node/import_node.vcxproj.filters \
	MSVC_Net2010/examples/sax_exception/sax_exception.vcxproj \
	MSVC_Net2010/examples/sax_exception/sax_exception.vcxproj.filters \
	MSVC_Net2010/examples/sax_parser/sax_parser.vcxproj \
	MSVC_Net2010/examples/sax_parser/sax_parser.vcxproj.filters \
	MSVC_Net2010/examples/sax_parser_build_dom/sax_parser_build_dom.vcxproj \
	MSVC_Net2010/examples/sax_parser_build_dom/sax_parser_build_dom.vcxproj.filters \
	MSVC_Net2010/examples/sax_parser_entities/sax_parser_entities.vcxproj \
	MSVC_Net2010/examples/sax_parser_entities/sax_parser_entities.vcxproj.filters \
	MSVC_Net2010/examples/schemavalidation/schemavalidation.vcxproj \
	MSVC_Net2010/examples/schemavalidation/schemavalidation.vcxproj.filters \
	MSVC_Net2010/examples/textreader/textreader.vcxproj \
	MSVC_Net2010/examples/textreader/textreader.vcxproj.filters

dist_noinst_SCRIPTS = autogen.sh \
	docs/manual/insert_example_code.pl

DISTCLEANFILES += MSVC_Net2005/libxml++/libxml++config.h \
	MSVC_Net2008/libxml++/libxml++config.h \
	MSVC_Net2010/libxml++/libxml++config.h

MAINTAINERCLEANFILES += docs/manual/html/*.html

# Make it easy to upload to the sourceforge web site.
# The manual and API reference are hosted on library.gnome.org via tarball releases.
web_path_project = /home/groups/l/li/libxmlplusplus/htdocs/
rsync_args = -vz --rsh ssh --recursive --cvs-exclude --exclude="**1.0**" --exclude=".cvsignore" --exclude="Makefile" --exclude="Makefile.in" --exclude=".deps" --exclude=".libs"

post-html: docs/index.html
	rsync $(rsync_args) -r docs/index.html $$USER,libxmlplusplus@web.sourceforge.net:$(web_path_project)
	rsync $(rsync_args) -r examples $$USER,libxmlplusplus@web.sourceforge.net:$(web_path_project)

