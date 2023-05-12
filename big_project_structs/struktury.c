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

	char tytul[ROZMIAR];
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
		puts("\nProsze wybrac operacje");
		puts("1 : Dodawanie nowej ksiazki do zbioru");
		puts("2 : Usuwanie ksiazki ze zbioru");
		puts("3 : Wyświetlenie calego zbioru w kolejnosci alfabetycznej");
		puts("4 : Wyświetlenie calego zbioru rocznikowej");
		puts("5 : Spis tresci");
		puts("6 : Wysweitlanie z pliku");
		puts("7 : zapis do pliku");
		puts("Podaj jakakolwiek litere zeby wylaczyc");
		puts("Uwaga: Wielkosc liter ma znaczenie.");
		char c;
		int num;
		scanf(" %c", &c);

		switch (c)
		{
		case '1':
		ilosc_ksia++;
			ksiazki = (Ksiazka*)realloc(ksiazki,sizeof(Ksiazka)*ilosc_ksia);
			puts("Wybierz wydawnictwo");
			puts("1: vulcan");
			puts("2: wsip");
				scanf("%d", &num);
			if (num == 1) dodawanie(vulcan,ksiazki,ilosc_ksia);
				else dodawanie(wsip,ksiazki,ilosc_ksia);
		break;
		case '2':
		ilosc_ksia--;
			Ksiazka *temp = (Ksiazka*)malloc(sizeof(Ksiazka)*ilosc_ksia);
			puts("Podaj ISBN, ktory chcesz usunac");	
			int ISBN;
			scanf("%d",&ISBN);
			usuwanie(ksiazki,temp,ilosc_ksia,ISBN);
			free(temp);
		break;
		case '3': 
			puts("Uwaga: Ksiazki wprowadzone od duzej litery maja pierwszenstwo wyswietlania");
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
				printf("Na miejscu %d  , ISBN %d: %s\n",i,spis[i][1].ISBN,spis[i][1].tytul);
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
	return 0;

	
	free(ksiazki);
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
		case 0: strcpy(tablica[y].tytul, line); break;
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
			for (int y = 0; y < strlen(ksia[i].tytul)-1; y++) {
			
				if(ksia[i].tytul[y] < ksia[k].tytul[y])
				{
					break;
					
				}
				else if(ksia[i].tytul[y] > ksia[k].tytul[y])
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

	char line[MAX_LINE_LENGTH];

	FILE* ptr = fopen("ksiazki.txt", "r");

	int i = 0;
	while (fgets(line,MAX_LINE_LENGTH,ptr)){
	
		if (i == 7) i = 0;
		
		switch(i){
		case 0:printf("***Tytul: %s\n",line);break;
		case 1:printf("Rok wydania: %s",line);break;
		case 2:printf("ISBN: %s",line);break;
		case 3:printf("Ilosc stron: %s",line);break;
		case 4:printf("Srednia ocena czytelnikow: %s",line);break;
		case 5:printf("cena: %s",line);break;
		case 6:printf("Nazwa wydawnictwa: %s\n",line);break;
		}
	i++;
	}

	fclose(ptr);
}

void wyswietlanie(Ksiazka* ksia,int ilosc_ksiazek) {


	for (int i = 0; i < ilosc_ksiazek; i++) {

		printf("***TYTUL: %s", ksia[i].tytul);

			printf("\nRok wydania: %d\n", ksia[i].rok_wydania);
			printf("ISBN: %d\n", ksia[i].ISBN);
			printf("Ilosc stron: %d\n", ksia[i].ilosc_stron);
			printf("Srednia ocena czytelnikow: %0.2lf\n", ksia[i].srednia_ocena_czytelnikow);
			printf("cena: %0.2lf\n", ksia[i].cena);
			printf("Nazwa wydawnictwa: %s\n", ksia[i].wyd.nazwa);
	}
}

void dodawanie(Wydawnictwo wydawnictwo,Ksiazka* ksia,int ilosc_ksiazek) {
	
	int ISBN;
	char tytul[ROZMIAR];
	
	puts("podaj tytul:");
	wpisz(tytul);
		strcpy(ksia[ilosc_ksiazek-1].tytul,tytul);
	puts("podaj rok_wydania:");
		scanf("%d", &ksia[ilosc_ksiazek-1].rok_wydania);
	puts("podaj ISBN:");
		scanf("%d", &ISBN);
		
	for(int i = 0; i<ilosc_ksiazek; ++i){	
		if(ISBN==ksia[i].ISBN)
		{
			puts("Kod ISBN nie moze sie powtarzac, prosze podac inny");	
			scanf("%d", &ISBN);
			i=-1;
		}
	}
		ksia[ilosc_ksiazek-1].ISBN = ISBN;
		
	puts("podaj ilosc_stron:");
		scanf("%d", &ksia[ilosc_ksiazek-1].ilosc_stron);
	puts("podaj srednia ocene czytelnikow:");
		scanf("%lf", &ksia[ilosc_ksiazek-1].srednia_ocena_czytelnikow);
	puts("podaj cene:");
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

	FILE* plik = fopen("ksiazki.txt","w+");
	
	for(int i = 0; i<ilosc_ksiazek;i++){
		fprintf(plik, "%s", ksia[i].tytul); 				
		
		fprintf(plik, "%d", ksia[i].rok_wydania); 			fprintf(plik, "\n");
			
		fprintf(plik, "%d", ksia[i].ISBN); 				fprintf(plik, "\n");
	
		fprintf(plik, "%d", ksia[i].ilosc_stron); 			fprintf(plik, "\n");
	
		fprintf(plik, "%lf", ksia[i].srednia_ocena_czytelnikow); 	fprintf(plik, "\n");
	
		fprintf(plik, "%lf", ksia[i].cena); 				fprintf(plik, "\n");

		fprintf(plik, "%s", ksia[i].wyd.nazwa); 			
	}
	fclose(plik);

}
