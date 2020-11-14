#include<alloc.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *link;
}l;

l *head=NULL,*x,*y;

void create();
void display();

void main()
{
	int ch;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\nCircular link list");
		printf("\n*******************");
		printf("\n\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.EXIT");
		printf("\n\nEnter your choice[1-3]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				clrscr();
				printf("\nAre you want to close the app?[Y/N]: ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					exit(0);
				}else{
					goto START;
				}
			default:
				printf("\nWrong choice...");
		}
	}
}


void create()
{
	char ch;
	x=(l*)malloc(1*sizeof(l));
	printf("\nEnter data: ");
	scanf("%d",&x->data);
	x->link=x;
	head=x;
	printf("\nContinue?[Y/N]: ");
	fflush(stdin);
	scanf("%c",&ch);
	while(ch=='Y'||ch=='y'){
		y=(l*)malloc(1*sizeof(l));
		printf("\nEnter data: ");
		scanf("%d",&y->data);
		x->link=y;
		y->link=head;
		x=y;
		printf("\nContinue?[Y/N]: ");
		fflush(stdin);
		scanf("%c",&ch);
	}
}

void display()
{
	x=head;
	if(head==NULL){
		printf("\nList is Empty...");
		return;
	}

	while(x->link!=head){
		printf("%d->",x->data);
		x=x->link;
	}
	printf("%d",x->data);
	getch();
}