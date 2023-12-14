#include "monty.h"
/**
 * faddnode - add node to the fhead stack
 * @fhead: fhead of the stack
 * @n: new_value
 * Return: no return
*/
void faddnode(stack_t **fhead, int n)
{

	stack_t *new_node, *faux;

	faux = *fhead;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (faux)
		faux->prev = new_node;
	new_node->n = n;
	new_node->next = *fhead;
	new_node->prev = NULL;
	*fhead = new_node;
}

/**
 * s_stack - prints the top
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_stack(stack_t **fhead, unsigned int counter)
{
	(void)fhead;
	(void)counter;
	fuse.fque = 0;
}

/**
 * s_queue - prints the top
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_queue(stack_t **fhead, unsigned int counter)
{
	(void)fhead;
	(void)counter;
	fuse.fque = 1;
}

/**
 * faddqueue - add node to the tail stack
 * @n: new_value
 * @fhead: fhead of the stack
 * Return: no return
*/
void faddqueue(stack_t **fhead, int n)
{
	stack_t *new_node, *faux;

	faux = *fhead;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (faux)
	{
		while (faux->next)
			faux = faux->next;
	}
	if (!faux)
	{
		*fhead = new_node;
		new_node->prev = NULL;
	}
	else
	{
		faux->next = new_node;
		new_node->prev = faux;
	}
}
