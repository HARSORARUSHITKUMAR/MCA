#include <stdio.h>
void swapbyval(int,int);
void swapbyref(int *, int *);
int main()
{
    int no1,no2;
    printf("Enter No1=");
    scanf("%d",&no1);
    printf("Enter no2=");
    scanf("%d",&no2);
    printf("Before swapping the values are no1 = %d, no2= %d\n",no1,no2);
    swapbyval(no1,no2);
    swapbyref(&no1,&no2);

}
void swapbyval(int no1, int no2)
{
    int temp;
    temp = no1;
    no1=no2;
    no2=temp;
    printf("After swapping(Swap By Value) values are no1 = %d, no2= %d\n",no1,no2);
}
void swapbyref(int *no1, int *no2)
{
    int temp;
    temp = *no1;
    *no1=*no2;
    *no2=temp;
    printf("After swapping(Swap By Reference) values are no1 = %d, no2= %d\n",*no1,*no2);
}
