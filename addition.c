/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0;
	int num1, num2;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	while (temp1 != NULL || temp2 != NULL || carry != 0)
	{
		num1 = 0;
		num2 = 0;

		if (temp1 != NULL)
			num1 = temp1->data;

		if (temp2 != NULL)
			num2 = temp2->data;

		int res = num1 + num2 + carry;
		carry = res / 10;
		res = res % 10;

		insert_at_first(headR, tailR, res);

		if (temp1 != NULL)
			temp1 = temp1->prev;

		if (temp2 != NULL)
			temp2 = temp2->prev;
	}

	return SUCCESS;
}
