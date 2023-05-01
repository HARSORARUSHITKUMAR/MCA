#include <stdio.h>

int main(){
    int value_arr[5];

    int *pointer_arr[5];

    printf("Enter the 5 value here : ");

    for(int i=0; i<5; i++){
        scanf("%d",&value_arr[i]);
    }

    for(int i=0; i<5; i++){
        pointer_arr[i]=&value_arr[i];
    }

    for(int i=0; i<5; i++){
        printf("%p-> %d\n",pointer_arr[i],*pointer_arr[i]);
    }
    return 0;
}