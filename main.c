#include "monty.h"
stack_t *head = NULL;

/**
 * main - main function and the etry point
 * @argc: arguments counter
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openfile(argv[1]);
	freenodes();
	return (0);
}
