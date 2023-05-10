#include <stdio.h>
#include <string.h>

#define SIZE 100

void zrob(char *string){

 	int range = SIZE - 1; 
 	int sign; 
	int i;
	
 	for (i=0; i<range && (sign=getchar()) != EOF && sign != '\n'; i++) string[i] = sign;
 
 	string[i] = '\0';	 
}

int main(){
	int i;
	char string[SIZE];

	zrob(string);
	char temp[SIZE];
	strcpy(temp,string); 
	i=0;
	while(string[i] !='\0'){
		temp[strlen(string) - 1 - i] = string[i]; 
			i++;
	}
	strcpy(string,temp);
	printf("%s\n",string);
	

}
