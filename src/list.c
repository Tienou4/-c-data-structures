#include "list.h"
#include <stdlib.h>
#include <stdio.h>

node *node_new(int val)
{
    node *n = malloc(sizeof *n);

    if (n == NULL)
        return NULL;
    n->val = val;
    n->next = NULL;
    return n;
}

int list_push_front(node **head, int val)
{
    node *n = node_new(val);

    if (n == NULL)
        return -1;
    n->next = *head;
    *head = n;
    return 0;
}

size_t list_len(const node *head)
{
    size_t len = 0;

    for (const node *p = head; p != NULL; p = p->next)
        len++;
    return len;
}

void list_print(const node *head)
{
    for(const node *p = head; p != NULL; p = p->next)
        printf("%d-->", p->val);
    printf("NULL\n");
}

void list_free(node **head)
{
    while(*head != NULL){
        node *next = NULL;
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}

int list_push_back(node **head, int val)
{
    node *n = node_new(val);

    if (n == NULL)
        return -1;
    if (*head == NULL) {
        *head = n;
    } else {
        node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = n;
    }
    return 0;
}

node *list_find(node *head, int val)
{
    for(node *p = head; p != NULL ; p = p->next)
    {
        if(p->val == val) return p;
    }

    return NULL;
}

int list_remove(node **head, int val)
{
    node *prev = NULL;
    node *cur = *head;

    while (cur != NULL && cur->val != val) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return 0;                   /* val absente */

    if (prev == NULL)
        *head = cur->next;          /* suppression de la tête */
    else
        prev->next = cur->next;     /* le précédent contourne cur */

    free(cur);
    return 1;
}