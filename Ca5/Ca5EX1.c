#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "POWERnFACTOR.h"

#define PI 3.14159265358979323846
#define DIFF 0.000001

int input();
double DegtoRad(double);
double SineCalc(double);
double CosineCalc(double);
int validation(double,double);


int main(int argc, char **argv){
	double deg = input();
	double rad = DegtoRad(deg);
	double sine = SineCalc(rad);
	double cosine = CosineCalc(rad);
	printf("\n-=====================================================-\n");
	printf(" Η τιμή της συνάρτησης μου για Sine(%.4f)= %.6f\n H τιμή της έτοιμης συνάρτησης sin(%.4f)= %.6f\n", deg, sine, deg, sin(rad));
	if(!validation(sine,sin(rad)))
		printf(" Ανεπιτυχής υπολογισμός ημιτόνου με μεγάλη ακρίβεια.");
	else
		printf(" Επιτυχής υπολογισμός ημιτόνου με μεγάλη ακρίβεια!\n");
	printf("--------------------------------------------------------");
	printf("\n Η τιμή της συνάρτησης μου για Cosine(%.4f)= %.6f\n H τιμή της έτοιμης συνάρτησης cos(%.4f)= %.6f\n", deg, cosine, deg, cos(rad));
	if(!validation(cosine,cos(rad)))
		printf(" Ανεπιτυχής υπολογισμός συνημιτόνου με μεγάλη ακρίβεια.");
	else
		printf(" Επιτυχής υπολογισμός συνημιτόνου με μεγάλη ακρίβεια!");
	printf("\n-=====================================================-\n");
	return 0;
}

int input(){
	int x;
	while(x<0 || x>360){
		printf("\nΠαρακαλώ εισάγετε μία τιμή από 0 έως 360 για την κλίση της γωνίας σε μοίρες: ");
		scanf("%d", &x);
		system("clear");
	}
	return x;
}

double DegtoRad(double deg){
	return deg * (PI/180);
}

double SineCalc(double rad){
	int exp=1, sign=1;
	double xPrev, xNext, res=0; //res-->result, το ημίτονο
	xNext = power(rad, exp)/factor(exp); //Η πράξη x^(n+2)/x!
	//printf("\n%f\n", xNext);
	while(fabs(xPrev - xNext) > DIFF){
		res+=sign*xNext;
		sign = -sign; 					 //Η προσημία του κάθε κλάσματος πρέπει να αλλάζει εναλλάξ βάσει τύπου, το ίδιο ισχύει και για το cosine.
		//printf("%f\n", res);
		exp += 2;						 //Το ανάπτυγμα σειράς Taylor λέει πως ο εκθέτης αυξάνεται κατά 2, εξού και exp=exp+2 με κάθε επανάληψη
		xPrev = xNext;
		xNext = power(rad,exp)/factor(exp);
	}
	return res;
}
// Ισχύει η ίδια λογική με της SineCalc για τη CosineCalc συνάρτηση, με τη διαφορά ότι ο εκθέτης(exp) αρχικοποιείται με τη τιμή 0 ώστε στη γραμμή 78
// (exp += 2;) να αυξηθεί κατά δύο κι από εκεί και ύστερα να παίρνει ζυγούς αριθμούς όπως και στον τύπο.
double CosineCalc(double rad){
	int exp=0, sign=1;
	double xPrev, xNext=1, res=0; 		 //res-->result, το συνημίτονο
	while(fabs(xPrev - xNext) > DIFF){
		res+=sign*xNext;
		sign = -sign; 					 		
		//printf("%f\n", res);
		exp += 2;					
		xPrev = xNext;
		xNext = power(rad,exp)/factor(exp);
	}
	return res;
}

int validation(double better,double lesser){
	if(fabs(better-lesser) < 0.000009) //Αφαίρεση των τιμών που έβγαλα από τις δικές μου συναρτήσεις για sine και cosine από αυτές που βγήκαν από της <math.h>
		return 1;
	else
		return 0;
}