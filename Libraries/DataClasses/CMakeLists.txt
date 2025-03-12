# Library: DataCLasses

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

set(MY_LIBRARY_NAME DataClasses)

set(HEADER_LIST 
	"include/DataInterface.h"
	"include/DataType.h"
	"include/Datum.h"
	"include/QuantityData.h")

set(SOURCE_LIST
	"source/QuantityData.cpp")

add_library(${MY_LIBRARY_NAME}  
	STATIC
	${HEADER_LIST} 
	${SOURCE_LIST}
 )

#set_target_properties(${MY_LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${MY_LIBRARY_NAME} PUBLIC include)

#if(PROJECT_TESTS_ENABLED)
  add_subdirectory(tests)
#endif()