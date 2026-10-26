#include <assert.h>
#include "list.h"

int main(void)
{
    node *head = NULL;
    assert(list_len(head) == 0);
    list_push_front(&head, 10);
    assert(list_len(head) == 1);
    list_push_front(&head, 20);
    assert(list_len(head) == 2);
    list_free(&head);
    assert(head == NULL);
    return 0;
}