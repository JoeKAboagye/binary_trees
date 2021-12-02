#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
* num_check - number check
* @tree: tree
* @n number of values
* @flag: 0 to compare left, 1 to compare right.
* Return: 0 or 1
*/
int num_check(const binary_tree_t *tree, int n, int flag)
{
	int i, j;

	if (!tree)
		return (1);
	if (flag)
	{
		if (tree->n > n)
		{
			i = num_check(tree->left, n, 1);
			j = num_check(tree->right, n, 1);
			if (i && j)
				return (1);
		}
	}
	else
		if (tree->n < n)
		{
			i = num_check(tree->left, n, 0);
			j = num_check(tree->right, n, 0);
			if (i && j)
				return (1);
		}
	return (0);
}

/**
* binary_tree_is_bst - helper
* @tree: tree to search
* Return: 1, success and 0 failure
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (num_check(tree->left, tree->n, 0) && num_check(tree->right, tree->n, 1))
		if (!tree->left || binary_tree_is_bst(tree->left))
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);

	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (binary_tree_is_bst(tree) && (binary_tree_is_complete(tree)));
}
