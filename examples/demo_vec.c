#include <stdio.h>
#include "vec.h"

int main(void) {
    vec v;
    int x;

    vec_init(&v);
    printf("Au depart : ");
    vec_print(&v);

    for (int i = 1; i <= 6; i++) {
        vec_push(&v, i * 10);
        printf("push(%d) : ", i * 10);
        vec_print(&v);
    }

    if (vec_get(&v, 2, &x)) printf("v[2] = %d\n", x);
    if (!vec_get(&v, 99, &x)) printf("v[99] : hors limites, refuse\n");

    vec_pop(&v, &x);
    printf("pop -> %d : ", x);
    vec_print(&v);

    vec_clear(&v);
    printf("Apres clear : ");
    vec_print(&v);

    vec_free(&v);
    printf("Apres free : ");
    vec_print(&v);
    return 0;
}
