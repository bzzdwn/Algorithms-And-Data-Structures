#include <iostream>
#include <vector>

int max(const int& a, const int& b) {
	return a > b ? a : b;
}

void LCS(const int& sequences_length, const std::vector<int> &first_sequence, const std::vector<int>& second_sequence) {
	std::vector<std::vector<int>> result(sequences_length + 1);
	std::vector<int> first_sequence_indeces(sequences_length);
	std::vector<int> second_sequence_indeces(sequences_length);
	int common_elements_counter = 0;
	for (size_t i = 0; i < sequences_length + 1; i++)
	{
		result[i].resize(sequences_length + 1);
	}
	for (size_t i = 1; i < sequences_length + 1; i++)
	{
		for (size_t j = 1; j < sequences_length + 1; j++)
		{
			if (first_sequence[i - 1] == second_sequence[j - 1]) {
				result[i][j] = result[i - 1][j - 1] + 1;
			}
			else 
			{
				result[i][j] = max(result[i - 1][j], result[i][j - 1]);
			}
		}
	}
	std::cout << result[sequences_length][sequences_length] << "\n";
	int j = sequences_length;
	for (int i = sequences_length; i > 0 && j > 0;)
	{
		for (; i > 0 && j > 0;)
		{
			if (first_sequence[i - 1] == second_sequence[j - 1]) {
				first_sequence_indeces[common_elements_counter] = i - 1;
				second_sequence_indeces[common_elements_counter] = j - 1;
				common_elements_counter++;
				i--;
				j--;
			}
			else {
				if (i > 0 && j > 0 && result[i - 1][j] == result[i][j])
					i--;
				else if (i > 0 && j > 0 && result[i][j - 1] == result[i][j])
					j--;
			}
		}
	}
	for (int i = common_elements_counter - 1; i >= 0; i--)
	{
		std::cout << first_sequence_indeces[i] << " ";
	}
	std::cout << "\n";
	for (int i = common_elements_counter - 1; i >= 0; i--)
	{
		std::cout << second_sequence_indeces[i] << " ";
	}
}

int main() {
	int sequences_length;
	std::cin >> sequences_length;
	std::vector<int> first_sequence(sequences_length);
	std::vector<int> second_sequence(sequences_length);
	for (size_t i = 0; i < sequences_length; i++)
	{
		std::cin >> first_sequence[i];
	}
	for (size_t i = 0; i < sequences_length; i++)
	{
		std::cin >> second_sequence[i];
	}
	LCS(sequences_length, first_sequence, second_sequence);
	return 0;
}