#include <iostream>
#include <fstream>
#include <vector>
struct Node {
	Node(const int& x) : value(x) {
	}
	Node* left = nullptr;
	Node* right = nullptr;
	int value;
};

class BSTree {
public:
	BSTree() : root(0) {}

	void InsertNode(const int& x) {
		Node** cur = &root;
		while (*cur) {
			Node& node = **cur;
			if (x < node.value) {
				cur = &node.left;
			}
			else if (x > node.value) {
				cur = &node.right;
			}
			else {
				return;
			}
		}
		*cur = new Node(x);
	}

	void Travesal() {
		PreOrderTravesal(root);
	}
	std::vector<int> vec;
private:
	void PreOrderTravesal(Node* current) {
		if (!current) {
			return;
		}
		if (current != nullptr) {
			Action(current->value);
		}
		PreOrderTravesal(current->left);
		PreOrderTravesal(current->right);
		
		
	}
	
	void Action(const int& value) {
		vec.push_back(value);
	}


	Node* root = nullptr;
};

int main() {
	BSTree tree;
	std::ifstream input;
	int temporary_value;
	input.open("input.txt");
	if (input.is_open()) {
		while (!input.eof()) {
			input >> temporary_value;
			tree.InsertNode(temporary_value);
		}
	}
	tree.Travesal();
	std::ofstream output;
		output.open("output.txt");
		for (size_t i = 0; i < tree.vec.size(); i++)
		{
			output << tree.vec[i] << "\n";
		}
		output.close();
	std::cout << "runtime = " << clock() / 1000.0;
}
