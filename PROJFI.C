#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct list{
	int id;
	char name[30];
	char g_name[30];
	int age;
	char standard[10];
	char tel[10];
	char address[30];
	struct list *prev;
	struct list *next;
}l;

l *head;
int c_data=0;
int ID=600;

void insert();
void insert_pos();
void display_all();
void search();
void update();
void delet();
void exit_function();
void take_input(l *s1);
void display(l *s1);

void main()
{
	int dec;
	char ch;
	START:
	clrscr();
	textcolor(9);
	printf("\t\t\t");
	cprintf("School Management System");
	printf("\n\t\t\t");
	cprintf("*************************");
	printf("\n\t");
	cprintf("1.Insert");
	printf("\t\t\t\t\t");
	cprintf("2.Insert At");
	printf("\n\t");
	cprintf("3.Display All");
	printf("\t\t\t\t\t");
	cprintf("4.Search");
	printf("\n\t");
	cprintf("5.Update");
	printf("\t\t\t\t\t");
	cprintf("6.Delete");
	printf("\n\t\t\t\t");
	cprintf("7.Exit");
	printf("\n\n\t\t     ");
	cprintf("Enter your choice[1-7]: [ ]\b\b");
	scanf("%d",&dec);

	switch(dec){
		case 1:
			insert();
			goto START;
		case 2:
			insert_pos();
			goto START;
		case 3:
			display_all();
			goto START;
		case 4:
			search();
			goto START;
		case 5:
			update();
			goto START;
		case 6:
			delet();
			goto START;
		case 7:
			exit_function();
			goto START;
		default:
			printf("\n\n\t\t    ");
			cprintf("Sorry, please enter valid input.");
			getch();
			goto START;
	}
}

