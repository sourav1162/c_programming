#include<conio.h>
#include<stdio.h>

void insert_array(int arr[]);
void display(int arr[]);

void insertion_sort_asc(int arr[],int size){
	int i,j,temp;

	for(i=1;i<size;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
	printf("\nAscending sort completed. List sorted ascendingly.");
	getch();
}

void insertion_sort_dsc(int arr[],int size){
	int i,j,temp;

	for(i=1;i<size;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]<temp){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
	printf("\nDescending sort completed. List sorted descendingly.");
	getch();
}

int element_of_array,number_of_element_in_array;

void main()
{
	int arr[100],ch;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\nInsertion sort menu based");
		printf("\n***********************");
		printf("\n\n1.INSERT");
		printf("\n2.DISPLAY");
		printf("\n3.ASCENDING SORT");
		printf("\n4.DESCENDING SORT");
		printf("\n5.EXIT");
		printf("\n\nEnter your choice[1-5]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert_array(arr);
				break;
			case 2:
				display(arr);
				break;
			case 3:
				insertion_sort_asc(arr,number_of_element_in_array);
				break;
			case 4:
				insertion_sort_dsc(arr,number_of_element_in_array);
				break;
			case 5:
				do{
					clrscr();
					printf("\nAre you want to close the app?[Y/N]: ");
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

void insert_array(int arr[]){
	char dec;
	do{
		printf("\nEnter element%d: ",element_of_array);
		scanf("%d",&arr[element_of_array]);
		element_of_array++;
		printf("\nContinue[Y/N]: ");
		fflush(stdin);
		scanf("%c",&dec);
		number_of_element_in_array=element_of_array;
	}while(dec=='Y'||dec=='y');
}

void display(int arr[]){
	int i;
	for(i=0;i<number_of_element_in_array;i++){
		printf("\nElement%d: %d",i,arr[i]);
	}
	getch();
}