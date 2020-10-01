#include "Node.h"

int Node::degree() const
{
    if (this->left == nullptr && this->right == nullptr) { return 0; }
    else if (this->left != nullptr && this->right != nullptr) { return 2; }
    else { return 1; }
}
