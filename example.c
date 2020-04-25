/*Это пример использования вектора на с для брос*/

#include "stdio.h"
#include "vector.h"
int main() {
    vector v;
    create(&v,0);
    push_back(&v,23);
    push_back(&v,256);
    pop(&v);
    print_all(&v);
    return 0;
}

