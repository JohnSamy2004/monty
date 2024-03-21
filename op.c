#include "monty.h"

/**
 * multiply_nd - muls top two elements of the stack.
 * @stack: pointer to pointer of node.
 * @lin_num: line number of of the opcode.
 */
void multiply_nd(stack_t **stack, unsigned int lin_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lin_num, "mul");

	(*stack) = (*stack)->next;
	tot = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modulus_nd - Adds the top two elements of the stack.
 * @stack: pointer to pointer of node.
 * @lin_num: line number of of the opcode.
 */
void modulus_nd(stack_t **stack, unsigned int lin_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lin_num, "mod");

	if ((*stack)->n == 0)
		more_err(9, lin_num);
	(*stack) = (*stack)->next;
	tot = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
