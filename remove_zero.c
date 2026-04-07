#include "apc.h"

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;

    while (temp && temp->data == 0 && temp->next)
    {
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        temp = *head;
    }

    if (*head == NULL)
        *tail = NULL;
}
