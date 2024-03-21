#include "header.h"

/**
 * swapnodes - Alters the positioning of
 * the top two elements in the stack.
 * @stack: A pointer that directs to the topmost point in the stack.
 * @l_n: The line number of of the opcode.
 */
void swapnodes(stack_t **stack, unsigned int l_n)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_n, "swap");
	tmpo = (*stack)->next;
	(*stack)->next = tmpo->next;
	if (tmpo->next != NULL)
		tmpo->next->prev = *stack;
	tmpo->next = *stack;
	(*stack)->prev = tmpo;
	tmpo->prev = NULL;
	*stack = tmpo;
}

/**
 * addnodes - Adds the top two elements of the stack.
 * @stack: A pointer that directs to the topmost point in the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void addnodes(stack_t **stack, unsigned int l_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_n, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subnodes - subs the top two elements of the stack.
 * @stack: A pointer that directs to the topmost point in the stack.
 * @l_n: line number of of the opcode.
 */
void subnodes(stack_t **stack, unsigned int l_n)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_n, "sub");

	(*stack) = (*stack)->next;
	res = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nothing_op - Doesn't anything.
 * @stack: A pointer that directs to the topmost point in the stack.
 * @l_n: The line number of of the opcode.
 */
void nothing_op(stack_t **stack, unsigned int l_n)
{
	(void)stack;
	(void)l_n;
}

/**
 * divnodes - divides the top two elements of the stack.
 * @stack: A pointer that directs to the topmost point in the stack.
 * @l_n: representing the line number of of the opcode.
 */
void divnodes(stack_t **stack, unsigned int l_n)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_n, "div");

	if ((*stack)->n == 0)
		more_err(9, l_n);
	(*stack) = (*stack)->next;
	res = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
