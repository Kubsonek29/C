#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void push(node **head, int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    p->next=*head;
    *head=p;
}
void pushEnd(node **head, int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    p->next=0;
    while(*head){
        head=&(*head)->next;
    }
    *head=p;
}
void pop(node **head){
    node* p;
    if(*head){
        p=*head;
        *head=(*head)->next;
        free(p);
    }
} 
void popEnd(node **head){
    if(*head==0) return;
    while((*head)->next){
        head=&(*head)->next;        
    }
    free(*head);
    *head=0;
}
node* find(node *head, int val){
    node* tmp=0;
    tmp=head;
    if(tmp==NULL){
        return 0;
    }
    while(tmp){
        if(tmp->data==val){
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;
}
void pushBefore(node **head, node *current, int val){
    while(*head && (*head)->data != current->data){
        head=&(*head)->next;
    }
    push(head,val);
}
void pushAfter(node **head, node *current, int val){
    while(*head && (*head)->data != current->data){
        head=&(*head)->next;
    }
    if(*head==NULL){
        push(head,val);
    }
    else{
        head=&(*head)->next;
        push(head,val);
    }
}
void removeNode(node **head, node *current){
    while(*head && (*head)->data != current->data){
        head=&(*head)->next;
    }
    pop(head);
}
node* readFromFile(char *fname){
    FILE *file;
    file=fopen(fname,"r+");
    node* head=NULL;
    int val;
    char tab[10];
    while(fscanf(file,"%s",tab)==1){
        val=atoi(tab);
        pushEnd(&head,val);
    }
    return head;
    fclose(file);
}
int saveToFile(node *head, char *fname){
    FILE *file;
    node* tmp=head;
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
void removeAll_iteratively(node **head, int val){
    while(*head){
        if((*head)->data==val){
            pop(head);
        }
        head=&(*head)->next;
        //*head=(*head)->next;
    }
}
void removeAll_recursively(node **head, int val){
    if(*head){
        if((*head)->data==val){
            pop(head);
            removeAll_recursively(&(*head)->next,val);
        }
        else{
            removeAll_recursively(&(*head)->next,val);
        }
    }
}
/////////zad 3 dodatkowe
int findMostCommon(node *head){
    node* tmp = head;
    node* worker = 0;
    int ctr=0;
    int max=0;
    while(tmp){
        worker=tmp;
        if(tmp->data==worker->data){
            ctr++;
        }
        tmp=tmp->next;
        //??????
    }
    return;
}
////////////
void revert_iteratively(node **head){  //zmienilem z (void *head)
    node* prev=NULL;
    node* curr=*head;
    node* next = 0;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev; //wskazuje na nowy poczatek
}
void revert_recursively(node **head){ //zmienilem z (void *head)
    node* tmp = *head;
    if((*head)&&((*head)->next)){
        //head=&(*head)->next;
        *head=(*head)->next;
        revert_recursively(head);
        tmp->next->next=tmp;
        tmp->next=NULL;
    }
}
