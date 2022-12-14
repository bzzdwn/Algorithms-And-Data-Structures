#include <iostream>
#include <fstream>
#include <vector>
struct Node {
	Node(const int& x) : value(x), leaves(1), height(0), semipath(0), b(0), max_semipath_length(0), semipath_counter(0) {
	}
	Node* left = nullptr;
	Node* right = nullptr;
	int value;
	int height;
	int semipath;
	int leaves;
	int b;
	int a;
	int c;
	int semipath_counter;
	int max_semipath_length;
	int h_;
	int l_;
};

class BSTree {
public:
	BSTree() : root(0), counter(0) {
	}

	void InsertNode(const int& x) {
		Node** current = &root;
		while (*current) {
			Node& node = **current;
			if (x < node.value) {
				current = &node.left;
			}
			else if (x > node.value) {
				current = &node.right;
			}
			else {
				return;
			}
		}
		*current = new Node(x);
		size++;
	}

	void FirstStep() {
		counter = 0;
		PastOrderTravesal(root);
	}
	void OutTree() {
		PreOrderOutTravesal(root);
	}

	void SecondStep() {
		PreOrderTraversal(root);
	}

	void ThirdStep() {
		InOrderTraversal(root);
	}
	void Delete() {
		root = DeleteNode(root, node_to_delete);
	}

	std::vector<int> vec;

private:

	void PastOrderTravesal(Node* current) {
		if (current != nullptr) {
			PastOrderTravesal(current->left);
			PastOrderTravesal(current->right);
			FirstAction(current);
		}
	}

	void FirstAction(Node* current) {
		if (current->left == nullptr && current->right == nullptr)
			counter = 0;
		else if (current->left != nullptr && current->right != nullptr && current->left->height > current->right->height)
			counter = current->left->height + 1;
		else if (current->left != nullptr && current->right != nullptr && current->left->height < current->right->height)
			counter = current->right->height + 1;
		current->height = counter;

		if (current->left != nullptr && current->right != nullptr) {
			current->semipath = current->left->height + current->right->height + 2;
			if (current->left->height == current->right->height)
				current->leaves = current->left->leaves + current->right->leaves;
			if (current->left->height > current->right->height)
				current->leaves = current->left->leaves;
			if (current->left->height < current->right->height)
				current->leaves = current->right->leaves;
		}

		else if (current->left != nullptr && current->right == nullptr) {
			current->semipath = current->left->height + 1;
			current->leaves = current->left->leaves;
		}

		else if (current->left == nullptr && current->right != nullptr) {
			current->semipath = current->right->height + 1;
			current->leaves = current->right->leaves;
		}

		if (current->semipath > max_semipath)
			max_semipath = current->semipath;
		counter++;
	}


	void PreOrderTraversal(Node* current) {
		if (current != nullptr) {
			SecondAction(current);
			ThirdAction(current);
			PreOrderTraversal(current->left);
			PreOrderTraversal(current->right);
			
		}
	}

	void InOrderTraversal(Node* current) {
		if (current != nullptr) {
			InOrderTraversal(current->right);
			FourthAction(current);
			InOrderTraversal(current->left);

		}
	}

	//void ThirdAction(Node* current) {
	//	if (current == root) {
	//		current->a = 0;
	//	}
	//	if (current->right == nullptr && current->left != nullptr) {
	//		current->left->a = current->a + current->b;
	//	}
	//	else if (current->left == nullptr && current->right != nullptr) {
	//		current->right->a = current->a + current->b;
	//	}
	//	else if (current->left != nullptr && current->left != nullptr) {
	//		if (current->left->height > current->right->height) {
	//			current->left->a = current->a + current->b;
	//			current->right->a = current->b;
	//		}
	//		else if (current->left->height < current->right->height) {
	//			current->right->a = current->a + current->b;
	//			current->left->a = current->b;
	//		}
	//		else {
	//			current->left->a = current->b + current->left->leaves * (current->a / current->leaves);
	//			current->right->a = current->b + current->right->leaves * (current->a / current->leaves);
	//		}
	//	}
	//	current->c = current->a + current->b;
	//	if (current->c > max_semipaths_number)
	//		max_semipaths_number = current->c;
	//}

	void ThirdAction(Node* current) {
		if (current == root) {
			current->h_ = 0;
			current->l_ = 1;
			current->a = 0;
		}
			if (current->right == nullptr && current->left != nullptr) {
				current->left->h_ = current->h_ + 1;
				current->left->l_ = current->l_;
			}
			else if (current->left == nullptr && current->right != nullptr) {
				current->right->h_ = current->h_ + 1;
				current->right->l_ = current->l_;
			}
			else if (current->left != nullptr && current->left != nullptr) {
				if (current->h_ == current->left->height + 1) {
					current->right->h_ = current->left->height + 2;
					current->right->l_ = current->l_ + current->left->leaves;
				}
				else if (current->h_ < current->left->height + 1) {
					current->right->h_ = current->left->height + 2;
					current->right->l_ = current->left->leaves;
				}
				else if (current->h_ > current->left->height + 1) {
					current->right->h_ = current->h_ + 1;
					current->right->l_ = current->l_;
				}
				if (current->h_ == current->right->height + 1) {
					current->left->h_ = current->right->height + 2;
					current->left->l_ = current->l_ + current->right->leaves;
				}
				else if (current->h_ < current->right->height + 1) {
					current->left->h_ = current->right->height + 2;
					current->left->l_ = current->right->leaves;
				}
				else if (current->h_ > current->right->height + 1) {
					current->left->h_ = current->h_ + 1;
					current->left->l_ = current->l_;
				}
			}
			if (current != root && current->h_ + current->height == max_semipath) {
				current->a = current->l_ * current->leaves;
			}
			else
				current->a = 0;
		current->c = current->a + current->b;
		if (current->c > max_semipaths_number)
			max_semipaths_number = current->c;
	}

	void SecondAction(Node* current) {
		if (current->semipath == max_semipath) {
			if (current->left != nullptr && current->right == nullptr)
				current->b = current->left->leaves;
			else if(current->right != nullptr && current->left == nullptr)
				current->b = current->right->leaves;
			else if (current->left != nullptr && current->right != nullptr)
				current->b = current->right->leaves * current->left->leaves;
			else current->b = 1;
		}

	}

	void FourthAction(Node* current) {
		if (current->c != 0 && current->c % 2 == 0)
			node_to_delete = current->value;
	}

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
	}

	Node* FindMin(Node* current) {
		if (current->left != nullptr)
			return FindMin(current->left);
		else
			return current;
	}


	void PreOrderOutTravesal(Node* current) {
		if (current != nullptr) {
			vec.push_back(current->value);
			PreOrderOutTravesal(current->left);
			PreOrderOutTravesal(current->right);
		}
	}


	int size = 0;
	int max_semipaths_number = 0;
	int max_semipath = 0;
	int counter;
	Node* root = nullptr;
	int node_to_delete = INT_MIN;
};

int main() {
	BSTree tree;
	std::ifstream input;
	int temporary_value;
	input.open("tst.in");
	if (input.is_open()) {
		while (!input.eof()) {
			input >> temporary_value;
			tree.InsertNode(temporary_value);
		}
	}
	tree.FirstStep();
	tree.SecondStep();
	tree.ThirdStep();
	tree.Delete();
	tree.OutTree();
	std::ofstream output;
	output.open("tst.out");
	for (size_t i = 0; i < tree.vec.size(); i++)
	{
		output << tree.vec[i] << "\n";
	}
	output.close();
}