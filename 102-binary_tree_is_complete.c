#include "binary_trees.h"
/**
 * new_node - Function that creates a new_node in a linked_list
 * @node: Type pointer of node to be created
 * Return: the node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new_;

	new_ =  malloc(sizeof(link_t));
	if (new_ == NULL)
	{
		return (NULL);
	}
	new_->node = node;
	new_->next = NULL;

	return (new_);
}
/**
 * free_q - Function that free the nodes at the linked list
 * @head: Node of the linked_list
 */
void free_q(link_t *head)
{
	link_t *_tempnode;

	while (head)
	{
		_tempnode = head->next;
		free(head);
		head = _tempnode;
	}
}
/**
 * _push - Function that pushes a node into the stack
 * @node: Type pointer of node of the tree
 * @head: Type head node of in the stack
 * @tail: Type tail node of in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new_;

	new_ = new_node(node);
	if (new_ == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = new_;
	*tail = new_;
}
/**
 * _pop - Function that pops a node into the stack
 * @head: Type head node of in the stack
 */
void _pop(link_t **head)
{
	link_t *_tempnode;

	_tempnode = (*head)->next;
	free(*head);
	*head = _tempnode;
}
/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Type pointer of node of the tree
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *_head, *_tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	_head = _tail = new_node((binary_tree_t *)tree);
	if (_head == NULL)
	{
		exit(1);
	}
	while (_head != NULL)
	{
		if (_head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(_head);
				return (0);
			}
			_push(_head->node->left, _head, &_tail);
		}
		else
			flag = 1;
		if (_head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(_head);
				return (0);
			}
			_push(_head->node->right, _head, &_tail);
		}
		else
			flag = 1;
		_pop(&_head);
	}
	return (1);
}
