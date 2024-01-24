#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/**
* print_array - Prints an array of integers
*
* @array: The array to be printed
* @size: Number of elements in @array
*/
void print_array(const int *array, size_t size);

/**
* print_list - Prints a list of integers
*
* @list: The list to be printed
*/
void print_list(const listint_t *list);

/* Additional function prototypes for sorting algorithms go here */

/* 0-bubble_sort.c */
void bubble_sort(int *array, size_t size);

/* 101-cocktail_sort_list.c */
void cocktail_sort_list(listint_t **list);

/* 103-merge_sort.c */
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int low, int high);
void merge(int *array, int low, int mid, int high);

/* 105-radix_sort.c */
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void counting_sort(int *array, size_t size);

/*void counting_sort(int *array, size_t size, int exp);*/

/* 107-quick_sort_hoare.c */
void quick_sort_hoare(int *array, size_t size);
void quicksort_hoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/* 2-selection_sort.c */
void selection_sort(int *array, size_t size);

/* 106-bitonic_sort.c */
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursive(int *array, size_t size, size_t start, int dir);
void bitonic_merge(int *array, size_t size, size_t start, int dir);
void bitonic_compare(int *array, size_t size, size_t start, int dir);

/* 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);

/* 1000-sort_deck.c */
#include "deck.h"
int compare_cards(const void *a, const void *b);
void sort_deck(deck_node_t **deck);

/* 104-heap_sort.c */
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i);

/* 3-quick_sort.c */
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/* 100-shell_sort.c */
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b);
#endif /* SORT_H */
