#pragma once
#include "Node.h"
#include <ostream>


class BST
{
private:
	Node* root;
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	bool find(Node* node, int data);
	void inOrder(Node* node, std::ostream& os);
	void preOrder(Node* node, std::ostream& os);
	void postOrder(Node* node, std::ostream& os);
	void destroy(Node*& node);
public:
	BST() : root(nullptr) {}
	~BST();
	bool insert(int data);
	bool remove(int data);
	bool find(int data);
	void inOrder(std::ostream& os);
	void preOrder(std::ostream& os);
	void postOrder(std::ostream& os);
};

