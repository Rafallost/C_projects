#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_LINE_LENGTH 100	
#define ROZMIAR 256

typedef struct {

	char nazwa[ROZMIAR];
	char szef[ROZMIAR];
	int rok_zalozenia;
	int ilosc_wydanych_ksiazek;
	int ilosc_pracownikow;

}Wydawnictwo;


typedef struct
{

	char Title[ROZMIAR];
	int rok_wydania;
	int ISBN;
	int ilosc_stron;
	double srednia_ocena_czytelnikow;
	double cena;
	Wydawnictwo wyd;

}Ksiazka;

void wpisz(char* tab); 
int ilosc_ksiazek();
void uzupelnij(Ksiazka* tablica);
void sortowanie_rocznikowe(Ksiazka* ksia,int ilosc_ksiazek);
void sortowanie_alfabetycznie(Ksiazka *ksia,int ilosc_ksiazek);
void wyswietlanie_z_pliku();
void wyswietlanie(Ksiazka* ksia,int ilosc_ksiazek);
void dodawanie(Wydawnictwo wydawnictwo,Ksiazka* ksia,int ilosc_ksiazek);
void usuwanie(Ksiazka* ksia,Ksiazka* temp,int ilosc_ksiazek, int ISBN);
void zapis_do_pliku(Ksiazka* ksia,int ilosc_ksiazek);

int main() {

	int ilosc_ksia = ilosc_ksiazek();

	Ksiazka *ksiazki = (Ksiazka*)malloc(sizeof(Ksiazka) * ilosc_ksia);
	uzupelnij(ksiazki);

	Wydawnictwo vulcan, wsip;

	strcpy(vulcan.nazwa, "vulcan\n");
	strcpy(vulcan.szef, "Jacek Rozycki");
	vulcan.rok_zalozenia = 1988;
	vulcan.ilosc_wydanych_ksiazek = 1000000;
	vulcan.ilosc_pracownikow = 1240;

	strcpy(wsip.nazwa, "wsip\n");
	strcpy(wsip.szef, "Jerzy Garlicki");
	vulcan.rok_zalozenia = 1945;
	vulcan.ilosc_wydanych_ksiazek = 5000000;
	vulcan.ilosc_pracownikow = 9240;
	int a = 1;
	
	while(a){	
		puts("\nSelect option");
		puts("1 : Adding a new book to the collection");
		puts("2 : Removing a book from the collection");
		puts("3 : Display the entire collection in alphabetical order");
		puts("4 : Display of the entire vintage collection");
		puts("5 : Contents");
		puts("6 : Displaying from a file");
		puts("7 : save");
		puts("\tNotes:");
		puts("--Enter any letter to disable");
		puts("--Letters are case-sensitive");
		char c;
		int num;
		scanf(" %c", &c);

		switch (c)
		{
		case '1':
		ilosc_ksia++;
			ksiazki = (Ksiazka*)realloc(ksiazki,sizeof(Ksiazka)*ilosc_ksia);
			puts("Select a publisher");
			puts("1: vulcan");
			puts("2: wsip");
				scanf("%d", &num);
			if (num == 1) dodawanie(vulcan,ksiazki,ilosc_ksia);
				else dodawanie(wsip,ksiazki,ilosc_ksia);
		break;
		case '2':
		ilosc_ksia--;
			Ksiazka *temp = (Ksiazka*)malloc(sizeof(Ksiazka)*ilosc_ksia);
			puts("Enter the ISBN you want to delete");	
			int ISBN;
			scanf("%d",&ISBN);
			usuwanie(ksiazki,temp,ilosc_ksia,ISBN);
			free(temp);
		break;
		case '3': 
			puts("Note: Books entered with a capital letter have priority in displaying");
			sortowanie_alfabetycznie(ksiazki,ilosc_ksia);
			wyswietlanie(ksiazki,ilosc_ksia);
		break;
		case '4': 
			sortowanie_rocznikowe(ksiazki,ilosc_ksia);
			wyswietlanie(ksiazki,ilosc_ksia);
		break;
		case '5': 
			Ksiazka **spis;
			spis = malloc(sizeof(Ksiazka)*ilosc_ksia);
			
			for(int i = 0; i<ilosc_ksia;i++){
			
				spis[i] = malloc(2 * sizeof(Ksiazka)*ilosc_ksia);
				spis[i][0] = ksiazki[i];
				spis[i][1] = ksiazki[i];
				printf("At location %d  , ISBN %d: %s\n",i,spis[i][1].ISBN,spis[i][1].Title);
			} 			
			
		break;
		case '6': 
			wyswietlanie_z_pliku();
		break;
		case '7': 
			zapis_do_pliku(ksiazki,ilosc_ksia);
		break;
		default: 
			
			a = 0;
			break;
		}
	}

	free(ksiazki);
	return 0;
}

