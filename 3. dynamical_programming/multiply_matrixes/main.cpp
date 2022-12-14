#include <fstream>
#include <vector>

int MatrixMultiply(std::vector<int> matrixes) {
	std::vector<std::vector<int>> result(matrixes.size());
	for (size_t i = 0; i < result.size(); i++)
	{
		result[i].resize(matrixes.size());
	}
 	for (size_t l = 2; l < result.size(); l++)
	{
		for (size_t i = 1; i < result.size() - l + 1; i++)
		{
			int j = i + l - 1;
			result[i][j] = INT_MAX;
			for (size_t k = i; k < j; k++)
			{
				int value = result[i][k] + result[k + 1][j] + matrixes[i - 1] * matrixes[k] * matrixes[j];
				result[i][j] = value < result[i][j] ? value : result[i][j];
			}
		}
	}
	return result[1][result.size() - 1];
}

int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int amount_of_matrices;
	input >> amount_of_matrices;
	std::vector <int> matrix_sizes(amount_of_matrices + 1);
	int tmp = 0;
	for (size_t i = 0; i < matrix_sizes.size(); i++)
	{
		input >> matrix_sizes[i];
		input >> tmp;
	}
	matrix_sizes[amount_of_matrices] = tmp;
	output << MatrixMultiply(matrix_sizes);
	return 0;
}