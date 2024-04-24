#include <stdio.h>
#include "binary_search.h"


int main(){
    int arr[]={13,33,53,56,72,96,99,101};
    int size=sizeof(arr)/sizeof(arr[0]);

    binarySearch(arr,99,size);


    return 0;
}