#include "binary_trees.h"

/**
* num_check - checks the number of values in the tree
* @tree: the tree to check
* @n: number of values in the tree
* @flag: 0 to compare left, 1 to compare right.
* Return: 1 if true, 0 if false
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
 * binary_tree_is_bst - wrapper function for tree_is_bst
 * @tree: tree to be checked
 *
 * Return: 1 for true, 0 for false
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
