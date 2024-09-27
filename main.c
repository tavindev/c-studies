#include <stdlib.h>
#include <stdio.h>
#include "datastructures/linkedlist.h"

int main()
{

	linkedlist_t *list;
	INIT_LLIST(&list);

	int first = 1;
	add(list, &first);

	int second = 3;
	add_first(list, &second);

	printf("%d\n", *(int *)list->head->value);
	printf("%d\n", *(int *)get_last(list)->value);

	return 0;
}