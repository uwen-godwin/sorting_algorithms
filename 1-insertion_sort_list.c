#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of
* integers in ascending order
* using the Insertion sort algorithm
* @list: Pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *next;

if (!list || !(*list) || !((*list)->next))
return;

current = (*list)->next;
while (current)
{
next = current->next;
prev = current->prev;

while (prev && prev->n > current->n)
{
prev->next = current->next;

if (current->next)
current->next->prev = prev;

current->next = prev;
current->prev = prev->prev;

if (prev->prev)
prev->prev->next = current;
else
(*list) = current;

prev->prev = current;

print_list(*list);
prev = current->prev;
}

current = next;
}
}
