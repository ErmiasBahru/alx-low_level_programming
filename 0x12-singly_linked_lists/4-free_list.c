#include "lists.h"
/**
  *free_list - frees a list_t
  *@head: pointer to head of list.
  *
  *Return: 0.
  */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->str);
		head = head->next;
		free(temp);
	}
}
