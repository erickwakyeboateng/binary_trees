#include "binary_trees.h"
/**
 * binary_tree_leaves - function that returns the number of leaves in a tree
 * @tree: tree to check
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, le_ft = 0, ri_ght = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		le_ft = binary_tree_leaves(tree->left);
		ri_ght = binary_tree_leaves(tree->right);
		leaf = le_ft + ri_ght;
		return ((!le_ft && !ri_ght) ? leaf + 1 : leaf + 0);
	}
}
