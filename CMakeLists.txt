cmake_minimum_required(VERSION 3.16)
project(OpenMS_playground)

set(CMAKE_CXX_STANDARD 17)

find_package(HDF5 REQUIRED COMPONENTS CXX HL)
find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/lib/blosc/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

include_directories(${HDF5_INCLUDE_DIRS})
add_subdirectory(lib/blosc)

add_executable(OpenMS_playground main.cpp)
add_dependencies(OpenMS_playground blosc_filter_shared)

target_include_directories(
    OpenMS_playground PUBLIC ${CMAKE_BINARY_DIR}/lib/blosc/blosc/include)
target_link_libraries(
    OpenMS_playground PRIVATE ${HDF5_LIBRARIES} blosc_filter_shared)
