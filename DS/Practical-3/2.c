#include<stdio.h>
#include<stdlib.h>

int main()
{
		int size,*ptr,*ptr1;
		printf("Enter Size Of Array:");
		scanf("%d",&size);

		ptr=(int *)malloc(size*sizeof(int));
		ptr1=ptr;

		printf("Enter Elemenets:\n");
		for(int i=0;i<size;i++)
			scanf("%d",&ptr[i]);
		int i;

		for(i=0;i<size;i++){
			printf("Address=%p and Value=%d\n",&ptr[i],ptr[i]);
		}
		
		printf("Enter New Size Of Array: \n");
		scanf("%d",&size);

		ptr=(int*)realloc(ptr,size*sizeof(int));
		printf("Enter elements:\n");

		for(;i<size;i++){
			scanf("%d",&ptr[i]);
		}

		printf("Address and Values:\n");
		for(int i=0;i<size;i++){
			printf("Address=%p and Value=%d\n",&ptr[i],ptr[i]);
		}
		return 0;
	}