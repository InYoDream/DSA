#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head_ref, int new_data, int position) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;

    if (position == 1 || *head_ref == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        struct node* curr_node = *head_ref;
        for (int i = 1; i < position - 1 && curr_node->next != NULL; i++) {
            curr_node = curr_node->next;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }
}

void print_list(struct node* head) {
    struct node* curr_node = head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int data, position, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("Enter the position for node %d: ", i + 1);
        scanf("%d", &position);
        insert(&head, data, position);
    }

    printf("Linked list: ");
    print_list(head);

    return 0;
}
