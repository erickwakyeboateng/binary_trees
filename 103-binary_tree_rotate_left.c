#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *_pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	_pivot = tree->right;
	tree->right = _pivot->left;
	if (_pivot->left != NULL)
	{
		_pivot->left->parent = tree;
	}
	_pivot->left = tree;
	_pivot->parent = tree->parent;
	tree->parent = _pivot;
	return (_pivot);
}
