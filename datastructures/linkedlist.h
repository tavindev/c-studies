typedef struct node
{
	void *value;
	struct node *next;
} linkedlist_node_t;

typedef struct linkedlist
{
	int size;
	linkedlist_node_t *head;
} linkedlist_t;

void LINKEDLIST_INIT(linkedlist_t *l);

void linkedlist_add(linkedlist_t *l, void *data);

void linkedlist_add_last(linkedlist_t *l, void *data);

void linkedlist_add_first(linkedlist_t *l, void *data);

void *linkedlist_get(linkedlist_t *l, int pos);

void *linkedlist_get_last(linkedlist_t *l);