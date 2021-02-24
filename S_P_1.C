#include<stdio.h>

typedef struct list{
	int data;
	struct list *next;
}l;

l *head;
int c_data=0;

void push();
void pop();
void display();

void main()
{
	int dec;
	START:
	clrscr();
	printf("1.Push");
	printf("\n2.Display");
	printf("\n3.Pop");
	printf("\n4.Exit");

	printf("\n\nEnter the decision: ");
	scanf("%d",&dec);
	switch(dec){
		case 1:
			push();
			goto START;
		case 2:
			display();
			goto START;
		case 3:
			pop();
			goto START;
		case 4:
			exit(0);
			goto START;
		default:
			printf("\nSorry invalid input");
			getch();
			goto START;
	}
}

void push(){
	l *temp;
	int data;
	char ch;
	clrscr();
	do{
		printf("Enter data: ");
		scanf("%d",&data);
		if(head==NULL){
			head=(l*)malloc(sizeof(l));
			head->data=data;
			head->next=NULL;
		}else{
			temp=(l*)malloc(sizeof(l));
			temp->data=data;
			temp->next=head;
			head=temp;
		}
		c_data++;
		printf("continue? : ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
}

void display(){
	l *temp;
	temp=head;
	clrscr();
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

void pop(){
	l *temp;
	temp=head;
	clrscr();
	if(temp==NULL){
		printf("Empty");
		getch();
		return;
	}else{
		temp=temp->next;
	}
	printf("Popped value: %d",head->data);
	free(head);
	head=temp;
	getch();
}