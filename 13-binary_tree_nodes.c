#include "binary_trees.h"
/**
 * binary_tree_nodes - function that returns # of nodes in a tree with children
 * @tree: tree to check
 * Return: number of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  no_de = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		no_de += ((tree->left || tree->right) ? 1 : 0);
		no_de += binary_tree_nodes(tree->left);
		no_de += binary_tree_nodes(tree->right);
		return (no_de);
	}
}
