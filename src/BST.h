#ifndef BST_h
#define BST_h

#include <vector>

struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
  }
};

class BST
{
public:
  Node *root;
  std::vector<int> inOrderTraversedNumbers;

  BST();

  // Insert a new item to the tree
  void insert(int value);
  // Check to see if a given value is in the tree
  bool hasValue(int value);
  void traverseInOrder(Node *node);
  std::vector<int> inOrder();
};

#endif /* BST_h */
