#include "sort.h"

void swap_nodes(listint_t **list, listint_t **tail, listint_t **shaker, int direction);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes - Swap a node in a listint_t doubly-linked list
 *              with the node in the specified direction.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 * @direction: An integer specifying the direction of swapping (1 for ahead, -1 for behind).
 */
void swap_nodes(listint_t **list, listint_t **tail, listint_t **shaker, int direction)
{
    listint_t *tmp = direction == 1 ? (*shaker)->next : (*shaker)->prev;

    if ((*shaker)->prev != NULL)
        (*shaker)->prev->next = tmp;
    else
        *list = tmp;

    if (tmp->next != NULL)
        tmp->next->prev = *shaker;
    else
        *tail = *shaker;

    if (direction == 1)
    {
        (*shaker)->next = tmp->next;
        tmp->prev = (*shaker)->prev;
        (*shaker)->prev = tmp;
        tmp->next = *shaker;
    }
    else
    {
        (*shaker)->prev = tmp->prev;
        tmp->next = (*shaker)->next;
        (*shaker)->next = tmp;
        tmp->prev = *shaker;
    }

    *shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *shaker;
    int shaken_not_stirred = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    while (!shaken_not_stirred)
    {
        shaken_not_stirred = 1;

        for (shaker = *list; shaker != tail; shaker = shaker->next)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_nodes(list, &tail, &shaker, 1);
                print_list((const listint_t *)*list);
                shaken_not_stirred = 0;
            }
        }

        for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
        {
            if (shaker->n < shaker->prev->n)
            {
                swap_nodes(list, &tail, &shaker, -1);
                print_list((const listint_t *)*list);
                shaken_not_stirred = 0;
            }
        }
    }
}
