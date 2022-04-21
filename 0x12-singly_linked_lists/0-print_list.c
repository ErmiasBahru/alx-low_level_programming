#include "lists.h"
/**
 * print_list -  prints all the elements of a list_t list
 * @h: element of the structure
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t con = 0;
	const list_t *move = h;

	if (h == NULL)
		return (0);

	while (move != NULL)
	{
		if (move->str)
			printf("[%d] %s\n", move->len, move->str);
		else
			printf("[0] (nil)\n");
		move = move->next;
		con++;
	}
	return (con);
}
