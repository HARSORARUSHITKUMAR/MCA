#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int *p=(int *)malloc(sizeof(int)*10);
	int *p2;
	printf("%d\n",*(p-1));
	for(int i=0;i<10;i++)
		*(p+i)=10+i;
	
	p2=(int *)realloc(p,sizeof(int)*5);
	if(p2!=NULL)
		p=p2;
	p2=p+5;
	for(int i=0;i<5;i++,p++)
		printf("%d\n",*p);
	printf("\nPLast=%d\n",*(p2-1));
	for(int i=0;i<5;i++,p2++)
		printf("%d\n",*p2);
	printf("%d\n",*p2);
	return 0;
}