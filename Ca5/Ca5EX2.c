/*
	Μάρκος Παντελιδάκης - ice18390228
	Το παρακάτω πρόγραμμα μεταγλωτήστηκε με gcc compiler και εκτελέστηκε σε περιβάλλον linux-Ubuntu.
*/
#include <stdio.h>
#include <stdlib.h>
#include "POWERnFACTOR.h"

void menu(int,int);
void func1(int,int);
void func2(int,int);
void func3(int,int);

int main(int argc, char **argv){
	int a,b;
	printf("Παρακαλώ εισάγετε δύο τιμές για Α και Β..\n-Α: ");
	scanf("%d", &a);
	printf("\n-Β: ");
	scanf("%d", &b);
	menu(a, b);
	printf("\nΑντίο!\n");
	return 0;
}

void menu(int a, int b){ 
	int option=10, option_count=0;
	float result;
	while(option!=0){
		printf("\n\n-=============================-ΜΕΝΟΥ-=============================-\nΠατήστε:\n");
		printf("1. Για το υπολογισμό Α είς την δύναμη του Β.\n");
		printf("2. Για τον υπολογισμό του παραγωντικού του Α και του Β. (Α!, Β!).\n");
		printf("3. Για τον υπολογισμό του πλήθους των συνδιασμών Α ανά Β.\n");
		printf("0. Για τον τερματισμό του προγράμματος.\n");
		
		printf("\n---------------------\nΕπιλογή: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				func1(a,b);
				option_count++;
			break;
			
			case 2:
				func2(a,b);
				option_count++;
			break;
			
			case 3:
				func3(a,b);
				option_count++;
			break;
		}
	}
	printf("\nΟ χρήστης έκανε %d επιλογές.", option_count);
}

void func1(int a, int b){
	system("clear");
	printf("\n\nΤο αποτέλεσμα του Α εις την δύναμη Β είναι: %.6f", power(a,b));
}

void func2(int a, int b){
	system("clear");
	int res = factor(a);
	if(!res)
		printf("Το Α είναι αρνητικός αριθμός, άρα δεν έχει παραγοντικό.");
	else
		printf("\n\nΤο παραγοντικό του A=%d είναι: %d\n", a, res);
	res = factor(b);
	if(!res)
		printf("\nΤο B είναι αρνητικός αριθμός, άρα δεν έχει παραγοντικό.");
	else
		printf("\n\nΤο παραγοντικό του B=%d είναι: %d\n", b, res);
}

void func3(int a, int b){
	system("clear");
	float res;
	if(a>=b && a>=0 && b>=0){
		res = factor(a)/(factor(b)*factor(a-b));
		printf("\nΤο πλήθος των συνδιασμών Α ανά Β βγαίνει: %.6f", res);
	}
	else
		printf("\nΓια να υφίσταται ο συνδιασμός πρέπει να ισχύει ότι Α>=Β και να είναι και οι δύο μεγαλύτεροι του 0.\n");
}