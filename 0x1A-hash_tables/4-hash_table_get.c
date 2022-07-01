#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table data structure of hash_table_t
 * @key: the key, string
 * Return: the value of the associated key or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *found_node = NULL;

	if (ht == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	found_node = ht->array[index];

	if (found_node == NULL)
		return (NULL);

	while (found_node)
	{
		if (strcmp(found_node->key, key) == 0)
			return (found_node->value);
		found_node = found_node->next;
	}

	return (NULL);
}
