#include "circularDoublyLinkedList.h"
#include <stdio.h>

void show(node head){
    node tmp=head;
    if(!head){
        return;
    }
    do{
        printf("Current: %d %p Next: %d %p Prev: %d %p\n",tmp->data,tmp,tmp->next->data,tmp->next, tmp->prev->data,tmp->prev);
        tmp=tmp->next;
    }while(tmp!=head);
    printf("\n");
}

node work=NULL;
node work2=NULL;

int main(){
    push(&work,5);
    push(&work,9);
    push(&work,7);
    push(&work,10);
    push(&work,12);
    pushEnd(&work,19);
    pushEnd(&work,13);
    pushEnd(&work,14);
    pushEnd(&work,15);
    pushEnd(&work,16);
    pop(&work);
    pop(&work);
    pop(&work);
    popEnd(&work);
    popEnd(&work);
    popEnd(&work);
    work2 = find(work,19);
    pushAfter(&work,work2,60);
    work2 = find(work,60);
    pushBefore(&work, work2,55);
    work2=find(work,55);
    removeNode(&work,work2);
    show(work);
    return 0;
}
