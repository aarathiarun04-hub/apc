/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)

{
    if (*head1 == NULL || *head2 == NULL)
    {
        printf("List is empty\n");
        return FAILURE;
    }
    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        printf("Division by zero not possible\n");
        return FAILURE;
    }
    if ((*head1)->data == 0 && (*head1)->next == NULL)
    {
        dl_insert_first(headR, tailR, 0);
        return SUCCESS;
    }
    int divisor = 0;
    Dlist *temp = *head2;
    while (temp)
    {
        divisor = divisor * 10 + temp->data;
        temp = temp->next;
    }
    int num = 0;
    temp = *head1;
    while(temp)
    {
        num = num * 10 + temp->data;
        int q = num / divisor;
        dl_insert_last(headR,tailR,q);
        num = num % divisor;
        temp = temp->next;
    }
    remove_zeros(headR, tailR);
    return SUCCESS;
}