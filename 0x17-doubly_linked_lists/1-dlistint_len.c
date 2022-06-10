#include "lists.h"

/**
 * dlistint_len - Return the number of elements in a dlistint_t list
 * @h: pointer to The list
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t con = 0;

	while (h)
	{
		con++;
		h = h->next;
	}

	return (con);
}