void wpisz(char* tab) {
	
	int i = 0, c;
	getchar();
	while ((c = getchar())!= EOF && (c != '\n')){
	
		tab[i] = c;
		i++;
	}
	tab[i] = '\n';

}

int ilosc_ksiazek() {

	FILE* ptr = fopen("ksiazki.txt", "r");

	char line[MAX_LINE_LENGTH];

	int i = 0;
	while (fgets(line,MAX_LINE_LENGTH,ptr))
		i++;
	fclose(ptr);
	int wynik = i / 7;
	return wynik;

}

void uzupelnij(Ksiazka* tablica) {

	FILE* ptr = fopen("ksiazki.txt", "r");

	char line[MAX_LINE_LENGTH];

	int i = 0, y = 0;
	while (fgets(line,MAX_LINE_LENGTH, ptr))
	{
		if (i == 7)
		{
			i = 0;
			y++;
		}

		switch (i)
		{
		case 0: strcpy(tablica[y].Title, line); break;
		case 1: tablica[y].rok_wydania = atoi(line); break;
		case 2: tablica[y].ISBN = atoi(line); break;
		case 3: tablica[y].ilosc_stron = atoi(line); break;
		case 4: tablica[y].srednia_ocena_czytelnikow = atof(line); break;
		case 5: tablica[y].cena = atof(line); break;
		case 6: strcpy(tablica[y].wyd.nazwa, line); break;
		default: puts("ERROR"); exit(0); break;
		}
		i++;
	}
	fclose(ptr);
}

void sortowanie_rocznikowe(Ksiazka* ksia,int ilosc_ksiazek) {

	for (int i = 0; i < ilosc_ksiazek; i++) {
		
		int numer = i, max = ksia[i].rok_wydania;
		
		for (int k = i + 1; k < ilosc_ksiazek; k++) {

			if (ksia[i].rok_wydania < ksia[k].rok_wydania)
			{
				if(max<ksia[k].rok_wydania)
				{
				max = ksia[k].rok_wydania;
				numer = k;
				}
			}

		}
		Ksiazka ks = ksia[i];
		ksia[i] = ksia[numer];
		ksia[numer] = ks;
	}
}

void sortowanie_alfabetycznie(Ksiazka *ksia,int ilosc_ksiazek){


	for (int i = 0; i < ilosc_ksiazek; i++) {

		for (int k = i + 1; k < ilosc_ksiazek; k++) {
			for (int y = 0; y < strlen(ksia[i].Title)-1; y++) {
			
				if(ksia[i].Title[y] < ksia[k].Title[y])
				{
					break;
					
				}
				else if(ksia[i].Title[y] > ksia[k].Title[y])
				{

					Ksiazka ks = ksia[i];
					ksia[i] = ksia[k];
					ksia[k] = ks;
					break;
				}				
			}
		}
	}
}


