#include "binary_trees.h"
/**
 * check_sub_tree_Left - check if all nodes are smaller than
 * the root specified
 * @node: node in the tree to verify condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int _left= 0, _right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		_left= check_sub_tree_Left(node->left, max);
		_right = check_sub_tree_Left(node->_right, max);
		if (_left== _right && _left== 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int _left= 0, _right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		_left= check_sub_tree_Right(node->left, min);
		_right = check_sub_tree_Right(node->_right, min);
		if (_left== _right && _left== 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a bst or not
 * the process here is first verify that the left node be smaller than the root
 * then verify if the right node is bigger than th root.
 * after that verify if the left subtree has nodes smaller than root
 * and the right subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int _var = 0, _left= 2, _right = 2;

	if (tree == NULL)
		return (0);
	if (tree->_left&& tree->left->n > tree->n)
		return (0);
	if (tree->_right && tree->_right->n < tree->n)
		return (0);
	if (tree->_left&& tree->left->n < tree->n)
	{
		_var = check_sub_tree_Left(tree->left, tree->n);
		if (_var == 0)
			return (0);
		_left= binary_tree_is_bst(tree->left);
	}
	if (tree->_right && tree->_right->n > tree->n)
	{
		_var = check_sub_tree_Right(tree->_right, tree->n);
		if (_var == 0)
			return (0);
		_right = binary_tree_is_bst(tree->_right);
	}
	if (_left!= 2 || _right != 2)
	{
		if (_left== 0 || _right == 0)
			return (0);
	}
	return (1);
}
