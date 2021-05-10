#include "binary_trees.h"

/**
 * heap_insert - Stores recursively each level in an array of strings
 *
 * @root: Pointer to the root node
 * @value: Value of the new node
 *
 * Return: Pointer to the new node
 */

heap_t *heap_insert(heap_t **root, int value)
{

    if (*root == NULL)
    {
        *root = binary_tree_node(*root, value);
        return *root;
    }
    else
    {
        if (value < (*root)->n) {
            heap_insert(&(*root)->left, value);
        } else {
            heap_insert(&(*root)->right, value);
        }
    }
    return (NULL);
}