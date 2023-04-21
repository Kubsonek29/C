#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "linkedList.h"

node work=NULL;
node work2=NULL;
node work3=NULL;
node ptrvar=NULL;

int var;
char filename[]="filelistaporz.txt";

int main(int argc, char** argv)
{
    node head = NULL;
/*
    addElement(&work,5);
    addElement(&work,7);
    addElement(&work,9);
    addElement(&work3,2);
    addElement(&work3,4);
    addElement(&work3,6);
    addElement(&work3,5);
    merge(work,work3);
*/
    int select = 1;
    while(select){
        printf("Cudowne menu naszego programu do list. Wybierz odpowiednia opcje.\n");
        printf("1 - dodaj element w kolejności\n");
        printf("2 - usuwanie pierwszego elementu listy i zwracanie jego wartości\n");
        printf("3 - usuwanie ostatniego elementu listy i zwracanie jego wartości\n");
        printf("4 - znajdowanie elementu o wskazanej wartości\n");
        printf("5 - usuwanie elementu wcześniej znalezionego\n");
        printf("6 - wyświetlanie listy\n");
        printf("7 - wczytaj zawartość listy z pliku\n");
        printf("8 - zapisz zawartość listy do pliku\n");
        printf("9 - utworz wartownika\n");
        printf("Mniej cudowne menu do 2 listy: \n");
        printf("10 - Dodaj element w kolejnosci do listy\n");
        printf("11 - Wyswietl 2 liste\n");
        printf("///////////////////////////\n");
        printf("12 - polacz listy\n");
        printf("0 - zakoncz dzialanie programu\n");
        printf("Wybierz opcje: ");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("Podaj zmienna do dodania do listy: ");
                scanf("%d",&var);
                addElement(&work,var);
                break;
            case 2:
                printf("Usunieto: %d\n",pop(&work));
                break;
            case 3:
                printf("Usunieto: %d\n",popBack(&work));
                break;
            case 4:
                printf("Podaj element do znalezienia:\n");
                scanf("%d",&var);
                find(work,var);
                printf("Znaleziony element dane: %p\n",find(work,var));
                work2=(find(work,var));
                break;
            case 5:
                if(work2){
                    removeElement(&work,work2);
                    printf("Usunieto wczesniej naznaczony element");
                }
                else{
                    printf("nie wybrano wczesniejszego elementu lub nie byl on zawartoscia listy\n");
                }
                break;
            case 6:
                printList(work);
                break;
            case 7:
                printf("Wczytywanie z pliku\n");
                ptrvar = readFromFile(filename);
                work = ptrvar;
                break;
            case 8:
                saveToFile(work,filename);
                printf("Zapisano liste do pliku\n");
                break;
            case 9:
                printf("Dodano Wartownika do listy!\n");
                addElement(&work,INT_MAX);
                break;
            case 10:
                printf("Podaj zmienna do dodania do 2 listy: ");
                scanf("%d",&var);
                addElement(&work3,var);
                break;
            case 11:
                printList(work3);
                break;
            case 12:
                merge(work,work3);
                printf("\n");
                break;
            default:
                break;
        }
    }

    return 0;
}