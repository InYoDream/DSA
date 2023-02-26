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
        new_node->next = *first;
        struct node* last_node = *first;
        while (last_node->next != *first) { 
            last_node = last_node->next;
        }
        last_node->next = new_node; 
        *first = new_node;
    } else { 
        struct node* prev_node = *first;
        for (int i = 1; i < position - 1 && prev_node->next != *first; i++) {
            prev_node = prev_node->next;
        }
        new_node->next = prev_node->next;
        prev_node->next = new_node;
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

void search(struct node* head, int key) {
    struct node* curr_node = head;
    int position = 1;
    do {
        if (curr_node->data == key) {
            printf("Node with key %d found at position %d\n", key, position);
            return;
        }
        curr_node = curr_node->next;
        position++;
    } while (curr_node != head);
    printf("Error: Node with key %d not found!\n", key);
}

int main() {
    struct node* head = NULL;
    int choice = 0;
    do {
        printf("\n1 - insert\n2 - search\n3 - display\n0 - exit\nEnter choice: ");
        scanf("%d", &choice);

        switch( choice ) {
            case 1: {
                int data, position;
                printf("Enter data ?\n");
                scanf("%d",&data);
                printf("Enter position ?\n");
                scanf("%d",&position);
                insert(&head, data, position);
                break;
            }
            case 2: {
                int key;
                printf("Enter the key ?");
                scanf("%d",&key);
                search(head,key);
                break;
            }
            case 3:
                print_list(head);
                break;
            case 0:
                break;
            default:
                printf("\nInvalid choice entered");
        }
    } while( choice != 0 );
    if (head != NULL) {
        struct node* curr_node = head->next;
        while (curr_node != head) {
            struct node* temp_node = curr_node;
            curr_node = curr_node->next;
            free(temp_node);
        }
        free(head);
    }

    return 0;
}
