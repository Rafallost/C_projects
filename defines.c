#include <stdio.h> 
#include <math.h> 
#include <stdbool.h>

#define TOLERANCE 1e-12
int main(void)
{

    //some defines

	#define NUMBER 6
	#define PRODUCT(x,y) (x)*(y)
	#define COUT(text) printf("%s\n", text)
	#define AVG(sum,amount) printf("Average : %g\n",sum/amount)


		printf("Number: %d\n", NUMBER);
		printf("product: %d\n", PRODUCT(NUMBER,2));
		AVG(15.,4.0);
		COUT("my cout");

    
    //precision testing

    float f1 = 1.5f/2.5f;  
    float f2 = 1.5f/2.5; 
    float f3 = 1.5/2.5;
    double d1 = 1.5/2.5; 
    double d2 = 1.5f/2.5; 
    double d3 = 1.5f/2.5f;
    
    printf("\tFloating point numbers:\n\n");
    	printf("For %%f\n");
    printf("float  -  f1 = 1.5f/2.5f = %f  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.5f/2.5 = %f  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.5/2.5 = %f  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.5/2.5 = %f  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.5f/2.5 = %f  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.5f/2.5f = %f  (Exactly: %0.20lf)\n", d3, d3);
        printf("For %%e\n");
    printf("float  -  f1 = 1.5f/2.5f = %e  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.5f/2.5 = %e  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.5/2.5 = %e  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.5/2.5 = %e  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.5f/2.5 = %e  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.5f/2.5f = %e  (Exactly: %0.20lf)\n", d3, d3);
        printf("For %%g\n");
    printf("float  -  f1 = 1.5f/2.5f = %g  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.5f/2.5 = %g  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.5/2.5 = %g  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.5/2.5 = %g  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.5f/2.5 = %g  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.5f/2.5f = %g  (Exactly: %0.20lf)\n", d3, d3);
    
     f1 = 1.2f/2.3f;  
     f2 = 1.2f/2.3; 
     f3 = 1.2/2.3;
     d1 = 1.2/2.3; 
     d2 = 1.2f/2.3; 
     d3 = 1.2f/2.3f;
    
        	printf("For %%f\n");
    printf("float  -  f1 = 1.2f/2.3f = %f  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.2f/2.3 = %f  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.2/2.3 = %f  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.2/2.3 = %f  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.2f/2.3 = %f  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.2f/2.3f = %f  (Exactly: %0.20lf)\n", d3, d3);
            printf("For %%e\n");
    printf("float  -  f1 = 1.2f/2.3f = %e  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.2f/2.3 = %e  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.2/2.3 = %e  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.2/2.3 = %e  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.2f/2.3 = %e  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.2f/2.3f = %e  (Exactly: %0.20lf)\n", d3, d3);
        printf("For %%le\n");
    printf("float  -  f1 = 1.2f/2.3f = %le  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.2f/2.3 = %le  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.2/2.3 = %le  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.2/2.3 = %le  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.2f/2.3 = %le  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.2f/2.3f = %le  (Exactly: %0.20lf)\n", d3, d3);
        printf("For %%g\n");
    printf("float  -  f1 = 1.2f/2.3f = %g  (Exactly: %0.20f)\n", f1, f1);
    printf("float  -  f2 = 1.2f/2.3 = %g  (Exactly: %0.20f)\n", f2, f2);
    printf("float  -  f3 = 1.2/2.3 = %g  (Exactly: %0.20f)\n", f3, f3);
    printf("double  -  d1 = 1.2/2.3 = %g  (Exactly: %0.20lf)\n", d1, d1);
    printf("double  -  d2 = 1.2f/2.3 = %g  (Exactly: %0.20lf)\n", d2, d2);
    printf("double  -  d3 = 1.2f/2.3f = %g  (Exactly: %0.20lf)\n", d3, d3);
    

    printf("\tMath logic\n\n");

	printf("(((p||q)&&r))==((p&&r)||(q&&r))\n");
	
	int p = 1 ,q = 1 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	_Bool 	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);
	
	p = 1 ,q = 1 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);
	
	p = 1 ,q = 0 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);		
		
	p = 0 ,q = 0 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);	
		
	p = 0 ,q = 0 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);
	
	p = 0 ,q = 1 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);	
	
	p = 1 ,q = 0 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);

	p = 0 ,q = 1 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p||q)&&r))==((p&&r)||(q&&r));
	printf("odp:%d\n",a);
	
		printf("(((p&&q)||r))==((p||r)&&(q||r))\n");
	
	p = 1 ,q = 1 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);
	
	p = 1 ,q = 1 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);
	
	p = 1 ,q = 0 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);		
		
	p = 0 ,q = 0 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);	
		
	p = 0 ,q = 0 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);
	
	p = 0 ,q = 1 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);	
	
	p = 1 ,q = 0 ,r = 1;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);

	p = 0 ,q = 1 ,r = 0;
	printf("p = %d,q = %d,r = %d : ",p,q,r);
	
	a = (((p&&q)||r))==((p||r)&&(q||r));
	printf("odp:%d\n",a);
	
	
	
	p = 0 ,q = 0 ,r = 0;
	printf("p = %d,q = %d,r = %d : \n",p,q,r);
	printf("(((p&&q)||r))==((p||r)&&(q||r)) odp: %d\n",(((p&&q)||r))==((p||r)&&(q||r)));
	printf("((p&&q)||r)==(p||r)&&(q||r)odp: %d\n",((p&&q)||r)==(p||r)&&(q||r));
	printf("(p&&q)||r==(p||r)&&(q||r) odp: %d\n",(p&&q)||r==(p||r)&&(q||r));
	printf("p&&q||r==p||r&&q||r odp: %d\n",p&&q||r==p||r&&q||r);
	printf("(p&&q||r)==(p||r&&q||r) odp: %d\n",(p&&q||r)==(p||r&&q||r));
	
	
    //prioritization testing
    printf("\tPrioritization testing\n\n");
  int n = 1, m=1, w;
  
  printf("\tn = %d, m = %d\n", n, m);

	w = n+m;
 
  printf("po operacji w = n+m: w = %d: n = %d, m = %d\n", w, n, m);
	n = 1, m=1,
  	w = n+++m;
 
  printf("po operacji w = n+++m: w = %d: n = %d, m = %d\n", w, n, m);
  
	n = 1, m=1,
	w = n++ + ++m;	
  printf("po operacji w = n++ + ++m: w = %d: n = %d, m = %d\n", w, n, m);
  
  	n = 1, m=1,
	w = n++ + m++;
  printf("po operacji w = n++ + m++: w = %d: n = %d, m = %d\n", w, n, m);
  
    	n = 1, m=1,
	w = ++n + ++m;
  printf("po operacji w = ++n + ++m: w = %d: n = %d, m = %d\n", w, n, m);
  
      	n = 1, m=1,
	w = n++ + (m+=2);
  printf("po operacji w = n++ + m+=2: w = %d: n = %d, m = %d\n", w, n, m);
  
        n = 1, m=1,
	w = (n-=1) + (m*=3);
  printf("po operacji w = (n-=1) + (m*=3): w = %d: n = %d, m = %d\n", w, n, m);

	n = 1, m=1,
	w = n-- - --m;	
  printf("po operacji w = n-- - --m: w = %d: n = %d, m = %d\n", w, n, m);
  
		n = 1, m=1;
	
	if(--m)printf("if(--m) zwraca 1\n");
	else printf("if(--m) zwraca 0\n");
	
		n = 1, m=1;
	
	if(m--)printf("if(m--) zwraca 1\n");
	else printf("if(m--) zwraca 0\n");
	
	
		n=5,m=4;
	  printf("\tn = %d, m = %d\n", n, m);
	         
	w = (n%=2) + (m/=2);
  printf("po operacji w = (n%%=2) + (m/=2): wynik = %d: n = %d, m = %d\n", w, n, m);
  
  		n=5,m=4;
  	w = (n-=5) + (m--);
  printf("po operacji w = (n-=5) + (m--): wynik = %d: n = %d, m = %d\n", w, n, m);
  
  

    printf("\nFloat and double precision issues:\n");

    float fx1 = 1.23e7;
    float fx2 = 1.23e-7;

    printf("\nfloat: fx1 = %20.15lf, fx2 = %20.15lf, \n", fx1, fx2);
    
    if( (fx1+fx2)-fx1 == fx2 ){
      printf("\n(fx1+fx2)-fx1 == fx2 (dla float)\n");
    }
    else {
      printf("\n(fx1+fx2)-fx1 != fx2 (dla float) ( (fx1+fx2)-fx1 = %.15lf )\n",(fx1+fx2)-fx1);
    }

    double dx1 = 1.23e7;
    double dx2 = 1.23e-7;


    printf("\ndouble: dx1 = %20.15lf, dx2 = %20.15lf, \n",dx1, dx2);
    if( (dx1+dx2)-dx1 == dx2 ){
      printf("\n(dx1+dx2)-dx1 == dx2 (dla double)\n");
    }
    else {
      printf("\n(dx1+dx2)-dx1 != dx2 (nawet dla double!) ( (dx1+dx2)-dx1 = %.15lf )\n",
    	   (dx1+dx2)-dx1);
    }
 
  	  if( fabs ((fx1+fx2)-fx1) < TOLERANCE){
      printf("\nTrying to divide by a number close to zero! Program interruption!\n");    
    return(-1);    
 	  }

    float fx3 = 1.0f / ((fx1+fx2)-fx1); 
    printf("\n1.0f / ((fx1+fx2)-fx1) = %20.15lf\n", fx3);
  
    double dx3 = 1.0 / ((dx1+dx2)-dx1); 
    printf("\n1.0/((dx1+dx2)-dx1) = %.12lf  != 1.0/dx2 = %.12lf\n", dx3, 1.0/dx2);
    printf("Only three significant figures left due to finite precision...\n");


  return(0);
}
