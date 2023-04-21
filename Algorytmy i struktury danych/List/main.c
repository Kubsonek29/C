#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

node* work=NULL;
node* ptrvar=NULL;
int var=0;
int var2=0;
char filename[]="filelista.txt";

void show(node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    node* head = NULL;
    int select = 1;
    while(select){
        printf("Cudowne menu naszego programu do list. Wybierz odpowiednia opcje.\n");
        printf("1 - dodaj na początek listy\n");
        printf("2 - dodaj na koniec listy\n");
        printf("3 - usun pierwszy element listy\n");
        printf("4 - usun ostatni element listy\n");
        printf("5 - odszukaj zadany element\n");
        printf("6 - dodaj nowy element przed wskazanym\n");
        printf("7 - dodaj nowy element za wskazanym\n");
        printf("8 - wczytaj zawartosc listy z pliku\n");
        printf("9 - zapisz zawartosc listy do pliku\n");
        printf("10 - wyswietl zawartosc listy\n");
        printf("11 - usun dany element z calej listy iteracyjnie\n");
        printf("12 - usun dany element z calej listy rekurencyjnie\n");
        printf("13 - obrocenie listy iteracyjnie\n");
        printf("14 - obrocenie listy rekurencyjnie\n");
        printf("15 - usun podany element (1)\n");
        printf("0 - zakoncz dzialanie programu\n");
        printf("Wybierz opcje: ");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("Podaj zmienna do dodania na początek listy: ");
                scanf("%d",&var);
                push(&work,var);
                break;
            case 2:
                printf("Podaj zmienna do dodania na koniec listy: ");
                scanf("%d",&var);
                pushEnd(&work,var);
                break;
            case 3:
                pop(&work);
                printf("Usunięto 1 element listy");
                break;
            case 4:
                popEnd(&work);
                printf("Usunięto ostatni element listy");
                break;
            case 5:
                printf("Podaj dana do znalezienia w liscie: ");
                scanf("%d",&var);
                ptrvar=find(work,var);
                if(ptrvar){
                    printf("Znaleziono element %d\n",ptrvar->data);
                }
                else{
                    printf("Nie znaleziono\n");
                }
                break;
            case 6:
                printf("Podaj element jaki chcesz dodac: ");
                scanf("%d",&var);
                printf("Podaj element przed ktorym chcesz dodac: ");
                scanf("%d",&var2);
                pushBefore(&work,find(work,var2),var);
                break;
            case 7:
                printf("Podaj element jaki chcesz dodac: ");
                scanf("%d",&var);
                printf("Podaj element za ktorym chcesz dodac: ");
                scanf("%d",&var2);
                pushAfter(&work,find(work,var2),var);
                break;
            case 8:
                printf("Wczytywanie z pliku\n");
                ptrvar = readFromFile(filename);
                work = ptrvar;
                break;
            case 9:
                printf("Zapisywanie do pliku\n");
                saveToFile(work,filename);
                break;
            case 10:
                printf("Aktualna lista: \n");
                show(work);
                break;
            case 11:
                printf("Podaj element do usuniecia z calej listy ");
                scanf("%d",&var);
                removeAll_iteratively(&work,var);
                printf("Usunieto dany element z calej listy iteracyjnie\n");
                break;
            case 12:
                printf("Podaj element do usuniecia z calej listy rekurencyjnie ");
                scanf("%d",&var);
                removeAll_recursively(&work,var);
                printf("Usunieto dany element z calej listy rekurencyjnie\n");
                break;
            case 13:
                revert_iteratively(&work);
                printf("Obrocono liste iteracyjnie\n");
                break;
            case 14:
                revert_recursively(&work);
                printf("Obrocono liste rekurencyjnie\n");
                break;
            case 15:
                printf("Podaj element do usuniecia ");
                scanf("%d",&var);
                removeNode(&work,find(work,var));
                printf("Usunieto\n");
                break;
            default:
                break;
        }
    }
    
    return 0;
}