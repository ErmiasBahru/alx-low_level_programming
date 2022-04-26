#include "lists.h"
/**
  * delete_nodeint_at_index - deletes the node at index.
  * @head: pointer to pointer of first elemnt of list.
  * @index: index of node to be deleted.
  *
  * Return: 1 if successful, -1 if fails.
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count;
	listint_t *next_node, *temp;

	temp = *head;
	count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && count < index - 1)
	{
		temp = temp->next;
		count++;
		if (temp == NULL || temp->next == NULL)
			return (-1);
	}

	next_node = temp->next->next;
	free(temp->next);
	temp->next = next_node;

	return (1);
}
