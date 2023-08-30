#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t k, l = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (k = 0; k < size; k++)
	{
		for (l = 0; l < k; l++)
		{
			if (array[l] == array[k])
				break;
		}
		if (l == k)
		{
			if (avl_insert(&root, array[k]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
