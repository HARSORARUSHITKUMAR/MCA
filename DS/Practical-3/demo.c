#include <stdio.h>

int main(){
	int size,*ptr;

	int sum=0;

	printf("Enter the size of arrays : ");
	scanf("%d",&size);

	ptr=(int*)malloc(size*sizeof(int));

	for(int i=0; i<size; i++){
		printf("Enter the elements [%d]=",(i+1));
		scanf("%d",&ptr[i]);
		sum+=ptr[i];
	}

	printf("%s\n", );
	return 0;
}