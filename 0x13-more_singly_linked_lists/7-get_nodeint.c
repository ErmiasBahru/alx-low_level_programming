#include "lists.h"
/**
  * listint_len - returns the number of elements ina linked listint_t list.
  * @h: pointer to first element on list.
  *
  * Return: number of elements in list.
  */
size_t listint_len(const listint_t *h)
{
	int count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
  * get_nodeint_at_index - returns nth node of a listint_t linked list.
  * @head: pointer to first elemnt of list.
  * @index: index of node.
  *
  * Return: nth node,
  * NULL if not found.
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int count;

	current = head;
	count = listint_len(head);

	if (current == NULL)
		count++;

	if (count <= index)
	{
		return (NULL);
	}
	else
	{
		count = 0;
		while (current != NULL)
		{
			if (count == index)
			{
				break;
			}
			else
			{
				count++;
				current = current->next;
			}
		}
		return (current);
	}
}
