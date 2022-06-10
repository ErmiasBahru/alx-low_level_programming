#include "lists.h"
/**
 * add_dnodeint_end - Add new node at the end of dlistint_t list
 * @head: The head of list
 * @n: The value of new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *lnode = *head;
	dlistint_t *nnode;

	nnode = malloc(sizeof(dlistint_t));
	if (nnode == NULL)
		return (NULL);

	nnode->n = n;
	nnode->next = NULL;

	if (*head == NULL)
	{
		nnode->prev = NULL;
		*head = nnode;
		return (nnode);
	}

	while (lnode->next)
		lnode = lnode->next;
	lnode->next = nnode;
	nnode->prev = lnode;

	return (nnode);
}
