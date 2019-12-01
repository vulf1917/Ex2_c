#include <stdio.h>
#include "myBank.h"/*
 * main.c
 *
 *  Created on: Nov 20, 2019
 *      Author: semen
 */
int main() {

	char choice;

	int bankAcount = 0;
	double depositAmount = 0;
	double attractingAmount = 0;
	double intrestRate = 0;
	//if( scanf("%d%d", &x, &y) == 2)

	printMenu();

	do {

		if (scanf("%c", &choice) == 1) {

			switch (choice) {

			case 'O':
				depositAmount = 0;
				printf("Initial deposit ?");
				if (scanf("%lf", &depositAmount) == 1) {
					openBankAcount(depositAmount);
				} else {
					printf("You must insert a double");
				}
			
				break;

			case 'B':
				bankAcount = 0;
				printf("Account number ? ");
				scanf("%d", &bankAcount);
				checkAccountancy(bankAcount);
		
				break;

			case 'D':
				bankAcount = 0;
				depositAmount = 0;
				printf("Account number ? \n");
				scanf("%d", &bankAcount);
				printf("Amount ? \n");
				if (scanf("%lf", &depositAmount) == 1) {
					deposit(depositAmount, bankAcount);
				} else {
					printf("You must insert a double");
					
				}
				break;

			case 'W':
				bankAcount = 0;
				attractingAmount = 0;
				printf("Account number ? \n");
				scanf("%d", &bankAcount);
				printf("Amount ? \n");
				if (scanf("%lf", &attractingAmount) == 1) {
					attracting(attractingAmount, bankAcount);
				} else {
					printf("You must insert a double");
				}
		
				break;

			case 'C':
				bankAcount = 0;
				printf("Account number ? \n");
				scanf("%d", &bankAcount);
				closeAcount(bankAcount);
				
				break;

			case 'I':

				printf("Intrest rate ? \n");
				if (scanf("%lf", &intrestRate) == 1) {
					addInrestRate(intrestRate);
				} else {
					printf("You must insert a double");
				}
				
				break;

			case 'P':
				printAllOpendAcounts();
				break;

			default:
				printf(
			"Insert one of the specified above chars :\n");

				break;
			}
		}

		else {
			printf("Wrong input :\n");
		}

	} while (choice != 'E');
	//else { printf("Wrong input : %c",choice);}

	return 0;
}

