#ifndef _lista_powiazana_
#define _lista_powiazana_

typedef struct element_listy* wsk_el_list;

typedef struct element_listy{
  char* nazwa_wezla;
  int klucz;
  wsk_el_list nastepny_wezel; // wskaźnik do kolejnego elementu
} el_list;

int wstaw_na_poczatek( el_list**, el_list* );

void drukuj_lista( el_list* );

int usun_lista( el_list** ,el_list* );

el_list* wyszukaj_lista( el_list* ,int );

#endif
