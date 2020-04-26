#ifndef C99_PROJECT_LIST_H
#define C99_PROJECT_LIST_H

#include <stdlib.h>
#include <stdio.h>

struct node{
    unsigned int data;
    struct node* next;
    struct node* prev;
};
typedef struct node* list ;
/*typedef struct list {
    struct node* item;
    unsigned int size;
} list;*/

int empty(list m){
    return (m == NULL);
}

list first(list m){
    return m;
}

list next(list m,list iter){
    if(iter != NULL){
        return iter->next;
    }
    return m;
}

list prev(list m, list iter){
    if(iter != NULL){
        return iter->prev;
    }
    return m->prev;
}

list delete(list m, list iter){
    list mm = m;
    if(m== iter){
        m->next->prev = m->prev;
        m = m->next;
        free(iter);
        return m;
    }
    while(m->next != iter){
        m=m->next;
    }
    m->next = iter->next;
    free(iter);
    return mm;
}

list insert (list m, list iter, const unsigned int x){
    list n = (list)malloc(sizeof(struct node));
    n->data = x;
    if(m == NULL){
        n->next = n;
        n->prev = n;
        return n;
    }
    list p = iter->next;
    iter->next = n;
    n->next = p;
    n->prev = iter;
    p->prev = n;
    return m;
}

list destroy(list m){
    list p = m;
    list mm;
    do{
        mm = p->next;
        free(p);
        p = mm;
    } while (p!= m);
    return p;
}

void print_all(list m, list iter){
    list p;
    p = m;
    do{if(p==iter){
            printf("|%d| ",p->data);
        }
        else {
            printf("%d ", p->data);
        }
        p = p->next;
    }   while(p!= m);
}
#endif //C99_PROJECT_LIST_H
