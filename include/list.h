#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct node{
    int val;
    struct node *next;
} node;

node *node_new(int val);
int list_push_front(node **head, int val);
size_t list_len(const node *head);
node *list_find(node *head, int val);
void list_print(const node *head);
void list_free(node **head);

#endif
