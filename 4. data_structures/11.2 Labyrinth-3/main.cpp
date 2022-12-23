#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
int main() {
	std::ifstream input;
	input.open("labyrinth.in");
	std::ofstream output;
	output.open("labyrinth.out");
	int rows, cols, people;
	input >> rows >> cols >> people;
	std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
	std::vector<std::vector<int>> labyrinth(rows + 2, std::vector<int>(cols + 2, 1));
	std::vector<bool> is_exits(cols);
	int people_exited = 0;
	std::vector<int> entries(people);
	std::vector<int> exits(people);
	std::vector<std::pair<int, int>> coords(8);
	coords[2] = std::make_pair(1, -1);
	coords[3] = std::make_pair(1, 0);
	coords[4] = std::make_pair(1, 1);
	coords[1] = std::make_pair(0, -1);
	coords[5] = std::make_pair(0, 1);
	coords[6] = std::make_pair(-1, 1);
	coords[7] = std::make_pair(-1, 0);
	coords[0] = std::make_pair(-1, -1);
	for (int i = 0; i < people; i++)
	{
		input >> entries[i];
	}
	for (int i = 0; i < people; i++)
	{
		int tmp;
		input >> tmp;
		exits[i] = tmp;
		is_exits[tmp - 1] = true;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int value;
			input >> value;
			result[i][j] = value;
			labyrinth[i + 1][j + 1] = value;
		}
	}
	std::stack<std::pair<int, int>> path;
	std::stack<std::pair<int, int>> wrong_path;
	for (int p = 0; p < people; p++)
	{
		int counter = 0;
		bool flag = false;
		int i = 1, j = entries[p];
		std::pair<int, int> start_pos = std::make_pair(i, j);
		path.push(std::make_pair(i, j));
		labyrinth[i][j] = p + 2;
		int reverse = 0;
		while (i <= rows && j <= cols) {
			bool closed_room = true;
				for (int k = 0; k < 8; k++)
				{
					if (labyrinth[i + coords[(counter + k) % 8].first][j + coords[(counter + k) % 8].second] == 0 || 
						i + coords[(counter + k) % 8].first == rows && j + coords[(counter + k) % 8].second!= 0 && is_exits[j + coords[(counter + k) % 8].second -1] == true) {
						i += coords[(counter + k) % 8].first;
						j += coords[(counter + k) % 8].second;
						counter = (counter + k + 5) % 8;
						labyrinth[i][j] = p + 2;

						path.push(std::make_pair(i, j));
						closed_room = false;
						reverse = 0;
						break;
					}
					else if (i == rows && is_exits[j - 1] == true) {
						closed_room = false;
						i += coords[(counter + k) % 8].first;
						j += coords[(counter + k) % 8].second;
						path.push(std::make_pair(i, j));
						break;
					}
				
			}
			if (i == rows && is_exits[j - 1] == true) {
				flag = true;
				break;
			}
			if (closed_room && !path.empty()) {
				wrong_path.push(std::make_pair(i, j));
				labyrinth[i][j] = -1;
				path.pop();
				if (!path.empty()) {
					i = path.top().first;
					j = path.top().second;
				}
				if(reverse== 0)
				counter = (counter + 5) % 8;
			
				closed_room = false;
				reverse++;
			}
			else if (i == start_pos.first && j == start_pos.second) {
				while (!path.empty()) {
					labyrinth[path.top().first][path.top().second] = 0;
					path.pop();
				}
				break;
			}
		}
		if (flag) {
			people_exited++;
			while (!path.empty()) {
				result[path.top().first - 1][path.top().second - 1] = p + 2;
				path.pop();
			}
		}
	}
	output << people_exited << "\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			output << result[i][j] << " ";
		}
		output << "\n";
	}
	input.close();
	return 0;
}