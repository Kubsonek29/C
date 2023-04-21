#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "circularLinkedList.h"

node work=NULL;
node work2=NULL;
node work3=NULL;
node ptrvar=NULL;

int var;
char filename[]="filelistacykl.txt";

void show(node head){
    node tmp=head;
    do{
        if(head){
            printf("%d %p %p\n",head->data,&(*head),head->next);
            head=head->next;
        }
    }while(head && tmp!=head);
    printf("\n");
}

int main(int argc, char** argv)
{
    push(&work3,5);
    push(&work3,7);
    push(&work3,9);
    push(&work3,2);
    push(&work,2);
    push(&work,23);
    push(&work,9);
    push(&work,33);
    push(&work,44);
    push(&work,77);
    //diffList(&work,work3);
    //removeEveryK(&work,3);

    int select = 1;
    while(select){
        printf("Cudowne menu naszego programu do list. Wybierz odpowiednia opcje.\n");
        printf("1 - dodawanie na początek listy\n");
        printf("2 - dodawanie na koniec listy\n");
        printf("3 - usuwanie pierwszego elementu listy\n");
        printf("4 - usuwanie ostatniego elementu listy\n");
        printf("5 - odszukaj podany element\n");
        printf("6 - dodaj element przed wskazanym\n");
        printf("7 - dodaj za wskazanym elementem\n");
        printf("8 - usuń wskazany element\n");
        printf("9 - wczytaj zawartość listy z pliku\n");
        printf("10 - zapisz zawartość listy do pliku\n");
        printf("11 - wyswietl liste\n");
        printf("12 - diff list\n");
        printf("13 - removeeveryK\n");
        printf("14 - show 2\n");
        printf("Wybierz opcje: ");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("Podaj zmienna do dodania do listy: ");
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
                printf("Usunieto pierwszy element listy");
                break;
            case 4:
                popEnd(&work);
                printf("Usunieto ostatni element listy");
                break;
            case 5:
                printf("Jaka wartosc chcesz znalezc: ");
                scanf("%d",&var);
                work2 = find(work,var);
                break;
            case 6:
                scanf("%d",&var);
                pushBefore(work2,var);
                break;
            case 7:
                scanf("%d",&var);
                pushAfter(work2,var);
                break;
            case 8:
                removeNode(&work,work2);
                break;
            case 9:
                readFromFile(filename);
                break;
            case 10:
                saveToFile(work,filename);
                break;
            case 11:
                show(work);
                break;
            case 12:
                diffList(&work,work3);
                break;
            case 13:
                removeEveryK(&work,3);
                break;
            case 14:
                show(work3);
                break;
            default:
                break;
        }
    }
    return 0;
}