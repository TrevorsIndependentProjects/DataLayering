# Library: ItemLibrary

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

set(MY_LIBRARY_NAME ItemLibrary)

set(HEADER_LIST
	"AbstractItem.h"
	"Book.h"
	"CompactDisc.h"
	"Magazine.h"

)

set(SOURCE_LIST
	"Book.cpp"
	"CompactDisc.cpp"
	"Magazine.cpp"
)

add_library(${MY_LIBRARY_NAME}
	STATIC
	${HEADER_LIST}
	${SOURCE_LIST}
)

target_include_directories(${MY_LIBRARYNAME} PUBLIC include)

target_link_libraries(${MY_LIBRARY_NAME}
	PUBLIC
	DataClasses
)

add_subdirectory(tests)