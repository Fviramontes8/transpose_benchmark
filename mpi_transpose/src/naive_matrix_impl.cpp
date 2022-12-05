#include <iostream>
#include <vector>

#include "../include/naive_matrix.hpp"

void print_matrix(const std::vector<double>& A, int row, int col) {
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			std::cout << A[(i * col) + j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void print_matrix(const double* A, int row, int col) {
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			std::cout << A[(i * col) + j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void naive_transpose(const std::vector<double>& A, std::vector<double>& AT,
		int row, int col) {
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			AT[(j * row) + i] = A[(i * col) + j];
		}
	}
}

void naive_transpose(const double* A, double* AT, int row, int col) {
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			AT[(j * row) + i] = A[(i * col) + j];
		}
	}
}

bool operator==(const std::vector<double>& lhs, 
		const std::vector<double>& rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	for (auto i=lhs.begin(), j=rhs.begin(); i != lhs.end(); ++i,++j) {
		if ((*i) != (*j)) {
			return false;
		}
	}
	return true;
}

bool operator!=(const std::vector<double>& lhs, 
		const std::vector<double>& rhs) {
	return !(lhs == rhs);
}
