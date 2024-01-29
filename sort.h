#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
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

int hoare_partition(int *array, size_t size, int left, int right);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void merge_subarr(int *subarr, int *buffer,
		size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
/*void merge_sort_recursive(int *array, int low, int high);*/
/*void merge(int *array, int low, int mid, int high);*/
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void counting_sort(int *array, size_t size);
void new_swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void new_swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void new_cocktail_sort_list(listint_t **list);
void perform_counting_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quicksort_hoare(int *array, int low, int high, size_t size);
/*int hoare_partition(int *array, int low, int high, size_t size);*/
void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursive(int *array, size_t size, size_t start, int dir);
void bitonic_merge(int *array, size_t size, size_t start, int dir);
void bitonic_compare(int *array, size_t size, size_t start, int dir);
void insertion_sort_list(listint_t **list);
int compare_cards(const void *a, const void *b);
/*void sort_deck(deck_node_t **deck);*/
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i);
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t **tail,
		listint_t **shaker, int direction);
#endif /* SORT_H */
