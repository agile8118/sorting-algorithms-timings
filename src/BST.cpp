#include "BST.h"

BST::BST()
{
  this->root = NULL;
}

// Insert a new item to the tree
void BST::insert(int value)
{

  Node *newNode = new Node(value);

  if (root == NULL)
  {
    this->root = newNode;
  }
  else
  {
    Node *current = this->root;

    while (true)
    {
      // Go to the left side
      if (value <= current->value)
      {
        if (current->left == NULL)
        {
          current->left = newNode;
          return;
        }
        else
        {
          current = current->left;
        }
      }

      // Go to the right side
      if (value > current->value)
      {
        if (current->right == NULL)
        {
          current->right = newNode;
          return;
        }
        else
        {
          current = current->right;
        }
      }
    }
  }
}

// Check to see if a given value is in the tree
bool BST::hasValue(int value)
{
  if (!root)
    return false;

  Node *current = root;
  bool found = false;

  while (!found && current)
  {
    // Value was found
    if (value == current->value)
    {
      found = true;
    }

    // Go to the left side
    if (value < current->value)
    {
      current = current->left;
    }

    // Go to the right side
    if (value > current->value)
    {
      current = current->right;
    }
  }

  return found;
}

void BST::traverseInOrder(Node *node)
{
  if (node->left)
    traverseInOrder(node->left);
  inOrderTraversedNumbers.push_back(node->value);
  if (node->right)
    traverseInOrder(node->right);
}

std::vector<int> BST::inOrder()
{
  traverseInOrder(this->root);
  return inOrderTraversedNumbers;
}