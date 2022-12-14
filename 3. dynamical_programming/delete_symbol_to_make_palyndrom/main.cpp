#include <fstream>
#include <vector>

int max(const int& lhs, const int& rhs) {
	return lhs > rhs ? lhs : rhs;
}

std::pair<int, std::string> FindPalyndrome(const std::vector<char>& str) {
	std::pair<int, std::string> result;
	std::vector<std::vector<int>> palyndrome_matrix(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		palyndrome_matrix[i].resize(str.size());
	}
	for (int i = 0; i < str.size(); i++)
	{
		palyndrome_matrix[i][i] = 1;
		for (int j = 0; j < str.size(); j++)
		{
			if (i < str.size() - 1 && i + 1 == j) {
				if (str[i] == str[i + 1])
					palyndrome_matrix[i][j] = 2;
				else
					palyndrome_matrix[i][j] = 1;
			}
		}
	}
	for (int j = 2; j < palyndrome_matrix.size(); j++)
	{
		for (int i = j - 2; i > -1; i--)
		{
			if (str[i] == str[j])
				palyndrome_matrix[i][j] = palyndrome_matrix[i + 1][j - 1] + 2;
			else
				palyndrome_matrix[i][j] = max(palyndrome_matrix[i + 1][j], palyndrome_matrix[i][j - 1]);
		}
	}
	result.first = palyndrome_matrix[0][str.size() - 1];
	std::string res;
	for (int i = 0, j = str.size() - 1; i <= j; ) {
		if (str[j] == str[i]) {
			res += str[i];
			i++;
			j--;
		}
		else {
			if (palyndrome_matrix[i + 1][j] == palyndrome_matrix[i][j])
				i++;
			else if (palyndrome_matrix[i][j - 1] == palyndrome_matrix[i][j])
				j--;
		}
	}
	if (result.first % 2 == 0) {
		res += std::string(res.rbegin(), res.rend());
	}
	else {
		res += std::string(res.rbegin() + 1, res.rend());
	}
	result.second = res;
	return result;
}

int main() {
	std::vector<char> string(7000);
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int size_ = 0;
	for (int i = 0; !input.eof(); i++)
	{
		input >> string[i];
		size_++;
	}
	input.close();
	string.resize(size_ - 1);
	output.open("output.txt");
	output << FindPalyndrome(string).first << "\n" << FindPalyndrome(string).second;
	output.close();
	return 0;
}