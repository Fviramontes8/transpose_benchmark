add_executable(
	${PROJECT_NAME}
	app.cpp
	${PROJECT_SOURCE_DIR}/src/naive_matrix_impl.cpp
	${PROJECT_SOURCE_DIR}/src/mpi_transpose_impl.cpp
)
