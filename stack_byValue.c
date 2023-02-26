#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;

	struct node *previous;
}nodetype;

nodetype* push(nodetype *);
nodetype* pop(nodetype*);
void display(nodetype*);

int main()
{
	nodetype *top = NULL;
	int choice = 0;
	do{
		printf("\n1 - Push\n2 - Pop\n3 - display\n0 - exit\nEnter choice: ");
		scanf("%d", &choice);
		switch( choice ){
			case 1:
				top = push( top );
				break;
			case 2:
				if( top != NULL ) 
					top = pop( top );
				else printf("\nStack Underflow");
				break;
			case 3:
				if( top != NULL ) display( top );
				break;
			case 0:
				break;
			default:
				printf("\nInvalid Choice");
		}
	}while( choice != 0 );
	
	return 0;
}



nodetype* push(nodetype *top)
{
	printf("\nEnter value: ");
	int x;
	scanf("%d",&x);

	nodetype *p = (nodetype*) malloc( sizeof(nodetype) );
	p->info = x;

	if( top == NULL ){
		top = p;
		top->previous = NULL;
	}
	else{
		p->previous = top;
		top = p;
	}
	
	return top;
}




nodetype* pop( nodetype *top )
{
	printf("\n%d", (top->info) );

	top = top->previous;

	return top;
}

void display( nodetype *top)
{
	while( top != NULL ){
		printf("\t%d", top->info);
		top = top->previous;
	}

	return;
}
