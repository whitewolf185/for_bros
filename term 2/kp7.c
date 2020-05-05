#include <stdio.h>
#include <stdlib.h>
#define START_SIM
//#define DEBUG
#define START_SUM
typedef struct val{
    int i;
    double x;
} val;

typedef struct vector{
    val *data;
    int size;
} vector;

typedef struct tmp_vector{
    int *data;
    int size;
} tmp_vector;

void create (vector *v, int size){
    v-> data = (val *) malloc(sizeof(val) * size);
    v->size = size;
    for (int i = 0; i < size; ++i) {
        v->data[i].i = 0;
        v->data[i].x = 0;
    }
}

void tmp_create (tmp_vector *v, int size){
    v-> data = (int *) malloc(sizeof(int) * size);
    v->size = size;
    for (int i = 0; i < size; ++i) {
        v->data[i] = 0;
    }
}

void tmp_push_back(tmp_vector* v, int x){
    v->data = (int*)realloc(v->data, sizeof(int) * (v->size+1));
    v->data[v->size] = x;
    v->size++;
}

void push_back(vector* v, int i, double x){
    v->data = (val*)realloc(v->data, sizeof(val) * (v->size+1));
    v->data[v->size].i = i;
    v->data[v->size].x = x;
    v->size++;
}

void clear(vector* v){
    v->data = (val*)realloc(v->data, 0);
    v->size = 0;
}

void pop(vector* v){
    v->data = (val*)realloc(v->data, --v->size);
    v->size--;
}

void print (vector* v){
    for (int i = 0; i < v->size; ++i) {
        printf("%d : %.2fl | ",v->data[i].i, v->data[i].x);
    }
    printf("\n\n");
}


void show_all (vector* v, int n, int m){
    int k = 0;
    int row = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v->data[k].i == 0 && v->data[k].x != 0){
                row = v->data[k].x + 0.5;
                k++;
            }
            if(row-1 == i && v->data[k].i-1 ==j){
                printf("%.2lf ", v->data[k].x);
                k++;
            }
            else{
                printf("0.00 ");
            }
        }
        printf("\n");
    }
}

int search(vector* v3, tmp_vector* tmp, int i, int j){
    for (int k = tmp->data[v3->data[j].i - 1]+1; k < tmp->data[v3->data[j].i] ; ++k) {
        if(v3->data[k].x == v3->data[j].x && i+1 == v3->data[k].i){
            return 1;
        }
    }
    return 0;
}

void tmp_print(tmp_vector* v){
    for (int i = 0; i < v->size; ++i) {
        printf("%d | ", v->data[i]);
    }
    printf("\n\n");
}

