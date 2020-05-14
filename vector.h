/*Vector для брос.
 * Пацаны ребята, я сделал вам вектор, чтобы вы могли им пользоваться.
 * Перед тем, как начать с ним работать, нужно сначала написать #include "vector.h". Затем в этом файле подправить
 * все типы данных, которые вам будут нужны. По умолчанию здесь будет int.
 *
 * Наслаждайтесь
 * */
#ifndef VECTOR_H
#define VECTOR_H
#include "stdlib.h"
#include "stdio.h"

typedef struct vector{
    int* data;//тут надо подправить тип
    int size;
}vector;

void create (vector *v, int size){
    v-> data = (int *) malloc(sizeof(int) * size);//тут надо подправить тип
    v->size = size;
    for (int i = 0; i < size; ++i) {
        v->data[i] = '\0';
    }
}

void push_back (vector *v, const int x){//тут надо подправить тип
    v->data = (int*)realloc(v->data, sizeof(int)*(v->size+1));//тут надо подправить тип
    v->data[v->size] = x;
    v->size++;
}

void pop (vector* v){
    v->data = (int*)realloc(v->data, sizeof(int)*(v->size-1));//тут надо подправить тип
    v->size--;
}

void print_all(vector* v){
    for (int i = 0; i < v->size; ++i) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int size(vector *v){
    return v->size;
}

void destroy(vector *v){
    v->size = 0;
    //free(v);
}
#endif
