#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
#include <mpi/mpi.h>

#include "../include/mpi_transpose.hpp"
#include "../include/naive_matrix.hpp"

int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);

	int proc, num_procs;
	MPI_Comm_rank(MPI_COMM_WORLD, &proc);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	const int global_n = 8;
	const int local_n = global_n / num_procs;
	const int first_n = local_n * proc;
	const int size = local_n * global_n;

	//std::vector<double> A(size);
	//std::vector<double> AT(size);
	//std::vector<double> AT_naive(size);
	//std::iota(A.begin(), A.end(), 0);
	double* A = new double[size];
	double* AT = new double[size];
	double* AT_naive = new double[size];

	for (int i=0; i<size; ++i) {
		A[i] = i;
	}

	if (proc == 0) {
		print_matrix(A, local_n, global_n);
	}
	naive_transpose(A, AT_naive, local_n, global_n);
	//naive_transpose(A, AT_naive, global_n, global_n);
	if (proc == 0) {
		print_matrix(AT_naive, local_n, global_n);
		//print_matrix(AT_naive, global_n, global_n);
	}

	mpi_transpose(A, AT, local_n, global_n);
	if (proc == 1) {
		print_matrix(AT, local_n, global_n);
		//print_matrix(AT, global_n, global_n);
	}

	//assert(AT_naive == AT);

	free(AT_naive);
	free(AT);
	free(A);

	MPI_Finalize();
	return 0;
}
