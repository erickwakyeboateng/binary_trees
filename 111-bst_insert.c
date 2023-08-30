#include "binary_trees.h"
/**
 * bst_insert - insert nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *_new, *_temp;
	binary_tree_t *_aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		_aux = binary_tree_node((binary_tree_t *)(*tree), value);
		_new = (bst_t *)_aux;
		*tree = _new;
	}
	else
	{
		_temp = *tree;
		if (value < _temp->n)
		{
			if (_temp->left)
				_new = bst_insert(&_temp->left, value);
			else
			{
				_aux = binary_tree_node((binary_tree_t *)_temp, value);
				_new = _temp->left = (bst_t *)_aux;
			}
		}
		else if (value > _temp->n)
		{
			if (_temp->right)
				_new = bst_insert(&_temp->right, value);
			else
			{
				_aux = binary_tree_node((binary_tree_t *)_temp, value);
				_new = _temp->right = _aux;
			}
		}
		else
			return (NULL);
	}
	return (_new);
}
