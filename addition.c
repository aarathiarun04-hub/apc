/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int count1=0,count2=0;
	int carry=0;
	int sum;
	if(*head1 == NULL || *head2 == NULL)
{
    printf("List is empty");
    return FAILURE;
}
	
Dlist *t1 = *tail1;
Dlist *t2 = *tail2;
Dlist *temp1 = t1;
Dlist *temp2 = t2;

while(temp1 != NULL)
{
    temp1 = temp1->prev;
    count1++;
}

while(temp2 != NULL)
{
    temp2 = temp2->prev;
    count2++;
}

if(count1<count2)
		{
			for(int i=0;i<(count2-count1);i++)
			{
				dl_insert_first(head1, tail1, 0);
			}
		}
		else if(count1>count2)
		{
			for(int i=0;i<(count1-count2);i++)
			{
				dl_insert_first(head2, tail2, 0);
			}
		}
		t1 = *tail1;
t2 = *tail2;
	
while(t1 != NULL && t2 != NULL)
{
    sum = t1->data + t2->data+carry;
	if(sum<10)
	{
    dl_insert_first(headR, tailR, sum);
   
	carry=0;
	}
	else
	{
		dl_insert_first(headR, tailR, sum%10);
	
	carry=1;
	}
		 t1 = t1->prev;
    t2 = t2->prev;


}
if(carry==1)
	  {
        dl_insert_first(headR, tailR, carry);
    }
	remove_zeros(headR, tailR);
return SUCCESS;
}