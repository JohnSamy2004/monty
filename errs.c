#include "monty.h"

/**
 * string_err - handles errors.
 * @err_c: Here are the error codes.
 * (10) ~> ASCII limits cannot be met for the number inside a node.
 * (11) ~> There is no item in the stack.
 */
void string_err(int err_c, ...)
{
	va_list ag;
	int res_sum;

	va_start(ag, err_c);
	res_sum = va_arg(ag, int);
	switch (err_c)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", res_sum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", res_sum);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_err - Prints error messages that match the error code.
 * @err_c: Here are the error codes.
 * (1) => The program requires only one file from the user.
 * (2) => The file provided cannot be opened or read.
 * (3) => The instruction provided is not valid.
 * (4) => If the program cannot allocate more memory.
 * (5) => If the parameter given to the 'push' instruction is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When the stack is insufficient for operation.
 */
void err_err(int err_c, ...)
{
	va_list ag;
	char *op_c_op;
	int res_sum;

	va_start(ag, err_c);
	switch (err_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			res_sum = va_arg(ag, int);
			op_c_op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", res_sum, op_c_op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err_c - handles errors.
 * @err_c: Here are the error codes.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When the stack is insufficient for operation.
 * (9) => Division by zero.
 */
void more_err_c(int err_c, ...)
{
	va_list ag;
	char *op_c_op;
	int res_sum;

	va_start(ag, err_c);
	switch (err_c)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			res_sum = va_arg(ag, unsigned int);
			op_c_op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", res_sum, op_c_op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
