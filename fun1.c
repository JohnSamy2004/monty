#include "monty.h"

/**
 * addtostack - Inserts a node into the stack.
 * @newnode: The link to the new node.
 * @line_number: The line number of the opcode is indicated by this number.
 */
void addtostack(stack_t **newnode, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	temp = head;
	head = *newnode;
	head->next = temp;
	temp->prev = head;
}


/**
 * printst - Inserts a node into the stack.
 * @stack: A reference to a reference that directs
 * to the topmost node in the stack..
 * @line_number: line number of the opcode.
 */
void printst(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	t = *stack;
	for (; t != NULL;)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * poptop - removes a node to the stack.
 * @stack: A pointer that directs to the top node of the stack.
 * @line_number: line number of the opcode
 */
void poptop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmpo = *stack;
	*stack = tmpo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmpo);
}

/**
 * printthetop - Displays the node at the top of the stack.
 * @stack: A pointer that directs to the top node of the stack.
 * @line_number: line number of the opcode.
 */
void printthetop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
