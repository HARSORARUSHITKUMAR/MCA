#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,*p,i,sum=0;
	printf ("\n Enter Size Of Array=") ;
	scanf ("%d",&N) ;

	p=(int *)malloc(N*sizeof(int));
	
	if (p==NULL)
	{
		printf ("\n Error In Memory Allocation. ..") ;
		exit (0) ;
	}


	printf ("\n Enter Elements Of Array \n") ;
	for (i=0; i<N;++i)
	{
	    printf("Enter Element [%d]=",(i+1));
		scanf ("%d", &p[i]) ;
		sum=sum+p[i] ;
	}

	printf (" \n Sum Of All Element Is :%d ", sum) ;
	return 0;
}