void wyswietlanie_z_pliku() {

	FILE* ptr = fopen("ksiazki.txt", "r");

	char line[MAX_LINE_LENGTH];
	puts("wlaczylem sie");
	int i = 0;
	while (fgets(line,MAX_LINE_LENGTH,ptr))	{

		if (i == 7) i = 0;
		
		switch(i){
		case 0:printf("***Title: %s\n",line);break;
		case 1:printf("Publication date: %s",line);break;
		case 2:printf("ISBN: %s",line);break;
		case 3:printf("Number of pages: %s",line);break;
		case 4:printf("Average reader rating: %s",line);break;
		case 5:printf("Price: %s",line);break;
		case 6:printf("Nazwa wydawnictwa: %s\n",line);break;
		}
	i++;
	}
	fclose(ptr);
}

void wyswietlanie(Ksiazka* ksia,int ilosc_ksiazek) {


	for (int i = 0; i < ilosc_ksiazek; i++) {

		printf("***Title: %s", ksia[i].Title);

			printf("\nPublication date: %d\n", ksia[i].rok_wydania);
			printf("ISBN: %d\n", ksia[i].ISBN);
			printf("Number of pages: %d\n", ksia[i].ilosc_stron);
			printf("Average reader rating: %0.2lf\n", ksia[i].srednia_ocena_czytelnikow);
			printf("Price: %0.2lf\n", ksia[i].cena);
			printf("Name of the publisher: %s\n", ksia[i].wyd.nazwa);
	}
}

void dodawanie(Wydawnictwo wydawnictwo,Ksiazka* ksia,int ilosc_ksiazek) {
	
	int ISBN;
	char Title[ROZMIAR];
	
	puts("Enter Title:");
	wpisz(Title);
		strcpy(ksia[ilosc_ksiazek-1].Title,Title);
	puts("Enter rok_wydania:");
		scanf("%d", &ksia[ilosc_ksiazek-1].rok_wydania);
	puts("Enter ISBN:");
		scanf("%d", &ISBN);
		
	for(int i = 0; i<ilosc_ksiazek; ++i){	
		if(ISBN==ksia[i].ISBN)
		{
			puts("The ISBN code cannot be repeated, please enter a different one");	
			scanf("%d", &ISBN);
			i=-1;
		}
	}
		ksia[ilosc_ksiazek-1].ISBN = ISBN;
		
	puts("Enter number of pages:");
		scanf("%d", &ksia[ilosc_ksiazek-1].ilosc_stron);
	puts("Enter average reader rating:");
		scanf("%lf", &ksia[ilosc_ksiazek-1].srednia_ocena_czytelnikow);
	puts("Enter price:");
		scanf("%lf", &ksia[ilosc_ksiazek-1].cena);
	strcpy(ksia[ilosc_ksiazek-1].wyd.nazwa, wydawnictwo.nazwa);

}

void usuwanie(Ksiazka* ksia,Ksiazka* temp,int ilosc_ksiazek, int ISBN){
	
	int  y = 0;
	
	for(int i = 0; i<=ilosc_ksiazek; i++){
	
		if(ksia[i].ISBN != ISBN)
		{
			temp[y++] = ksia[i];
		}
	}

	ksia = (Ksiazka*)realloc(ksia,sizeof(Ksiazka)*y);
	
	memcpy(ksia,temp,sizeof(Ksiazka)*y);
}

void zapis_do_pliku(Ksiazka* ksia,int ilosc_ksiazek){
	FILE* ptr = fopen("ksiazki.txt","w+");
	for(int i = 0; i<ilosc_ksiazek;i++){
		fprintf(ptr, "%s", ksia[i].Title); 				
		
		fprintf(ptr, "%d", ksia[i].rok_wydania); 					fprintf(ptr, "\n");
			
		fprintf(ptr, "%d", ksia[i].ISBN); 							fprintf(ptr, "\n");
	
		fprintf(ptr, "%d", ksia[i].ilosc_stron); 					fprintf(ptr, "\n");
	
		fprintf(ptr, "%lf", ksia[i].srednia_ocena_czytelnikow); 	fprintf(ptr, "\n");
	
		fprintf(ptr, "%lf", ksia[i].cena); 							fprintf(ptr, "\n");

		fprintf(ptr, "%s", ksia[i].wyd.nazwa); 			
	}
	fclose(ptr);
}
