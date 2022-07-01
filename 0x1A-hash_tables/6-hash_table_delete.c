#include "hash_tables.h"

/**
 * hash_table_delete - deletes the hash table
 * @ht: the hash table of hash_table_t
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	int i;
	hash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < (int)ht->size; i++)
	{
		node = ht->array[i];
		if (!node)
			continue;
		while (node)
		{
			free(node->value);
			free(node->key);
			tmp = node->next;
			free(node);
			node = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
