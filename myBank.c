#include <stdio.h>
#include "myBank.h"
#define howManyAcaunts 50

double bankArr[howManyAcaunts][2] ={{0}};// the bank 2d array

void printMenu(){
     printf("                                 __                      ||      __ \n");
	printf("  _____       _____.__          |      |  |  _            ||     _    \n");
	printf("  /     | ___.__.  |_ |__ _     | ____ |  |   _    ||     ||_____  \n");
	printf("/    Y    (___  |  | (___) ()   | (|)  |  |     _  ||     ||      _     \n ");
	printf(" |___|__  / ____|  |_______   (____  /___ |       _/|_    ||      __() \n ");
	printf("  \n \n \n ");
	printf(" _________.__                       \n");
	printf(" /   _____/|__| _____   ____   ____  \n");
	printf(" (_____  () |  |/     ) /  _ ) /    ) \n");
	printf(" /       ( )|  |  Y Y  (  <_> )   |  \n");
	printf("|_______  /|__|__|_|  /|____/|___|   \n");



	printf("\n \n Transaction type::");
	printf(
			"\n O-open a new bank account.\n B-check the accountancy. \n D-Money deposit. \n W-attracting money from  \n C-Close the account. \n I- Add intrest rate to all accounts \n P-Print all the accounts \n E-Close all the accounts and exit from the program. ");

}



int isMoneyValid(double moneyToCheck) {
	if (moneyToCheck>=0) {
		return 1;
	}
	else{
		printf("\n wrong input : must be Possitive input here  !\n" );
		return 0;
	}


}


double convertTo02(double unConverted){
	unConverted*=100;
	int toConvert=(int)unConverted;
	double ans = ((double)toConvert)/100;
	return ans;


}




int checlValidAcountNumber(double arr[][2], int acountNumber) {

	if ((acountNumber > 950.0) || (acountNumber < 901.0)) { // check for valid acountNumber if it int the neded range"
		printf("Please insert a valid account number, (you entered %d) \n",
				acountNumber);
		return 0;
	}

	int acountIndex = acountNumber - 901;
	if (bankArr[acountIndex][1] == 0) { // the case its an empty acount
		printf("Thats account is not open , (you entered %d)  \n", acountNumber);
		return 0;
	}

	return 1;
}

int freeAcountIndex(double arr[][2]) { // check if there are free acounts when i stands for the first free index  and 0 for false (no free acount)
	for (int i = 0; i < howManyAcaunts; i++) {
		if (bankArr[i][1] == 0)
			return i;
	}
	return -1; // the case all the acounds are full
}

void openBankAcount(double firstDeposit) {
	int isValid = isMoneyValid(firstDeposit);
	if (isValid==0) {return;}
	int acountIndex = freeAcountIndex(bankArr);
	if (acountIndex == -1) {
		printf("unfortunately there are no free accounts at the moment\n");
		return;
	}

	else {
		bankArr[acountIndex][0] =convertTo02(firstDeposit); // put the monet in the acount and convert it to only two gids after the dot
		bankArr[acountIndex][1] = 1; // means that this acount is active
		int acountNumber = 901 + acountIndex; // calculate the new acaunt index
		printf("\nYour account number is : %d \n", acountNumber);
	}

}

void printAllOpendAcounts() { // printinf all the acounts with the 1 flag;
int bankAcountNum=0;
	printf("[");
	for (int i = 0; i < howManyAcaunts; i++) { // the main arr loop

		if (bankArr[i][1] != 0) {
			bankAcountNum = i+901;
			printf("Acount number:%d, Balance status : %.2f, ", bankAcountNum,bankArr[i][0]); // if the acount is open print it

		}

	}
	printf("]\n");







}

void checkAccountancy(int acountNumber) {

	int acountIndex = acountNumber - 901; // convert acountNumber to an index
	int testValidAcount = checlValidAcountNumber(bankArr, acountNumber); // check if its a vailid acount, if not print its not
	if (testValidAcount == 1) // the case its valid acount
			{
		printf("Your current balance status is : %.2f  \n",
				bankArr[acountIndex][0]); // print the current balance status

	}

}

