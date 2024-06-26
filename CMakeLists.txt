cmake_minimum_required(VERSION 3.14)
include_directories(.)

project(BrezenhamCircleRsterization)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

find_package(Doxygen REQUIRED)

add_subdirectory(BrezenhamLib)

set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_IN})

add_custom_target(doc ALL
   	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
    	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
   	COMMENT "Generating API documentation with Doxygen"
    	VERBATIM
)


find_package(OpenCV REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(BrezenhamTest BrezenhamTest.cpp)

target_link_libraries(BrezenhamTest PRIVATE opencv_core opencv_highgui BrezenhamLib nlohmann_json::nlohmann_json)
	
install(DIRECTORY ${CMAKE_SOURCE_DIR}/tests/
  	DESTINATION tests
)

install(TARGETS BrezenhamTest 
  	DESTINATION bin
)

install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/ 
    	DESTINATION bin 
    	FILES_MATCHING PATTERN "*BrezenhamTest*" 
    	EXCLUDE PATTERN "*" 
)

