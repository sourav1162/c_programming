#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct d_list{
	struct d_list *left;
	int data;
	struct d_list *right;
}dlist;

void create(dlist *start);
void display(dlist *start);
void rev_display(dlist *start);

void main()
{
	char ans;
	int ch;
	dlist *head;
	head=(dlist*)malloc(sizeof(dlist));
	head->left=NULL;
	while(1){
		clrscr();
		printf("\nDouble Linked list");
		printf("\n___________________");
		printf("\n1.INSERT");
		printf("\n2.DISPLAY");
		printf("\n3.REVERSE DISPLAY");
		printf("\n4.EXIT");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				rev_display(head);
				break;
			case 4:
				exit(0);
			default:
				printf("\nWrong choice...");
				break;

		}
	}
}

void create(dlist *start)
{
	char ch;
	dlist *temp;
	do{
		printf("\nEnter data: ");;
		scanf("%d",&start->data);
		printf("\nAre you want to continue? [Y/N]: ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y'){
			temp=(dlist*)malloc(1*sizeof(dlist));
			start->right=temp;
			temp->left=start;
			start=temp;
		}else{
			break;
		}
	}while(ch=='Y'||ch=='y');
	start->right=NULL;
}

void display(dlist *start)
{
	do{
		printf("\nData: %d",start->data);
		start=start->right;
	}while(start);
	getch();
}

void rev_display(dlist *start)
{
	dlist *s1,*s2;
	s1=start->right;
	s2=start;
	while(s1!=NULL){
		s2=s1;
		s1=s1->right;
	}
	do{
		printf("\nData: %d",s2->data);
		s2=s2->left;
	}while(s2->left!=NULL);
	printf("\nData: %d",s2->data);
	getch();
}