#include "zad21.h"
#include <stdlib.h>
#include <stdio.h>

void pushEnd(dah *head, int indexo, int data1, int data2){
    dah p = (dah)malloc(sizeof(dataH));
    p->data1=data1;
    p->data2=data2;
    p->indexo=indexo;
    p->next=0;
    while(*head){
        head=&(*head)->next;
    }
    *head=p;
}

void printdane(srt head, dah dhead){
    if(head && dhead){
        while(head && dhead){
            if(head->que==dhead->indexo){
                printf("\nIndex = %d,   MaxPodst = %d,  MinPodst = %d,  MaxPorown = %d,     MinPorown = %d ", head->que,head->maxpodst,head->minpodst,head->maxporown,head->minporown);
            }
            head=head->next;
            dhead=dhead->next;
        }
    }
}

void srttabadd(srt *head, int que){
    srt p = (srt)malloc(sizeof(sortT));
    p->que=que;
    p->maxpodst=0;
    p->maxporown=0;
    p->minpodst=0;
    p->minporown=0;
    p->next=0;
    while(*head){
        head=&(*head)->next;
    }
    *head=p;
}

srt sortthesort(srt head, dah dhead, int ctr){
    if(ctr == 1){
        while(head != NULL && dhead != NULL){
            if(head->que==dhead->indexo){
                head->maxpodst=dhead->data1;
                head->maxporown=dhead->data2;
                head->minpodst=dhead->data1;
                head->minporown=dhead->data2;
            }
            dhead = dhead->next;
            head = head->next;
        }
    }
    else if(ctr > 1){
        while(head!=NULL && dhead!=NULL){
            if(head->que==dhead->indexo){
                if(head->maxpodst < dhead->data1){
                    head->maxpodst = dhead->data1;
                }
                if(head->minpodst > dhead->data1){
                    head->minpodst = dhead->data1;
                }
                if(head->maxporown < dhead->data2){
                    head->maxporown = dhead->data2;
                }
                if(head->minporown > dhead->data2){
                    head->minporown = dhead->data2;
                }
            }
            dhead = dhead->next;
            head = head->next;
        }
    }
    return head;
}

void byebye(dah head){
    if(head){
        while(head){
            head->data1=0;
            head->data2=0;
            head=head->next;
        }
    }
}

//////
dah Bubblesort(int *t, int t_size, dah *head){
    while(*head && (*head)->indexo!=1){
        head=&(*head)->next;
    }
    int tmp;
    for(int i = 0 ; i < t_size; i++){
        for(int j = 0; j < t_size; j++){
            if(t[i]<t[j]){
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
                (*head)->data1+=3;
            }
            (*head)->data2+=1;
        }
    }
    return *head;
}
//////
dah byinsert(int *t, int t_size, dah *head){
    int i,j,tmp;
    while(*head && (*head)->indexo!=2){
        head=&(*head)->next;
    }
    for(i = 0 ; i < t_size; i++){
        if(t[i]<t[0]){
            tmp = t[0];
            t[0]=t[i];
            (*head)->data1+=2;
        }
        else{
            tmp=t[i];
            (*head)->data1+=2;
        }
        (*head)->data2+=1;
        for(j = i-1; tmp < t[j]; j--){
            t[j+1]=t[j];
            (*head)->data1+=1;
            (*head)->data2+=1;
        }
        t[j+1]=tmp;
        (*head)->data1+=1;
    }
    return *head;
}
///////
int partition_qs(int *t, int p, int r, dah *head){
    int i,j,tmp,tmp2;
    while((*head)->indexo!=3){
        head=&(*head)->next;
    }
    tmp=t[r];
    (*head)->data1+=1;
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(t[j]<=tmp){
            i++;
            tmp2=t[i];
            t[i]=t[j];
            t[j]=tmp2;
            (*head)->data1+=3;
        }
        (*head)->data2+=1;
    }
    tmp2=t[i+1];
    t[i+1]=t[r];
    t[r]=tmp2;
    (*head)->data1+=3;
    return i+1;
}

dah quicksort(int *t, int p, int r, dah *head){
    int Santa;
    if(p<r){
        Santa = partition_qs(t,p,r,head);
        quicksort(t,p,Santa-1,head);
        quicksort(t,Santa+1,r,head);
    }
    return *head;
}
////
dah shellsort(int *t, int t_size, dah *head){
    int tmp;
    while(*head && (*head)->indexo!=4){
        head=&(*head)->next;
    }
    for(int i = t_size/2; i > 0; i/=2){
        for(int j = i; j < t_size; j++){
            tmp = t[j];
            (*head)->data1+=1;
            int k;
            for(k=j; k >= i && t[k-i]>tmp; k-=i){
                (*head)->data2+=1;
                t[k]=t[k-i];
                (*head)->data1+=1;
            }
            t[k]=tmp;
            (*head)->data1+=1;
        }
    }
    return *head;
}
