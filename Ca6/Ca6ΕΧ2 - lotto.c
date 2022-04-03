#include <stdio.h>
#include <stdlib.h>

int SearchMatrix(int*, int, int);
void SortMatrix(int*, int);
void swapPTR(int*, int*);
int EvenOdd(int);

int main(int argc, char **argv){
	int n, x1, x2, y1, y2, R, even=0, sum=0, cond1, not_cond1, cond12, total_comb;
	cond1 = cond12 = not_cond1 = total_comb = 0;
	int i, j, k, l, m, p; //Δήλωση μεταβλητών μετρητών

	do{
		system("clear");
		printf("\nΠαρακαλώ εισάγετε έναν αριθμό για το πλήθος των στοιχείων 'n' από 7 έως 49: ");
		scanf("%d", &n);
	}while(n<7 || n>49);
	
	int *arr=(int*)malloc(n*sizeof(int));
	
	for(i=0; i<n; i++){
		do{
			printf("\nΠαρακαλώ εισάγετε τιμή %dου στοιχείου: ", i+1);
			scanf("%d", &R);
			if(!SearchMatrix(arr, i, R))
				*(arr+i) = R;
		}while(*(arr+i)<1 || *(arr+i)>49);
	}

	do{
		printf("\nΕισάγετε τιμή για Χ1 για τον οποίο θα ισχύει 0 <= X1 <= 6: ");
		scanf("%d", &x1);
	}while(x1<0 || x1>6);
	
	do{
		printf("\nΕισάγετε τιμή για Χ2 για τον οποίο θα ισχύει X1 <= X2 <= 6: ");
		scanf("%d", &x2);
	}while(x2<x1 || x2>6);
	//Τα X1 και X2 εκφράζουν το πόσους ζυγούς αριθμούς θα χρειαστεί μία εξάδα για να την μετρήσουμε στη συνέχεια.
	
	printf("\n--------------------------------------------------------\n");
	
	do{
		printf("\nΕισάγετε τιμή για Y1 για τον οποίο θα ισχύει 21 <= Y1 <= 279: ");
		scanf("%d", &y1);
	}while(y1<21 || y1>279);
	//Τα Y1 και Y2 εκφράζουν τα όρια του αθροίσματος της εξάδας που θα υπολογίσει το πρόγραμμα στη συνέχεια.
	
	do{
		printf("\nΕισάγετε τιμή για Y2 για τον οποίο θα ισχύει Y1 <= Y2 <= 279: ");
		scanf("%d", &y2);
	}while(y2<y1 || y2>279);

	
	SortMatrix(arr, n);
	printf("\n");
	for(i=0; i<n-5; i++){
		if(!EvenOdd(*(arr+i)))
			even++;
		for(j=i+1; j<n-4; j++){
			if(!EvenOdd(*(arr+j)))
				even++;
			for(k=j+1; k<n-3; k++){
				if(!EvenOdd((*arr+k)))
					even++;
				for(l=k+1; l<n-2; l++){
					if(!EvenOdd((*arr+l)))
						even++;
					for(m=l+1; m<n-1; m++){
						if(!EvenOdd((*arr+m)))
							even++;
						for(p=m+1; p<n; p++){
							total_comb++;  // Σε αυτό το σημείο δεν έχουν τεθεί ακόμα περιορισμοί και απλά συγκαταλέγεται στο σύνολο ο κάθε συνδιασμός.
							if(!EvenOdd((*arr+p)))
								even++;
							 
							sum = *(arr+i) + *(arr+j) + *(arr+k) + *(arr+l) + *(arr+m) + *(arr+p);
							if(even>=x1 && even<=x2){	
								if(sum>=y1 && sum<=y2){
									printf("|%d %d %d %d %d %d|\n", *(arr+i),  *(arr+j), *(arr+k), *(arr+l), *(arr+m), *(arr+p) );
									cond12++;
								}
								else
									cond1++;
							}
							else if(sum>y1 && sum<y2)
								not_cond1++;
						}
					}
				}
			}
		}
	}
	printf("\n===============================================\n");
	printf("Πλήθος συνδυασμών των Ν αριθμών ανά 6 : %d\n", total_comb);
	printf("Πλήθος συνδυασμών όπου δεν πληρούσαν τον 1ο όρο: %d\n", not_cond1);
	printf("Πλήθος συνδυασμών όπου πληρούσαν τον πρώτο, αλλά όχι τον δεύτερο όρο: %d\n", cond1);
	printf("Πλήθος συνδυασμών όπου τυπώθηκαν : %d\n", cond12);
	printf("=================================================\n");

	free(arr);
	return 0;
}

int SearchMatrix(int *mat, int len, int val){
	int i;
	for(i=0; i<len; i++)
		if(*(mat+i) == val)
			return 1;
	return 0;
}

void SortMatrix(int *mat, int len){
	int i, j, mid_idx;
	
	for(i=0; i<len; i++){
		mid_idx = i; //Αρχικοποίηση μέγιστης προσωρινά τιμής με 0
		for(j=i+1; j<len; j++)
			if(*(mat+j) < *(mat+mid_idx))
				mid_idx = j;
		swapPTR(mat+mid_idx, mat+i); //Αλλαγή διέυθυνσης μικρότερης συγκριτικά τιμής με αυτή του προηγούμενου στοιχείου	
	}
}

void swapPTR(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int EvenOdd(int val){
	if(val % 2 == 0)
		return 0;
	return 1;
}
