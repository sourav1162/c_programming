#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *prev;
	struct list *next;
}l;

l *head;
int c_data=0;

void insert();
void display();

void main()
{
	int dec;
	START:
	clrscr();
	printf("1.Insert");
	printf("\n2.Display");
	printf("\n3.Exit");
	printf("\n\nEnter your decision: ");
	scanf("%d",&dec);
	switch(dec){
		case 1:
			insert();
			goto START;
		case 2:
			display();
			goto START;
		case 3:
			exit(0);
		default:
			printf("\nSorry invalid input");
			getch();
			goto START;
	}
}

void insert(){
	int data;
	l *temp,*s1,*s2;
	char ch;
	clrscr();
	do{
		printf("Enter data: ");
		scanf("%d",&data);
		if(head==NULL){
			head=(l*)malloc(sizeof(l));
			head->data=data;
			head->prev=NULL;
			head->next=NULL;
		}else{
			s1=head->next;
			s2=head;
			while(s1!=NULL){
				s2=s1;
				s1=s1->next;
			}
			temp=(l*)malloc(sizeof(l));
			temp->data=data;
			temp->next=NULL;
			temp->prev=s2;
			s2->next=temp;
		}
		c_data++;
		printf("Continue? : ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	printf("\nNumber of data: %d",c_data);
	getch();
}

void display(){
	l *temp;
	clrscr();
	temp=head;
	if(temp==NULL){
		printf("Empty");
		getch();
		return;
	}

	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	getch();
}