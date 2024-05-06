cmake_minimum_required(VERSION 3.18)
project(CMakeDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib")

set(TARGET1 my_math_test)
project(CMakeDemo LANGUAGES CXX)


# 添加编译器编译选项
list(APPEND compiler_flags "-fPIC" "-Wall" "-Wextra" "-Wpedantic" "-O2")

add_executable(${TARGET1} my_math_test.cpp)

target_compile_options(${TARGET1} PUBLIC ${compiler_flags})

# 添加my_math库
option(MY_MATH "Use my_math lib" ON)
if (MY_MATH)
    add_subdirectory(libs)
    target_include_directories(${TARGET1} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs)
    target_link_libraries(${TARGET1} PUBLIC my_math)
    target_compile_definitions(${TARGET1} PUBLIC "MY_MATH")
endif()

# 引用第三方fmt库
include(FetchContent)

FetchContent_Declare(
    fmt 
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git 
    GIT_TAG 10.2.0 
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/fmt 
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(${TARGET1} PUBLIC fmt::fmt)

install(TARGETS ${TARGET1} DESTINATION bin)

# Add test case 
enable_testing()
add_subdirectory(test)