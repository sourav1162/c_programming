#include<stdio.h>
#include<stdlib.h>
  int get_int(int *px,int x){
  scanf("%d",&x);
  px=&x;
  while (!scanf("%d",px)&& !isspace()&& getchar()!= '\n'){
	printf("Please enter an integer value:");
	return 0;
  }
  return x;
 }

void main(){
  int x,i;
  clrscr();
  printf("Please enter a number:\n");
  get_int(&x,x);
  //for (i=0; i <20; i++)
   printf("you input the value: %d\n",x);
   fflush(stdin);
   getch();
}