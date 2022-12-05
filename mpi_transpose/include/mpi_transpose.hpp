void mpi_transpose(double* A, double* AT, int local_n, int global_n);
void mpi_transpose_all_to_all(double* A, double* AT, int local_n, int global_n, 
	int offset);