void deposit(double moneyToDep, int bankAcountNumber) {
	int isValid = isMoneyValid(moneyToDep);
	if (isValid==0) {return;}
	moneyToDep=convertTo02(moneyToDep); // convert the monry to dep to 2 digs after the dot
	int acountIndex = bankAcountNumber - 901; // convert acountNumber to an index
	int testValidAcount = checlValidAcountNumber(bankArr, bankAcountNumber); // check if its a vailid acount, if not print its not
	if (testValidAcount == 1) // the case its valid acount
			{
		bankArr[acountIndex][0] += moneyToDep; // put the monet in the acount
		printf("Your current balance status is : %.2f  \n",
				bankArr[acountIndex][0]); // print the current balance status

	}
}

void attracting(double moneyToAtt, int bankAcountNumber) {
	int isValid = isMoneyValid(moneyToAtt);
	if (isValid==0) {return;}
	 moneyToAtt = convertTo02(moneyToAtt);
	int acountIndex = bankAcountNumber - 901; // convert acountNumber to an index
	int testValidAcount = checlValidAcountNumber(bankArr, bankAcountNumber); // check if its a vailid acount, if not print its not
	if (testValidAcount == 1) // the case its valid acount
			{
		double tempBalnceStatus = ((bankArr[acountIndex][0])-moneyToAtt); //store the new  acount after the attraction (can be - )
		if (tempBalnceStatus >= -0.000001) { // if has money , not to go to minus
			bankArr[acountIndex][0] = tempBalnceStatus; // atract the money and update the balance
			printf("Your current balance status is : %.2f  \n",
					bankArr[acountIndex][0]); // print the current balance status

		} else { // user dont have ength money

			printf("You don't have enough cache to attract \n"); // print the current balance status

		}

	}

}

void addInrestRate(double InrestRate){
	int isValid = isMoneyValid(InrestRate);
	if (isValid==0) {return;}
	for (int i = 0; i < howManyAcaunts; i++) { // the main arr loop

		if(bankArr[i][1]==1){ // check if the acount is open
			bankArr[i][0]=(bankArr[i][0])*(1+(InrestRate/100)); // add the intest rate
			bankArr[i][0]=convertTo02(bankArr[i][0]); // make it only 2 digs after the dot.
		}

	}






}

void closeAcount(double bankAcountNumber) {

	int testValidAcount = (int) checlValidAcountNumber(bankArr,
			bankAcountNumber); // check if its a vailid acount, if not print its not
	if (testValidAcount == 1) // the case its valid acount
			{
		int acountIndex = bankAcountNumber - 901; // convert acountNumber to an index
		bankArr[acountIndex][0] = 0;
		bankArr[acountIndex][1] = 0;

	}
}



void exits() {
	for (int i = 0; i < howManyAcaunts; i++) { // the main arr loop
		bankArr[i][0] = 0.0;
		bankArr[i][1] = 0.0;
	}

}





void test() {

	int bool = freeAcountIndex(bankArr);
	printf("%d", bool);
	openBankAcount(0.256);
	openBankAcount(656.56);
	openBankAcount(2555.6556);

	//print all the bank acounts

	printf("\n \n \n");

	printAllOpendAcounts();

	printf("\n");

	checkAccountancy(901);

	printf("\n");
	checkAccountancy(925);

	printf("\n");
	checkAccountancy(953);

	printf("\n");
	checkAccountancy(953.2);
	printf("\n");

	checkAccountancy(900);

	printf("\n");
	deposit(405, 901);
	printf("\n");
	attracting(40, 901);
	printf("\n");
	attracting(1000, 901);
	printf("\n");
	attracting(800000, 85);
	printf("\n");

	printAllOpendAcounts();
	printf("\n");
	exits();
	printAllOpendAcounts();
	printf("\n");
	printf("the end");
	printf("\n");
	double h = 0.666666;
	printf("%lf" ,h);
	h=convertTo02(h);
	printf("\n %lf" ,h);

}
