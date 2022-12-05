set(HEADER_NAIVE_MATRIX "${mpi_transpose_SOURCE_DIR}/include/naive_matrix.hpp")
set(HEADER_MPI_TRANSPOSE "${mpi_transpose_SOURCE_DIR}/include/mpi_transpose.hpp")

add_library(naive_matrix_lib naive_matrix_impl.cpp ${HEADER_NAIVE_MATRIX})
add_library(mpi_transpose_lib mpi_transpose_impl.cpp ${HEADER_MPI_TRANSPOSE})

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_NAIVE_MATRIX} ${HEADER_MPI_TRANSPOSE}
)
