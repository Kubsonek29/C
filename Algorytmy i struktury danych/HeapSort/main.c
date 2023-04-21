// proszę wykonać sortowanie przez kopcowanie na tablicy o długości przynajmniej 1000 słów
#include "heapSort.h"
#include <stdio.h>

int main(){
    char *tab[6] = {"siema", "jamalbee" , "unpoco", "wowi", "abc", "bambus"};
    hsort(tab,6);
    for(int i = 0; i < 6; i++){
        printf("%d, %s\n",i,tab[i]);
    }

    return 0;
}