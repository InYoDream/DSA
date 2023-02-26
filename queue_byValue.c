#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}nodetype;

nodetype* insert(nodetype*);
nodetype* delete(nodetype*);
void display(nodetype*);

int main()
{
	nodetype *left = NULL, *right = NULL;
	int choice = 0;
	do{
		printf("\n1 - insert\n2 - delete\n3 - display\n0 - exit\nEnter value:\t");
		scanf("%d", &choice);

		switch( choice ){
			case 1:
				right = insert( right );
				if( left == NULL ) left = right;
				break;

			case 2:
				if( left != NULL ){
					left = delete( left );
					if( left == NULL ) right = NULL;
				}
				break;
			
			case 3:
				if( left != NULL )
					display(left);
				break;

			case 0:
				break;

			default:
				printf("\nInvalid choice");
		}


	}while( choice != 0);

	return 0;
}


nodetype* insert( nodetype *right)
{
	nodetype *p = (nodetype*) malloc( sizeof(nodetype) );

	printf("\nEnter value: ");
	scanf("%d", &(p->info));

	p->next = NULL;

	if( right == NULL ) right = p;
	else right->next = p;

	return p;
}

nodetype* delete(nodetype *left)
{
	printf("\n%d\n", (left->info) );

	nodetype *p = left;
	left = left->next;
	free(p);

	return left;
}

void display(nodetype *left)
{
	while( left != NULL ){
		printf("\t%d", left->info);
		left = left->next;
	}
}























