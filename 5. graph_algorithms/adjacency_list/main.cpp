#include <fstream>
#include <vector>
#include <stack>
#include <map>
int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int vertexes, edges;
	input >> vertexes >> edges;
	std::vector<std::pair <int, std::vector<int>>> list_of_adjency (vertexes);
	for (int i = 0; i < edges; ++i)
	{
		int first_vertex, second_vertex;
		input >> first_vertex >> second_vertex;
		list_of_adjency[first_vertex - 1].first++;
		list_of_adjency[second_vertex - 1].first++;
		list_of_adjency[first_vertex - 1].second.push_back(second_vertex);
		list_of_adjency[second_vertex - 1].second.push_back(first_vertex);
	}
	input.close();
	output.open("output.txt");
	for (int i = 0; i < list_of_adjency.size(); ++i)
	{
		output << list_of_adjency[i].first << " ";
		for (int j = 0; j < list_of_adjency[i].second.size(); j++)
		{
			output << list_of_adjency[i].second[j] << " ";
		}
		output << "\n";
	}
	output.close();
	return 0;
}