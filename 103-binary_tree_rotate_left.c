#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree.
* @tree: pointer to the root node of the tree to rotate.
* Return: pointer to the new root node of the tree once rotated.
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *temp_2 = NULL;

	if (tree == NULL)
		return (NULL);
	if (tree->right != NULL)
	{
		temp = tree;
		tree = tree->right;
		temp_2 = tree->left;
		tree->left = temp;
		tree->left->right = temp_2;
		if (tree->left->right != NULL)
			tree->left->right->parent = tree->left;
		tree->parent = temp->parent;
		tree->left->parent = tree;
		return (tree);
	}
	return (NULL);
}
