#include "binarTree.h"
#include <stdio.h>
#include <stdlib.h>

void insert(node *root, int val){
    if(*root==0){
        *root = (node)malloc(sizeof(treeNode));
        (*root)->value=val;
        (*root)->left=0;
        (*root)->right=0;
    }
    else{
        if(val<(*root)->value){
            insert(&(*root)->left,val);
        }
        else{
            insert(&(*root)->right,val);
        }
    }
}
//////
node treeMin(node root){
    if(root){
        while(root->left){
            root=root->left;
        }
    }
    return root;
}
node treeMax(node root){
    if(root){
        while(root->right){
            root=root->right;
        }
    }
    return root;
}
node ancestor(node root){
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
    return root;
}

node descendant(node root){
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
    return root;
}

///////
int containSameValues(node tree1, node tree2){
    node p, q;
    p = treeMin(tree1);
    q = treeMin(tree2);
    while(p && q){
        if(p->value != q->value){
            return 0;
        }
        p = ancestor(p);
        q = ancestor(q);
    }
    return (p==q);
}
