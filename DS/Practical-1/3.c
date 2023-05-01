#include <stdio.h>

int main(){
   int num;

   int *ptr1;
   int **ptr2;

   printf("Enter the Number here : ");
   scanf("%d",&num);

   ptr1=&num;
   ptr2=&ptr1;

   printf("Number = %d\n &Number = %p\n ptr1=%p\n &ptr1=%p\n ptr2=%p\n &ptr2=%p\n *ptr1=%d\n **ptr2=%d\n",num,&num,ptr1,&ptr1,ptr2,&ptr2,*ptr1,**ptr2);
   return 0;
}