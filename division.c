/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1 = *head1;
	Dlist *currHead = NULL;
	Dlist *currTail = NULL;

	*headR = NULL;
	*tailR = NULL;

	if (*head2 == NULL || ((*head2)->data == 0 && (*head2)->next == NULL))
		return FAILURE;

	while (temp1)
	{
		insert_at_last(&currHead, &currTail, temp1->data);
		remove_leading_zeros(&currHead, &currTail);

		int count = 0;

		while (compare_list(currHead, *head2) >= 0)
		{
			Dlist *headr = NULL;
			Dlist *tailr = NULL;

			subtraction(&currHead, &currTail, head2, tail2, &headr, &tailr);

			delete_list(&currHead, &currTail);
			currHead = headr;
			currTail = tailr;

			remove_leading_zeros(&currHead, &currTail);
			count++;
		}

		insert_at_last(headR, tailR, count);
		temp1 = temp1->next;
	}
	remove_leading_zeros(headR, tailR);
	return SUCCESS;
}
