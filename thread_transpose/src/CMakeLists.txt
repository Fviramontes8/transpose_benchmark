set(HEADER_NAIVE_MATRIX 
	"${thread_transpose_SOURCE_DIR}/include/naive_matrix.hpp"
)

set(HEADER_THREAD_TRANSPOSE 
	"${thread_transpose_SOURCE_DIR}/include/thread_transpose.hpp"
)

add_library(naive_matrix_lib naive_matrix_impl.cpp ${HEADER_NAIVE_MATRIX})
add_library(thread_transpose_lib 
	thread_transpose_impl.cpp 
	${HEADER_THREAD_TRANSPOSE}
)

source_group(
	TREE "${PROJECT_SOURCE_DIR}"
	PREFIX "Header Files"
	FILES ${HEADER_NAIVE_MATRIX} ${HEADER_THREAD_TRANSPOSE}
)
