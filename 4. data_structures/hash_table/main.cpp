#include <fstream>

int main() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	int table_size, constant, number_of_keys;
	input >> table_size >> constant >> number_of_keys;
	int* table = new int[table_size];
	for (int i = 0; i < table_size; ++i)
	{
		table[i] = -1;
	}
	for (int j = 0; j < number_of_keys; j++)
	{
		int value;
		input >> value;
		int h = (value % table_size) % table_size;
		int i = 1;
		while (table[h] != value && table[h] != -1) {
			h = ((value % table_size) + constant * i) % table_size;
			i++;
		}
		table[h] = value;
	}
	input.close();
	output.open("output.txt");
	for (int i = 0; i < table_size; ++i)
	{
		output << table[i] << " ";
	}
	output.close();
	return 0;
}