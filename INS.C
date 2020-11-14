#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[]={12,32,8,5,34};
	int i,j,temp;
	clrscr();
	for(i=1;i<5;i++){
		temp=arr[i];
		j=i-1;
		while((temp<arr[j])&&(j>=0)){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}

	for(i=0;i<5;i++){
		printf("\n%d ",arr[i]);
	}
	getch();
}