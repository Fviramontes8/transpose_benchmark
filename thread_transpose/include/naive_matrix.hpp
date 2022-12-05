#include <vector>

void print_matrix(const std::vector<double>& A, int row, int col);

void naive_transpose(const std::vector<double>& A, std::vector<double>& AT, 
	int row_size, int col_size);

bool operator==(const std::vector<double>& lhs, 
	const std::vector<double>& rhs);

bool operator!=(const std::vector<double>& lhs, 
	const std::vector<double>& rhs);
