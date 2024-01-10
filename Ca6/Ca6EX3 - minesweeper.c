/*
	Μάρκος Παντελιδάκης - 18390228
	Το παρακάτω πρόγραμμα μεταγλωτήστηκε με gcc compiler και εκτελέστηκε σε περιβάλλον linux-Ubuntu.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int*, int*, int*);
void mineplacement(char**, int, int, int);
void numbers(char**, int, int);
void printTable(char**, int, int);

int main(int argc, char *argv[]){
	int i=0, j;
	int M,L,C;

	do{
		system("clear");
		input(&L,&C,&M);
		if(L*C>=M)
			break;
	}while(i==0);
	
	char **arr=malloc(L*sizeof(char*));
	
	for(i=0;i<L;i++)
		arr[i]=malloc(C*sizeof(char));	

	mineplacement(arr,L,C,M);
	numbers(arr,L,C);
	printTable(arr,L,C);
	
	FILE *fp;
	fp = fopen("minesweeper.txt", "w");
	if(fp == NULL){
		perror("-error- An error has occured while opening the selected file(fp)");
		exit(1);
	}
	for(i=0; i<L; i++){
		for(j=0; j<C; j++)
			fprintf(fp, "%c\t", arr[i][j]);
		fprintf(fp,"\n");	
	}
	fclose(fp);
	
	for(i=0; i<C; i++)
		free(arr[i]);
	free(arr);
	return 0;
}

void input(int *lines, int *columns, int *mines){
	int l,c,m;
	printf("\nΕισάγετε αριθμό γραμμών: ");
	scanf("%d", lines);
	printf("\nΕισάγετε αριθμό στήλων: ");
	scanf("%d", columns);
	printf("\nΕισάγετε αριθμό βομβών: ");
	scanf("%d", mines);
	l=*lines;
	c=*columns;
	m=*mines;
	if(l*c<m){
		printf("Ο αριθμός των βομβών πρέπει να είναι μικρότερος από το πλήθος των θέσεων του πίνακα.\nΠαρακαλώ εισάγετε ξανά τα στοιχεία.\n");
		printf("--------------------------------------------------------------------------------------------------------------------------");
	}
}

void mineplacement(char **arr, int lines, int columns, int mines){
	srand(time(NULL));
	int i, j, l, c, count=0;
	
	for(i=0; i<lines; i++){
		for(j=0; j<columns; j++)
			arr[i][j]='0';
	}
	
	while(count<mines){
		l=rand()%(lines);
		c=rand()%(columns);
		if(arr[l][c] != '*'){
			arr[l][c] = '*';
			count++;
		}
	}
}

void numbers(char **arr, int lines, int columns){
	int i, j;
	for(i=0; i<lines; i++){
		for(j=0; j<columns; j++){
			if(arr[i][j] != '*'){
				if((i+1<lines) && (j+1<columns) && (arr[i+1][j+1] == '*'))
					arr[i][j]++;
				if((i+1<lines) && (arr[i+1][j] == '*'))
					arr[i][j]++;
				if((j+1<columns) && (arr[i][j+1] == '*'))
					arr[i][j]++;
				if((i+1<lines) && (j-1>=0) && (arr[i+1][j-1] == '*'))
					arr[i][j]++;
				if((i-1>=0) && (j+1<columns) && (arr[i-1][j+1] == '*'))
					arr[i][j]++;
				if((i-1>=0) && (arr[i-1][j] == '*'))
					arr[i][j]++;
				if((j-1>=0) && (arr[i][j-1] == '*'))
					arr[i][j]++;
				if((i-1>=0) && (j-1>=0) && (arr[i-1][j-1] == '*'))
					arr[i][j]++;
			}
		}	
	}
}

void printTable(char **arr, int lines, int columns){
	int i,j;
	for(i=0; i<lines; i++){
		for(j=0; j<columns; j++)
			printf("%c\t", arr[i][j]);
		printf("\n");
	}
}
