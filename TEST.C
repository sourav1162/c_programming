#include<conio.h>
#include<stdio.h>

void selection_sort(int arr[],int arr_size){
	int i,j,temp;
	for(i=0;i<arr_size-1;i++){
		for(j=i+1;j<arr_size;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	printf("Array after sort");
	for(i=0;i<arr_size;i++){
		printf("\n%d",arr[i]);
	}
	getch();
}

void main()
{
	int array[]={54,21,85,35,10,40,5};
	int count = sizeof(array)/sizeof(int);
	clrscr();
	selection_sort(array,count);
}