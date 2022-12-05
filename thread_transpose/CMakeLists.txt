cmake_minimum_required(VERSION 3.22)

project(thread_transpose
	VERSION 1.0
	DESCRIPTION "Implements matrix transpose via std::thread"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-ggdb3)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(app)
add_subdirectory(src)
