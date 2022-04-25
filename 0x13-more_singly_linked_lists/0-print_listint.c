#include "lists.h"
/**
 * print_listint - prints all the elements of listint_t
 * @h: takes in a const struct type *h
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t c = 0;
	const listint_t *move = h;

	if (move == NULL)
		return (0);
	while (move != NULL)
	{
		printf("%d\n", move->n);
		move = move->next;
		c++;
	}
	return (c);
}
