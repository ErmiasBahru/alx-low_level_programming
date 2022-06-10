#include "lists.h"
/**
 * insert_dnodeint_at_index - insert node at a position
 * @h: The head of list
 * @idx: The index, starting at 0
 * @n: The value of new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *actnode = *h;
	dlistint_t *nnode;
	unsigned int con;

	if (!h)
		return (NULL);
	if (*h == NULL && idx != 0)
		return (NULL);
	nnode = malloc(sizeof(dlistint_t));
	if (nnode == NULL)
		return (NULL);
	nnode->n = n;
	if (idx == 0)
	{
		if (*h)
			actnode->prev = nnode;
		*h = nnode;
		nnode->prev = NULL;
		nnode->next = actnode;
		return (nnode);
	}
	for (con = 1; con < idx; con++)
	{
		actnode = actnode->next;
		if (actnode == NULL)
		{
			free(nnode);
			return (NULL);
		}
	}
	nnode->prev = actnode;
	nnode->next = actnode->next;
	if (actnode->next)
		actnode->next->prev = nnode;
	actnode->next = nnode;
	return (nnode);
}
