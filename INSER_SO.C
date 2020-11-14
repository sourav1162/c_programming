/*PROGRAM OF INSERTION SORT*/

#include<stdio.h>
#include<conio.h>

void insertion_sort(int arr[],int arr_size){
	int i,j,temp;
	for(i=1;i<arr_size;i++){
		temp=arr[i];
		j=i-1;
		while((j>=0) && (arr[j]<temp)){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}

	printf("\nResult after sorting");
	for(i=0;i<arr_size;i++){
		printf("\n%d",arr[i]);
	}
	getch();
}

void main()
{
	int arr[]={32,54,12,20,8,45};
	int size=sizeof(arr)/sizeof(int);
	clrscr();
	insertion_sort(arr,size);
}