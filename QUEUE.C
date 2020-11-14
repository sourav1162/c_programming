#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *link;
}n;

n *front,*rear;

void enque(){
	int data;
	char ch;
	n *temp;
	do{
		printf("\nEnter data: ");
		scanf("%d",&data);
		if(front==NULL){
			rear=(n*)malloc(1*sizeof(n));
			rear->info=data;
			rear->link=NULL;
			front=rear;
		}else{
			temp=(n*)malloc(1*sizeof(n));
			rear->link=temp;
			temp->info=data;
			temp->link=NULL;
			rear=temp;
		}
		printf("\nAre you want to continue? ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='Y'||ch=='y');
}

void display(){
	n *tempF;
	tempF=front;
	if((tempF==NULL)&&(rear==NULL)){
		printf("\nQueue is empty");
		getch();
		return;
	}
	while(tempF!=rear){
		printf("%d->",tempF->info);
		tempF=tempF->link;
	}
	if(tempF==rear){
		printf("%d",tempF->info);
	}
	getch();
}

void main()
{
	int ch;
	char dec;
	do{
		START:
		clrscr();
		printf("\n1.Enque");
		printf("\n2.Display");
		printf("\n3.Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enque();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
			default:
				printf("\nPlease enter a valid choice");
				getch();
				goto START;
		}
		printf("\nClose? ");
		fflush(stdin);
		scanf("%c",&dec);
	}while(dec=='n'||dec=='N');
}