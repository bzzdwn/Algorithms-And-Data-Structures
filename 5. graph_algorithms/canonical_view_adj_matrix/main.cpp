#include <fstream>
#include <vector>

int main() {
	std::ifstream input;
	input.open("input.txt");
	int size;
	input >> size;
	std::vector<std::vector<int>> adjacement_matrix(size);
	for (int i = 0; i < size; i++)
	{
		adjacement_matrix[i].resize(size);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			input >> adjacement_matrix[i][j];
		}
	}
	input.close();
	std::ofstream output;
	output.open("output.txt");
	bool flag = false;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (adjacement_matrix[i][j] == 1) {
				output << i + 1 << " ";
				flag = true;
			}
		}
		if (!flag)
			output << "0 ";
		flag = false;
	}
	output.close();
	return 0;
}