/* program of sorting using SELECTION SORT METHOD */

#include<conio.h>
#include<stdio.h>

void main()
{
	int arr[100];
	int i=0,j=0,k=0,temp=0;
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
				for(j=0;j<count;j++){
					for(k=j+1;k<count;k++){
						if(arr[j]>arr[k]){
							temp=arr[j];
							arr[j]=arr[k];
							arr[k]=temp;
						}
					}
				}
				printf("\nYour array sorted as ascending.");
				getch();
				break;
			case 4:
				for(j=0;j<count;j++){
					for(k=j+1;k<count;k++){
						if(arr[j]<arr[k]){
							temp=arr[j];
							arr[j]=arr[k];
							arr[k]=temp;
						}
					}
				}
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