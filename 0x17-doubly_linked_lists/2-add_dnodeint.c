#include "lists.h"
/**
 * add_dnodeint - Add a new node at the beginning of dlistint_t list
 * @head: The head of list
 * @n:the value of the new node
 * Return: The address of the new node, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nnode;

	nnode = malloc(sizeof(dlistint_t));
	if (nnode == NULL)
		return (NULL);
	nnode->n = n;
	nnode->next = *head;
	nnode->prev = NULL;
	if (*head)
		(*head)->prev = nnode;
	*head = nnode;
	return (nnode);
}
