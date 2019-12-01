
#ifndef MYBANK_H_
#define MYBANK_H_
#define howManyAcaunts 50

extern double bankArr[howManyAcaunts][2]; // the bank 2d array

void printMenu();
int isMoneyValid(double moneyToCheck);
int checlValidAcountNumber(double arr[][2],int acountNumber);
void test();
int freeAcountIndex (double arr[][2]);
void openBankAcount(double firstDeposit);
void checkAccountancy(int bankAcountNumber);
void deposit(double moneyToDep,int bankAcountNumber);
void attracting(double moneyToAtract,int bankAcountNumber);
void closeAcount(double bankAcountNumber);
void addInrestRate(double InrestRate);
void printAllOpendAcounts();
void exits();






#endif /* MYBANK_H_ */
