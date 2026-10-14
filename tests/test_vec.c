#include <assert.h>
#include <stdio.h>
#include "vec.h"

static void test_init(void) {
    vec v;
    vec_init(&v);
    assert(v.data == NULL && v.size == 0 && v.capacity == 0);
    vec_free(&v);
}

static void test_push_et_croissance(void) {
    vec v;
    int x;
    vec_init(&v);
    for (int i = 0; i < 4; i++) assert(vec_push(&v, i));
    assert(v.size == 4 && v.capacity == 4);
    assert(vec_push(&v, 4));                  /* 5e element : realloc */
    assert(v.size == 5 && v.capacity == 8);
    assert(vec_get(&v, 4, &x) && x == 4);
    vec_free(&v);
}

static void test_get_limites(void) {
    vec v;
    int x = -1;
    vec_init(&v);
    assert(!vec_get(&v, 0, &x));              /* vecteur vide */
    vec_push(&v, 7);
    assert(vec_get(&v, 0, &x) && x == 7);
    assert(!vec_get(&v, 1, &x));              /* juste apres la fin */
    vec_free(&v);
}

static void test_pop(void) {
    vec v;
    int x = 0;
    vec_init(&v);
    assert(!vec_pop(&v, &x));                 /* pop sur vide refuse */
    vec_push(&v, 1);
    vec_push(&v, 2);
    assert(vec_pop(&v, &x) && x == 2);
    assert(vec_pop(&v, &x) && x == 1);
    assert(!vec_pop(&v, &x));
    vec_free(&v);
}

static void test_clear(void) {
    vec v;
    vec_init(&v);
    vec_clear(&v);                            /* clear sur vecteur jamais rempli */
    assert(v.size == 0);
    for (int i = 0; i < 5; i++) vec_push(&v, i);
    vec_clear(&v);
    assert(v.size == 0 && v.capacity == 8 && v.data != NULL);
    vec_push(&v, 99);                         /* memoire reutilisee, sans realloc */
    assert(v.size == 1 && v.capacity == 8);
    vec_free(&v);
}

static void test_free_deux_fois(void) {
    vec v;
    vec_init(&v);
    vec_push(&v, 1);
    vec_free(&v);
    vec_free(&v);                             /* sans danger */
    assert(v.data == NULL && v.size == 0 && v.capacity == 0);
}

int main(void) {
    test_init();
    test_push_et_croissance();
    test_get_limites();
    test_pop();
    test_clear();
    test_free_deux_fois();
    printf("Tous les tests passent.\n");
    return 0;
}
