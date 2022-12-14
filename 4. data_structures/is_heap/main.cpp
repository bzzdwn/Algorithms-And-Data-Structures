#include <fstream>
#include <vector>

bool isHeap(const int* heap, const int& heap_size) {
	for (size_t i = 1; i < heap_size; i++)
	{
		if (heap[i] >= heap[(i - 1) / 2]) {
			if (2 * i + 2 < heap_size && heap[i] > heap[2 * i + 2])
				return false;
			else if (2 * i + 1 < heap_size && heap[i] > heap[2 * i + 1])
				return false;
		}
		else return false;
	}
	return true;
}

int main() {
	std::ifstream input;
	input.open("input.txt");
	int heap_size;
	input >> heap_size;
	int* heap = new int[heap_size];
	for (size_t i = 0; i < heap_size; i++)
	{
		input >> heap[i];
	}
	input.close();
	std::ofstream output;
	output.open("output.txt");
	if (isHeap(heap, heap_size) == 1)
		output << "Yes";
	else output << "No";
	output.close();
}