int main(){
    int n,m;
    vector v1;
    create(&v1, 0);
    printf("Enter n and m for v\n");
    fflush(stdout);
    scanf("%d %d", &n, &m);
    int sim = (n == m)? 1 : 0;
    int f;
    printf("Entering v1\n");
    fflush(stdout);
    for (int i = 0; i < n; ++i) { //initial
        f=1;
        for (int j = 0; j < m; ++j) {
            double x;
            scanf("%lf",&x);

            if (f == 1){
                f = 0;
                push_back(&v1, 0, i + 1);
            }
            if(x == 0){ continue;}
            push_back(&v1, j + 1, x);
        }
    }
    push_back(&v1, 0, 0);

    vector v2;
    create(&v2, 0);
    printf("Entering v2\n");
    fflush(stdout);
    for (int i = 0; i < n; ++i) { //initial v2
        f=1;
        for (int j = 0; j < m; ++j) {
            double x;
            scanf("%lf",&x);
            if (f == 1){
                f = 0;
                push_back(&v2, 0, i + 1);
            }
            if(x == 0){ continue;}
            push_back(&v2, j + 1, x);
        }
    }
    push_back(&v2, 0, 0);

//    _______________SUM________________________________
#ifdef START_SUM
    vector v3;
    create(&v3,0);
    int i1 = 0;
    int i2 = 0;
    int r1 = -1, r2 = -1;
    while (v1.data[i1].i != 0 || v1.data[i1].x != 0 || v2.data[i2].i != 0 || v2.data[i2].x != 0) {
        if (v1.data[i1].i == 0) {
            r1 = v1.data[i1].x;
        }
        if (v2.data[i2].i == 0) {
            r2 = v2.data[i2].x;
        }

        if (r1 == 0) r1 = r2 + 1;
        if (r2 == 0) r2 = r1 + 1;
        // printf("%d %d\n", r1, r2);

        if (r1 < r2) {
            push_back(&v3, v1.data[i1].i, v1.data[i1].x);
            // printf("1 %d : %.2lf\n", m1.data[i1].i, m1.data[i1].x);
            i1++;

        } else if (r1 > r2) {
            push_back(&v3, v2.data[i2].i, v2.data[i2].x);
            // printf("2 %d : %.2lf\n", m2.data[i2].i, m2.data[i2].x);
            i2++;

        } else {
            if (v1.data[i1].i < v2.data[i2].i) {
                push_back(&v3, v1.data[i1].i, v1.data[i1].x);
                // printf("3 %d : %.2lf\n", m1.data[i1].i, m1.data[i1].x);
                i1++;

            } else if (v1.data[i1].i > v2.data[i2].i) {
                push_back(&v3, v2.data[i2].i, v2.data[i2].x);
                // printf("4 %d : %.2lf\n", m2.data[i2].i, m2.data[i2].x);
                i2++;

            } else if(v1.data[i1].i == 0 && v2.data[i2].i == 0){
                push_back(&v3, v1.data[i1].i, r1);
                i1++;
                i2++;
            }else if(v1.data[i1].x + v2.data[i2].x == 0){
                i1++;
                i2++;
            }else{
                push_back(&v3, v1.data[i1].i, v1.data[i1].x + v2.data[i2].x);
                i1++;
                i2++;
            }
        }
    }
    push_back(&v3, 0, 0);
    show_all(&v3,n,m);
    fflush(stdout);
#endif //START_SUM

//    __________________CHECKING FOR SIM________________
#ifdef START_SIM
    if(sim){
        tmp_vector tmp;
        vector v4;
        tmp_create(&tmp,0);
        create(&v4,0);
        for (int i = 0; i < v3.size; ++i) {
            if(v3.data[i].i == 0){
                tmp_push_back(&tmp,i);
                continue;
            }
        }

#ifdef DEBUG
        printf("this is tmp\n");
        tmp_print(&tmp);
        fflush(stdout);
#endif


       /* for (int i = 1; i <= n; ++i) {
            push_back(&v4,0,i);
            for (int j = 1; j < tmp.size; ++j) {
                if(i > tmp.data[j] - tmp.data[j-1]){
                    continue;
                }
                push_back(&v4,i,v3.data[tmp.data[j-1]+i].x);
            }
        }
        push_back(&v4,0,0);
#ifdef DEBUG
        printf("this is v4\n");
        show_all(&v4,n,m);
        print(&v4);
#endif*/
        for (int i = 0; i < tmp.size-1; ++i) {
            for (int j = tmp.data[i]+1; j < tmp.data[i+1]; ++j) {
                if(i+1 == v3.data[j].i){
                    continue;
                }
                else if(search(&v3,&tmp,i, j) == 0) {
                    sim = 0;
                }
            }
        }
        if(sim){
            printf("Simmetry\n");
            fflush(stdout);
        }
        else{
            printf("No simmetry\n");
            fflush(stdout);
        }

    }
    else {
        printf("No simmetry\n");
        fflush(stdout);
    }
#endif //START_SIM


//-----------------------------------------------DEBUG------------------------------------------------
#ifdef DEBUG
    //-----------------printing v1------------------------------------
    printf("this is v1\n");
    show_all(&v1,n,m);
    print(&v1);
    fflush(stdout);
//--------------------printing v2-------------------------------------
    printf("this is v2\n");
    show_all(&v2,n,m);
    print(&v2);
    fflush(stdout);

    //--------------------printing v3-------------------------------------
    printf("this is v3\n");
    print(&v3);
    fflush(stdout);
#endif //DEBUG
//--------------------------------------------------END DEBUG--------------------------------------


    return 0;
}



