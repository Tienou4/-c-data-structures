#include <stdio.h>
#include "list.h"

int main(void)
{
    node *head = NULL;
    printf("%zu\n",list_len(head));
    list_push_front(&head, 20);
    printf("%zu\n", list_len(head));
    list_push_front(&head, 30); 
    list_push_front(&head, 10);
    list_push_front(&head, 15);
    printf("%zu\n", list_len(head));
    list_print(head);
    list_free(&head);
    list_print(head);
    list_push_back(&head, 15);
    list_push_back(&head, 10);
    list_push_back(&head, 30);

    node *found = list_find(head, 10);
    if (found != NULL)
        printf("trouvé : %d\n", found->val);   // trouvé : 10

    printf("%s\n", list_find(head, 99) == NULL ? "absent" : "présent");   // absent
    printf("%s\n", list_find(NULL, 1) == NULL ? "absent" : "présent");    // absent (liste vide)

    list_free(&head);


    return 0;
}