/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
//multiplicattion main logic
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
Dlist *temp1 = *tail1;
Dlist *temp2 = *tail2;
int count1 = 0, count2 = 0;
int mul;
int extra = 0;
if(*head1==NULL||*head2==NULL)
{
	return FAILURE;
}

while(temp1 != NULL)
{
    temp1 = temp1->prev;
    count1++;
}
temp1 = *tail1;

while(temp2 != NULL)
{
    temp2 = temp2->prev;
    count2++;
}
temp2 = *tail2;
//swap logic

	if(count1==1||count1<count2)
	{
		Dlist *temp;
    temp = *head1;
    *head1 = *head2;
    *head2 = temp;
    temp = *tail1;
    *tail1 = *tail2;
    *tail2 = temp;
int t = count1;
count1 = count2;
count2 = t;
	}
	temp1 = *tail1;
	//single didgit num detected case
if(count1==1||count2==1)
{
	while(temp1)
	{
	mul=temp1->data * (*tail2)->data+extra;
	if(mul<10)
	{
extra=0;
dl_insert_first(headR, tailR, mul);
	}
	else
	{
		extra=mul/10;
		dl_insert_first(headR, tailR, mul%10);
		
	}
	temp1 = temp1->prev;
     }
	 if(extra)
{
    dl_insert_first(headR, tailR, extra);
}
	 return SUCCESS;
}
//both num1 and num2 are multi digit
temp2 = *tail2;
int i = 0;
while(temp2)
{
    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;
    temp1 = *tail1;
    extra = 0;
while(temp1)
{
	
mul=temp1->data * temp2->data+extra;
	if(mul<10)
	{
extra=0;
dl_insert_first(&temp_head, &temp_tail, mul);

	}
	else
	{
		extra=mul/10;
		dl_insert_first(&temp_head, &temp_tail,mul%10);
		
	}
	  temp1 = temp1->prev;    
}
	if(extra)
    {
        dl_insert_first(&temp_head, &temp_tail, extra);
    }
		for(int j=0;j<i;j++)
		{
			dl_insert_last(&temp_head, &temp_tail,0);
		}
	 if(*headR == NULL)
    {
        *headR = temp_head;
        *tailR = temp_tail;
    }
    else
    {
        Dlist *res_head = NULL;
        Dlist *res_tail = NULL;
 addition(&temp_head, &temp_tail,headR, tailR,&res_head, &res_tail);
	*headR = res_head;
    *tailR = res_tail;
    }
  temp2 = temp2->prev;
  i++;
}
remove_zeros(headR, tailR);
return SUCCESS;

}
// while compiling add '*' intead of *