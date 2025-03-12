# DataClasses Library Tests CMakeLists.txt

enable_testing()

set(TEST_NAME DataClassesTests)

set(TEST_LIST
	"source/Datum_test.cpp"
	"source/QuantityData_test.cpp"

)

add_executable(${TEST_NAME} ${TEST_LIST})

target_link_libraries(${TEST_NAME}
	PUBLIC 
	${MY_LIBRARY_NAME}
	GTest::gtest
	GTest::gtest_main
	GTest::gmock
	GTest::gmock_main
)

include(GoogleTest)

# Register tests
gtest_discover_tests(${TEST_NAME})