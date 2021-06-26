#include "binary_trees.h"

/**
 * heap_insert - Function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: a pointer to the new node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	if (!root)
		return (NULL);

	parent = insert_child(*root);
	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent == NULL)
		*root = new;

	else if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	node_swap(&new);

	return (new);
}

/**
 * insert_child - Function to find the parent to insert the child
 * @root: double pointer to the root
 * Return: Pointer to the parent
*/
heap_t *insert_child(heap_t *root)
{
	heap_t *parent;
	int left_count, right_count, left_perfect, right_perfect;

	if (root == NULL)
		return (NULL);

	parent = root;
	left_count = count_node(parent->left);
	right_count = count_node(parent->right);
	left_perfect = is_perfect(parent->left);
	right_perfect = is_perfect(parent->right);

	if (left_count < 1 || right_count < 1)
		return (parent);

	if (left_perfect < 1 || (left_perfect
		&& right_perfect && left_count == right_count))

		return (insert_child(parent->left));

	else if (right_perfect < 1 || (left_perfect
		&& right_perfect && left_count > right_count))

		return (insert_child(parent->right));

	return (parent);
}

/**
 * count_node - Function that count the nodes in the binary tree
 * @root: double pointer to the root
 * Return: number of nodes
*/
int count_node(heap_t *root)
{
	int l;

	if (root == NULL)
		return (0);

	if (root)
		l = 1;

	l += count_node(root->left);
	l += count_node(root->right);

	return (l);
}

/**
 * node_swap - Swaps current node with larger node
 * @node: Pointer to current node
 * Return: A new node
 */
void node_swap(heap_t **node)
{
	heap_t *current;
	int vaux;

	current = *node;

	while (current->parent != NULL)
	{
		if (current->parent->n < current->n)
		{
			vaux = current->parent->n;
			current->parent->n = current->n;
			current->n = vaux;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * is_perfect - Function to check if a tree is perfect
 * @root: pointer to the root
 * Return: 1 for true, otherwhise 0
*/
int is_perfect(const heap_t *root)
{
	int l, r;

	if (root == NULL)
		return (0);

	l = count_node(root->left);
	r = count_node(root->right);

	if (l == r)
		return (1);

	return (0);
}