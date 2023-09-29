cmake_minimum_required(VERSION 3.16)
project(assignment-6 VERSION 0.1.0 LANGUAGES C CXX) # ${PROJECT_NAME}

set(CMAKE_CXX_STANDARD 20) # Needed to use designated initializers in ./tests/tests.cpp
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(max STATIC max.c)
target_compile_definitions(max PRIVATE -DTEST)
add_library(list STATIC list.c)
target_compile_definitions(list PRIVATE -DTEST)

set(libs max list)

add_executable(unit-tests tests/tests.cpp)
target_include_directories(unit-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unit-tests ${libs})
target_link_libraries(unit-tests Catch2::Catch2WithMain)
target_compile_definitions(unit-tests PRIVATE -DTEST)