void insert(){
	char ch;
	clrscr();
	textcolor(2);
	do{
		if(head==NULL){
			head=(l*)malloc(sizeof(l));
			head->id=ID++;
			take_input(head);
			head->prev=NULL;
			head->next=NULL;
			printf("\n");
			cprintf("Continue insert(y/n)? : [ ]\b\b");
			fflush(stdin);
			scanf("%c",&ch);
		}else{
			l *s1,*s2,*s3,*s4;
			s1=head->next;
			s2=head;
			while(s1!=NULL){
				s2=s1;
				s1=s1->next;
			}
			s4=(l*)malloc(sizeof(l));
			s4->id=ID++;
			take_input(s4);
			s2->next=s4;
			s4->next=NULL;
			s4->prev=s2;
			printf("\n");
			cprintf("Continue insert(y/n)? : [ ]\b\b");
			fflush(stdin);
			scanf("%c",&ch);
		}
	}while(ch=='y'||ch=='Y');
	printf("\n\n");
	cprintf("Number of data: %d",c_data);
	getch();
}
void insert_pos(){
	l *s1,*s2,*s3,*s4;
	int pos,i;
	clrscr();
	textcolor(10);
	cprintf("Enter position to insert: [  ]\b\b\b");
	scanf("%d",&pos);
	if(pos==1){
		s1=(l*)malloc(sizeof(l));
		s1->id=ID++;
		take_input(s1);
		s1->next=head;
		s1->prev=NULL;
		head->prev=s1;
		head=s1;
	}else if(pos==c_data+1){
		s1=head->next;
		s2=head;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}
		s3=(l*)malloc(sizeof(l));
		s3->id=ID++;
		take_input(s3);
		s3->next=NULL;
		s3->prev=s2;
		s2->next=s3;
	}else{
		s1=head->next;
		s2=head;
		for(i=1;i<pos;i++){
			s3=s2;
			s2=s1;
			s1=s1->next;
		}
		s4=(l*)malloc(sizeof(l));
		s4->id=ID++;
		take_input(s4);
		s4->next=s2;
		s4->prev=s3;
		s3->next=s4;
		s2->prev=s4;
	}
	printf("\n");
	cprintf("Record inserted successfully");
	getch();
}
void display_all(){
	l *s1;
	clrscr();
	textcolor(10);
	s1=head;
	while(s1!=NULL){
		display(s1);
		s1=s1->next;
	}
	getch();
}
void search(){
	int idno,i,flag=0;
	l *s1,*s2;
	clrscr();
	textcolor(10);
	cprintf("Enter id to search: [   ]\b\b\b\b");
	scanf("%d",&idno);
	if(c_data<1||idno<600){
		printf("\n\n\t\t   ");
		cprintf("Sorry no data found");
	}else{
		s1=head;
		for(i=1;i<=c_data;i++){
			if(s1->id==idno){
				flag=1;
				break;
			}
			s1=s1->next;
		}
		if(flag==1){
			display(s1);
		}else{
			cprintf("Sorry no data found with this id");
		}
	}
	getch();
}
void update(){
	int idno,i,flag=0;
	char ch;
	l *s1,*s2,*s3,*s4;
	clrscr();
	textcolor(14);
	cprintf("Enter id to modify: [   ]\b\b\b\b");
	scanf("%d",&idno);
	if(c_data<1||idno<600){
		printf("\n\n\t\t   ");
		cprintf("Sorry no data found");
	}else{
		s2=head;
		s1=head->next;
		s3=NULL;
		for(i=1;i<=c_data;i++){
			if(s2->id==idno){
				flag=1;
				break;
			}
			s3=s2;
			s2=s1;
			s1=s1->next;
		}
		if(flag==1){
			display(s2);
			printf("\n\n");
			cprintf("Are you want to update data(y/n)? : [ ]\b\b");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y'){
				if(s3==NULL){
					s4=(l*)malloc(sizeof(l));
					s4->id=s2->id;
					take_input(s4);
					s4->next=s1;
					s4->prev=NULL;
					s1->prev=s4;
					head=s4;
				}else{
					s4=(l*)malloc(sizeof(l));
					s4->id=s2->id;
					take_input(s4);
					s4->next=s1;
					s4->prev=s3;
					s3->next=s4;
					s1->prev=s4;
				}
			}else{
				return;
			}
		}else{
			cprintf("Sorry no data found with this id");
		}
	}
	printf("\n\n");
	cprintf("Record updated successfully");
	getch();
}
void delet(){
	int idno,i,flag=0;
	char ch;
	l *s1,*s2,*s3,*s4;
	clrscr();
	textcolor(14);
	cprintf("Enter id to delte: [   ]\b\b\b\b");
	scanf("%d",&idno);
	if(c_data<1||idno<600){
		printf("\n\n\t\t   ");
		cprintf("Sorry no data found");
	}else{
		s2=head;
		s1=head->next;
		s3=NULL;
		for(i=1;i<=c_data;i++){
			if(s2->id==idno){
				flag=1;
				break;
			}
			s3=s2;
			s2=s1;
			s1=s1->next;
		}
		if(flag==1){
			display(s2);
			printf("\n\n");
			cprintf("Are you want to delete this record(y/n)? : [ ]\b\b");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y'){
				if(s3==NULL){
					head=s2->next;
					head->prev=NULL;
				}else{
					s3->next=s2->next;
					s1->prev=s2->prev;
				}
				c_data--;
			}else{
				return;
			}
		}else{
			cprintf("Sorry no data found with this id");
		}
	}
	printf("\n\n");
	cprintf("Record deleted successfully");
	getch();
}
void exit_function(){
	char ch;
	clrscr();
	textcolor(4);
	printf("\n\n\n\n\n\t\t");
	cprintf("Are you want to close the program(y/n)? : [ ]\b\b");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y'){
		exit(0);
	}
}
void take_input(l *s1){
	textcolor(3);
	//s1->id=ID++;
	printf("\n");
	cprintf("Enter name: _____________\b\b\b\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->name);
	cprintf("Enter guardian name: _____________\b\b\b\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->g_name);
	cprintf("Enter age: ___\b\b\b");
	scanf("%d",&s1->age);
	cprintf("Enter standard: ___\b\b\b");
	fflush(stdin);
	gets(s1->standard);
	cprintf("Enter telephone no.: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->tel);
	cprintf("Enter address: _____________\b\b\b\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->address);
	c_data++;
}
void display(l *s1){
	printf("\n\t\t\t\t");
	cprintf("ID: %d",s1->id);
	printf("\n\t");
	cprintf("Name: ");
	cprintf("%s",s1->name);
	printf("\t\t\t\t\t");
	cprintf("Guardian name: ");
	cprintf("%s",s1->g_name);
	printf("\n\t");
	cprintf("Age: %d",s1->age);
	printf("\t\t\t\t\t");
	cprintf("Standard: ");
	cprintf("%s",s1->standard);
	printf("\n\t");
	cprintf("Telephone: ");
	cprintf("%s",s1->tel);
	printf("\t\t\t\t");
	cprintf("Address: ");
	cprintf("%s",s1->address);
	printf("\n\t\t    ");
	cprintf("************************************");
}