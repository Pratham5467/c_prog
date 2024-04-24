/*
WAP to implement binary search on 1-D array(create your own header file)
*/

#include <stdio.h>

void binarySearch(int *arr,int key,int size){
    int left,right,mid;

    left=0;
    right=size-1;
    while(left <= right){
        mid=(left + right) / 2;
        if(key == *(arr + mid)){
            printf("%d key is found at index %d",key,mid);
            break;
        }
        else if(key > *(arr + mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    if(left > right)
        printf("%d is not found in the array",key);

}


int main(){
    int arr[]={13,33,53,56,72,96,99,101};
    int size=sizeof(arr)/sizeof(arr[0]);

    binarySearch(arr,99,size);


    return 0;
}