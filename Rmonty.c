#include "monty.h"
fvar_t fuse = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @ac: number of arguments
* @av: monty file location
* Return: 0 on success
*/
int main(int ac, char *av[])
{
	char *fcontent;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	fuse.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		fcontent = NULL;
		read_line = getline(&fcontent, &size, file);
		fuse.fcontent = fcontent;
		counter++;
		if (read_line > 0)
		{
			Rexec(fcontent, &stack, counter, file);
		}
		free(fcontent);
	}
	free_rstack(stack);
	fclose(file);
return (0);
}
