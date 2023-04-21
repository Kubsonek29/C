#include "circularLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void push(node *head, int value){
    node p=(node)malloc(sizeof(linkedListNode));
    if(*head){
        p->data=(*head)->data;
        p->next=(*head)->next;
        (*head)->data=value;
        (*head)->next=p;
    }
    else{
        p->data=value;
        p->next=p;
        *head=p;
    }
}

void pushEnd(node *head, int value){
    push(head,value);
    *head=(*head)->next;
}

void pop(node *head){
    node p;
    if(*head){
        p=(*head)->next;
        if(p==(*head)){
            (*head)=NULL;
        }
        else{
            (*head)->data=p->data;
            (*head)->next=p->next;
        }
        free(p);
    }
}

void popEnd(node *head){
    node p = *head;
    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    while ((*head)->next->next != p)
    {
        head = &(*head)->next;
    }
    node tmp = (*head)->next;
    (*head)->next = tmp->next;
    free(tmp);
}

node find(node head, int value){
    node p = head;
    if(p){
        while(p->next != head && p->data != value){
            p=p->next;
        }
        if(p->data == value){
            return p;
        }
    }
    return 0;
}

void pushBefore(node current, int val){
    if(current){
        push(&current,val);
    }
}

void pushAfter(node current, int value){
    if(current){
        push(&current->next,value);
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
    *head=p;
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

void removeEveryK(node *head, int k){
    node tmp=*head;
    if(*head){
        while(tmp->next!=tmp){
            for(int i = 0; i < k; i++){
                tmp=tmp->next;
            }
            pop(&tmp);
            *head=tmp;
        }
    }
}

void diffList(node *a, node b){
    node tmp;
    node hold=b;
    while(b->next!=hold){
        while(a){
            tmp=find(*a,b->data);
            if(!tmp){
                break;
            }
            else{
                removeNode(a,tmp);
            }
        }
        b=b->next;
    }
}
