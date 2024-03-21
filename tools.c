#include "monty.h"

/**
 * openfile - opens any file
 * @file_name: the file namepath
 * Return: void
 */

void openfile(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file only
 * @fd: points to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parseline(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parseline - To determine which function to call,
 * each line is broken up into tokens
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buffer, int line_number, int format)
{
	char *op, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	op = strtok(buffer, delim);
	if (op == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find_function(op, val, line_number, format);
	return (format);
}

/**
 * find_function - discover the suitable function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *opcode, char *val, int ln, int format)
{
	int n;
	int flag_int;

	instruction_t function_list[] = {
		{"push", addtostack},
		{"pall", printst},
		{"pint", printthetop},
		{"pop", poptop},
		{"nop", nothing_op},
		{"swap", swapnodes},
		{"add", addnodes},
		{"sub", subnodes},
		{"div", divnodes},
		{"mul", multiply_nd},
		{"mod", modulus_nd},
		{"pchar", print_chr},
		{"pstr", print_string},
		{"rotl", rotm},
		{"rotr", rotp},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag_int = 1, n = 0; function_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, function_list[n].opcode) == 0)
		{
			call_func(function_list[n].f, opcode, val, ln, format);
			flag_int = 0;
		}
	}
	if (flag_int == 1)
		err(3, ln, opcode);
}


/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_err(5, ln);
		}
		node = cr_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			addnodequeue(&node, ln);
	}
	else
		func(&head, ln);
}
