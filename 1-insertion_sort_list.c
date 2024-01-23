#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of
* integers in ascending order
* using Insertion sort algorithm
* @list: Double pointer to the head of the linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *next;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
next = current->next;
prev = current->prev;

while (prev != NULL && current->n < prev->n)
{
current->prev = prev->prev;
prev->prev = current;
prev->next = next;

if (current->prev != NULL)
current->prev->next = current;

if (next != NULL)
next->prev = prev;

if (prev == *list)
*list = current;

print_list(*list);
prev = current->prev;
}

current = next;
}
}
