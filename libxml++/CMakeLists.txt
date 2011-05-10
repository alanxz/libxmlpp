SET(libxmlpp_SRC
	libxml++.h
	string.h
	attribute.h
	attribute.cc
	schema.h
	schema.cc
	document.h
	document.cc
	keepblanks.h
	keepblanks.cc
	dtd.h
	dtd.cc
	noncopyable.h
	noncopyable.cc
	io/outputbuffer.h
	io/istreamparserinputbuffer.h
	io/ostreamoutputbuffer.h
	io/parserinputbuffer.cc
	io/istreamparserinputbuffer.cc
	io/parserinputbuffer.h
	io/outputbuffer.cc
	io/ostreamoutputbuffer.cc
	validators/dtdvalidator.h
	validators/validator.h
	validators/schemavalidator.h
	validators/dtdvalidator.cc
	validators/validator.cc
	validators/schemavalidator.cc
	parsers/parser.cc
	parsers/parser.h
	parsers/textreader.cc
	parsers/saxparser.cc
	parsers/textreader.h
	parsers/domparser.cc
	parsers/domparser.h
	parsers/saxparser.h
	exceptions/validity_error.h
	exceptions/parse_error.cc
	exceptions/internal_error.h
	exceptions/validity_error.cc
	exceptions/internal_error.cc
	exceptions/parse_error.h
	exceptions/exception.cc
	exceptions/exception.h
	nodes/node.cc
	nodes/textnode.h
	nodes/element.h
	nodes/processinginstructionnode.h
	nodes/contentnode.h
	nodes/entityreference.h
	nodes/cdatanode.cc
	nodes/node.h
	nodes/entityreference.cc
	nodes/processinginstructionnode.cc
	nodes/cdatanode.h
	nodes/textnode.cc
	nodes/contentnode.cc
	nodes/element.cc
	nodes/commentnode.cc
	nodes/commentnode.h
	)


INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
ADD_DEFINITIONS(${LIBXML2_DEFINITIONS})

ADD_LIBRARY(xmlpp SHARED ${libxmlpp_SRC})

TARGET_LINK_LIBRARIES(xmlpp ${LIBXML2_LIBRARIES})

