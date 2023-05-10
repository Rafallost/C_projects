#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M_LN2		0.69314718055994530942

#define SCALAR double // choose the type you want to work with  (remember to command second one)
//#define SCALAR float

int main(){

	int iteration;
	SCALAR ln2 = 0;

	printf("Enter the number of iterations (I don't recommend more than 10000) : ");
	scanf("%d",&iteration);

	if(sizeof(SCALAR)==4) //Command specifying what type is currently set
	{ 
		int n = 1;
	
		while(n<iteration+1){ 

			ln2 += pow((-1),n-1)*pow((2-1),n)/(float)n; //Taylor series lnx = (-1)^n-1 * ((x-2)^n)/n	
			printf("current number : %.21f	,math.h number: %.21f , difference : %.21f\n",ln2,M_LN2,fabs(M_LN2-ln2));
		 	n++;
		}
		printf("\tUsing type variables float and done %d iteration\n\n",iteration);
		printf("We finally got the number              : %.21f\n",ln2);
		printf("ln2 in the library has a value         : %.21f\n",M_LN2);
		printf("These values differ from each other by : %.21f\n",fabs(M_LN2-ln2));
	}
	else
	{
	
		for(int n = 1; n<iteration+1; n++){ //dla urozmaicenia uzylem roznych petli

			ln2 += pow((-1),n-1)*pow((2-1),n)/(double)n; //Szerego Taylora lnx = (-1)^n-1 * ((x-2)^n)/n
			printf("Akutualnie : %.21lf ,Liczba w bibliotece %.21lf , roznica: %.21lf\n",ln2,M_LN2,fabs(M_LN2-ln2));	
			
		}
		printf("\tUsing type variables double and done %d iteration\n\n",iteration);
		printf("We finally got the number              : %.21lf\n",ln2);
		printf("ln2 in the library has a value         : %.21lf\n",M_LN2);
		printf("These values differ from each other by : %.21lf\n",fabs(M_LN2-ln2));
	}  

return 0;
}
