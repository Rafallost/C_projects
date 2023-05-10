#include <stdio.h>
#define size 10

//to trun of use ctrl+z and enter
// a program for counting digits and other characters in the read string

int main() { 

	int sign, white = 0, others = 0, lines = 0;
	int tab[size] = {0};
	
	while((sign = getchar())!= EOF){
	
		if(sign<=57 && sign>=48)
		{
			tab[sign - '0']++;
		}	
		else if(sign == ' '||sign == '\t') 
		{
			white++;
		}
		else if(sign == '\n')
		{
			white++;
			lines++;
		}
		else
		{
			others++;
		}
	}
	
	for(int i = 0; i<size; i++) 
	printf("'%d' = %d times\n",i,tab[i]);

	printf("Amount of white signs: %d\n",white);
	printf("In this: %d lines \n",lines);
	printf("Amount of other signs: %d\n",others);

return 0;
}
