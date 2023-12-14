#include "monty.h"

/**
 * s_push - add node to the stack
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_push(stack_t **fhead, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (fuse.ag)
	{
		if (fuse.ag[0] == '-')
			j++;
		for (; fuse.ag[j] != '\0'; j++)
			if (fuse.ag[j] > 57 || fuse.ag[j] < 48)
				flag = 1;
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(fuse.file);
			free(fuse.fcontent);
			free_rstack(*fhead);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	n = atoi(fuse.ag);

	if (fuse.fque == 0)
		faddnode(fhead, n);
	else
		faddqueue(fhead, n);
}

/**
 * s_pall - prints the stack
 * @fhead: stack fhead
 * @counter: no used
 * Return: no return
*/
void s_pall(stack_t **fhead, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *fhead;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * s_pint - prints the top
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_pint(stack_t **fhead, unsigned int counter)
{
	if (*fhead == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*fhead)->n);
}

/**
 * s_pop - prints the top
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_pop(stack_t **fhead, unsigned int counter)
{
	stack_t *h;

	if (*fhead == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	*fhead = h->next;
	free(h);
}

/**
 * s_swap - adds the top two elements of the stack.
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_swap(stack_t **fhead, unsigned int counter)
{
	stack_t *h;
	int len = 0, faux;

	h = *fhead;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	faux = h->n;
	h->n = h->next->n;
	h->next->n = faux;
}
