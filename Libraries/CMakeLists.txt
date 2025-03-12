# Libraries CMakeLists.txt

project(Libraries LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
if(MSVC)
  add_compile_options("/permissive-")
endif()

#if(PROJECT_TESTING_ENABLED)
  #============================
  # Google Test configuration
  #============================
  include(FetchContent)

  FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest
      GIT_TAG v1.15.2
  )

  # Prevent overriding compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  message(STATUS "Begin GoogleTest API configuration")
  FetchContent_MakeAvailable(googletest)
  message(STATUS "Completed GoogleTest API configuration")

  #set(GTEST_LINKED_AS_SHARED_LIBRARY ON)

  # Place all GoogleTest executables in an IDE directory
  set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES FOLDER "Extern/GoogleTest")

#endif()

add_subdirectory(DataClasses)
add_subdirectory(Item)
#add_subdirectory(ShoppingCart)