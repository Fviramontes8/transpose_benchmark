#include <cassert>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

#include "../include/thread_transpose.hpp"
#include "../include/naive_matrix.hpp"

//void thread_transpose(const std::vector<double>& A, std::vector<double> &AT, 
//	int rows, int cols, int offset);

int main(int argc, char* argv[]) {
	const int num_threads = 2;
	const int global_n = 8;
	const int local_n = global_n / num_threads;
	const int size = local_n * global_n;
	std::vector<std::thread> threads;

	std::vector<double> A(size);
	std::vector<double> AT(size);
	std::vector<double> AT_naive(size);

	std::iota(A.begin(), A.end(), 0);

	print_matrix(A, local_n, global_n);
	naive_transpose(A, AT_naive, global_n, global_n);
	print_matrix(AT_naive, global_n, local_n);

	//thread_transpose(A.data(), AT.data(), local_n, global_n);
	//print_matrix(AT, global_n, global_n);

	//assert(AT_naive == AT);
	return 0;
}
