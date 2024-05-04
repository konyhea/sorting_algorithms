#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion sort
 * @list: The list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL, *current = *list, *next, *temp;

    while (current != NULL)
    {
        next = current->next;

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            temp = sorted;
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }

        print_list(sorted);
        current = next;
    }

    *list = sorted;
}
