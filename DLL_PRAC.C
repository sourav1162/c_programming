#include<alloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

typedef struct list{
	struct list *left;
	int data;
	struct list *right;
}l;

void create(l *start);
void display(l *start);

void main()
{
	int ch;
	char dec;
	l *head;
	head=(l*)malloc(1*sizeof(l));
	head->left=NULL;
	while(1){
		START:
		clrscr();
		printf("\nDouble link list practice");
		printf("\n**************************");
		printf("\n\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.EXIT");
		printf("\nEnter your choice[1-3]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				clrscr();
				printf("\nAre you want to close the app? [Y/N]: ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='Y'||dec=='y'){
					exit(0);
				}else{
					goto START;
				}
			default:
				printf("\nWrong choice...");
		}
	}
}


void create(l *start)
{
	char ch;
	l *s1;
	do{
		printf("\nEnter data: ");
		scanf("%d",&start->data);
		printf("\nContinue?[Y/N]: ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y'){
			s1=(l*)malloc(sizeof(l));
			s1->left=start;
			start->right=s1;
			start=s1;
		}
	}while(ch=='Y'||ch=='y');
	start->right=NULL;
}

void display(l *start)
{
	do{
		printf("\nData: %d",start->data);
		start=start->right;
	}while(start);
	getch();
}