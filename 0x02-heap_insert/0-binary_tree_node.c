#include "binary_trees.h"

/**
 * struct binary_tree_s - Binary tree node
 *
 * @value: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * return : Pointer to the right child node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
  binary_tree_t* node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
  node->n = value;
  node->left = NULL;
  node->right = NULL;
  return node;
  
}