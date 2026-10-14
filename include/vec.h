#ifndef VEC_H
#define VEC_H

#include <stddef.h>

/* Tableau dynamique d'entiers */
typedef struct {
    int *data;        /* adresse du tableau alloué sur le tas */
    size_t size;      /* nombre d'éléments utilisés */
    size_t capacity;  /* nombre de cases allouées   */
} vec;

void vec_init(vec *v);                          /* vecteur vide, rien d'alloué   */
int  vec_push(vec *v, int x);                   /* ajoute en fin ; 0 si échec    */
int  vec_pop(vec *v, int *out);                 /* retire le dernier ; 0 si vide */
int  vec_get(const vec *v, size_t i, int *out); /* lit data[i] ; 0 si hors limites */
void vec_print(const vec *v);                   /* affiche le contenu            */
void vec_clear(vec *v);                         /* size = 0, mémoire conservée   */
void vec_free(vec *v);                          /* libère la mémoire             */

#endif
