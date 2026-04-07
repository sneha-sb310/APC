#include "apc.h"

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));

    if (newNode == NULL)
        return FAILURE;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    Dlist *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return SUCCESS;
    }
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    *tail = newNode;

    return SUCCESS;
}