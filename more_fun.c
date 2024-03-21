#include "monty.h"

/**
 * cr_node - Creates a node.
 * @n: Number.
 * Return: Upon success a pointer to the node. Otherwise NULL.
 */
stack_t *cr_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freenodes - Frees nodes.
 */
void freenodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	for (; head != NULL;)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addnodequeue - Adds a node to the queue only.
 * @newnode: double pointer to new node.
 * @line_number: line number.
 */
void addnodequeue(stack_t **newnode, __attribute__((unused))unsigned int line_number)
{
	stack_t *tempo;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	tempo = head;
	for (; tempo->next != NULL;)
		tempo = tempo->next;

	tempo->next = *newnode;
	(*newnode)->prev = tempo;

}
