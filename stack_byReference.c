#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
int info;
	struct node *previous;
}nodetype;


void push( nodetype **top);
void pop( nodetype **top);
void display( nodetype *top);
void displayReverse( nodetype *top);


int main()
{
	nodetype *top = NULL;

	int choice = 0;

	do{
		printf("\n\n1 - push\n2 - pop\n3 - display\n4 - display_reverse\n0 -exit\nEnter choice:\t");
		scanf("%d", &choice);

		switch( choice ){

			case 1:
				push( &top );
				break;

			case 2:
				if( top != NULL ) pop( &top );
				else printf("\nStack is empty");
				break;

			case 3:
				if( top != NULL ) display( top );
				break;

			case 4:
				if( top != NULL ) displayReverse( top );
				break;

			case 0:
				break;

			default:
				printf("\nInvalid choice");
		}
	
	}while( choice != 0 );

	return 0;
}



void push( nodetype **top)
{
	nodetype *p = (nodetype*) malloc( sizeof(nodetype) );
	printf("\nEnter value: ");
	scanf("%d", &(p->info) );

	if( *top == NULL )
		*top = p;
	else{
		p->previous = *top;
		*top = p;
	}

	return;
}

void pop( nodetype **top)
{
	printf("\nPopped: %d", (*top)->info);
	
	nodetype *p = *top;
	*top = (*top)->previous;
	free(p);

	return;
}

void display(nodetype *top)
{
	while( top != NULL ){
		printf("\n%d", top->info);
		top = top->previous;
	}

	return;
}

void displayReverse(nodetype *top)
{
	if( top->previous == NULL ){
		printf("\n%d", top->info);
		return ;
	}
	
	displayReverse( (top)->previous );
	printf("\n%d", (top)->info);

	return;
}