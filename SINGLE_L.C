#include<conio.h>
#include<alloc.h>
#include<stdio.h>

typedef struct list{
	int data;
	struct list *next;
}l;

l *insert(l *start,int d){
	l *s1,*s2,*n;
	if(start==NULL){
		start=(l *)malloc(1*sizeof(l));
		start->data=d;
		start->next=NULL;
		return(start);
	}else{
		s1=start->next;
		s2=start;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}
		n=(l *)malloc(1*sizeof(l));
		n->data=d;
		n->next=NULL;
		s2->next=n;
		return(start);
	}
}

void display(l *start){
	l *s1;
	if(start==NULL){
		printf("\nSorry no data found...");;
	}else{
		s1=start;
		while(s1!=NULL){
			printf("\nData: %d",s1->data);
			s1=s1->next;
		}
	}
	getch();
}

void delet(l *start,int p){
	int i;
	l *s1,*temp;
	if(p==1){
		s1=start;
		start=start->next;
		temp=start->next;
		s1->next=temp;
	}else{
		for(i=1;i<p;i++){
		s1=start;
		start=start->next;
		}
		temp=start->next;
		s1->next=temp;
	}
}


l *delt(l *start)
{
	int d;
	l *s1,*s2;
	if(start==NULL){
		printf("\nList is currently empty...");
	}else{
		printf("\nEnter data to delete: ");
		scanf("%d",&d);
		if(start->data==d && start->next==NULL){
			start=NULL;
			printf("\nData found at first position and deleted successfully, list becomes empty...");;
			getch();
			return(start);
		}
		if(start->data==d){
			start=start->next;
			printf("\nData found at first position and deleted successfully...");
			return(start);
		}else{
			s1=start->next;
			s2=start;
			while(s1!=NULL){
				if(s1->data==d){
					s2->next=s1->next;
					printf("\nData deleted successfully...");
					return(start);
				}
				s2=s1;
				s1=s1->next;
			}
			printf("\nSorry no such data found in the list...");
			getch();
			return(start);
		}
	}
}

void main()
{
	l *head;
	int ch,d,p;
	char dec,deci;
	head=NULL;
	do{
		clrscr();
		printf("\n Single linked list");
		printf("\n*******************");
		printf("\n\n1.Insert");
		printf("\n2.Display");
		printf("\n3.Delete");
		printf("\n4.Delete by data");
		printf("\n5.Exit");
		printf("\n\nEnter your choice[1-5]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter element to insert: ");
					scanf("%d",&d);
					head=insert(head,d);
					printf("\nAre you continue inserting?[Y/N]: ");
					fflush(stdin);
					scanf("%c",&deci);
				}while(deci=='Y'||deci=='y');
				break;
			case 2:
				display(head);
				break;
			case 3:
				printf("\nEnter element to delete: ");
				scanf("%d",&p);
				delet(head,p);
				break;
			case 4:
				head=delt(head);
				break;
			case 5:
				exit(0);
			default:
				printf("\n\nPlease input a valid option...");
				break;
		}
		printf("\nAre you want to close ? [Y/N]: ");
		fflush(stdin);
		scanf("%c",&dec);
	}while(dec=='n'||dec=='N');
}