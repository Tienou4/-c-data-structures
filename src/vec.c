#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

void vec_init(vec *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int vec_push(vec *v, int x) {
    if (v->size == v->capacity) {                       /* tableau plein : on l'agrandit */
        size_t new_cap = v->capacity ? v->capacity * 2 : 4;
        int *temp = realloc(v->data, new_cap * sizeof *temp);
        if (temp == NULL) return 0;                     /* v->data reste valide */
        v->data = temp;
        v->capacity = new_cap;
    }
    v->data[v->size++] = x;
    return 1;
}

int vec_pop(vec *v, int *out) {
    if (v->size == 0) return 0;
    *out = v->data[--v->size];
    return 1;
}

int vec_get(const vec *v, size_t i, int *out) {
    if (i >= v->size) return 0;
    *out = v->data[i];
    return 1;
}

void vec_print(const vec *v) {
    printf("[");
    for (size_t i = 0; i < v->size; i++)
        printf("%s%d", i ? ", " : "", v->data[i]);
    printf("]  (taille=%zu, capacite=%zu)\n", v->size, v->capacity);
}

void vec_clear(vec *v) {
    v->size = 0;
}

void vec_free(vec *v) {
    free(v->data);
    vec_init(v);
}
