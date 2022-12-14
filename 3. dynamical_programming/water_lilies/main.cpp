#include <fstream>
#include <vector>

int max(const int& lhs, const int& rhs) {
	return lhs > rhs ? lhs : rhs;
}

int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int number_of_lilies;
	input >> number_of_lilies;
	if (number_of_lilies == 1) {
		int tmp;
		input >> tmp;
		output.open("output.txt");
		output << tmp;
		output.close();
	}
	else if (number_of_lilies == 2) {
		output.open("output.txt");
		output << -1;
		output.close();
	}
	else {
		std::vector <int> mosquitoes(number_of_lilies);
		for (int i = 0; i < number_of_lilies; i++)
		{
			input >> mosquitoes[i];
		}
		std::vector<int> result(number_of_lilies);
		result[0] = mosquitoes[0];
		result[1] = INT_MIN;
		result[2] = mosquitoes[2] + result[0];
		for (size_t i = 3; i < mosquitoes.size(); i++)
		{
			result[i] = max(result[i - 2], result[i - 3]) + mosquitoes[i];
		}
		output.open("output.txt");
		output << result[result.size() - 1];
		input.close();
		output.close();
	}
}