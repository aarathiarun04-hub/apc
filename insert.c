#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;

    return SUCCESS;
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;

    return SUCCESS;
}
void remove_zeros(Dlist **head, Dlist **tail)
{
    while (*head != *tail && (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}