#include<stdio.h>
#include<stdio.h>
#define MAX 100

void ascending(int n,int arr[]){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	//print function
	printf("\nElement of array after ascending sort: \n");
	for(i=0;i<n;i++){
		printf("\n%d",arr[i]);
	}
	getch();
}

void descending(int n,int arr[]){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	//print function
	printf("\nElement of array after descending sort: \n");
	for(i=0;i<n;i++){
		printf("\n%d",arr[i]);
	}
	getch();
}

void main()
{
	int arr[MAX],n,i;
	char ch,dec;
	do{
		clrscr();
		printf("\nEnter the length of array: ");
		scanf("%d",&n);
		//insert the element of array
		for(i=0;i<n;i++){
			printf("\nEnter the element %d: ",i+1);
			scanf("%d",&arr[i]);
		}
		//ask user for sorting option
		SORTING_OPTION:
		printf("\n\nHow you want to sort array?[A(Ascending)/D(descending)]: ");
		fflush(stdin);
		scanf("%c",&ch);
		//sort as per user choice
		if(ch=='A'||ch=='a'){
			ascending(n,arr);
		}else if(ch=='D'||ch=='d'){
			descending(n,arr);
		}else{
			clrscr();
			printf("\nPlease enter valid input...");
			goto SORTING_OPTION;
		}
		clrscr();
		printf("\n\nAre you want to close ? [Y/N]: ");
		fflush(stdin);
		scanf("%c",&dec);
	}while(dec=='N'||dec=='n');
}