#include "doublyLinkedList.h" //zad9
#include <stdlib.h>
#include <stdio.h>

void push(node *head, int value){
    node p = (node)malloc(sizeof(doublyLinkedListNode));
    p->data=value;
    if(*head==0){
        p->next=(*head);
        p->prev=NULL;
        *head=p;
    }
    else{
        p->next=(*head);
        p->prev=(*head)->prev;
        (*head)->prev=p;
        *head=p;
    }
}

void pushEnd(node *head, int value){
    while((*head)->next){
        head=&(*head)->next;
    }
    push(head,value);
}

int pop(node *head){
    int check=0;
    if(*head){
        node p = *head;
        check=p->data;
        if((*head)->next){
            (*head)=(*head)->next;

            free(p);
        }
        else{
            free(p);
            (*head)=NULL;
        }
        (*head)->prev=NULL;
    }
    return check;
}

int popEnd(node *head){
    if(*head){
        while((*head)->next){
            head=&(*head)->next;
        }
    }
    int check=0;
    if(*head){
        node p = *head;
        check=p->data;
        if((*head)->next){
            (*head)=(*head)->next;

            free(p);
        }
        else{
            free(p);
            (*head)=NULL;
        }
    }
    return check;
}

node find(node head, int val){
    while(head && head->data!=val){
        head=head->next;
    }
    return head;
}

void pushBefore(node* head, node current, int val){
    if(current){
        while(*head && (*head)->data!=current->data)
            head=&(*head)->next;
        push(head,val);
        //push(current,val);
    }
}

void pushAfter(node *head, node current, int val){
    if(current){
        while(*head && (*head)->data!=current->data)
            head=&(*head)->next;
        head=&(*head)->next;
        push(head,val);
        //push(current->next,val);
    }
}

void removeNode(node *head, node current){
    if(current){
        while((*head) && (*head)->data != current->data){
            head=&(*head)->next;
        }
        if((*head)->next){
            pop(head);
        }
        else{
            popEnd(head);
        }
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

void printList(node head){
    while(head){
        printf("Current: %d %p Next: %p Prev: %p\n",head->data,head,head->next,head->prev);
        head=head->next;
    }
}

node wartownik(){
    node p = (node)malloc(sizeof(doublyLinkedListNode));
    p->data=INT_MAX;
    p->next=NULL;
    return p;
}

void addElementInOrder(node* head, int value){
    if((*head)==NULL){
        push(head,value);
    }
    else{
        while((*head) && (*head)->data<value){
            head=&(*head)->next;
        }
        push(head,value);
    }
}

node findInOrder(node head, int value){
    node p=head;
    if(!p){
        return NULL;
    }
    while(p->data!=value){
        p=p->next;
    }
    return p;
}

void removeElementInOrder(node* head, node element){
    if(element){
        while(*head && (*head)->data!=element->data){
            head=&(*head)->next;
        }
        if((*head)->next){
            pop(head);
        }
        else{
            popEnd(head);
        }
    }
}

node readFromFileInOrder(char *fname){
    FILE *file;
    file=fopen(fname,"r+");
    node *head=NULL;
    int value;
    char tab[50];
    while(fscanf(file,"%s",tab)==1){
        value=atoi(tab);
        addElementInOrder(head,value);
    }
    fclose(file);
    return *head;
}
