/* program of sorting using SELECTION SORT METHOD */

#include<conio.h>
#include<stdio.h>

void swap(int *ptr1,int *ptr2);
void s_s_asc(int arr[],int size);
void s_s_desc(int arr[],int size);

void swap(int *ptr1,int *ptr2){
	int temp;
	temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}

void s_s_asc(int arr[],int size){
	int i,j,temp;
	for(i=0;i<size-1;i++){
		temp=i;
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[temp]){
				temp=j;
			}
		}
		swap(&arr[i],&arr[temp]);
	}
}

void s_s_desc(int arr[],int size){
	int i,j,temp;
	for(i=0;i<size-1;i++){
		temp=i;
		for(j=i+1;j<size;j++){
			if(arr[j]>arr[temp]){
				temp=j;
			}
		}
		swap(&arr[i],&arr[temp]);
	}
}

void main()
{
	int arr[100];
	int i=0,j=0;
	int count=0;
	char deci;
	int ch;
	char dec;
	while(1){
		START:
		clrscr();
		printf("\n1.INSERT ARRAY");
		printf("\n2.DISPLAY ARRAY");
		printf("\n3.SORT ASCENDING");
		printf("\n4.SORT DESCENDNG");
		printf("\n5.EXIT");
		printf("\nEnter your choice[1-5]: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("\nEnter element: ");
					scanf("%d",&arr[i]);
					i++;
					count=i;
					printf("\nContinue?[Y/N]: ");
					fflush(stdin);
					scanf("%c",&deci);
				}while(deci=='y'||deci=='Y');
				break;
			case 2:
				for(j=0;j<count;j++){
					printf("\n%d.%d",j+1,arr[j]);
				}
				getch();
				break;
			case 3:
				s_s_asc(arr,count);
				printf("\nYour array sorted as ascending.");
				getch();
				break;
			case 4:
				s_s_desc(arr,count);
				printf("\nYour array sorted as descending.");
				getch();
				break;
			case 5:
				clrscr();
				printf("\nAre you want to close the app?[Y/N]: ");
				fflush(stdin);
				scanf("%c",&dec);
				if(dec=='y'||dec=='Y'){
					exit(0);
				}else{
					goto START;
				}
			default:
				printf("\nWrong choice...");
		}
	}
}