/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    int count1 = 0, count2 = 0;
    int borrow = 0;
    int sub;
    int sign = 0;
    if (*head1 == NULL||*head2 == NULL)
    {
        printf("List is empty");
        return FAILURE;
    }
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    while (temp1)
    {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        count2++;
        temp2 = temp2->next;
    }
    //both list equalizing by padding 0ss
    if (count1 < count2)
    {
        for (int i = 0; i < count2 - count1; i++)
        {
            dl_insert_first(head1, tail1, 0);
        }
    }
    else if (count2 < count1)
    {
        for (int i = 0; i < count1 - count2; i++)
        {
            dl_insert_first(head2, tail2, 0);
        }
    }
    temp1 = *head1;
    temp2 = *head2;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            break;
        else if (temp1->data < temp2->data)
        {
            Dlist *temp;
            temp = *head1;
            *head1 = *head2;
            *head2 = temp;
            temp = *tail1;
            *tail1 = *tail2;
            *tail2 = temp;
            sign = 1;
            break;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    while (t1 != NULL && t2 != NULL)
    {
        sub = t1->data- borrow - t2->data;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        dl_insert_first(headR, tailR, sub);
        t1 = t1->prev;
        t2 = t2->prev;
    }

    remove_zeros(headR, tailR);
    if (sign)
    printf("-");
    return SUCCESS;
}