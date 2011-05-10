ADD_EXECUTABLE(sax_exception 
		main.cc
		myparser.h
		myparser.cc)

TARGET_LINK_LIBRARIES(sax_exception xmlpp)
