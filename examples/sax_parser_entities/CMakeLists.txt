ADD_EXECUTABLE(sax_parser_entities
		main.cc
		myparser.h
		myparser.cc)

TARGET_LINK_LIBRARIES(sax_parser_entities xmlpp)
