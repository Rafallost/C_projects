#include <stdio.h>
#include <assert.h>

int power_int(int base, int n);
int power_int_rekur(int m, int n);


int statycznaRekur()
{
   static int liczba_wywolan_rekur = 0;
  return ++liczba_wywolan_rekur;
}
 
int statycznaIt()
{
  static int liczba_wywolan_it = 0;
  return ++liczba_wywolan_it;
  
}
  
int main (int argc, char** argv) 
{
	printf("write argc: ");
	scanf("%d",&argc);
	printf("write argv: ");
	scanf("%s",*argv);
	
   int base = argc;
   int exp = my_atoi(*argv);
 
   printf("Command line data: %d^%d=%d number of calls iteratively:", base, exp, power_int(base,exp));
   printf(" %d\n",statycznaIt()-1);

   printf("Command line data: %d^%d=%d number of calls recursively:", base, exp, power_int_rekur(base,exp));
   printf(" %d\n",statycznaRekur()-1);

  FILE* wsk_do_pliku;

  wsk_do_pliku = fopen("dane.txt","r");
  if(wsk_do_pliku==NULL) {
  puts("There is no such file"); return 0;
  }

  fscanf(wsk_do_pliku,"%d",&argc);
  fscanf(wsk_do_pliku,"%s",*argv);
  
  fclose(wsk_do_pliku);

  int base_f = argc;
  int exp_f = atoi(*argv);
 
  printf("Data from files: %d^%d=%d\n", base_f, exp_f, power_int_rekur(base_f,exp_f));

  
  return 0;
}

int power_int(int base, int n)
{
  int i, p;
  p=1;
  for (i = 1; i <= n; ++i){
	  printf("Iterative call (loop repetitions) nr: %d\n",statycznaIt());
    p = p * base;
  }
  return p;
}


int power_int_rekur(int m,int n){

	printf("Recursive call no: %d\n",statycznaRekur());
	
	assert(n>=0);
	
  if(n==0) return 1;
  else if(n == 1) return(m);
  
  int cokolwiek = power_int_rekur(m,n-1);

	return cokolwiek*m;
  

}


int my_atoi(char s[])
{
  int sign=1; // = (s[0]=='-') ? -1 : 1;
  if(s[0]=='-') sign=-1;
  int i=0;
  if (s[0]=='+' || s[0]=='-') i++;  
  int n = 0;
  while( s[i] >= '0' && s[i] <= '9' ) {
    n = 10 * n + (s[i] - '0');
    i++;
  }
  return sign*n;
}