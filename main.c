/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/

#include "apc.h"
void print_list(Dlist *head)
{
    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int valid_cla_arguments(char *num1, char *op, char *num2)
{
	if(num1[0] == '\0'||num2[0] == '\0')
{
    return FAILURE;
}
	for(int i=0;num1[i]!='\0';i++)
	{
if(!isdigit(num1[i]))
{
return FAILURE;
}

	}
	for(int i=0;num2[i]!='\0';i++)
	{
	if(!isdigit(num2[i]))
{
return FAILURE;
}
	}
	if(isdigit(op[0])||(op[1]!='\0'))
	{
	return FAILURE;
	}
if(!(op[0]=='-'||op[0]=='+'||op[0]=='/'||op[0]=='*'))
{
	return FAILURE;
}
	
	return SUCCESS;
}
//create list
int create_list(Dlist **head, Dlist **tail,char *num)

{
	int i=0;
	/** num1[i] - '0';
num2[i] - '0';**/
while (num[i] != '\0')
    {
 Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
new->data=num[i]-'0';
new->next = NULL;
new->prev = NULL;
if(*head==NULL)
{
*head=*tail=new;

}
else
{
 new->prev = *tail;
(*tail)->next = new;
  *tail = new;
}
   i++;
}

    return SUCCESS;

}
int main(int argc,char *argv[])
{
    /* Declare and Initialize the pointers */
    char option, operator;
	int result;
	Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    /* function call to validate CLA */
	if(argc!=4)
	{
		return FAILURE;
	}
if(valid_cla_arguments(argv[1],argv[2],argv[3])==FAILURE)
{
	printf("Invalid arguments entered");
	return FAILURE;
}
    /* extract the operator */
    /* function call to convert CLA to list */
	create_list(&head1,&tail1,argv[1]);
	create_list(&head2,&tail2,argv[3]);
	print_list(head1);
print_list(head2);

operator=argv[2][0];
switch (operator)
    {
	case '+':
	    /* call the function to perform the addition operation */
		addition( &head1,  &tail1, &head2, &tail2,  &headR, &tailR);
		print_list(headR);
	    break;
	case '-':	
	    /* call the function to perform the subtraction operation */
		subtraction( &head1,  &tail1, &head2, &tail2,  &headR, &tailR);
		print_list(headR);
	    break;
	case '*':	
	    /* call the function to perform the multiplication operation */
	   multiplication( &head1,  &tail1, &head2, &tail2,  &headR, &tailR);
		print_list(headR);
	    break;
	case '/':	
	    /* call the function to perform the division operation */
		division( &head1,  &tail1, &head2, &tail2,  &headR, &tailR);
			print_list(headR);
	    break;
	default:
	    printf("Invalid Input:-( Try again...\n");
    }
    return 0;
}