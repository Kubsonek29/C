#include "doublyLinkedList.h" //zad9
#include <stdio.h>


node work=NULL;
node work2=NULL;
node work3=NULL;

int main(){
    push(&work,4);
    push(&work,9);
    push(&work,2);
    push(&work,23);
    push(&work,78);
    push(&work,12);
    pushEnd(&work,15);
    pushEnd(&work,14);
    pushEnd(&work,99);
    pop(&work);
    pop(&work);
    popEnd(&work);
    work2 = find(work,15);
    work3 = find(work,23);
    pushAfter(&work,work2,76);
    pushBefore(&work,work3,45);
    work2 = find(work,9);
    work3 = find(work,99);
    removeNode(&work,work2);
    removeNode(&work,work3);
    printList(work);
    return 0;
}
