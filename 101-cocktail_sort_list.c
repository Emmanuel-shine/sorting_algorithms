#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
    listint_t *tmp = *a;

    *a = (*a)->prev;
    if ((*a))
        (*a)->next = *b;

    (*b)->prev = *a;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    tmp->prev = *b;
    if (tmp->next)
        tmp->next->prev = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *curr;

    if (!list || !*list)
        return;

    while (swapped)
    {
        swapped = 0;
        for (curr = *list; curr->next; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(&curr, &(curr->next));
                if (!curr->prev)
                    *list = curr;
                print_list(*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (; curr->prev; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(&(curr->prev), &curr);
                if (!curr->prev)
                    *list = curr;
                print_list(*list);
                swapped = 1;
            }
        }
    }
}
