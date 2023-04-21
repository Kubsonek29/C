#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <limits.h>

void addElement(node *head, int value){   // dodaj element w kolejności
    node p=(node)malloc(sizeof(linkedListNode));
    if(*head==NULL){
        p->data=value;
        p->next=*head;
        *head=p;
    }
    else{
        while(*head && (*head)->data!=INT_MAX && (*head)->data<value){
            head=&(*head)->next;
        }
        p->data=value;
        p->next=*head;
        *head=p;
    }
}

int pop(node* head){  // usuwanie pierwszego elementu listy i zwracanie jego wartości
    int returnval;
    node p;
    if(*head && (*head)->data<INT_MAX){
        p=*head;
        returnval=p->data;
        *head=(*head)->next;
        free(p);
    }
    return returnval; //usuwa 2 pierwsze i w popback 2 ostatnie
}

int popBack(node* head){ // usuwanie ostatniego elementu listy i zwracanie jego wartości
    int returnval;
    node p;
    if(*head==NULL){
        return *head;
    }
    while((*head)->next && ((*head)->next)->data!=INT_MAX){
        head=&(*head)->next;
    }
    if(*head){
        p=*head;
        *head=(*head)->next;
        returnval=p->data;
        free(p);
    }
    return returnval;
}

node find(node head, int value){  // znajdowanie elementu o wskazanej wartości
    node tmp=0;
    tmp=head;
    if(tmp==NULL){
        return 0;
    }
    while(tmp->data<=value){
        if(tmp->data==value){
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;
}

void removeElement(node* head, node element){  // usuwanie elementu wcześniej znalezionego
    while((*head) && (*head)->data!=INT_MAX && ((*head)->data!=element->data)){
        head=&(*head)->next;
    }
    pop(head);
}

void printList(node head){ // wyświetlanie listy
    while(head && head->data<=INT_MAX){
        printf("%d %p %p\n",head->data,&(*head),head->next);
        head=head->next;
    }
    printf("\n");
}

node readFromFile(char *fname){  // wczytaj zawartość listy z pliku
    FILE *file;
    file=fopen(fname,"r+");
    node* head=NULL;
    int val;
    char tab[100];
    while(fscanf(file,"%s",tab)==1){
        val=atoi(tab);
        addElement(&head,val);
    }
    return head;
    fclose(file);
}

int saveToFile(node head, char *fname){  // zapisz zawartość listy do pliku
    FILE *file;
    node tmp=head;
    if((file=fopen(fname,"w+"))==NULL){
        exit(1);
    }
    while(tmp){
        fprintf(file,"%d ",tmp->data);
        tmp=tmp->next;
    }
    fclose(file);
    return 0;
}

node merge(node p, node q){
    node tmp=0;
    if(!p){
        return q;
    }
    if(!q){
        return p;
    }
    if(p->data <= q->data){
        tmp=p;
        tmp->next=merge(p->next,q);
    }
    else{
        tmp=q;
        tmp->next=merge(p,q->next);
    }
    q=NULL;
    p=tmp;
    return p;
}
