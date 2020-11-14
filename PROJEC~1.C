#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book{
	int book_id;
	char book_name[50];
	char author_name[50];
	char publication[50];
	int edition;
	char issued_date[30];
	char isbn_no[20];
	struct book *next;
}b;

b *head;
int count_data;

void insert();
void display();
void take_input();
void data_dis();
void search();
void search_by_rec_no();
void search_by_id();
void search_by_name();
void delt();
void search_by_name_dlt();
void search_by_id_dlt();
void search_by_rec_no_dlt();
void modify();
void search_by_name_mod();
void search_by_id_mod();
void search_by_rec_no_mod();
void insert_at();

void main()
{
	int ch;
	char dec;
	while(1){
		START:
		clrscr();
		textcolor(13);
		cprintf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
		textcolor(RED);
		printf("\n\n");
		printf("\t\t     ");
		cprintf("Library Management System");
		printf("\n\t\t    ");
		cprintf("***************************");
		printf("\n\n");
		textcolor(13);
		cprintf("\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
		textcolor(15);
		printf("\n\n");
		cprintf("1.INSERT");
		printf("\n");
		cprintf("2.INSERT AT SPECIFIC POSITION");
		printf("\n");
		cprintf("3.DISPLAY ALL");
		printf("\n");
		cprintf("4.SEARCH");
		printf("\n");
		cprintf("5.DELETE");
		printf("\n");
		cprintf("6.MODIFY");
		printf("\n");
		cprintf("7.EXIT");
		printf("\n\n");
		cprintf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				insert_at();
				break;
			case 3:
				display();
				break;
			case 4:
				search();
				break;
			case 5:
				delt();
				break;
			case 6:
				modify();
				break;
			case 7:
				do{
					clrscr();
					textcolor(4);
					cprintf("are u want to close the app?[y/n] : ");
					fflush(stdin);
					scanf("%c",&dec);
					if(dec=='Y'||dec=='y'){
						exit(0);
					}else{
						goto START;
					}
				}while(dec=='y'||dec=='Y');
				break;
			default:
				printf("\nplease choose valid option...");
				getch();
		}
	}
}

void insert_at(){
	int i,ch;
	b *s1,*s2,*s3,*temp;
	textcolor(6);
	printf("\nEnter the position to insert: ");
	scanf("%d",&ch);
	if(ch>=count_data+2){
		printf("\n");
		cprintf("Sorry number of data is: ");
		printf("%d",ch);
		getch();
		textcolor(15);
		return;
	}else if(ch==count_data+1){
		s1=head->next;
		s2=head;
		while(s1!=NULL){
			s2=s1;
			s1=s1->next;
		}
		temp=(b*)malloc(1*sizeof(b));
		take_input(temp);
		temp->next=NULL;
		s2->next=temp;
		textcolor(6);
		printf("\n");
		cprintf("Record inserted at the last position successfully...");
		getch();
		textcolor(15);
		return;
	}else if(ch==1){
		if(head==NULL){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			temp->next=NULL;
			textcolor(6);
			printf("\n");
			count_data++;
			cprintf("Record inserted at the first position successfully. List has only one record.");
			getch();
			textcolor(15);
			return;
		}else{
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			temp->next=head;
			head=temp;
			textcolor(6);
			printf("\n");
			count_data++;
			cprintf("Record inserted at the first position successfully...");
			getch();
			textcolor(15);
			return;
		}
	}else{
		s1=head;
		s2=NULL;
		for(i=i;i<ch;i++){
			s2=s1;
			s1=s1->next;
		}
		temp=(b*)malloc(1*sizeof(b));
		take_input(temp);
		temp->next=s1;
		s2->next=temp;
		textcolor(6);
		printf("\n");
		count_data++;
		cprintf("Record inserted successfully...");
		getch();
		textcolor(15);
		return;
	}
}

void modify(){
	int ch;
	char dec='n';

	if(head==NULL){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	while(dec=='n'||dec=='N'){
		textcolor(14);
		printf("\n");
		cprintf("Search the record to modify");
		textcolor(9);
		printf("\n\n");
		cprintf("1.Search by name");
		printf("\n");
		cprintf("2.Search by id");
		printf("\n");
		cprintf("3.Search by record no.");
		printf("\n\n");
		cprintf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				search_by_name_mod();
				break;
			case 2:
				search_by_id_mod();
				break;
			case 3:
				search_by_rec_no_mod();
				break;
		}
		textcolor(9);
		printf("\n\n");
		cprintf("Are u want to close search: ");
		fflush(stdin);
		scanf("%c",&dec);
	}
	textcolor(15);
}

