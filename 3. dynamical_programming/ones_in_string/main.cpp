#include <iostream>
#include <vector>

long long FermaCorollary(long long& a) {
	long long MOD = 1000000007;
	long long pow = MOD - 2;
	long long p = 1;
	while (pow > 0) {
		if (pow % 2 != 0)
			p = (p * a) % MOD;
		a = (a * a) % MOD;
		pow >>= 1;
	}
	return p;
}

long long OnesInString(const int& string_length, const int& number_of_ones) {
	long long num = 1, denum = 1;
	long MOD = 1000000007;
	for (size_t i = string_length - number_of_ones + 1; i <= string_length; i++)
	{
		num = (num * i) % MOD;
	}
	for (size_t i = 1; i <= number_of_ones; i++)
	{
		denum = (denum * i) % MOD;
	}
	return (num * FermaCorollary(denum)) % MOD;
}

int main() {
	int string_length, number_of_ones;
	std::cin >> string_length >> number_of_ones;
	std::cout << OnesInString(string_length, number_of_ones);
}