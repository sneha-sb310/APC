#include "apc.h"

int insert_at_first(Dlist **head, Dlist **tail, int data)
{  
    Dlist *newNode = (Dlist*)malloc(sizeof(Dlist));

    if (newNode == NULL)
        return FAILURE;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    Dlist *temp = *head;

    if (*head == NULL){
        *head = newNode;
        *tail = newNode;
        return SUCCESS;
    }

    newNode->next = temp;
    temp->prev = newNode;
    *head = newNode;
    return SUCCESS;
}