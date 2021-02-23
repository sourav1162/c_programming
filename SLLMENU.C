#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<alloc.h>
#include<graphics.h>

typedef struct list{
	int book_id;
	char book_name[30];
	char auth_name[30];
	char publication[30];
	int edition;
	char date_issue[20];
	char isbn_no[15];
	struct list *next;
}l;

void insert();
void display_all();
void insert_first();
void insert_last();
void search();
void delet();
void delet_first();
void delet_last();
void modify();
void insert_position();
void take_input(l *pointer);
void display(l *s1);
void exitfun();

l *head;
int c_data=0;

//printf("");

void main()
{
	int dec;
	char ch;
	START:
	clrscr();
	textcolor(3);
	printf("\t\t\t");
	cprintf("Library Management System");
	printf("\n\t\t\t");
	cprintf("**************************");
	printf("\n\t");
	cprintf("1.Insert");
	printf("\t\t\t\t\t");
	cprintf("2.Display All");
	printf("\n\t");
	cprintf("3.Insert First");
	printf("\t\t\t\t\t");
	cprintf("4.Insert Last");
	printf("\n\t");
	cprintf("5.Search");
	printf("\t\t\t\t\t");
	cprintf("6.Delete");
	printf("\n\t");
	cprintf("7.Delete First");
	printf("\t\t\t\t\t");
	cprintf("8.Delete Last");
	printf("\n\t");
	cprintf("9.Modify");
	printf("\t\t\t\t\t");
	cprintf("10.Insert Specific");
	printf("\n\t\t\t\t");
	cprintf("11.Exit");
	printf("\n\n\t\t\t   ");
	cprintf("Number of data: %d",c_data);
	printf("\n\n\t\t\t   ");
	cprintf("Enter choice: [  ]\b\b\b");
	scanf("%d",&dec);
	switch(dec){
		case 1:
			insert();
			goto START;
		case 2:
			display_all();
			goto START;
		case 3:
			insert_first();
			goto START;
		case 4:
			insert_last();
			goto START;
		case 5:
			search();
			goto START;
		case 6:
			delet();
			goto START;
		case 7:
			delet_first();
			goto START;
		case 8:
			delet_last();
			goto START;
		case 9:
			modify();
			goto START;
		case 10:
			insert_position();
			goto START;
		case 11:
			exitfun();
			goto START;
		default:
			printf("\n\t\t\t   ");
			cprintf("Enter valid data...");
			getch();
			goto START;
	}
}

void exitfun(){
	char ch;
	clrscr();
	textcolor(RED);
	cprintf("Are you want to exit?(y/n): [ ]\b\b");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y'){
		exit(0);
	}else{
		return;
	}
}

