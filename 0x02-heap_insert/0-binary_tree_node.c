#include "binary_trees.h"

/**
 * binary_tree_node - Stores recursively each level in an array of strings
 *
 * @parent: Pointer to the parent node
 * @value: Value of the new node
 *
 * Return: Pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node = malloc(sizeof(binary_tree_t));
if (node)
{
node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;
return (node);
}
return (NULL);
}
