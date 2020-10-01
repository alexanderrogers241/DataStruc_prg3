#include "BST.h"
// From class notes on BST
bool BST::insert(Node*& node, int data)
{
    if (node == nullptr) { // IF EMPTY POINTER
        node = new Node(data); // constructor
        return true;
    }
    if (data < node->data) // If data is less than data in referenced node pointer
        return insert(node->left, data); // recursive call to left child. Constructes a new node
    if (data > node->data)
        return insert(node->right, data); // recursive call to right child. Constructes a new node
    return false;
}

bool BST::remove(Node*& node, int data)
{
    if (node == nullptr) // if empty. Not existing. No need to delete
        return false;
    if (data < node->data) // if data is less than current nodes data look left
        return remove(node->left, data);
    if (data > node->data) // if data is less than current nodes data look right
        return remove(node->right, data); // recursive call
    
    int deg = node->degree(); // get degree of node 0-2
    if (deg == 0) // no childen 
    {
        delete node;
        node = nullptr;
    }
    else if (deg == 1) // one child node
    {
        Node* tmp = node; // dupicate pointer to current node
        if (node->left != nullptr) {
            node = node->left; // overwrites node pointer to left child
        }
        else {
            node = node->right; // overwrites node pointer to right child
        }
        delete tmp; // deletes the parent
    }
    else // two child nodes
    {
        Node* tmp = node->left; // go left than right
        while (tmp->right != nullptr) // returns the last right node
        {
            tmp = tmp->right;
        }
        node->data = tmp->data; // overwrites current node by copiing last right node's data 
        remove(node->left, tmp->data); // removes the copied data from the original left than right node
    }
    return true;
}

// FROM ZYBOOK example
bool BST::find(Node* node, int key)
{
    if (node == nullptr) // if empty. Not existing. No need to delete
        return false;
    if (key < node->data) // if data is less than current nodes data look left
        return find(node->left, key);
    if (key > node->data) // if data is less than current nodes data look right
        return find(node->right, key); // recursive call
    if (key == node->data)
        return true;
}



void BST::inOrder(Node* node, std::ostream& os) // LEFT NODE RIGHT
{
    if (node == nullptr) return;
    
    postOrder(node->left, os);
    os << node->data << " ";
    postOrder(node->right, os);
    
}

void BST::preOrder(Node* node, std::ostream& os) //  NODE LEFT RIGHT 
{

    if (node == nullptr) return;

    os << node->data << " ";
    postOrder(node->left, os);
    postOrder(node->right, os);
}

void BST::postOrder(Node* node, std::ostream& os) //  LEFT RIGHT NODE
{
    if (node == nullptr) return;
    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}


void BST::destroy(Node*& node)  // LEFT RIGHT NODE
{
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = nullptr;
}


BST::~BST()
{
    BST::destroy(root);
}


bool BST::insert(int data)
{
    return insert(root, data);
}


bool BST::remove(int data)
{
    return remove(root, data);
}


bool BST::find(int data)
{
    return find(root, data);
}


void BST::inOrder(std::ostream& os)
{
    return inOrder(root, os);
}


void BST::preOrder(std::ostream& os)
{
    return preOrder(root, os);
}


void BST::postOrder(std::ostream& os)
{
    return postOrder(root, os);
}