void take_input(l *s1){
	textcolor(6);
	printf("\n");
	cprintf("Enter book id: ___\b\b\b");
	scanf("%d",&s1->book_id);

	cprintf("Enter book name: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->book_name);

	cprintf("Enter author name: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->auth_name);

	cprintf("Enter publication: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->publication);

	cprintf("Enter edition: ___\b\b\b");
	scanf("%d",&s1->edition);

	cprintf("Enter date of issue: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->date_issue);

	cprintf("Enter isbn no.: __________\b\b\b\b\b\b\b\b\b\b");
	fflush(stdin);
	gets(s1->isbn_no);
}

void insert(){
	char ch;
	clrscr();
	do{
		if(head==NULL){
			head=(l*)malloc(sizeof(l));
			take_input(head);
			head->next=NULL;
			c_data++;
			printf("continue?(y/n): ");
			fflush(stdin);
			scanf("%c",&ch);
		}else{
			l *s1,*s2,*s3;
			s1=head->next;
			s2=head;
			while(s1!=NULL){
				s2=s1;
				s1=s1->next;
			}
			s3=(l*)malloc(sizeof(l));
			take_input(s3);
			s3->next=NULL;
			s2->next=s3;
			c_data++;
			printf("continue?(y/n): ");
			fflush(stdin);
			scanf("%c",&ch);
		}
	}while(ch=='y'||ch=='Y');
	printf("\n\nNumber of data: %d",c_data);
	getch();
}

void insert_first(){
	l *s1;
	clrscr();
	if(head==NULL){
		textcolor(5);
		cprintf("Sorry, first insert some data to use this features.");
		getch();
		return;
	}else{
		s1=(l*)malloc(sizeof(l));
		take_input(s1);
		s1->next=head;
		head=s1;
		c_data++;
		printf("\n\nNumber of data: %d",c_data);
		getch();
	}
}

void insert_last(){
	l *s1,*s2,*s3;
	clrscr();
	if(head==NULL){
		textcolor(5);
		cprintf("Sorry, first insert some data to use this features.");
		getch();
		return;
	}else{
		s1=head->next;
		s2=head;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}

		s3=(l*)malloc(sizeof(l));
		take_input(s3);
		s3->next=NULL;
		s2->next=s3;
		c_data++;
		printf("\n\nNumber of data: %d",c_data);
		getch();
	}
}

void display_all(){
	l *s1;
	clrscr();
	textcolor(5);
	if(head==NULL){
		printf("Sorry no data found");
		getch();
		return;
	}
	s1=head;
	while(s1!=NULL){
		display(s1);
		s1=s1->next;
	}
	printf("\n\n\t\t\t    This is the last data");
	getch();
}

void display(l *s1){
	if(head==NULL){
		printf("Sorry no data found");
		getch();
		return;
	}
	printf("\n\t\t\t\t");
	cprintf("Book ID: %d",s1->book_id);
	printf("\n\t");
	cprintf("Book Name: %s",s1->book_name);
	printf("\t\t\t\t\t");
	cprintf("Author Name: %s",s1->auth_name);
	printf("\n\t");
	cprintf("Publication: %s",s1->publication);
	printf("\t\t\t\t");
	cprintf("Edition: %d",s1->edition);
	printf("\n\t");
	cprintf("Date Issue: %s",s1->date_issue);
	printf("\t\t\t\t");
	cprintf("ISBN no.: %s",s1->isbn_no);
	printf("\n\t\t");
	cprintf("***********************************************");
	getch();
}

void search(){
	char name[30],ch;
	int flag=0,s_id=0;
	l *s1;
	SEARCH:
	clrscr();
	textcolor(9);
	cprintf("Search by name or id [n/i] ? : [ ]\b\b");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='n'||ch=='N'){
		s1=head;
		clrscr();
		cprintf("Enter name to search: ");
		fflush(stdin);
		gets(name);
		while(s1!=NULL){
			if(strcmp(s1->book_name,name)==0){
				flag=1;
				break;
			}else{
				s1=s1->next;
			}
		}
		if(flag==1){
	 //		printf("Name: ");
	 //		puts(s1->name);
	 //		printf("Roll: %d\n",s1->roll);
	 //		printf("Marks: %d\n\n",s1->marks);
			display(s1);
		}else{
			cprintf("Sorry, no such data found...");
		}
		getch();
	}else if(ch=='i'||ch=='I'){
		s1=head;
		clrscr();
		cprintf("Enter id to search: ");
		scanf("%d",&s_id);
		while(s1!=NULL){
			if(s1->book_id==s_id){
				flag=1;
				break;
			}else{
				s1=s1->next;
			}
		}
		if(flag==1){
	 //		printf("Name: ");
	 //		puts(s1->name);
	 //		printf("Roll: %d\n",s1->roll);
	 //		printf("Marks: %d\n\n",s1->marks);
			display(s1);
		}else{
			cprintf("Sorry, no such data found...");
		}
		getch();
	}else{
		cprintf("Sorry invalid input");
		getch();
		goto SEARCH;
	}
}

void delet(){
	char del_name[30],ch,dec;
	int flag=0,sd_id=0;
	l *s1,*s2;
	DELETE:
	clrscr();
	textcolor(14);
	cprintf("Search data to delete by name or id [n/i] ? : [ ]\b\b");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='n'||ch=='Y'){
		clrscr();
		cprintf("Enter name to search: ");
		fflush(stdin);
		gets(del_name);
		s1=head;
		s2=head;
		while(s1!=NULL){
			if(strcmp(s1->book_name,del_name)==0){
				display(s1);
				textcolor(14);
				printf("\n");
				cprintf("Are you want to delete the record(y/n)?: [ ]\b\b");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					flag=1;
					c_data--;
					if(s1==head){
						head=s1->next;
						break;
					}else{
						s2->next=s1->next;
						break;
					}
				}else{
					return;
				}
			}else{
				s2=s1;
				s1=s1->next;
			}
		}
	}else if(ch=='i'||ch=='I'){
		clrscr();
		printf("Enter id to search: ");
		scanf("%d",&sd_id);
		s1=head;
		s2=head;
		while(s1!=NULL){
			if(s1->book_id==sd_id){
				display(s1);
				printf("\n");
				textcolor(14);
				cprintf("Are you want to delete the record(y/n)?: [ ]\b\b");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					flag=1;
					c_data--;
					if(s1==head){
						head=s1->next;
						break;
					}else{
						s2->next=s1->next;
						break;
					}
				}else{
					return;
				}
			}else{
				s2=s1;
				s1=s1->next;
			}
		}
	}else{
		cprintf("Sorry invalid input");
		getch();
		goto DELETE;
	}
	if(flag==1){
		cprintf("Record deleted successfully...");
	}else{
		cprintf("Sorry, no such data found...");
	}
	getch();
}

