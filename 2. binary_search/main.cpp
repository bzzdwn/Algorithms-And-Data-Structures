#include <iostream>
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

int LowerBound(const std::vector<int>& arr_to_find, const int& value) {
	int left_border = 0, right_border = arr_to_find.size();
	while (left_border < right_border) {
		int center = (left_border + right_border) / 2;
		if (arr_to_find[center] >= value)
			right_border = center;
		else left_border = center + 1;
	}
	return left_border;
}

bool Binary(const std::vector<int>& arr_to_find, const int& value) {
	int left_border = 0, right_border = arr_to_find.size();
	while (left_border < right_border) {
		int center = (left_border + right_border) / 2;
		if (arr_to_find[center] == value)
			return true;
		else if (arr_to_find[center] > value)
			right_border = center;
		else if (arr_to_find[center] < value)
			left_border = center + 1;
	}
	return false;
}

void BinarySearch(const std::vector<int>& arr_to_find, std::vector <int> reqs_arr) {
	for (size_t i = 0; i < reqs_arr.size(); i++)
	{
		int is_in_arr = 0;
		if (Binary(arr_to_find, reqs_arr[i]))
			is_in_arr = 1;
		std::cout << is_in_arr << " ";
		std::cout << LowerBound(arr_to_find, reqs_arr[i]) << " ";
		std::cout << UpperBound(arr_to_find, reqs_arr[i]) << "\n";
		is_in_arr = 0;
	}

}

int main() {
	int size_;
	std::cin >> size_;
	std::vector <int> arr_to_find (size_);
	for (size_t i = 0; i < size_; i++)
	{
		std::cin >> arr_to_find[i];
	}
	int reqs;
	std::cin >> reqs;
	std::vector <int> reqs_arr (reqs);
	for (size_t i = 0; i < reqs; i++)
	{
		std::cin >> reqs_arr[i];
	}
	BinarySearch(arr_to_find, reqs_arr);
	return 0;
}