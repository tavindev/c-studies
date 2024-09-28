#include <stdlib.h>
#include "linkedlist.h"

void LINKEDLIST_INIT(linkedlist_t *l)
{
	l->size = 0;
	l->head = NULL;
}

linkedlist_node_t *get_tail(linkedlist_t *l)
{
	if (l == NULL || l->head == NULL)
		return NULL;

	linkedlist_node_t *tail = l->head;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	return tail;
}

linkedlist_node_t *create_node(void *data)
{
	linkedlist_node_t *n_node = malloc(sizeof(linkedlist_node_t));
	n_node->value = data;
	return n_node;
}

void linkedlist_add(linkedlist_t *l, void *data)
{
	if (l->head == NULL)
	{
		l->head = create_node(data);
	}
	else
	{
		linkedlist_node_t *tail = get_tail(l);
		tail->next = create_node(data);
	}

	l->size += 1;
}

void linkedlist_add_last(linkedlist_t *l, void *data)
{
	linkedlist_add(l, data);
}

void linkedlist_add_first(linkedlist_t *l, void *data)
{
	linkedlist_node_t *n_node = create_node(data);
	n_node->next = l->head;
	l->head = n_node;
}

void *linkedlist_get(linkedlist_t *l, int pos)
{
	if (l == NULL)
		return NULL;

	void *value;
	linkedlist_node_t *node = l->head;

	for (int i = 0; i < pos; i++)
	{
		if (node == NULL)
			return NULL;

		value = node->value;
		node = node->next;
	}

	return value;
}

void *linkedlist_get_last(linkedlist_t *l)
{
	return get_tail(l)->value;
}