void delet_first(){
	char ch;
	clrscr();
	textcolor(14);
	if(head==NULL){
		cprintf("Soory no data found.");
		getch();
		return;
	}else{
		cprintf("Are you want to delete the first record[y/n]?: [ ]\b\b");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y'){
			head=head->next;
			c_data--;
			cprintf("First record deleted.");
			getch();
			return;
		}else{
			return;
		}
	}
}

void delet_last(){
	l *s1,*s2,*s3;
	char ch;
	clrscr();
	textcolor(14);
	if(head==NULL){
		cprintf("Sorry please input some to use this features.");
		getch();
		return;
	}else{
		cprintf("Are you want to delete the last record[y/n]?: [ ]\b\b");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y'){
			s1=head->next;
			s2=head;
			while(s1!=NULL){
				s3=s2;
				s2=s1;
				s1=s1->next;
			}
			s3->next=NULL;
			c_data--;
			cprintf("Last record deleted.");
			getch();
			return;
		}else{
			return;
		}
	}
}

void modify(){
	char name[30],ch,dec;
	int flag=0,sm_id;
	l *s1,*s2;
	UPDATE:
	clrscr();
	textcolor(10);
	cprintf("Search data to modify by name or id[n/i]? : [ ]\b\b");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='n'||ch=='N'){
		clrscr();
		cprintf("Enter name to modify: ");
		fflush(stdin);
		gets(name);
		s1=head;
		while(s1!=NULL){
			if(strcmp(s1->book_name,name)==0){
				display(s1);
				textcolor(10);
				printf("\n");
				cprintf("Are you want to modify[y/n]?: [ ]\b\b");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					flag=1;
					take_input(s1);
					break;
				}
			}else{
				s1=s1->next;
			}
		}
	}else if(ch=='i'||ch=='I'){
		clrscr();
		cprintf("Enter id to modify: ");
		scanf("%d",&sm_id);
		s1=head;
		while(s1!=NULL){
			if(s1->book_id==sm_id){
				display(s1);
				textcolor(10);
				printf("\n");
				cprintf("\nAre you want to modify[y/n]?: [ ]\b\b");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					flag=1;
					take_input(s1);
					break;
				}
			}else{
				s1=s1->next;
			}
		}
	}else{
		cprintf("Sorry invalid input");
		getch();
		goto UPDATE;
	}

	if(flag==1){
		printf("\n");
		cprintf("Record modified...");
	}else{
		printf("\n");
		cprintf("Sorry no such data found...");
	}
	getch();
}

void insert_position(){
	int ch,i;
	l *s1,*s2,*s3;
	clrscr();
	textcolor(6);
	cprintf("Enter data number where you want to insert: [  ]\b\b\b");
	scanf("%d",&ch);
	s1=head;
	if(ch==1){
		s3=(l*)malloc(sizeof(l));
		take_input(s3);
		s3->next=head;
		head=s3;
		c_data++;
		textcolor(6);
		cprintf("Inserted at position %d",ch);
		getch();
	}else{
		for(i=1;i<ch;i++){
			s2=s1;
			s1=s1->next;
		}
		s3=(l*)malloc(sizeof(l));
		take_input(s3);
		s3->next=s1;
		s2->next=s3;
		c_data++;
		textcolor(6);
		printf("Inserted at position %d",ch);
		getch();
	}
}