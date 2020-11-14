#include<stdio.h>
#include<conio.h>

typedef struct list{
	int data;
	struct list *next;
}l;

l *head;

void insert(int data);
void display();

void main()
{
	int ch,data;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\n1.INSERT");
		printf("\n2.DISPLAY");
		printf("\nEXIT");
		printf("\n\nEnter choice: [Y/N]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter data: ");
					scanf("%d",&data);
					insert(data);
					printf("\nContinue?[Y/N]: ");
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
					printf("\nWant to close? [Y/N]: ");
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

void insert(int data){
	if(head==NULL){
		head=(l*)malloc(sizeof(l));
		head->data=data;
		head->next=NULL;
	}else{
		l *s1,*s2,*temp;
		s1=head->next;
		s2=head;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}
		temp=(l*)malloc(sizeof(l));
		temp->data=data;
		temp->next=NULL;
		s2->next=temp;
	}
}

void display(){
	l *s1;
	s1=head;
	if(s1==NULL){
		printf("\nList is empty...");
		getch();
		return;
	}else{
		while(s1!=NULL){
			printf("\nData: %d",s1->data);
			s1=s1->next;
		}
	}
	getch();
}