#include <fstream>

int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int vertexes;
	input >> vertexes;
	int* canonical_view = new int[vertexes]{0};
	for (int i = 0; i < vertexes - 1; ++i)
	{
		int father, son;
		input >> father >> son;
		canonical_view[son - 1] = father;
	}
	input.close();
	output.open("output.txt");
	for (int i = 0; i < vertexes; ++i)
	{
		output << canonical_view[i] << " ";
	}
	output.close();
	return 0;
}