#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order traversal
 * @tree: root node of the tree to traverse
 * @func: pointer to a function to call for each node, for formatted printing
 *
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != 0 && func != 0)
	{
		if (tree->left != 0)
			binary_tree_postorder(tree->left, func);
		if (tree->right != 0)
			binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
