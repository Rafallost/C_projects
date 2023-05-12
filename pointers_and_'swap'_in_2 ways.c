#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fill(int* tab, int s);

void swap2(int *int_1_p, int *int_2_p);

void swap(int* tab,int i, int j);

void bubble_sort(int* A, int n);

int main(){

	int tab[SIZE] = {0};

	fill(tab,SIZE);

		puts("The array before sorting:");

	for(int i = 0; i<SIZE; i++){

		printf("%d, ",tab[i]);

	}

	bubble_sort(tab,SIZE);

		puts("\nThe array after sorting:");		
		
	for(int i = 0; i<SIZE; i++){

		printf("%d, ",tab[i]);
	
	}
	puts("");
	
	int a = 10;
	int* w_a = &a;

	float b = 2.5f;
	float* w_b = &b;

	char c = 'x';
	char* w_c = &c;

	double d = 3.23;
	double* w_d = &d;

	puts("----------------------------------------");
	printf("value of variable int: %d\n", a);
	printf("value of variable char: %c\n", c);
	printf("value of variable float: %f\n", b);
	printf("value of variable double: %lf\n", d);

	puts("----------------------------------------");
	printf("value of pointer int: %p\n", w_a);
	printf("value of pointer char: %p\n", w_c);
	printf("value of pointer float: %p\n", w_b);
	printf("value of pointer double: %p\n", w_d);
	puts("----------------------------------------");
	printf("SIZE of variable int: %lld\n", sizeof(a));
	printf("SIZE of variable char: %lld\n", sizeof(c));
	printf("SIZE of variable float: %lld\n", sizeof(b));
	printf("SIZE of variable double: %lld\n", sizeof(d));
	puts("----------------------------------------");
	printf("SIZE of pointer int: %lld\n", sizeof(w_a));
	printf("SIZE of pointer char: %lld\n", sizeof(w_c));
	printf("SIZE of pointer float: %lld\n", sizeof(w_b));
	printf("SIZE of pointer double: %lld\n", sizeof(w_d));
	puts("----------------------------------------");
	
	
	
}

void fill(int* tab, int s){

    srand(time(NULL));	

	int a = 0, b = s-1;	

    for(int i = 0; i < s; i++){

        tab[i] = a + rand()%(b-a+1);

    }

}

void swap2(int *int_1_p, int *int_2_p){
	
	int bufor = *int_1_p;
	*int_1_p = *int_2_p;
	*int_2_p = bufor;	

}

//other way

void swap(int* tab,int i, int j){
	
	int bufor = tab[j];
	tab[j] = tab[i];
	tab[i] = bufor;	

}

void bubble_sort(int* A, int n){

	for(int i = 0; i<n; i++)
		for(int j = i+1; j<n; j++)
			if(A[i]>A[j])
			{
				//swap(A,i,j);
				swap2(&A[i],&A[j]);
			}
}
