#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
/*printf("\n");*/
typedef struct student{
	int book_id;
	char book_name[50];
	char author_name[50];
	char publication[50];
	int edition;
	char issued_date[30];
	char isbn_no[30];
	struct student *next;
}s;

s *head;
int count_data=0;

void insert();
void display();

void main()
{
	int data,ch;
	//int gd=DETECT,gm;
	char dec;
	//initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	while(1){
		START:
		clrscr();
		textcolor(BROWN);
		cprintf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
		textcolor(WHITE);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
		printf("\n\t\t\t   ");
		cprintf("Library Management System");
		printf("\n\t\t\t   ");
		cprintf("--------------------------");
		printf("\n");
		textcolor(BROWN);
		printf("\n");
		cprintf("\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
		textcolor(14);
		printf("\n");
		cprintf("1.INSERT");
		printf("\n");
		cprintf("2.DISPLAY");
		printf("\n");
		cprintf("3.EXIT");
		printf("\n");
		printf("\n");
		cprintf("Enter your choice[1-3]: ");
		textcolor(15);
		scanf("%d",&ch);

		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				do{
					clrscr();
					textcolor(RED);
					printf("\n");
					cprintf("Are you want to close the app?[Y/N]: ");
					fflush(stdin);
					cscanf("%c",&dec);
					getch();
					textcolor(15);
					if(dec=='y'||dec=='Y'){
						exit(0);
					}else{
						goto START;
					}
				}while(dec=='n'||dec=='N');
			default:
				textcolor(12);
				printf("\n");
				cprintf("Sorry wrong choice. Please input between 1 to 3.");
				printf("\n");
				cprintf("Try again.");
				getch();
				textcolor(15);
		}
	}
}


void insert(){
	s *temp;
	char dec='y';
	while(dec=='y'||dec=='Y'){
		if(head==NULL){
			head=(s*)malloc(1*sizeof(s));
			textcolor(9);
			printf("\n");
			cprintf("Enter book id: ");
			scanf("%d",&head->book_id);
			printf("\n");
			cprintf("Enter book name: ");
			fflush(stdin);
			gets(head->book_name);
			printf("\n");
			cprintf("Enter author name: ");
			fflush(stdin);
			gets(head->author_name);
			printf("\n");
			cprintf("Enter publication name: ");
			fflush(stdin);
			gets(head->publication);
			printf("\n");
			cprintf("Enter edition: ");
			scanf("%d",&head->edition);
			printf("\n");
			cprintf("Enter date of issue: ");
			fflush(stdin);
			gets(head->issued_date);
			printf("\n");
			cprintf("Enter isbn no.: ");
			fflush(stdin);
			gets(head->isbn_no);

			head->next=NULL;
			count_data++;

			textcolor(15);
		}else{
			s *s1,*s2,*temp;
			s1=head->next;
			s2=head;
			while(s1!=NULL){
				s2=s1;
				s1=s1->next;
			}
			temp=(s*)malloc(1+sizeof(s));
			textcolor(9);
			printf("\n");
			cprintf("Enter book id: ");
			scanf("%d",&temp->book_id);
			printf("\n");
			cprintf("Enter book name: ");
			fflush(stdin);
			gets(temp->book_name);
			printf("\n");
			cprintf("Enter author name: ");
			fflush(stdin);
			gets(temp->author_name);
			printf("\n");
			cprintf("Enter publication name: ");
			fflush(stdin);
			gets(temp->publication);
			printf("\n");
			cprintf("Enter edition: ");
			scanf("%d",&temp->edition);
			printf("\n");
			cprintf("Enter date of issue: ");
			fflush(stdin);
			gets(temp->issued_date);
			printf("\n");
			cprintf("Enter isbn no.: ");
			fflush(stdin);
			gets(temp->isbn_no);
			temp->next=NULL;
			s2->next=temp;
			count_data++;
			textcolor(15);
		}
		printf("\nAre you want to continue inserting?[Y/N]: ");
		fflush(stdin);
		scanf("%c",&dec);
	}
}

void display(){
	s *temp;
	int i=1;
	temp=head;
	if(head==NULL){
		printf("\n\nSorry no data found...");
		getch();
		return;
	}
	while(temp!=NULL){
		textcolor(3);
		printf("\n");
		cprintf("Record %d",i);
		printf("\n---------\n");
		printf("\n");
		cprintf("ID: ");
		printf("%d",temp->book_id);
		printf("\n");
		cprintf("BOOK NAME: ");
		puts(temp->book_name);
		cprintf("AUTHOR NAME: ");
		puts(temp->author_name);
		cprintf("PUBLICATION : ");
		puts(temp->publication);
		cprintf("EDITION : ");
		printf("%d",temp->edition);
		printf("\n");
		cprintf("ISSUED DATE: ");
		puts(temp->issued_date);
		cprintf("ISBN NO. : ");
		puts(temp->isbn_no);
		printf("\n_____________________\n");
		i++;
		temp=temp->next;
		getch();
	}
	textcolor(2);
	printf("\n");
	cprintf("Number of data is : %d",count_data);
	getch();
	textcolor(15);
}