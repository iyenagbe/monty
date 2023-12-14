#include "monty.h"

/**
* Rexec - executes the opcode
* @stack: fhead linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @fcontent: line fcontent
* Return: no return
*/
int Rexec(char *fcontent, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", s_push}, {"pall", s_pall}, {"pint", s_pint},
				{"pop", s_pop}, {"swap", s_swap}, {"add", s_add},
				{"sub", s_sub}, {"div", s_div}, {"mul", s_mul},
				{"mod", s_mod}, {"nop", s_nop}, {"pchar", s_pchar},
				{"pstr", s_pstr}, {"rotl", s_rotl}, {"rotr", s_rotr},
				{"queue", s_queue}, {"stack", s_stack}, {NULL, NULL}
				};
	unsigned int f = 0;
	char *fop;

	fop = strtok(fcontent, " \n\t");
	if (fop && fop[0] == '#')
		return (0);
	fuse.ag = strtok(NULL, " \n\t");
	while (opst[f].opcode && fop)
	{
		if (strcmp(fop, opst[f].opcode) == 0)
		{	opst[f].f(stack, counter);
			return (0);
		}
		f++;
	}
	if (fop && opst[f].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, fop);
		fclose(file);
		free(fcontent);
		free_rstack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
* free_rstack - frees a doubly linked list
* @fhead: fhead of the stack
*/
void free_rstack(stack_t *fhead)
{
	stack_t *faux;

	faux = fhead;
	while (fhead)
	{
		faux = fhead->next;
		free(fhead);
		fhead = faux;
	}
}
