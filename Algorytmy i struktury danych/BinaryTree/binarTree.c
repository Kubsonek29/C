#include "binarTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(node *root, char *value){
    int check;
    if(*root==0){
        *root = (node)malloc(sizeof(treeNode));
        (*root)->word=value;
        (*root)->left=0;
        (*root)->right=0;
    }
    else{
        check=strcmp((*root)->word,value);
        if(check<0){
            insert(&(*root)->right,value);
        }
        else{
            insert(&(*root)->left,value);
        }
    }
}

void removeNode(node *root,char *value){
    node tmp=*root;
    if(tmp->word==value){
        free(tmp);
        (*root)=NULL;
        return;
    }
    if(*root==0 || ((*root)->left==0 && (*root)->right==0)){
        return;
    }
    if((*root)->word!=value){
        int check=strcmp((*root)->word,value);
        if(check<0){
            removeNode(&tmp->right,value);
        }
        else if(check>0){
            removeNode(&tmp->left,value);
        }
    }
}

char* treeMax(node root){
    if(root){
        while(root->right){
            root=root->right;
        }
    }
    return root->word;
}

char* treeMin(node root){
    if(root){
        while(root->left){
            root=root->left;
        }
    }
    return root->word;
}

char* ancestor(node root){
    node tmp;
    if(root){
        if(root->right){
            return treeMin(root->right);
        }
        do{
            tmp=root;
            root=root->parent;
        }while(root && root->right==tmp);
    }
    return root->word;
}

char* descendant(node root){
    node tmp;
    if(root){
        if(root->left){
            return treeMax(root->left);
        }
        do{
            tmp=root;
            root=root->parent;
        }while(root && root->left==tmp);
    }
    return root->word;
}

void show(node root, int height){
    if(root==0) return;
    show(root->left, height+1);
    for(int i = 0; i < height; i++){
        putchar('_');
    }
    printf("%s\n",root->word);
    show(root->right,height+1);
}

void printTree(node root){
    show(root,0);
    putchar('\n');
}