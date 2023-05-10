#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROZMIAR 256

void zrob(char *string){

 	int range = ROZMIAR - 1; 
 	int sign; 
	int i;
	
 	for (i=0; i<range && (sign=getchar()) != EOF && sign != '\n'; i++) string[i] = sign;
 
 	string[i] = '\0';	 
}

int type(char sign) {

    if (sign >= 97 && sign <= 122) return 0;
    if (sign >= 65 && sign <= 90) return 1;
    return 2;
}

void cezar(int key,char *word){

	for(int i = 0; i<strlen(word);i++){
	
		int typ,a,z;
		
		typ = type(word[i]);
			
			if (typ == 0) a = 97, z = 122;
            		else a = 65, z = 90;
			
			if(typ<2)
			{
			
				if(key >= 0)
				{
					if(word[i] + key <= z) word[i] += key;
					else word[i] = word[i]+key - 26;
				}
				else
				{
				
					if(word[i] + key >= a) word[i] += key;
					else word[i] = word[i]+key + 26;
				
				}			
			}
	}

}

int main(){

	char c;
	int key,i_g = 0;
	char word[ROZMIAR];
	puts("Enter the word to be encrypted");
	
	zrob(word);
		
	puts("Enter a key in the <-26;26> range");
	scanf("%d",&key);	
	
	if(key>26||key<-26)
	{
		puts("Wrong key provided");
		exit(0);
	}
	
	cezar(key,word);
	printf("After encryption : %s\n",word);
	
	int i,k,j,slowa = 1, linia = 1;
	
		for (j = 0; word[j] != '\0'; j++) if(word[j]=='\n') linia++;
	
		for (k = 0; word[k] != '\0'; k++) if(word[k]==' ') slowa++;

 		for (i = 0; word[i] != '\0'; i++);
			
	puts("Your cipher does:");
	printf("%d words\n",slowa);
	printf("%d signs\n",i);
	printf("%d lines\n",linia);
	
	cezar(-key,word);
	printf("from decryption : %s\n",word);
	
	

}
