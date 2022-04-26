#include "lists.h"
/**
  * pop_listint - delets the head node of a listint_t
  * @head: pointer to pointer of head node.
  *
  * Return: 0 if list is empty.
  * headnode data (n).
  */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int removed = 0;

	if (*head == NULL)
		return (removed);

	if (*head == NULL)
		return (removed);

	temp = *head;
	removed = temp->n;
	/*make head point to the next element*/
	*head = (*head)->next;
	free(temp);

	return (removed);
}
