#ifndef C99_PROJECT_BIN_TREE_H
#define C99_PROJECT_BIN_TREE_H
#include <stdlib.h>
#include "vector.h"
#include <stdio.h>
struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};
typedef struct tree* tree;



tree insert(tree t, int x){
    if(t == NULL){
        t = (tree)malloc(sizeof(struct tree));
        t->data = x;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if(x < t->data){
        t->left = insert(t->left,x);
    }
    if(x >= t->data){
        t->right = insert(t->right, x);
    }
    return t;
}

tree delete_son(tree t){
    if(t->right == NULL && t->left ==NULL){
        free(t);
        return NULL;
    }
    if(t->left == NULL){
        tree tmp;
        tmp = t->right;
        free(t);
        return tmp;
    }
    if(t->right == NULL){
        tree tmp;
        tmp = t->left;
        free(t);
        return tmp;
    }
    tree p = t;
    tree parent = t;
    t = t->left;
    while(t->right != NULL){
        parent = t;
        t = t->right;
    }
    p->data = t->data;
    if(parent->left == t){
        parent->left = delete_son(t);
    }
    else{
        parent->right = delete_son(t);
    }
    return p;
}

tree delete (tree t, int x){
    if(t== NULL){
        return NULL;
    }
    if(t->data == x){
        t = delete_son(t);
        return t;
    }
    if(x < t->data){
        t->left = delete(t->left,x);
    }
    else{
        t->right = delete(t->right,x);
    }
    return t;

}

void search(tree t, int lvl, vector *size){
    if(t == NULL){
        return;
    }
    if(lvl+1 > size->size){
        push_back(size, 0);
    }
    size->data[lvl]++;
    search(t->right, lvl+1, size);
    search(t->left, lvl+1, size);
}

void print_tree (tree t, int d){
    if(t!= NULL){
        print_tree(t->right, d + 1);
        printf("%*s%d\n", 3*d, "", t->data);
        print_tree(t->left, d + 1);
    }
}

#endif //C99_PROJECT_BIN_TREE_H
