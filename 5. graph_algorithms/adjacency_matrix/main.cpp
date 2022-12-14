#include <fstream>

int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int vertexes, edges;
	input >> vertexes >> edges;
	int** adjacency_matrix = new int*[vertexes];
	for (int i = 0; i < vertexes; ++i)
	{
		adjacency_matrix[i] = new int[vertexes]{0};
	}
	for (int i = 0; i < edges; ++i)
	{
		int row, column;
		input >> row >> column;
		adjacency_matrix[row-1][column-1] = 1;
		adjacency_matrix[column-1][row-1] = 1;
	}
	input.close();
	output.open("output.txt");
	for (int i = 0; i < vertexes; ++i)
	{
		for (int j = 0; j < vertexes; j++)
		{
			output << adjacency_matrix[i][j] << " ";
		}
		output << "\n";
	}
	output.close();
	return 0;
}