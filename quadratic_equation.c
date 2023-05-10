#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

#define SMALL_NUMBER 1.e-20 

//#define SCALAR float
#define SCALAR double

//#define TOLERANCE 1.e-6 //for float
#define TOLERANCE 1.e-15 // for double

//#define TOLERANCE_A 1.e-6 //for float
#define TOLERANCE_A 1.e-9 //for double


void check_a(SCALAR a,SCALAR b, SCALAR c);
void check_b(SCALAR a,SCALAR b, SCALAR c);

int main(void){


  printf("\nProgram for solving the quadratic equation ax^2 + bx + c = 0\n");
	char d;

  SCALAR a = 0, b = 0, c = 0, x0 ,x1 ,x2, fi;
  
  
  puts("\nFor a = 10^-k, b = 2, c =-1, write 1");
  puts("For a = 1, b = 10^-k, c = 1, write 2");
  puts("write whatever to write it yourself");
  
  scanf(" %s",&d);
  
  switch(d){
  case '1': check_a(a,b,c); break;
  case '2': check_b(a,b,c); break;
  default: break;
  }
   
  printf("\nParameter a: "); scanf("%lf",&a); 
  printf("Parameter b: "); scanf("%lf", &b); // if we change to float to change formats
  printf("Parameter c: "); scanf("%lf", &c);
  

	if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER )	printf("Incorrect data: a and b are equal to 0 (too close to 0). Program interruption.\n"); 
	else
    {

		if(fabs(a)<TOLERANCE) 
        { 
    		
			x0 = -c/b;
			printf("This is a linear equation\n");
			printf("One real root: x = %.15lf\n", x0);
				
      		}	
   		else
        {

			SCALAR delta;  
      		delta = b*b - 4*a*c;  
                               

			if(delta<0){
				
      				fi = sqrt(fabs(delta));
      				
      				x1 = (-b+fi)/2*a; 
      				x2 = (-b-fi)/2*a;
	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two complex elements: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
			
			}
			else if (delta == 0)
            {

				x0 = -b/(2*a);
	
				if(fabs(x0)<TOLERANCE)	printf("The root is less than the tolerance!!!: x = %.15lf ", x0);
				else	printf("One real root: x = %.15lf\n", x0);
				
			}
			else 
            {

				SCALAR temp = sqrt(delta);
				x1 = (-b+temp)/(2*a);
				x2 = (-b-temp)/(2*a);
				
					puts("\n\tMethod 1\n");
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					puts("\n\tMethod 2\n");
				x1 = (-b+temp)/2*a;
				x2 = c/(a*x1);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					puts("\n\tMethod 3\n");
				x1 = (-b+temp)/2*a;
				x2 = (-b/a)-x1;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					puts("\n\tMethod 4\n");
				x2 = (-b-temp)/2*a;
				x1 = c/(a*x2);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					puts("\n\tMethod 5\n");
				x2 = (-b-temp)/2*a;
				x1 = (-b/a)-x2;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
	
      			}	 
   		}
	}

  return(0);
}

void check_a(SCALAR a,SCALAR b, SCALAR c){

	printf("For a = 10^-k, b = 2, c =-1 \n\n");
	
	SCALAR x1,x2,x0,fi;
	
	b = 2, c = -1;
	
	for(int k = 5; k <=15; k++){
	
		a = pow(10,-k);
		printf("k = %d : \n",k);

		  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER )	printf("Incorrect data: a and b are equal to 0 (too close to 0). Program interruption.\n");
  		  else{

    		  	if(fabs(a)<TOLERANCE_A){ 
				
				x0 = -c/b;
				printf("This is a linear equation\n");
				printf("One real root: x = %.15lf\n", x0);
				
      			}	
   		 	else{

      			SCALAR delta;  
      			delta = b*b - 4*a*c;            
      			
      				if(delta<0){
      				
      					fi = sqrt(fabs(delta));
      					
      					x1 = (-b-fi)/2*a; 
      					x2 = (-b+fi)/2*a;
      					
					if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else	printf("Two complex elements: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
      					       					
      				
      				}
  				else if (delta == 0){

					x0 = -b/(2*a);
	
					if(fabs(x0)<TOLERANCE)	printf("The root is less than the tolerance!!!: x = %.15lf ", x0);
					else	printf("One real root: x = %.15lf\n", x0);
				
      				}
      				else {

				SCALAR temp = sqrt(delta);
				x1 = (-b+temp)/(2*a);
				x2 = (-b-temp)/(2*a);
				
					//puts("\n\tMethod 1\n");
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				/* 
				
					
                For the sake of readability of the results, only 1 method of counting has been left
				
					//puts("\n\tMethod 2\n");
				x1 = (-b+temp)/2*a;
				x2 = c/(a*x1);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 3\n");
				x1 = (-b+temp)/2*a;
				x2 = (-b/a)-x1;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 4\n");
				x2 = (-b-temp)/2*a;
				x1 = c/(a*x2);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 5\n");
				x2 = (-b-temp)/2*a;
				x1 = (-b/a)-x2;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				*/
      				}
   		 	}	 
		  }
	}
	exit(-1);	 
}

void check_b(SCALAR a,SCALAR b, SCALAR c){

	printf("For a = 1, b = 10^-k, c =1 \n\n");
	
	SCALAR x1,x2,x0,fi;
	
	a = 1, c = 1;
	
	for(int k = 2; k <=10; k++)
    {
	
		b = pow(10,k);
		printf("k = %d : \n",k);

		  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER )	printf("Incorrect data: a and b are equal to 0 (too close to 0). Program interruption.\n");
  		  else{

    		  	if(fabs(a)<TOLERANCE_A){ 
				
				x0 = -c/b;
				printf("This is a linear equation\n");
				printf("One real root: x = %.15lf\n", x0);
				
      			}	
   		 	else
            {

      			SCALAR delta;  
      			delta = b*b - 4*a*c;            
      			
      				if(delta<0)
                    {
      				
      					fi = sqrt(fabs(delta));
      					
      					x1 = (-b-fi)/2*a; 
      					x2 = (-b+fi)/2*a;
      					
					if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
					else	printf("Two complex elements: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
      					       					
      				
      				}
  				else if (delta == 0)
                {

					x0 = -b/(2*a);
	
					if(fabs(x0)<TOLERANCE)	printf("The root is less than the tolerance!!!: x = %.15lf ", x0);
					else	
					printf("One real root: x = %.15lf\n", x0);
				
      				}
      				else {

				SCALAR temp = sqrt(delta);
				x1 = (-b+temp)/(2*a);
				x2 = (-b-temp)/(2*a);
				
					// puts("\n\tMethod 1\n");
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 2\n");
				x1 = (-b+temp)/2*a;
				x2 = c/(a*x1);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 3\n");
				x1 = (-b+temp)/2*a;
				x2 = (-b/a)-x1;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
				
				
					//puts("\n\tMethod 4\n");
				x2 = (-b-temp)/2*a;
				x1 = c/(a*x2);	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				
					//puts("\n\tMethod 5\n");
				x2 = (-b-temp)/2*a;
				x1 = (-b/a)-x2;	
				if(fabs(x1)<TOLERANCE && fabs(x2)<TOLERANCE) printf("Elements are smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x1)<TOLERANCE)	printf("Root x1 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else if(fabs(x2)<TOLERANCE)	printf("Root x2 smaller than tolerance!!!: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
				else	printf("Two real roots: x1 = %.15lf, x2 = %.15lf\n", x1, x2);
	
				
      				}
   		 	}	 
		  }
	}
	exit(-1);	 
}

