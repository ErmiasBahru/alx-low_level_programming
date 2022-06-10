#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete the node at the specified index
 * @head: The head of the list
 * @index: The index, starting at 0
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *actnode = *head;
	unsigned int con;

	if (!head || !(*head))
		return (-1);

	for (con = 0; con < index; con++)
	{
		actnode = actnode->next;
		if (actnode == NULL)
			return (-1);
	}

	if (index == 0)
	{
		if (actnode->next)
			actnode->next->prev = NULL;
		*head = actnode->next;
	}
	else
	{
		if (actnode->next)
			actnode->next->prev = actnode->prev;
		if (actnode->prev)
			actnode->prev->next = actnode->next;
	}

	free(actnode);
	return (1);
}
