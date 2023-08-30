#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *_pivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	_pivot = tree->left;
	tree->left = _pivot->right;
	if (_pivot->right != NULL)
	{
		_pivot->right->parent = tree;
	}
	_pivot->right = tree;
	_pivot->parent = tree->parent;
	tree->parent = _pivot;
	return (_pivot);
}
