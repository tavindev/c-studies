#include <stdlib.h>
#include "linkedlist.h"

void INIT_LLIST(linkedlist_t **l)
{
	*l = malloc(sizeof(linkedlist_t *));
	(*l)->size = 0;
	(*l)->head = NULL;
}

node_t *get_tail(linkedlist_t *l)
{
	if (l == NULL || l->head == NULL)
		return NULL;

	node_t *tail = l->head;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	return tail;
}

node_t *create_node(void *data)
{
	node_t *n_node = malloc(sizeof(node_t));
	n_node->value = data;
	return n_node;
}

void add(linkedlist_t *l, void *data)
{
	if (l->head == NULL)
	{
		l->head = create_node(data);
	}
	else
	{
		node_t *tail = get_tail(l);
		tail->next = create_node(data);
	}

	l->size += 1;
}

void add_last(linkedlist_t *l, void *data)
{
	add(l, data);
}

void add_first(linkedlist_t *l, void *data)
{
	node_t *n_node = create_node(data);
	n_node->next = l->head;
	l->head = n_node;
}

node_t *get_last(linkedlist_t *l)
{
	return get_tail(l);
}
