#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a bal tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t le_ft = 0;
	size_t ri_ght = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			le_ft = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			ri_ght = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((le_ft > ri_ght) ? le_ft : ri_ght);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int ri_ght = 0, le_ft = 0, _total = 0;

	if (tree)
	{
		le_ft = ((int)binary_tree_height_b(tree->le_ft));
		ri_ght = ((int)binary_tree_height_b(tree->ri_ght));
		_total = le_ft - ri_ght;
	}
	return (_total);
}
