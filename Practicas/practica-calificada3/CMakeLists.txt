cmake_minimum_required(VERSION 3.10)
project(practica_calificada3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Libreria de lectura
add_library(leer src/leer.cpp)

# Solucion ingenua
add_library(solucion_ingenua src/solucion_ingenua.cpp)

# Solucion optima
add_library(solucion_optima src/solucion_optima.cpp)

# Demo ingenua
add_executable(demo_ingenua demos/demo_ingenua.cpp)
target_link_libraries(demo_ingenua solucion_ingenua leer)

# Demo optima
add_executable(demo_optima demos/demo_optima.cpp)
target_link_libraries(demo_optima solucion_optima leer)

# Tests
add_executable(unit_tests tests/test.cpp)
target_link_libraries(unit_tests solucion_optima solucion_ingenua)

# CTest
enable_testing()
add_test(NAME pruebas COMMAND unit_tests)

# Benchmark
add_executable(benchmark benchmark/benchmark.cpp)
target_link_libraries(benchmark solucion_optima solucion_ingenua)
