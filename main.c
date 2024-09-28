#include <stdlib.h>
#include <stdio.h>
#include "datastructures/linkedlist.h"

int main()
{

	linkedlist_t list;
	LINKEDLIST_INIT(&list);

	int first = 1;
	linkedlist_add(&list, &first);

	int second = 3;
	linkedlist_add_first(&list, &second);

	printf("%d\n", *(int *)list.head->value);
	printf("%d\n", *(int *)linkedlist_get_last(&list)->value);

	return 0;
}