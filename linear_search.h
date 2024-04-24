#include <stdio.h>

void linearSearch(int *arr,int key,int size){
    int i;

    for(i=0;i<size;i++){
        if(*(arr + i)==key){
            printf("%d is found at index %d",key,i);
            break;
        }
    }
    if(i==size)
        printf("%d is not found in the array",key);
}
