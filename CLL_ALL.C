#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *next;
}l;

/*printf("\n");*/
l *head=NULL,*x=NULL,*y=NULL,*z=NULL;
int no_of_element;
void insert();
void display();
void ins_at_pos();
void delt();
void search_by_element();
void search_by_pos();
void update();
void sort_asc();

void main()
{
	int ch;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\nCIRCULAR LINKED LIST");
		printf("\n********************");
		printf("\n\n1.Create");
		printf("\n2.Display");
		printf("\n3.Insert at position");
		printf("\n4.Delete");
		printf("\n5.Search by element");
		printf("\n6.Search by position");
		printf("\n7.Update");
		printf("\n8.Sort ascending");
		printf("\n9.Exit");
		printf("\n\nEnter your choice[1-9]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				ins_at_pos();
				break;
			case 4:
				delt();
				break;
			case 5:
				search_by_element();
				break;
			case 6:
				search_by_pos();
				break;
			case 7:
				update();
				break;
			case 8:
				sort_asc();
				break;
			case 9:
				clrscr();
				printf("\nAre you want to close the app? [Y/N]: ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					exit(0);
				}else{
					goto START;
				}
			default:
				printf("\nWrong choice");
				getch();
		}
	}
}

void insert(){
	char ch;
	char chh;
	if(head==NULL){
		x=(l*)malloc(1*sizeof(l));
		printf("\nEnter data: ");
		scanf("%d",&x->data);
		x->next=x;
		head=x;
		no_of_element++;
		printf("\nContinue?[Y/N]: ");
		fflush(stdin);
		scanf("%c",&ch);
		while(ch=='y'||ch=='Y'){
			y=(l*)malloc(1*sizeof(l));
			printf("\nEnter data: ");
			scanf("%d",&y->data);
			x->next=y;
			y->next=head;
			x=y;
			printf("\nContinue?[Y/N]: ");
			fflush(stdin);
			scanf("%c",&ch);
			no_of_element++;
		}
	}else{
		l *s1,*temp;
		z=head;
		s1=z->next;
		while(s1!=head){
			z=s1;
			s1=s1->next;
		}
		do{
			temp=(l*)malloc(1*sizeof(l));
			printf("\nEnter data: ");
			scanf("%d",&temp->data);
			temp->next=head;
			z->next=temp;
			z=temp;
			printf("\nContinue?[Y/N]: ");
			fflush(stdin);
			scanf("%c",&chh);
			no_of_element++;
		}while(chh=='y'||chh=='Y');
	}
}

void delt(){
	int pos,i;
	DELETE_START:
	y=head->next;
	z=head;
	printf("\nEnter position of element to delete: ");
	scanf("%d",&pos);
	if(pos>no_of_element){
		printf("\nSorry list has only %d element...");
		goto DELETE_START;
	}else if(pos==1){
		if(head->next==head){
			head=NULL;
			printf("\n\nFirst element deleted successfully. List become empty...");
			getch();
			no_of_element=0;
			return;
		}else{
			x=head->next;
			y=head;
			z=head->next;
			while(z!=head){
				y=z;
				z=z->next;
			}
			head=x;
			y->next=x;
			no_of_element--;
			printf("\nFirst element deleted.");
			getch();
			return;
		}
	}
	else{
		for(i=1;i<pos-1;i++){
			z=y;
			y=y->next;
		}
		z->next=y->next;
		no_of_element--;
		if(pos==2){
			printf("\n2nd element deleted.");
			getch();
			return;
		}else if(pos==3){
			printf("\n3rd element deleted.");
			getch();
			return;
		}else{
			printf("\n%dth element deleted.",pos);
			getch();
			return;
		}
	}
}

void ins_at_pos(){
	int pos,i;
	l *temp,*temp2;
	z=head;
	printf("\nEnter position: ");
	scanf("%d",&pos);
	if(pos>no_of_element){
		printf("\nSorry list has only %d element.",no_of_element);
		getch();
		return;
	}
	for(i=1;i<pos;i++){
		temp=z;
		z=z->next;
	}
	if(z==head){
		temp2=(l*)malloc(1*sizeof(l));
		printf("\nEnter data: ");
		scanf("%d",&temp2->data);
		temp2->next=head;
		temp->next=temp2;
		no_of_element++;
	}else{
		temp2=(l*)malloc(1*sizeof(l));
		printf("\nEnter data: ");
		scanf("%d",&temp2->data);
		temp2->next=z;
		temp->next=temp2;
		no_of_element++;
	}
}

void display(){
	x=head;
	if(head==NULL){
		printf("\nList is empty...");
		getch();
		return;
	}
	while(x->next!=head){
		printf("%d->",x->data);
		x=x->next;
	}
	printf("%d",x->data);
	printf("\n\nNumber of Element: %d",no_of_element);
	getch();
}

void search_by_element(){
	int data,i=0,counter=0,j;
	int arr2[100];
	int flag=0;
	y=head->next;
	z=head;
	printf("\nEnter element to search: ");
	scanf("%d",&data);
	while(y!=head){
		counter++;
		if(z->data==data){
			arr2[i]=counter;
			i++;
			flag=1;
		}else{
			goto NEXT;
		}
		NEXT:
		z=y;
		y=y->next;
	}
	counter++;
	if(z->data==data){
		arr2[i]=counter;
		flag=1;
		i++;
	}
	if(flag==0){
		printf("\nSorry no such data found in list.");
		getch();
		return;
	}else{
		printf("\nYour searched element found in:- \n");
		for(j=0;j<i;j++){
			printf("\nPosition: %d",arr2[j]);
		}
		getch();
	}
}


void search_by_pos(){
	int pos,i;
	printf("\nEnter the position to search element: ");
	scanf("%d",&pos);
	if(pos>no_of_element){
		printf("\nSorry list has only %d element.",no_of_element);
		getch();
		return;
	}
	x=head;
	y=head->next;
	for(i=1;i<pos;i++){
		x=y;
		y=y->next;
	}
	printf("\nData found in searched position: %d",x->data);
	getch();
	return;
}


void update(){
	int pos,i;
	printf("\nEnter the position to update element: ");
	scanf("%d",&pos);
	if(pos>no_of_element){
		printf("\nSorry list has only %d element.",no_of_element);
		getch();
		return;
	}
	x=head;
	y=head->next;
	for(i=1;i<pos;i++){
		x=y;
		y=y->next;
	}
	printf("\nData found in searched position: %d",x->data);
	printf("\nEnter data: ");
	scanf("%d",&x->data);
	printf("\nData updated successfully.");
	getch();
	return;
}


void sort_asc(){
	int i,j,temp;
	x=head;
	y=head->next;
	for(i=0;i<no_of_element;i++){
		for(j=i+1;j<no_of_element;j++){
			if(x->data>y->data){
				temp=x->data;
				x->data=y->data;
				y->data=temp;
			}
			x=y;
			y=y->next;
		}
	}
}