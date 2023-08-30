#include "binary_trees.h"
/**
 * array_to_bst - turns an array to a BST tree
 * @array: array to turns to BST tree
 * @size: size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *_root;
	size_t j = 0;

	_root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; j < size; j++)
	{
		if (j == 0)
		{
			bst_insert(&_root, array[j]);
		}
		else
		{
			bst_insert(&_root, array[j]);
		}
	}
	return (_root);
}
