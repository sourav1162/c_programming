#include<conio.h>
#include<stdio.h>

void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
void insert_array(int arr[]);
void display(int arr[]);

void selection_sort_asc(int arr[],int size){
	int i,j,k;
	for(i=0;i<size-1;i++){
		k=i;
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[k]){
				k=j;
			}
		}
		swap(&arr[k],&arr[i]);
	}
	printf("\nAscending sort completed. List sorted ascendingly.");
	getch();
}

void selection_sort_dsc(int arr[],int size){
	int i,j,k;
	for(i=0;i<size-1;i++){
		k=i;
		for(j=i+1;j<size;j++){
			if(arr[j]>arr[k]){
				k=j;
			}
		}
		swap(&arr[k],&arr[i]);
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
		printf("\nSelection sort practice");
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
				selection_sort_asc(arr,number_of_element_in_array);
				break;
			case 4:
				selection_sort_dsc(arr,number_of_element_in_array);
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