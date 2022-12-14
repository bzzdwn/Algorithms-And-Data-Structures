#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <queue>

int adjency_components = 0;

void bfs(const std::vector<std::pair <int, std::vector<int>>>& list_of_adjency, const int& key, std::vector<bool>& visited) {
	std::queue <int> queue;
	visited[key] = true;
	queue.push(key);
	while (!queue.empty()) {
		int vert = queue.front();
		queue.pop();
		for (int u : list_of_adjency[vert].second)
		{
			if (visited[u] == false) {
				visited[u] = true;
				queue.push(u);
			}
		}
	}
}


int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int vertexes, edges;
	input >> vertexes >> edges;
	std::vector<std::pair <int, std::vector<int>>> list_of_adjency(vertexes);
	for (int i = 0; i < edges; ++i)
	{
		int first_vertex, second_vertex;
		input >> first_vertex;
		input >> second_vertex;
		list_of_adjency[first_vertex - 1].first++;
		list_of_adjency[second_vertex - 1].first++;
		list_of_adjency[first_vertex - 1].second.push_back(second_vertex - 1);
		list_of_adjency[second_vertex - 1].second.push_back(first_vertex - 1);
	}
	input.close();
	std::vector<bool> visited(vertexes, false);
	for (int key = 0; key < list_of_adjency.size(); ++key)
	{	
		if (!visited[key]) {
			adjency_components++;
			bfs(list_of_adjency, key, visited);
			
		}
	}
	adjency_components--;
	output.open("output.txt");
	output << adjency_components;
	output.close();
	return 0;
}

