cmake_minimum_required(VERSION 3.22)

project(mpi_transpose
	VERSION 1.0
	DESCRIPTION "Implements matrix transpose via MPI"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-ggdb3)

find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(app)
add_subdirectory(src)

target_link_libraries(mpi_transpose ${MPI_LIBRARIES})
