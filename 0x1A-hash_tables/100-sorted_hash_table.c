#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: the size of the array to create
 * Return: pointer to the newly created hash table or NULL on
 * failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(shash_table_t));
	if (!hash_table)
		return (NULL);

	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!hash_table->array)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	hash_table->shead = NULL;
	hash_table->stail = NULL;
	return (hash_table);
}

/**
 * create_new_node - helper function to create a new node
 * @ht: hash table of shash_table_t
 * @index: the index position to insert the new node
 * @key: the key of the new node
 * @value: value of the new node
 * Return: new created node on success and NULL on failure
 */
shash_node_t *create_new_node(shash_table_t *ht, unsigned long int index,
const char *key, const char *value)
{
	shash_node_t *new_node = NULL;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup((char *)key);
	new_node->value = strdup((char *)value);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (new_node);
}

/**
 * sort_shash_node_t - adds and sorts new node to the shash_node_t doubly
 * linked list
 * @ht: hash table of shash_table_t
 * @new_node: pointer to the new created node
 * Return: nothing
 */
void sort_shash_node_t(shash_table_t **ht, shash_node_t **new_node)
{
	shash_node_t *head = (*ht)->shead, *node = *new_node, *prev, *next;

	if (head == NULL)
	{
		(*ht)->shead = (*ht)->stail = node;
		return;
	}
	while (head)
	{
		if (head->key[0] >= node->key[0])
		{
			next = head;
			prev = head->sprev;
			node->snext = next;
			node->sprev = prev;
			next->sprev = node;
			if (prev)
				prev->snext = node;
			if (!node->sprev)
				(*ht)->shead = node;
			break;
		}
		else if (node->key[0] > head->key[0])
		{
			if (!head->snext || (head->snext && head->snext->key[0] > node->key[0]))
			{
				prev = head;
				next = head->snext;
				node->snext = next;
				node->sprev = prev;
				prev->snext = node;
				if (next)
					next->sprev = node;
				if (!node->snext)
					(*ht)->stail = node;
				break;
			}
		}
		head = head->snext;
	}
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: hash table data structure of shash_table_t
 * @key: the key string
 * @value: the value corresponding to the key
 * Return: 1 if it succeeded, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL, *tmp = NULL;
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL || ht->size == 0
	    || key == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup((char *)value);
			if (tmp->value == NULL)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}
	new_node = create_new_node(ht, index, key, value);
	if (!new_node)
		return (0);

	sort_shash_node_t(&ht, &new_node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table data structure of shash_table_t
 * @key: the key, string
 * Return: the value of the associated key or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *found_node = NULL;

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

/**
 * shash_table_print - prints the hash table
 * @ht: the hash table of shash_table_print
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first_flag = 0;

	if (ht == NULL)
		return;

	tmp = ht->shead;
	printf("{");
	while (tmp)
	{
		if (first_flag <= 1)
			first_flag++;
		if (first_flag == 2)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the hash table in reverse
 * @ht: the hash table of shash_table_t
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first_flag = 0;

	if (ht == NULL)
		return;

	tmp = ht->stail;
	printf("{");
	while (tmp)
	{
		if (first_flag <= 1)
			first_flag++;
		if (first_flag == 2)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * free_shash_node_t_list - frees a doubly linked list
 * @head: beginning of shash_node_t doubly linked list
 * Return: nothing
 */

void free_shash_node_t_list(shash_node_t *head)
{
	shash_node_t *tmp;

	if (head)
	{
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}

/**
 * shash_table_delete - deletes the hash table
 * @ht: the hash table of shash_table_t
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			free(node->value);
			free(node->key);
			node = node->next;
		}
	}
	free_shash_node_t_list(ht->shead);
	free(ht->array);
	free(ht);
}
