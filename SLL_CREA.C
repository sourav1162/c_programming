#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *link;
}l;

int counter;
l *head;

void insert(int data);
void display();

void main()
{
	int ch;
	char ex;
	char dec;
	int data;
	while(1){
	START:
		clrscr();
		printf("\t\t\tSingle linked list creation");
		printf("\n1.Create list");
		printf("\n2.Display list");
		printf("\n3.Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter data: ");
					scanf("%d",&data);
					insert(data);
					printf("\nContinue insert? ");
					fflush(stdin);
					scanf("%c",&dec);
				}while(dec=='y'||dec=='Y');
				break;
			case 2:
				display();
				break;
			case 3:
				do{
					clrscr();
					printf("\nAre you want to close the application? ");
					fflush(stdin);
					scanf("%c",&ex);
					if(ex=='y'||ex=='Y'){
						exit(0);
					}else{
						goto START;
					}
				}while(ex=='n'||ex=='N');
			default:
				printf("\nSorry wrong input, please input between 1-3.");
		}
	}
}

void insert(int data){
	char dec;
	if(head==NULL){
		head=(l*)malloc(1*sizeof(l));
		head->data=data;
		head->link=NULL;
	}else{
		l *s1,*s2,*temp;
		s1=head->link;
		s2=head;
		while(s1!=NULL){
			s2=s1;
			s1=s1->link;
		}
		temp=(l*)malloc(1*sizeof(l));
		temp->data=data;
		temp->link=NULL;
		s2->link=temp;
	}
	counter++;
}

void display(){
	l *s2;
	int i=1;
	if(head==NULL){
		printf("\nSorry list is empty. First create the list then try to display");
		return;
	}else{
		s2=head;
		while(s2!=NULL){
			printf("\nData%d: %d",i,s2->data);
			s2=s2->link;
			getch();
		}
		printf("\nTotal number of data is: %d",counter);
		getch();
		return;
	}
}