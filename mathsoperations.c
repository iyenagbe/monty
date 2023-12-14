#include "monty.h"
/**
 * s_add - adds the top two elements of the stack.
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_add(stack_t **fhead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	faux = h->n + h->next->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}

/**
  *s_sub- sustration
  *@fhead: stack fhead
  *@counter: line_number
  *Return: no return
 */
void s_sub(stack_t **fhead, unsigned int counter)
{
	stack_t *faux;
	int sus, nodes;

	faux = *fhead;
	for (nodes = 0; faux != NULL; nodes++)
		faux = faux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	faux = *fhead;
	sus = faux->next->n - faux->n;
	faux->next->n = sus;
	*fhead = faux->next;
	free(faux);
}

/**
 * s_div - divides the top two elements of the stack.
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_div(stack_t **fhead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	faux = h->next->n / h->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}

/**
 * s_mul - multiplies the top two elements of the stack.
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_mul(stack_t **fhead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	faux = h->next->n * h->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}

/**
 * s_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_mod(stack_t **fhead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	faux = h->next->n % h->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}
