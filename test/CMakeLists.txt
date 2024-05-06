cmake_minimum_required(VERSION 3.18)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/3rd-party/googletest
)
FetchContent_MakeAvailable(googletest)

# Link my_math and gtest_main to simple_test
add_executable(simple_test src/test.cpp)
target_compile_features(simple_test PRIVATE cxx_auto_type)
target_include_directories(simple_test PUBLIC ${CMAKE_SOURCE_DIR}/libs)
target_link_libraries(simple_test PUBLIC my_math)

target_link_libraries(simple_test PUBLIC GTest::gtest_main)

add_test(NAME example_test COMMAND simple_test)
