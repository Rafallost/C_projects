#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ACCURACY (1.e-5)
#define ACCURACY_double (1.e-9)

double sum(double a, double b);

double difference (double a, double b);

double product(double a, double b);

double quotient(double a, double b);

double quotient_precisely(double a, double b);

int exponentiation_int(int a, int b);

double square_root(double a);

double square_root_other(double a);

int factorial (int a);

void horner();

int hornerus(int*,int,int);

int main(){


	puts("Select option");

	puts("0:sum");
	puts("1:difference ");
	puts("2:product");
	puts("3:quotient");
	puts("4:exponentiation");
	puts("5:square_root");
	puts("6:factorial ");
	puts("7:calculation of the polynomial value using the horner scheme");
	puts("8:square_root in other way");
	puts("9:quotient more precisely");
	
	
	char a;
	double x,y;
	scanf("%c",&a);
	if(a=='0'||a=='1'||a=='2'||a=='3'||a=='4'||a=='9')
	{
		printf("Write a: ");
		scanf("%lf",&x);
		printf("\nWrite b: ");
		scanf("%lf",&y);
	}
	else if(a=='7')
	{
		
		horner();
	
	}
	else
	{
		printf("Write number: ");
		scanf("%lf",&x);
	
	}



switch(a)
{
	case '0': printf("\n%lf\n",sum(x,y)); break;
	case '1': printf("\n%lf\n",difference (x,y)); break;
	case '2': printf("\n%lf\n",product(x,y)); break;
	case '3': printf("\n%lf\n",quotient(x,y)); break;
	case '4': printf("\n%d\n",exponentiation_int(x,y)); break;
	case '5': printf("\n%lf\n",square_root(x)); break;
	case '6': printf("\n%d\n",factorial (x)); break;
	case '7': break;
	case '8': printf("\n%lf\n",square_root_other(x)); break;
	case '9': printf("\n%lf\n",quotient_precisely(x,y)); break;
	default : puts("\nNie ma takiej opcji!"); break;
}

}

double square_root_other(double a){

	if(a<0.0){
		puts("There are no real roots of negative numbers");
		exit(0);
	}
	else if(fabs(a)<ACCURACY)
	{
		return a;
	}

	double bok1 = a;
	double bok2 = a/bok1;
	
	
	if(fabs(bok1-bok2) < ACCURACY)
		return bok1;
	
	do{
		bok1 = (bok1 + bok2)/2.0;
		bok2 = a/bok1;
	}
	while(fabs(bok1-bok2) > ACCURACY);
	
	return bok1;
}


double square_root(double a){

	if(a<0.0){
		puts("There are no real roots of negative numbers");
		exit(0);
	}
	
    double pierwiastek = 1.0;
    double temp;
	
	do{
      	 	 temp = pierwiastek;
       	 pierwiastek = 0.5 * (temp + a/temp);
       } 
       while(fabs(pierwiastek*pierwiastek - a)/a > ACCURACY); 
    

	return pierwiastek;

}

int hornerus(int *tab,int st,int arg){

	int wynik = tab[st];

	for(int i=1;i<=st;i++)
		wynik = wynik*arg + tab[st-i];
	
	return wynik;

}

void horner(){

	int *tablica;
	int stopien, argument, wynik;
	
	puts("Write maximum degree of a polynomial: ");
	scanf("%d",&stopien);
	
	tablica = (int*)malloc(stopien * sizeof(int));
	
	for(int i = 0;i<=stopien; i++){
	
		printf("enter value at x^%d: ",stopien - i);
		scanf("%d",&tablica[stopien - i]);
	}
	
	for(int i = 0;i<=stopien;i++){
	
		if(tablica[stopien-i]>=0)
			printf("+%dx^%d",tablica[stopien-i],stopien-i);
		else	
			printf("%dx^%d",tablica[stopien-i],stopien-i);
	}
	
	puts("");
	
	printf("Write for which argument do you want to calculate the value of the polynomial: ");
	scanf("%d",&argument);
	
	wynik = hornerus(tablica,stopien,argument);
	
	printf("W(%d) = %d\n",argument,wynik);
	
	free(tablica);

}


int factorial (int a){

	int wynik = 1;

	for(int i = 2; i<=a; i++){

		wynik*=i;
	
	}

	return wynik;

}

int exponentiation_int(int podstawa, int wykladnik){

  	int potega = 1;
  	
 	 for (int i = 1; i <= wykladnik; i++){
 	   potega *= podstawa;
 	 }
 	 return potega;
}

double sum(double a, double b){

	return a+b;

}

double difference (double a, double b){

	return a-b;

}

double product(double a, double b){

	return a*b;
}

double quotient(double a, double b){

	if(b==0)
	{
	puts("You can't divide by 0!!!");
	exit(0);
	}
	else
	 return a/b;
}

double quotient_precisely(double a, double b){

	if(b<ACCURACY_double)
	{
	puts("You can't divide by 0!!!");
	exit(0);
	}
	else
	 return a/b;
}

