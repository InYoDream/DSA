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
void search(struct node* first, int key) {
    struct node* curr_node = first;
    int position = 1;
    while (curr_node != NULL && curr_node->data != key) {
        curr_node = curr_node->next;
        position++;
    }
    if (curr_node == NULL) {
        printf("Error: Node with key %d not found!\n", key);
    } else {
        printf("Node with key %d found at position %d\n", key, position);
    }
}


int main()
{
	struct node* head = NULL;
	int choice = 0;
	do{
		printf("\n1 - insert\n2 - search\n3 - display\n0 - exit\nEnter choice: ");
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
                printf("Enter the key ?");
                scanf("%d",&key);
                search(head,key);
                break;
			case 3:
				print_list(head);
				break;

			case 0:
				break;

			default:
				printf("\nInvalid choice entered");

		}
	}while( choice != 0 );

	return 0;
}