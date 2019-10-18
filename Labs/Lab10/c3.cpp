#include <cstddef>
#include <iostream>

class Node{
public:
	int value;
	Node* left;
	Node* right;

	Node(const int x) : value(x), left(NULL), right(NULL) {}
};

bool shape_match(Node* a, Node* b)
{
	if(a == NULL && b == NULL) return true;
	else if((a && !b) || (!a && b))
		return false;
	else
	{
		// compares to see if the left and right are both not NULL on either tree.
		return shape_match(a->left, b->left) && shape_match(a->right, b->right);
	}


}

Node* find_subtree_match(Node* a, Node* b)
{
	Node* t1 = a->right;
	Node* t2 = a->left;
	if(shape_match(t1, b))
		return t1;
	if(shape_match(t2, b))
		return t2;
	return a;
}

int main()
{
	Node* a = new Node(6);
	a->left = new Node(9);
	a->right = new Node(8);


	Node* b = new Node(6);
	b->left = new Node(9);
	b->right = new Node(8);
	b->left->right = new Node(1);
	b->left->left = new Node(1);



	if(shape_match(a,b))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << find_subtree_match(b,a)->value << std::endl;

}