#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *next;
}l;

l *insert(l *start,int data);
void display(l *start);

void main()
{
	int ch;
	char dec;
	l *head;
	int data;
	char deci;
	head=NULL;
	while(1){
		START:
		clrscr();
		printf("\nSingle linked list practice");
		printf("\n***************************");
		printf("\n1.Insert");
		printf("\n2.Display");
		printf("\n3.Exit");
		printf("\n\nEnter your choice[1-3]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter data: ");
					scanf("%d",&data);
					head=insert(head,data);
					printf("\nContinue?[Y/N]: ");
					fflush(stdin);
					scanf("%c",&deci);
				}while(deci=='Y'||deci=='y');
				break;
			case 2:
				display(head);
				break;
			case 3:
				clrscr();
				printf("\nAre you want to close the app?[Y/N]: ");
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


l *insert(l *start,int data){
	l *temp;
	if(start==NULL){
		start=(l*)malloc(1*sizeof(l));
		start->data=data;
		start->next=NULL;
		return(start);
	}else{
		l *s1,*s2;
		s1=start->next;
		s2=start;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}
		temp=(l*)malloc(1*sizeof(l));
		temp->data=data;
		temp->next=NULL;
		s2->next=temp;
		return(start);
	}
}

void display(l *start){
	do{
		printf("\nData: %d",start->data);
		start=start->next;
	}while(start);
	getch();
}