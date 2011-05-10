ADD_EXECUTABLE(sax_parser 
		main.cc
		myparser.h
		myparser.cc)

TARGET_LINK_LIBRARIES(sax_parser xmlpp)
