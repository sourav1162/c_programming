#include<stdio.h>

typedef struct list{
	int data;
	struct list *next;
}l;

l *front,*rear;
int c_data=0;

void enque();
void display();

void main()
{
	int dec;
	START:
	clrscr();
	printf("1.Enque");
	printf("\n2.Display");
	printf("\n3.Exit");

	printf("\n\nEnter the decision: ");
	scanf("%d",&dec);
	switch(dec){
		case 1:
			enque();
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

void enque(){
	l *temp;
	int data;
	char ch;
	clrscr();
	do{
		printf("Enter data: ");
		scanf("%d",&data);
		if(rear==NULL){
			rear=(l*)malloc(sizeof(l));
			rear->data=data;
			rear->next=NULL;
			front=rear;
		}else{
			temp=(l*)malloc(sizeof(l));
			temp->data=data;
			temp->next=rear;
			rear->next=temp;
			rear=temp;
		}
		c_data++;
		printf("\nContinue? : ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	printf("\n\nNumber of data: %d",c_data);
	getch();
}

void display(){
	l *temp;
	temp=front;
	clrscr();
	if((front==NULL)&&(rear==NULL)){
		printf("Empty");
		getch();
		return;
	}

	while(temp!=rear){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	if(temp==rear){
		printf("%d",temp->data);
	}
	getch();
}