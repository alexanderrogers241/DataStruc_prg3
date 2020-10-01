#pragma once
#include <string>
#include <vector>

class Node_user
{

public:
	std::string data;
	std::vector<int> u_tickets;
	Node_user* left;
	Node_user* right;
	int degree() const; // one or two nodes

	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
};