void search_by_name_mod(){
	int flg=0,res,result;
	char getname[50],dec;
	b *s1,*s2,*temp;;
	printf("\n\n");
	cprintf("Enter the book name: ");
	fflush(stdin);
	gets(getname);
	s1=head->next;
	s2=head;
	res=strcmp(s2->book_name,getname);
	if(res==0 && s2->next==NULL){
		data_dis(s2);
		textcolor(14);
		printf("\n\n");
		cprintf("Are you want to update the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			head=temp;
			temp->next=NULL;
			printf("\n");
			cprintf("First record updated. list has only one record.");
			flg=1;
			getch();
			return;
		}else{
			return;
		}
	}else if(res==0 && s2->next!=NULL){
		data_dis(s2);
		textcolor(14);
		printf("\n\n");
		cprintf("Are you want to update the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			head=temp;
			temp->next=s2->next;
			printf("\n");
			cprintf("First record updated.");
			flg=1;
			getch();
			return;
		}else{
			return;
		}
	}else{
		while(s1!=NULL){
			result=strcmp(s1->book_name,getname);
			if(result==0 && s1->next==NULL){
				data_dis(s1);
				textcolor(14);
				printf("\n\n");
				cprintf("Are you want to update the record? : ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					temp=(b*)malloc(1*sizeof(b));
					take_input(temp);
					s2->next=temp;
					temp->next=NULL;
					printf("\n");
					cprintf("Last record updated.");
					flg=1;
					getch();
					return;
				}else{
					return;
				}
			}else if(result==0 && s1->next!=NULL){
				data_dis(s1);
				textcolor(14);
				printf("\n\n");
				cprintf("Are you want to update the record? : ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					temp=(b*)malloc(1*sizeof(b));
					take_input(temp);
					s2->next=temp;
					temp->next=s1->next;
					printf("\n");
					cprintf("Last record updated.");
					flg=1;
					getch();
					return;
				}else{
					return;
				}
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		printf("\n");
		cprintf("Sorry no record found.");
		getch();
	}
	textcolor(15);
}

void search_by_id_mod(){
	int flg=0,getid;
	b *s1,*s2,*temp;
	char dec;
	printf("\n\n");
	cprintf("Enter the book id: ");
	scanf("%d",&getid);
	s1=head->next;
	s2=head;
	if(s2->book_id==getid && s2->next==NULL){
		data_dis(s2);
		textcolor(14);
		printf("\n\n");
		cprintf("Are you want to update the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			head=temp;
			temp->next=NULL;
			printf("\n");
			cprintf("First record updated. list has only one record.");
			flg=1;
			getch();
			return;
		}else{
			return;
		}
	}else if(s2->book_id==getid && s2->next!=NULL){
		data_dis(s2);
		textcolor(14);
		printf("\n\n");
		cprintf("Are you want to update the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			head=temp;
			temp->next=s2->next;
			printf("\n");
			cprintf("First record updated.");
			flg=1;
			getch();
			return;
		}else{
			return;
		}
	}else{
		while(s1!=NULL){
			if(s1->book_id==getid && s1->next==NULL){
				data_dis(s1);
				textcolor(14);
				printf("\n\n");
				cprintf("Are you want to update the record? : ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					temp=(b*)malloc(1*sizeof(b));
					take_input(temp);
					s2->next=temp;
					temp->next=NULL;
					printf("\n");
					cprintf("Last record updated.");
					flg=1;
					getch();
					return;
				}else{
					return;
				}
			}else if(s1->book_id==getid && s1->next!=NULL){
				data_dis(s1);
				textcolor(14);
				printf("\n\n");
				cprintf("Are you want to update the record? : ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					temp=(b*)malloc(1*sizeof(b));
					take_input(temp);
					s2->next=temp;
					temp->next=s1->next;
					printf("\n");
					cprintf("Last record updated.");
					flg=1;
					getch();
					return;
				}else{
					return;
				}
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		printf("\n");
		cprintf("Sorry no data found.");
		getch();
	}
	textcolor(15);
}

void search_by_rec_no_mod(){
	int i,ch,flg=1;
	char deci;
	b *s1,*s2,*s3,*temp;
	s1=head->next;
	s2=head;
	s3=s2;
	textcolor(9);
	printf("\n");
	cprintf("Enter record no. : ");
	scanf("%d",&ch);
	if(ch>count_data){
		flg=0;
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	if(ch==1){

		if(s2->next==NULL){

			data_dis(s2);
			textcolor(14);
			printf("\n");
			cprintf("Are you want to update? : ");
			fflush(stdin);
			scanf("%c",&deci);

			if(deci=='y'||deci=='Y'){

				temp=(b*)malloc(1*sizeof(b));
				take_input(temp);
				head=temp;
				temp->next=NULL;
				printf("\n");
				cprintf("First record updated. list has only one record");
				getch();
			}else{
				return;
			}
		}else if(s2->next!=NULL){
			data_dis(s2);
			textcolor(14);
			printf("\n");
			cprintf("Are you want to update? : ");
			fflush(stdin);
			scanf("%c",&deci);
			if(deci=='y'||deci=='Y'){
				temp=(b*)malloc(1*sizeof(b));
				take_input(temp);
				head=temp;
				temp->next=s2->next;
				printf("\n");
				cprintf("First record updated.");
				getch();
			}
		}
	}else{
		for(i=1;i<ch;i++){
			s3=s2;
			s2=s1;
			s1=s1->next;
		}
		data_dis(s2);
		textcolor(14);
		printf("\n");
		cprintf("Are you want to update? : ");
		fflush(stdin);
		scanf("%c",&deci);
		if(deci=='y'||deci=='Y'){
			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			temp->next=s2->next;
			s3->next=temp;
			printf("\n");
			cprintf("Record updated successfully");
			getch();
			return;
		}else{
			return;
		}
	}
	textcolor(15);
}

void delt(){
	int ch;
	char dec='n';

	if(head==NULL){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	while(dec=='n'||dec=='N'){
		textcolor(RED);
		printf("\n");
		cprintf("Search the record to delete");
		textcolor(9);
		printf("\n\n");
		cprintf("1.Search by name");
		printf("\n");
		cprintf("2.Search by id");
		printf("\n");
		cprintf("3.Search by record no.");
		printf("\n\n");
		cprintf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				search_by_name_dlt();
				break;
			case 2:
				search_by_id_dlt();
				break;
			case 3:
				search_by_rec_no_dlt();
				break;
		}
		textcolor(9);
		printf("\n\n");
		cprintf("Are u want to close search: ");
		fflush(stdin);
		scanf("%c",&dec);
	}
	textcolor(15);
}

void search_by_id_dlt(){
	int flg=0,getid;
	b *s1,*s2;
	char dec;
	textcolor(9);
	printf("\n\n");
	cprintf("Enter the book id: ");
	scanf("%d",&getid);
	s1=head->next;
	s2=head;
	if(s2->book_id==getid && s2->next==NULL){
		data_dis(s2);
		textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
		head=NULL;
		printf("\n");
		cprintf("First record deleted. list becomes empty");
		count_data--;
		flg=1;
		getch();
		return;
		}else{
			return;
		}
	}else if(s2->book_id==getid && s2->next!=NULL){
		data_dis(s2);
		textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
		head=s2->next;
		printf("\n");
		cprintf("First record deleted.");
		count_data--;
		flg=1;
		getch();
		return;
		}else{
			return;
		}
	}else{
		while(s1!=NULL){
			if(s1->book_id==getid && s1->next==NULL){
				data_dis(s1);
				textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
				s2->next=NULL;
				printf("\n");
				cprintf("Last record deleted successfully");
				count_data--;
				flg=1;
				getch();
				return;
		}else{
			return;
		}
			}else if(s1->book_id==getid && s1->next!=NULL){
				data_dis(s1);
				textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
				s2->next=s1->next;
				printf("\n");
				cprintf("Record deleted successfully");
				count_data--;
				flg=1;
				getch();
				return;
		}else{
			return;
		}
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found.");
		getch();
		return;
	}
	textcolor(15);
}

void search_by_name_dlt(){
	int flg=0,res,result;
	b *s1,*s2;
	char getname[50],dec;
	textcolor(9);
	printf("\n\n");
	cprintf("Enter the book name: ");
	fflush(stdin);
	gets(getname);
	s1=head->next;
	s2=head;
	res=strcmp(s2->book_name,getname);
	if(res==0 && s2->next==NULL){
		data_dis(s2);
		textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
		head=NULL;
		printf("\n");
		cprintf("First record deleted. list becomes empty");
		count_data--;
		flg=1;
		getch();
		return;
		}else{
			return;
		}
	}else if(res==0 && s2->next!=NULL){
		data_dis(s2);
		textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
		head=s2->next;
		printf("\n");
		cprintf("First record deleted.");
		count_data--;
		flg=1;
		getch();
		return;
		}else{
			return;
		}
	}else{
		while(s1!=NULL){
			result=strcmp(s1->book_name,getname);
			if(result==0 && s1->next==NULL){
				data_dis(s1);
				textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
				s2->next=NULL;
				printf("\n");
				cprintf("Last record deleted successfully");
				count_data--;
				flg=1;
				getch();
				return;
		}else{
			return;
		}
			}else if(result==0 && s1->next!=NULL){
				data_dis(s1);
				textcolor(4);
		printf("\n\n");
		cprintf("Are you want to delete the record? : ");
		fflush(stdin);
		scanf("%c",&dec);
		if(dec=='y'||dec=='Y'){
				s2->next=s1->next;
				printf("\n");
				cprintf("Record deleted successfully");
				count_data--;
				flg=1;
				getch();
				return;
		}else{
			return;
		}
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found.");
		getch();
		return;
	}
	textcolor(15);
}

void search_by_rec_no_dlt(){
	int i,ch,flg=1;
	char deci;
	b *s1,*s2,*s3;
	s1=head->next;
	s2=head;
	s3=s2;
	textcolor(9);
	printf("\n");
	cprintf("Enter record no. : ");
	scanf("%d",&ch);
	if(ch>count_data){
		flg=0;
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	for(i=1;i<ch;i++){
		s3=s2;
		s2=s1;
		s1=s1->next;
	}
	data_dis(s2);
	textcolor(4);
	printf("\n");
	cprintf("Are you want to delete the record? ");
	fflush(stdin);
	scanf("%c",&deci);
	if(deci=='y'||deci=='Y'){
		if(ch==1){
			if(s2->next==NULL){
				head=NULL;
				printf("\n");
				cprintf("First record deleted. list becomes empty.");
				count_data--;
				getch();
				return;
			}else if(s2->next!=NULL){
				head=s2->next;
				printf("\n");
				cprintf("First record deleted.");
				count_data--;
				getch();
				return;
			}
		}else{
			s3->next=s2->next;
			printf("\n");
			cprintf("Record successfully deleted");
			count_data--;
			getch();
			return;
		}
	}else{
		return;
	}
	getch();
	textcolor(15);
}

void search(){
	int ch;
	char dec='n';
	textcolor(9);
	if(head==NULL){
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	while(dec=='n'||dec=='N'){
		textcolor(9);
		printf("\n\n");
		cprintf("1.Search by name");
		printf("\n");
		cprintf("2.Search by id");
		printf("\n");
		cprintf("3.Search by record no.");
		printf("\n\n");
		cprintf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				search_by_name();
				break;
			case 2:
				search_by_id();
				break;
			case 3:
				search_by_rec_no();
				break;
		}
		textcolor(9);
		printf("\n\n");
		cprintf("Are u want to close search: ");
		fflush(stdin);
		scanf("%c",&dec);
	}
	textcolor(15);
}

void search_by_name(){
	int flg=0,res,result;
	b *s1,*s2;
	char getname[50],dec;
	textcolor(5);
	printf("\n\n");
	cprintf("Enter the book name: ");
	fflush(stdin);
	gets(getname);
	s1=head->next;
	s2=head;
	res=strcmp(s2->book_name,getname);
	if(res==0){
		data_dis(s2);
		flg=1;
		getch();
	}else{
		while(s1!=NULL){
			result=strcmp(s1->book_name,getname);
			if(result==0){
				data_dis(s1);
				flg=1;
				getch();
				return;
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found.");
		getch();
		return;
	}
	textcolor(15);
}

void search_by_id(){
	int flg=0,getid;
	b *s1,*s2;
	textcolor(5);
	printf("\n\n");
	cprintf("Enter the book id: ");
	scanf("%d",&getid);
	s1=head->next;
	s2=head;
	if(s2->book_id==getid){
		data_dis(s2);
		flg=1;
		getch();
	}else{
		while(s1!=NULL){
			if(s1->book_id==getid){
				data_dis(s1);
				flg=1;
				getch();
				return;
			}else{
				flg=0;
				s2=s1;
				s1=s1->next;
			}
		}
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found.");
		getch();
		return;
	}
	textcolor(15);
}

void search_by_rec_no(){
	int i,ch,flg=1;
	b *s1,*s2;
	s1=head->next;
	s2=head;
	textcolor(5);
	printf("\n");
	cprintf("Enter record no. : ");
	scanf("%d",&ch);
	if(ch>count_data){
		flg=0;
	}

	if(flg==0){
		textcolor(9);
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}

	for(i=1;i<ch;i++){
		s2=s1;
		s1=s1->next;
	}
	data_dis(s2);
	printf("\n");
	getch();
	textcolor(15);
}

void display(){
	int i=0;
	b *s1;
	s1=head;

	if(head==NULL){
		printf("\n");
		cprintf("Sorry no data found...");
		getch();
		return;
	}
	while(s1!=NULL){
		i++;
		textcolor(15);
		printf("\n");
		cprintf("Record %d",i);
		printf("\n");
		cprintf("-------------");
		data_dis(s1);
		printf("\n");
		getch();
		s1=s1->next;
	}
	cprintf("_____________________________");
	printf("\n\n");
	textcolor(6);
	cprintf("Total number of record is: ");
	printf("%d",count_data);
	getch();
	textcolor(15);
}

void insert(){
	char dec;
	do{
		if(head==NULL){
			head=(b*)malloc(1*sizeof(b));
			take_input(head);
			head->next=NULL;
			count_data++;
			textcolor(14);
			printf("\n\n");
			cprintf("Number of data is : %d",count_data);
			printf("\n");
			cprintf("Continue? [y/n]: ");
			fflush(stdin);
			scanf("%c",&dec);
		}else{
			b *s1,*s2,*temp;
			s1=head->next;
			s2=head;

			while(s1!=NULL){
				s2=s1;
				s1=s1->next;
			}

			temp=(b*)malloc(1*sizeof(b));
			take_input(temp);
			temp->next=NULL;
			s2->next=temp;
			count_data++;
			textcolor(14);
			printf("\n\n");
			cprintf("Number of data is : %d",count_data);

			printf("\n");
			cprintf("Continue? [y/n]: ");
			fflush(stdin);
			scanf("%c",&dec);
		}
	}while(dec=='y'||dec=='Y');
	textcolor(15);
}

void take_input(b *poi){
	textcolor(11);
	printf("\n");
	cprintf("Enter book id: ");
	scanf("%d",&poi->book_id);

	textcolor(11);
	cprintf("Enter book name: ");
	fflush(stdin);
	gets(poi->book_name);

	textcolor(11);
	cprintf("Enter author name: ");
	fflush(stdin);
	gets(poi->author_name);

	textcolor(11);
	cprintf("Enter publication name: ");
	fflush(stdin);
	gets(poi->publication);

	textcolor(11);
	cprintf("Enter edition: ");
	scanf("%d",&poi->edition);

	textcolor(11);
	cprintf("Enter issued date: ");
	fflush(stdin);
	gets(poi->issued_date);

	textcolor(11);
	cprintf("Enter isbn no.: ");
	fflush(stdin);
	gets(poi->isbn_no);
	textcolor(15);
}

void data_dis(b *poi){
	textcolor(2);
	printf("\n\n");
	cprintf("Book id: ");
	printf("%d",poi->book_id);
	printf("\n");
	cprintf("Book name: ");
	puts(poi->book_name);
	cprintf("Author name: ");
	puts(poi->author_name);
	cprintf("Publication: ");
	puts(poi->publication);
	cprintf("Edition: ");
	printf("%d",poi->edition);
	printf("\n");
	cprintf("Issued date: ");
	puts(poi->issued_date);
	cprintf("Isbn no. : ");
	puts(poi->isbn_no);
	textcolor(15);
}