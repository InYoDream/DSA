#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}nodetype;


void insert( nodetype**, nodetype** );
void delete( nodetype**, nodetype** );
void display( nodetype* );


int main()
{
	nodetype *left = NULL, *right = NULL;

	int choice = 0;
	do{
		printf("\n1 - insert\n2 - delete\n3 - display\n0 - exit\nEnter choice: ");
		scanf("%d", &choice);

		switch( choice ){

			case 1: 
				insert( &left, &right );
				break;

			case 2:
				if( left != NULL ) delete( &left, &right );
				else printf("\nQueue is Empty");
				break;

			case 3:
				if( left != NULL ) display( left );
				break;

			case 0:
				break;

			default:
				printf("\nInvalid choice entered");

		}
	}while( choice != 0 );

	return 0;
}

void insert( nodetype **left, nodetype **right )
{
	nodetype *p = (nodetype*) malloc( sizeof( nodetype ) );
	printf("\nEnter value: ");
	scanf("%d", &(p->info) );

	if( *right == NULL )
		*left = *right = p;
	else{
		(*right)->next = p;
		(*right) = p;
	}

	return;
}

void delete( nodetype **left, nodetype **right )
{
	printf(" deleted value: %d", (*left)->info );

	nodetype *p = *left;
	*left = (*left)->next;
	free( p );

	if( *left == NULL ) *right = NULL;

	return;
}

void display( nodetype *left )
{
	while( left != NULL){
		printf("\t%d", left->info );
		left = left->next;
	}

	
}


