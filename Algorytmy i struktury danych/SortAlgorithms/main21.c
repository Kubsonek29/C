#include "zad21.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

dah work=NULL;
srt manage=NULL;

int main(){
    int counter;
    srand(time(NULL));
    for(int i = 1; i < 5; i++){
        srttabadd(&manage,i);
    }
    pushEnd(&work,1,0,0);
    pushEnd(&work,2,0,0);
    pushEnd(&work,3,0,0);
    pushEnd(&work,4,0,0);
    for(counter = 1; counter < 1000; counter++){
        ///////////////
        int t[10000]; ///oryginalna tablica
        int tmp1[10000]; ///kopie
        int tmp2[10000]; ///
        int tmp3[10000]; ///
        int tmp4[10000]; ///
        for(int i = 0 ; i < 10000; i++){
            t[i]= rand()%10000;
            tmp1[i] = t[i];
            tmp2[i] = t[i];
            tmp3[i] = t[i];
            tmp4[i] = t[i];
        }
        Bubblesort(tmp1,10000,&work);
        byinsert(tmp2,10000,&work);
        /////////
        quicksort(tmp3,0,10000,&work);
        /////////
        shellsort(tmp4,sizeof(tmp4)/sizeof(tmp4[0]),&work);
        ////////////////////////////
        sortthesort(manage,work,counter); ///need for fix 2
        byebye(work);
    }
    printdane(manage,work);
    printf("\n1 - Bubble, 2 - ByInsert, 3 - quicksort, 4 - shell");
    return 0;
}