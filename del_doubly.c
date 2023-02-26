#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insert(struct node** first, int new_data, int position) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;

    if (position == 1 || *first == NULL) {
        new_node->prev = NULL;
        new_node->next = *first;
        if (*first != NULL) {
            (*first)->prev = new_node;
        }
        *first = new_node;
    } else {
        struct node* curr_node = *first;
        for (int i = 1; i < position - 1 && curr_node->next != NULL; i++) {
            curr_node = curr_node->next;
        }
        new_node->next = curr_node->next;
        new_node->prev = curr_node;
        if (curr_node->next != NULL) {
            curr_node->next->prev = new_node;
        }
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


void delete(struct node** first, int key) {
    struct node* temp = *first;
    if (temp != NULL && temp->data == key) {
        *first = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node with key %d not found!\n", key);
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

int main()
{
    struct node* head = NULL;
    int choice = 0;
    do{
        printf("\n1 - insert\n2 - delete\n3 - display\n0 - exit\nEnter choice: ");
        scanf("%d", &choice);

        switch( choice ){

            case 1:
                int data,position;
                printf("Enter data ?\n");
                scanf("%d",&data);
                printf("Enter position ?\n");
                scanf("%d",&position);
                insert(&head, data, position);
                break;

            case 2:
                int key;
                printf("Enter key to be deleted ?");
                scanf("%d",&key);
                delete(&head,key);
                break;

            case 3:
                print_list(head);
                break;

            case 0:
                break;

            default:
                printf("\nInvalid choice entered");

        }
    } while( choice != 0 );

    return 0;
}
