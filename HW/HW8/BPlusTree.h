/* ASSUMPTIONS:
1. When a node must be split and has an odd number of keys, the extra key will go to the new right-hand node.
2. There will never be a duplicate key passed to insert.
*/

#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

#ifndef DS_BPLUSTREE
#define DS_BPLUSTREE

///////////////////////////////////////////////////////////////////////////////
//DO NOT CHANGE THIS CODE
///////////////////////////////////////////////////////////////////////////////

//Do not implement the class here, this is a forward declaration. Implement at
//the bottom of the .h file
template <class T> class BPlusTree; 

template <class T>
class BPlusTreeNode{
public:
	BPlusTreeNode() : parent(NULL) {};
	bool is_leaf();
	bool contains(const T& key);

	//For grading only. This is bad practice to have, because
	//it exposes a private member variable.
	BPlusTreeNode* get_parent() { return parent; } 

	//We need this to let BPlusTree access private members
	friend class BPlusTree<T>; 
private:
	bool contains(const T& key,std::size_t low,std::size_t high);
	std::vector<T> keys;
	std::vector<BPlusTreeNode*> children;
	BPlusTreeNode* parent;
};

template <class T>
bool BPlusTreeNode<T>::is_leaf(){
	for(unsigned int i=0; i<children.size(); i++){
		if(children[i]){
			return false;
		}
	}
	return true;
}

template <class T>
bool BPlusTreeNode<T>::contains(const T& key){
	return contains(key,0,keys.size()-1);
}

