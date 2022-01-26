cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(workCpp)

include_directories(/usr/local/include)

AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")

# Source files
set(SOURCE_FILES
    
    ${PROJECT_SOURCE_DIR}/graphs.cpp
    ${PROJECT_SOURCE_DIR}/kruskal.cpp
    ${PROJECT_SOURCE_DIR}/prim.cpp
     
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

add_executable(graphs src/graphs.cpp)
add_executable(kruskal src/kruskal.cpp)
add_executable(prim src/prim.cpp)
