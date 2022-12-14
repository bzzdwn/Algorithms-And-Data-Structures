#include <fstream>
#include <set>


int main() {
	std::ifstream in;
	std::ofstream out;
	in.open("input.txt");
	std::set<long long> res;
	long long tmp;
	std::set<long long>::iterator it;
	if (in.is_open()) {
		while (!in.eof()) {
			in >> tmp;
			res.insert(tmp);
		}
	}
	long long sum = 0;
	for (it = res.begin(); it != res.end(); ++it)
	{
		sum += *it;
	}
	in.close();
	out.open("output.txt");
	out << sum;
	out.close();
}