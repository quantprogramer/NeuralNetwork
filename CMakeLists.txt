cmake_minimum_required(VERSION 3.10)

project(NeuralNetwork VERSION 0.1 LANGUAGES C CXX)

set(ProjectLib ${PROJECT_NAME}Lib)
set(ProjectExe ${PROJECT_NAME}Test)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(${ProjectLib}
    src/core/core.cpp
)

add_executable(${ProjectExe}
    test/main.cpp
)

target_link_libraries(${ProjectExe} PRIVATE ${ProjectLib})
