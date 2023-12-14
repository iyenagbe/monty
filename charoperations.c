#include "monty.h"

/**
  *s_nop- nothing
  *@fhead: stack fhead
  *@counter: line_number
  *Return: no return
 */
void s_nop(stack_t **fhead, unsigned int counter)
{
	(void) counter;
	(void) fhead;
}

/**
 * s_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_pchar(stack_t **fhead, unsigned int counter)
{
	stack_t *h;

	h = *fhead;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_rstack(*fhead);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * s_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_pstr(stack_t **fhead, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *fhead;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
  *s_rotl- rotates the stack to the top
  *@fhead: stack fhead
  *@counter: line_number
  *Return: no return
 */
void s_rotl(stack_t **fhead,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *fhead, *faux;

	if (*fhead == NULL || (*fhead)->next == NULL)
	{
		return;
	}
	faux = (*fhead)->next;
	faux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *fhead;
	(*fhead)->next = NULL;
	(*fhead)->prev = tmp;
	(*fhead) = faux;
}

/**
  *s_rotr- rotates the stack to the bottom
  *@fhead: stack fhead
  *@counter: line_number
  *Return: no return
 */
void s_rotr(stack_t **fhead, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *fhead;
	if (*fhead == NULL || (*fhead)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *fhead;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*fhead)->prev = copy;
	(*fhead) = copy;
}
