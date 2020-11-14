#include<stdio.h>
#include<conio.h>

void quicksort(int arr[],int f,int l){
	int i,j,pivot,temp;
	if(f<l){
		pivot = f;
		i = f;
		j = l;

		while(i<j){
			while(arr[i]<=arr[pivot] && i<l){
				i++;
			}
			while(arr[j]>arr[pivot]){
				j--;
			}
			if(i<j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		quicksort(arr,f,j-1);
		quicksort(arr,j+1,l);
	}
}

void main()
{
	int array[] = {54,22,87,10,35,47,9};
	int size = sizeof(array)/sizeof(int);
	int i;
	clrscr();
	quicksort(array,0,size-1);
	printf("Sorted array");
	for(i=0;i<size;i++){
		printf("\n%d",array[i]);
	}
	getch();
}