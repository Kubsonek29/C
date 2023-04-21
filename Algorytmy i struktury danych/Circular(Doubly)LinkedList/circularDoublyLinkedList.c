#include "circularDoublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void push(node *head, int value){
    node p = (node)malloc(sizeof(doublyLinkedListNode));
    p->data=value;
    if(p){
        if ((*head)==NULL){
            p->next=p;
            p->prev=p;
            (*head)=p;
        }
        else{
            (*head)->prev->next = p;
            p->prev = (*head)->prev;
            p->next = (*head);
            (*head)->prev = p;
            (*head) = p;
        }
    }
}

void pushEnd(node *head, int value){
    node p = (node)malloc(sizeof(doublyLinkedListNode));
    p->data=value;
    if(p){
        if((*head) == NULL){
            p->next = p;
            p->prev = p;
            (*head) = p;
        }
        else{
            (*head)->prev->next = p;
            p->prev = (*head)->prev;
            p->next = (*head);
            (*head)->prev = p;
        }
    }
}

void pop(node *head) {
    node p = *head;
    if(*head){
        if((*head)->next == (*head)){
            free((*head));
            head = NULL;
        }
        else{
            (*head)->prev->next = (*head)->next;
            (*head)->next->prev = (*head)->prev;
            (*head) = (*head)->next;
            free(p);
            p = NULL;
        }
    }
}

void popEnd(node *head){
    if(*head){
        if((*head)->next==(*head)){
            free((*head));
            (*head) = NULL;
        }
        else{
            node p = (*head)->prev;
            p->prev->next = (*head);
            (*head)->prev = p->prev;
            free(p);
            p = NULL;
        }
    }
}

node find(node head,int value){
    node p=head;
    if(p){
        while((p->next!=head)&&(p->data!=value)){
            p=p->next;
        }
        if(p->data==value){
            return p;
        }
    }
    return 0;
}

void pushBefore(node *head, node current, int val){
    node p = current;
    p=find(*head,current->data);
    if(current){
        push(&p,val);
    }
}

void pushAfter(node *head, node current, int val){
    node p = current;
    p=find(*head,current->data);
    if(current){
        p=p->next;
        push(&p,val);
    }
}

void removeNode(node *head, node current){
    node p=*head;
    if(current){
        while(p->data != current->data){
            p=p->next;
        }
        pop(&p);
    }
}

node readFromFile(char* fname){
    FILE *file;
    file=fopen(fname,"r+");
    node* head=NULL;
    int val;
    char tab[100];
    while(fscanf(file,"%s",tab)==1){
        val=atoi(tab);
        pushEnd(head,val);
    }
    fclose(file);
    return *head;
}

int saveToFile(node head, char *fname){
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
