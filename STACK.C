#include<stdio.h>
#include<conio.h>

typedef struct node{
	int info;
	struct node *ptr;
}n;

n *top,*top1;

void push(int data);
void display();
void pop();

int count=0;

int main()
{
	int ch,data;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\n1.PUSH");
		printf("\n2.DISPLAY");

		printf("\n3.POP");
		printf("\n4.EXIT");
		printf("\n\nEnter your choice[Y/N]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter data: ");
					scanf("%d",&data);
					push(data);
					printf("\nContinue?[Y/N]: ");
					fflush(stdin);
					scanf("%c",&dec);
				}while(dec=='y'||dec=='Y');
				break;
			case 2:
				display();
				break;
			case 3:
				pop();
				break;
			case 4:
				do{
					clrscr();
					printf("\nAre you want to close? [y/n]: ");
					fflush(stdin);
					scanf("%c",&dec);
					if(dec=='y'||dec=='Y'){
						exit(0);
					}else{
						goto START;
					}
				}while(dec=='y'||dec=='Y');
			default:
				printf("\nWrong choice...");
		}
	}
}

void pop(){
	n *temp;
	temp=top;
	if(temp==NULL){
		printf("\nSorry error while pop.List is empty");
		getch();
		return;
	}else{
		temp=temp->ptr;
	}
	printf("\nPopped value: %d",top->info);
	free(top);
	top=temp;
	getch();
	return;
}

void push(int data){
	n *temp;
	if(top==NULL){
		top=(n*)malloc(sizeof(n));
		top->info=data;
		top->ptr=NULL;
	}else{
		temp=(n*)malloc(sizeof(n));
		temp->info=data;
		temp->ptr=top;
		top=temp;
	}
}

void display(){
	top1=top;
	if(top1==NULL){
		printf("\nList is empty...");
		getch();
		return;
	}else{
		while(top1!=NULL){
			printf("\nData: %d",top1->info);
			top1=top1->ptr;
		}
	}
	getch();
}