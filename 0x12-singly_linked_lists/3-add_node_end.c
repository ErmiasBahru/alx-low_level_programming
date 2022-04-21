#include "lists.h"
/**
  *_strlen - returns length of string.
  *@str: string;
  *
  *Return: length of string.
  */
int _strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);

}
/**
  *add_node_end - adds a new node at the end of a list_t.
  *@head: pointer to head element.
  *@str: string to be duplicated
  *
  *Return: address of the new element.
  */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode, *lastNode;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	newNode->len = _strlen(str);
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		lastNode = *head;

		while (lastNode->next != NULL)
			lastNode = lastNode->next;
		lastNode->next = newNode;
	}

	return (newNode);
}
