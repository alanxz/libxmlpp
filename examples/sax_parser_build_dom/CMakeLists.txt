INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
ADD_EXECUTABLE(sax_parser_build_dom
		main.cc
		svgdocument.cc
		svgdocument.h
		svgelement.cc
		svgelement.h
		svggroup.h
		svgparser.cc
		svgparser.h
		svgpath.h
		)

TARGET_LINK_LIBRARIES(sax_parser_build_dom xmlpp)
