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

	void Delete(const int& key) {
		root = DeleteNode(root, key);
	}
	
private:

	Node* DeleteNode(Node* current, const int& key) {
		if (current == nullptr) return nullptr;
		if (key < current->value) {
			current->left = DeleteNode(current->left, key);
			return current;
		}
		else if (key > current->value) {
			current->right = DeleteNode(current->right, key);
			return current;
		}
		if (current->left == nullptr)
			return current->right;
		else if (current->right == nullptr)
			return current->left;
		else {
			int min_value = FindMin(current->right)->value;
			current->value = min_value;
			current->right = DeleteNode(current->right, min_value);
			return current;
		}
		//Node** cur = &root;
		//while (*cur) {
		//	Node& node = **cur;
		//	if (key < node.value) {
		//		cur = &node.left;
		//	}
		//	else if (key > node.value) {
		//		cur = &node.right;
		//	}
		//	else {
		//		if (node.left == nullptr && node.right == nullptr) {
		//			*cur = nullptr;
		//			return true;
		//		} else if (node.left == nullptr || node.right == nullptr) {
		//			//while (*cur) {
		//			
		//				node = **cur;
		//				if (node.left != nullptr) {
		//					cur = &node.left;
		//					node = **cur;
		//					return true;
		//				}
		//				else if (node.right != nullptr) {
		//					cur = &node.right;
		//					node = **cur;
		//					return true;
		//				}
		//			//}
		//			//*cur = nullptr;
		//			//return true;
		//		}
		//		else {
		//			Node** node_to_delete = cur;
		//			cur = &node.right;
		//			node = **cur;
		//			if (node.left == nullptr) {
		//				while (node.left == nullptr) {
		//					node = **cur;
		//					cur = &node.right;
		//				}
		//			}
		//			cur = &node.left;
		//			node = **cur;
		//			while (node.right == nullptr) {
		//				node = **cur;
		//				cur = &node.left;
		//			}
		//			int tmp_key = node.value;
		//			cur = &node.right;
		//			node = **cur;
		//			cur = node_to_delete;
		//			node = **cur;
		//			node.value = tmp_key;
		//			return true;
		//		}
		//	}
		//}
		//return false;
	}

	Node* FindMin(Node* current) {
		if (current->left != nullptr)
			return FindMin(current->left);
		else
			return current;
	}

	void PreOrderTravesal(Node* current) {
		if (current != nullptr) {
			Action(current->value);
		}
		if (!current) {
			return;
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
	int node_to_delete;
	if (input.is_open()) {
		input >> node_to_delete;
		while (!input.eof()) {
			input >> temporary_value;
			tree.InsertNode(temporary_value);
		}
	}
	tree.Delete(node_to_delete);
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