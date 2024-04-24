/*
WAP to implement linear search on 1-D array(create your own header file)
*/
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

int main(){
    int arr[]={1,88,99,66,47,101,63};
    int size=sizeof(arr)/sizeof(arr[0]);

    linearSearch(arr,63,size);

    return 0;
}