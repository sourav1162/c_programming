#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*1=head
  0=tail
  printf("\n");	*/
void main()
{
	int u_c;	//user choice
	int res,i,j;
	clrscr();
	printf("Enter your choice[1 for \'head\' and 0 for \'tail\']: ");
	scanf("%d",&u_c);
	i=rand();
	if(i%2==0){
		printf("\nHead");
		getch();
		return;
	}else{
		printf("\nTail");
		getch();
		return;
	}
}