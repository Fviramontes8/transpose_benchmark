#include <mpi.h>

#include "../include/mpi_transpose.hpp"

void mpi_transpose(double* A, double* AT, int local_n, int global_n) {
	MPI_Datatype row_type;
	MPI_Type_vector(local_n, local_n, global_n, MPI_DOUBLE, &row_type);
	MPI_Type_commit(&row_type);

	MPI_Datatype col_type;
	MPI_Type_vector(local_n, 1, global_n, MPI_DOUBLE, &col_type);
	MPI_Type_commit(&col_type);

	MPI_Datatype mult_col_type;
	MPI_Type_create_hvector(local_n, 1, sizeof(double), col_type,
		&mult_col_type);
	MPI_Type_commit(&mult_col_type);

	MPI_Datatype row_contig_type;
	MPI_Type_create_resized(row_type, 0, local_n*sizeof(double),
		&row_contig_type);
	MPI_Type_commit(&row_contig_type);

	MPI_Datatype mult_col_contig_type;
	MPI_Type_create_resized(mult_col_type, 0, local_n*sizeof(double),
		&mult_col_contig_type);
	MPI_Type_commit(&mult_col_contig_type);

	MPI_Alltoall(A, 1, mult_col_contig_type, AT, 1, row_contig_type,
		MPI_COMM_WORLD);

	MPI_Type_free(&mult_col_contig_type);
	MPI_Type_free(&row_contig_type);
	MPI_Type_free(&mult_col_type);
	MPI_Type_free(&col_type);
	MPI_Type_free(&row_type);
}
