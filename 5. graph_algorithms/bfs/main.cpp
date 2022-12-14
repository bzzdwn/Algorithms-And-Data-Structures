#include <fstream>
#include <vector>
#include <queue>

int next_idx = 1;

void bfs(const std::vector<std::vector<int>>& adjency_matrix, const int& key, std::vector <int>& ord, std::vector<bool>& visited) {

	std::queue <int> q;
	
	ord[key] = next_idx;
	next_idx++;
	visited[key] = true;
	q.push(key);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u = 0; u < adjency_matrix.size(); u++)
		{
			if (adjency_matrix[v][u] != 0 && !visited[u]) {
				visited[u] = true;
				ord[u] = next_idx;
				next_idx++;
				q.push(u);
			}
		}

	}
}

int main() {
	std::ifstream input;
	input.open("input.txt");
	int size;
	input >> size;
	std::vector <std::vector<int>> adjency_matrix(size);
	for (int i = 0; i < size; i++)
	{
		adjency_matrix[i].resize(size);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			input >> adjency_matrix[i][j];
		}
	}
	input.close();
	std::vector<bool> visited(adjency_matrix.size(), false);
	std::vector <int> ord(size);
	for (int i = 0; i < size; i++)
	{
		if (!visited[i])
			bfs(adjency_matrix, i, ord, visited);
	}
	std::ofstream output;
	output.open("output.txt");
	for (int i = 0; i < size; i++)
	{
		output << ord[i] << " ";
	}
	output.close();
	return 0;
}