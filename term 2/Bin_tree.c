#include "../Bin_tree.h"
#include <stdio.h>

int main(){
    vector size;
    tree t = NULL;
    char c;
    while(scanf("%c", &c)>0){
        if(c==' ' || c=='\n' || c=='\t') continue;
        if(c == 'b'){
            break;
        }
        int x;
        if(c == 'i') {
            printf("Enter your val\n");
            fflush(stdout);
            scanf("%d ", &x);
            t = insert(t, x);
        }
        if(c == 'd') {
            printf("Enter your val\n");
            fflush(stdout);
            scanf("%d ", &x);
            t = delete(t, x);
        }
        if(c == 'q') {
            create(&size,0);
            search(t, 0, &size);
            int max = 0;
            int max_i = -1;
            for (int i = 0; i < size.size; ++i) {
                if (max < size.data[i]) {
                    max = size.data[i];
                    max_i = i;
                }
            }
            printf("%d\n", max_i);
            printf("all lvl with max vertex: ");
            for (int j = 0; j < size.size; ++j) {
                if(size.data[j] == max){
                    printf("%d ", j);
                }
            }
            printf("\n");
            fflush(stdout);
            destroy(&size);
        }

        if(c == 'p') {
            print_tree(t, 0);
            fflush(stdout);
        }
        if(c == 'h'){
            printf("p - print\ni - insert\nq - :)\nd - delete\n");
            fflush(stdout);
        }
    }
    return 0;
}