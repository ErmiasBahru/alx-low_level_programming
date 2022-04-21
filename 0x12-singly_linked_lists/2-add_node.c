#include "lists.h"
#include <string.h>
/**
 *add_node - function to add item at the beginning of a linked_list
 *@head: head pointer to linked_list
 *@str: string to add
 *
 *Return: address of new element
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
unsigned int i = 0;

if (str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

while (new_node->str[i])
{
i++;
}
new_node->len = i;
new_node->next = *head;
*head = new_node;

return (new_node);
}