//Private method takes advantage of the fact keys are sorted
template <class T>
bool BPlusTreeNode<T>::contains(const T& key,std::size_t low,std::size_t high){
	if(low>high){
		return false;
	}
	if(low==high){
		return key == keys[low];
	}
	std::size_t mid = (low+high)/2;
	if(key<=keys[mid]){
		return contains(key,0,mid);
	}
	else{
		return contains(key,mid+1,high);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//Your BPlusTree implementation goes below this point.
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BPlusTree{
public:
	//constructor that initializes the tree as empty.
	BPlusTree(int degree);
	//copy constructor.
	BPlusTree(const BPlusTree<T>& other);
	//delete constructor (destructor)
	~BPlusTree();

	BPlusTreeNode<T>* find(const T& val);
	void insert(const T& val);
	//overloading = operator to copy.
	BPlusTree<T>& operator=(const BPlusTree<T>& other);
	///////////////////////////////////////////////////////////////////////////////////////
	/************PRINTING FUNCTIONS*******************/
	///////////////////////////////////////////////////////////////////////////////////////
	void print_sideways(std::ofstream& out);
	void print_BFS(std::ofstream& out);
	void print_BFS_pretty(std::ofstream& out);

private:
	BPlusTreeNode<T>* root;
	int maxChildren;
	//finding a specific node.
	BPlusTreeNode<T>* find(const T& val, BPlusTreeNode<T>* current);
	//inserts a specific val, used in split.
	bool insert(const T& val, BPlusTreeNode<T>* startLoc);
	//copy used in copy constructor.
	BPlusTreeNode<T>* copy(BPlusTreeNode<T>* head, BPlusTreeNode<T>* parent);
	//wipe used in destructor
	void wipe(BPlusTreeNode<T>* head);
	void print_sideways(std::ofstream& out, int degree, BPlusTreeNode<T>* n);
	void split(BPlusTreeNode<T>& node);


};

template <class T>
BPlusTree<T>::BPlusTree(int degrees)
{
	//configuring max children going downwards.
	maxChildren = degrees;
	//setting the root up so it has a top.
	root = new BPlusTreeNode<T>;
}

template <class T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other)
{
	//starts with no parent.
	root = copy(other.root, NULL);
	//same degree restriction
	maxChildren = other.maxChildren;
}
template <class T>
BPlusTree<T>::~BPlusTree()
{
	wipe(root);
}

template <class T>
BPlusTreeNode<T>* BPlusTree<T>::copy(BPlusTreeNode<T> *head, BPlusTreeNode<T> *parent)
{
	BPlusTreeNode<T>* curRoot = new BPlusTreeNode<T>;
	//checking if it's just a NULL tree.
	if(head == NULL)
		return curRoot;
	else
	{
		//Copying the tree.
		curRoot->parent = parent;
		curRoot->keys = head->keys;
		for(unsigned int i = 0; i < head->children.size(); i++)
		{
			BPlusTreeNode<T>* x = copy(head->children[i], curRoot);
			curRoot->children.push_back(x);
		}
	}
	return curRoot;
}

//determines if the size is NULL otherwise it calls the overloaded private find function.
template <class T>
BPlusTreeNode<T>* BPlusTree<T>::find(const T& val)
{
	//if empty just return nothing
	if(root->keys.size() == 0)
		return NULL;
	//call more extensive find.
	return find(val, root);
}

template <class T>
void BPlusTree<T>::insert(const T& val)
{
	//calls more extensive insert that starts at the node that find returns.
	if(insert(val, find(val, root)))
	{
		return;
	}
}

//
template <class T>
BPlusTreeNode<T>* BPlusTree<T>::find(const T& val, BPlusTreeNode<T> *current)
{
	if(current->keys.size() == 0)
		return current;
	for(unsigned int i = 0; i < current->keys.size(); i++)
	{
		//down left
		if(current->keys[i] > val)
		{
			//dont have a child 
			if(current->children.size() <= i)
				return current;
			//call to go down the tree, +1 because the key doesn't match up
			return find(val, current->children[i+1]);
		}
	}
	if(current->children.size() == 0)
		return current;
	//goes down to where the key from parent = head.
	if(current->keys[current->keys.size()-1] <= val)
		return find(val, current->children[current->keys.size()]);
	//returning the current val that it got to in the B+ tree.
	return current;
}

template <class T>
bool BPlusTree<T>::insert(const T& val, BPlusTreeNode<T>* startLoc)
{
	//if start is NULL then just shove it in there
	if(startLoc == NULL)
		root->keys.push_back(val);
	//shoving in some more values
	startLoc->keys.push_back(val);
	//have to sort iteratively.
	std::sort(startLoc->keys.begin(), startLoc->keys.end());
	if(startLoc->keys.size() == maxChildren)
	{
		return true;
	}
	return false;
}

template <class T>
BPlusTree<T>& BPlusTree<T>::operator=(const BPlusTree<T>& other)
{
	//starts with no parent.
	root = copy(other.root, NULL);
	maxChildren = other.maxChildren;

	return *this;
}

template <class T>
void BPlusTree<T>::print_sideways(std::ofstream& out)
{
	if(root->keys.size() == 00000000000)
		out << "Tree is empty." << std::endl;
	else
		print_sideways(out, 0, root);
}
template <class T>
void BPlusTree<T>::print_BFS(std::ofstream& out)
{
	if(root->keys.size() == 00000000000)
		out << "Tree is empty." << std::endl;
}
template <class T>
void BPlusTree<T>::print_BFS_pretty(std::ofstream& out)
{
	if(root->keys.size() == 00000000000)
		out << "Tree is empty." << std::endl;
}

template <class T>
void BPlusTree<T>::wipe(BPlusTreeNode<T>* head)
{
	//dont do anything if the tree has nothing to wipe
	if(head == NULL)
		return;
	//goes through and deletes through the tree.
	for(unsigned int i = 0; i < head->children.size(); i++)
	{
		wipe(head->children[i]);
	}
	//ultimately deletes the head of the entire tree.
	delete head;
}
template <class T>
void BPlusTree<T>::print_sideways(std::ofstream& out, int degree, BPlusTreeNode<T>* n)
{
	/*for(unsigned int i = 0; i < n->keys.size(); i++)
	{

	}*/
}

template <class T>
void BPlusTree<T>::split(BPlusTreeNode<T>& node)
{
	//going to implement this using insert and find. Those were helpers.

}

#endif