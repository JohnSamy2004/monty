#include "monty.h"

/**
 * print_chr - Print Ascii value (aii).
 * @stack: Pointer to a pointer.
 * @ln_num: line number.
 */
void print_chr(stack_t **stack, unsigned int ln_num)
{
	int aii;

	if (stack == NULL || *stack == NULL)
		string_err(11, ln_num);

	aii = (*stack)->n;
	if (aii < 0 || aii > 127)
		string_err(10, ln_num);
	printf("%c\n", aii);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to a pointer.
 * @ln: line number.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int aii;
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmpo = *stack;
	while (tmpo != NULL)
	{
		aii = tmpo->n;
		if (aii <= 0 || aii > 127)
			break;
		printf("%c", aii);
		tmpo = tmpo->next;
	}
	printf("\n");
}

/**
 * rotm - Moves the initial point in the stack to the bottom.
 * @stack: Pointer to a pointer.
 * @ln: line number.
 */
void rotm(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;
	for (; tmpo->next != NULL;)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	(*stack)->prev = tmpo;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotp - Moves the initial point in the stack to the top.
 * @stack: Pointer to a pointer.
 * @ln: line number.
 */
void rotp(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;

	for (; tmpo->next != NULL;)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	tmpo->prev->next = NULL;
	tmpo->prev = NULL;
	(*stack)->prev = tmpo;
	(*stack) = tmpo;
}
