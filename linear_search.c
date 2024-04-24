#include <stdio.h>
#include "linear_search.h"

int main(){
    int arr[]={1,88,99,66,47,101,63};
    int size=sizeof(arr)/sizeof(arr[0]);

    linearSearch(arr,63,size);

    return 0;
}