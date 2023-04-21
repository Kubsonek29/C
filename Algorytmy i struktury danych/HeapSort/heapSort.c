#define left(x) (2*x + 1)
#define right(x) (2*x + 2)
#include <string.h>
#include "heapSort.h"

void hsort(char **tab, int n){
    int i,heapSize=n;
    char *x;
    hbuild(tab,n);
    for(i = n-1; i>0; i--){
        x = tab[0];
        tab[0] = tab[i];
        tab[i] = x;
        heapify(tab,0,--heapSize);
    }
}

void hbuild(char **tab, int n){
    for(int i = (n-1)/2 ; i >= 0; i--){
        heapify(tab,i,n);
    }
}

void heapify(char** tab, int i, int heapSize){
    int l,r,largest;
    l=left(i);
    r=right(i);
    char* x;
    if(l<heapSize && strcmp(tab[l],tab[i]) > 0){
        largest=l;
    }
    else{
        largest = i;
    }
    if(r < heapSize && strcmp(tab[r],tab[largest]) > 0){
        largest = r;
    }
    if(largest != i){
        x = tab[i];
        tab[i] = tab[largest];
        tab[largest] = x;
        heapify(tab,largest,heapSize);
    }
}