#include <fstream>
#include <vector>
#include <string>

bool Delta(const char& a, const char& b) {
	return a == b ? 0 : 1;
}

int min(const int& left, const int& central, const int& right) {
	if (left <= central && left <= right) return left;
	else if (central <= left && central <= right) return central;
	else if (right <= left && right <= central) return right;
}

int main() {
	std::ifstream input;
	input.open("in.txt");
	int delete_cost, insert_cost, replace_cost, tmp;
	input >> delete_cost >> insert_cost >> replace_cost;
	std::string A, B;
	std::getline(input, A);
	std::getline(input, A);
	std::getline(input, B);
	input.close();
	std::vector<std::vector<int>> matrix(A.length() + 1);
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(B.length() + 1);
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i][0] = delete_cost * i;
	}
	for (int i = 0; i < matrix.front().size(); i++)
	{
		matrix[0][i] = insert_cost * i;
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix.front().size(); j++)
		{
			matrix[i][j] = min(matrix[i - 1][j] + delete_cost, matrix[i][j - 1] + insert_cost,
				matrix[i - 1][j - 1] + Delta(A[i - 1], B[j - 1]) * replace_cost);
		}
	}
	std::ofstream output;
	output.open("out.txt");
	output << matrix[A.length()][B.length()];
	output.close();
	return 0;
}