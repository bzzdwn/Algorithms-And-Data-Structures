#include <fstream>
#include <vector>
struct Node {
	Node (const int& value_, int max_, int min_): value(value_), max_limit(max_), min_limit(min_) {
	}
	Node(const int& value_) {
		value = value_;
	}
	int value;
	int min_limit = INT_MIN;
	int max_limit = INT_MAX;
};

class Tree {
public:
	Tree(const int& size_, const int& value_) {
		root = new Node(value_);
		vec.resize(size_);
		vec[0] = root;
		counter = 1;
	}
	bool InsertNode(const int& key, const int& parent_pos, std::string side) {
		if (side == "R") {
			if (vec[parent_pos - 1]->value <= key && key < vec[parent_pos - 1]->max_limit) {
				Node* node = new Node(key, vec[parent_pos - 1]->max_limit, vec[parent_pos - 1]->value);
				vec[counter] = node;
				counter++;
				return true;
			}
		}
		else if (side == "L") {
			if (vec[parent_pos - 1]->value > key && key >= vec[parent_pos - 1]->min_limit) {
				Node* node = new Node(key, vec[parent_pos - 1]->value - 1, vec[parent_pos - 1]->min_limit);
				vec[counter] = node;
				counter++;
				return true;
			}
		}
		return false;
	}
	int GetSize() {
		return vec.size();
	}

private:
	int counter;
	std::vector <Node*> vec;
	Node* root;
};

int main() {
	std::ifstream input_file;
	std::ofstream output_file;
	input_file.open("bstin.txt");
	int root_value, tree_size;
	input_file >> tree_size >> root_value;
	Tree tree(tree_size, root_value);
	bool flag;
	while (tree_size > 1) {
		int key, parent_key;
		std::string side;
		input_file >> key >> parent_key >> side;
		if (!tree.InsertNode(key, parent_key, side)) {
			flag = false;
			break;
		}
		tree_size--;
		flag = true;
	}
	output_file.open("bstout.txt");
	if (!flag) output_file << "NO";
	else output_file << "YES";
	output_file.close();
	return 0;
}