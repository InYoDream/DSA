#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** first, int new_data, int position) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;

    if (*first == NULL) {
        new_node->next = new_node;
        *first = new_node;
    } else if (position == 1) {
        struct node* last = *first;
        while (last->next != *first) {
            last = last->next;
        }
        new_node->next = *first;
        last->next = new_node;
        *first = new_node;
    } else {
        struct node* curr_node = *first;
        for (int i = 1; i < position - 1 && curr_node->next != *first; i++) {
            curr_node = curr_node->next;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }
}

void print_list(struct node* head) {
    struct node* curr_node = head;
    do {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    } while (curr_node != head);
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

    printf("Circular linked list: \n ");
    print_list(head);

    return 0;
}
