/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int carry = 0;
	int num1, num2,res;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	while (temp1 != NULL)
	{
		num1 = temp1->data - carry;
        num2 = (temp2 != NULL) ? temp2->data : 0;

		if (num1 < num2)
        {
            num1 = num1 + 10;
            carry = 1;
        }
        else
            carry = 0;

        res = num1 - num2;

		insert_at_first(headR, tailR, res);

		temp1 = temp1->prev;

		if (temp2 != NULL)
			temp2 = temp2->prev;
	}

	return SUCCESS;
}
