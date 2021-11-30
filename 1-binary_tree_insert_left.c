#include "binary_trees.h"

/**
 * binary_tree_insert_left - creates a node in binary tree at insert in left
 * @parent: binary tree
 * @value: value
 * Return: new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree = 0;

	if (parent == 0)
		return (0);
	binary_tree = calloc(1, sizeof(binary_tree_t));
	if (binary_tree == 0)
		return (0);
	binary_tree->parent = parent;
	binary_tree->n = value;
	if (parent->left != 0)
	{
		binary_tree->left = parent->left;
		binary_tree->left->parent = binary_tree;
	}
	parent->left = binary_tree;
	return (binary_tree);
}
