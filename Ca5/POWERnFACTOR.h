// Οι συναρτήσεις αυτού του αρχείου καλούνται και από τα δύο προγράμματα Ca5EX1.c και Ca5EX2.c
// για τις ασκήσεις 1 και 2 της εργασίας 5
double power(double base, int exp){
	int i;
	double res=1;
	
	while(exp < 0){
		res/=base;
		exp++;		
	}
	//printf("res=%f, exp=%d", res, exp);
	if(exp > 0){
		for(i=0; i < exp; i++)
			res*=base;
	}
	return res; 
}

double factor(int num){
	int i;
	double res=1;
	for(i=1; i<= num; i++)
		res*=i;
	if(num<0)
		return 0; 
	else
		return res;
}