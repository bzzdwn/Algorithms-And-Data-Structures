#include <fstream>
#include <vector>

int UpperBound(const std::vector<int>& arr_to_find, const int& value) {
	int left_border = 0, right_border = arr_to_find.size();
	while (left_border < right_border) {
		int center = (left_border + right_border) / 2;
		if (arr_to_find[center] > value)
			right_border = center;
		else left_border = center + 1;
	}
	return left_border;
}

int max(int lhs, int rhs) {
	return lhs > rhs ? lhs : rhs;
}

int LargestIncreasingSubsequence(const std::vector<int>& sequence) {
	int max_sequence_length = 0;
	std::vector<int> result(sequence.size() + 1);
	for (int i = 1; i < sequence.size() + 1; i++)
	{
		result[i] = INT_MAX;
	}
	result[0] = INT_MIN;
	for (int i = 0; i < sequence.size(); i++)
	{
		int j = UpperBound(result, sequence[i]);
		if (sequence[i] > result[j - 1] && sequence[i] < result[j]) {
			result[j] = sequence[i];
			max_sequence_length = max(j, max_sequence_length);
		}
	}
	return max_sequence_length;
}

int main() {
	std::ifstream input;
	input.open("input.txt");
	int size = 0;
	input >> size;
	std::vector<int> sequence(size);

	for (size_t i = 0; i < size; i++)
	{
		input >> sequence[i];
	}
	std::ofstream output;
	output.open("output.txt");
	output << LargestIncreasingSubsequence(sequence);
	output.close();
}