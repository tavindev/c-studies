typedef struct node
{
	void *value;
	struct node *next;
} node_t;

typedef struct linkedlist
{
	int size;
	node_t *head;
} linkedlist_t;

void INIT_LLIST(linkedlist_t **l);

void add(linkedlist_t *l, void *data);

void add_last(linkedlist_t *l, void *data);

void add_first(linkedlist_t *l, void *data);

// void *get(int i);

node_t *get_last(linkedlist_t *l);