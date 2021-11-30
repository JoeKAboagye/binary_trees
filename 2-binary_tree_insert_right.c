#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 *                            right-child of another node
 * @parent: binary tree
 * @value: value
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree = 0;

	if (parent == 0)
		return (0);
	binary_tree = calloc(1, sizeof(binary_tree_t));
	if (binary_tree == 0)
		return (0);
	binary_tree->parent = parent;
	binary_tree->n = value;
	if (parent->right != 0)
	{
		binary_tree->right = parent->right;
		binary_tree->right->parent = binary_tree;
	}
	parent->right = binary_tree;
	return (binary_tree);
}
