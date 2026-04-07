/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = NULL;
	Dlist *temp2 = *tail2;

	Dlist *headR1 = NULL;
	Dlist *tailR1 = NULL;
	Dlist *headR2 = NULL;
	Dlist *tailR2 = NULL;
	int count = 0;

	while (temp2)
	{
		temp1 = *tail1;
		headR2 = NULL;
		tailR2 = NULL;

		int carry = 0;
		int num2 = temp2->data;

		for (int i = 0; i < count; i++)
			insert_at_first(&headR2, &tailR2, 0);

		while (temp1)
		{
			int num1 = temp1->data;
			int res = (num1 * num2) + carry;

			carry = res / 10;
			res = res % 10;

			insert_at_first(&headR2, &tailR2, res);
			temp1 = temp1->prev;
		}
		if (carry)
			insert_at_first(&headR2, &tailR2, carry);

		Dlist *sumHead = NULL;
		Dlist *sumTail = NULL;

		addition(&headR1, &tailR1, &headR2, &tailR2, &sumHead, &sumTail);

		headR1 = sumHead;
		tailR1 = sumTail;

		count++;
		temp2 = temp2->prev;
	}

	*headR = headR1;
	*tailR = tailR1;
	return SUCCESS;
}
