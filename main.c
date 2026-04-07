/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
/*
Name : Sneha Bujurke
Project : APC
Date : 05-02-2026
Description : Arbitrary Precision Calculator is a project that performs calculations on very large numbers which normal data types cannot store. 
			  It uses linked lists and custom logic to accurately implement operations like addition, subtraction, multiplication, and division.
*/

#include "apc.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL;
	Dlist *tail1 = NULL;
	Dlist *head2 = NULL;
	Dlist *tail2 = NULL;
	Dlist *headR = NULL;
	Dlist *tailR = NULL;
	char option;
	char op;
	int sign = 0;

	if (argc != 4)
	{
		printf("Usage: ./a.out <num1> <operator> <num2>\n");
		return FAILURE;
	}

	op = argv[2][0];

	int i = 0;
	while (argv[1][i] != '\0')
	{
		insert_at_last(&head1, &tail1, argv[1][i] - '0');
		i++;
	}

	i = 0;
	while (argv[3][i] != '\0')
	{
		insert_at_last(&head2, &tail2, argv[3][i] - '0');
		i++;
	}

	do
	{
		/* Code for reading the inputs */
		printf("----------------------------------\n");
		printf("Arithemetic Precision Calculator\n");
		printf("Performing operation: %c\n", op);

		headR = NULL;
		tailR = NULL;
		sign = 0;

		/* Function for extracting the operator */

		switch (op)
		{
		case '+':
			/* call the function to perform the addition operation */
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			remove_leading_zeros(&headR, &tailR);
			break;
		case '-':
			/* call the function to perform the subtraction operation */ {

				int res = compare_list(head1, head2);

				if (res == 1)
				{
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				else if (res == -1)
				{
					sign = 1; // negative result
					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				}
				else
				{
					insert_at_first(&headR, &tailR, 0);
				}
				remove_leading_zeros(&headR, &tailR);
				break;
			}
		case 'x':
			/* call the function to perform the multiplication operation */
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			remove_leading_zeros(&headR, &tailR);
			break;
		case '/':
		{
			/* call the function to perform the division operation */
			int status = division(&head1, &tail1,&head2, &tail2,&headR, &tailR);

			if (status == FAILURE)
				printf("Error: Division by zero is not allowed\n");
			
			break;
		}
		default:
			printf("Invalid Input:-( Try again...\n");
		}

		if (sign)
			printf("-");

		printf("Result : ");
		print_list(headR);
		printf("Want to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);

		if (option == 'y' || option == 'Y')
		{
			printf("Enter operator [+ - x /]: ");
			scanf(" %c", &op);
		}
		// printf("----------------------------------\n");

	} while (option == 'y' || option == 'Y');

	return 0;
}
