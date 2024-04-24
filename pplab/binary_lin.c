#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int linear(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
        
    }
    return -1;
}

int binary(int arr[],int low,int high,int x){
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            return mid;

        }
        if(arr[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main(){
    FILE *file=fopen("num.txt","r");
    if(file==NULL){
        printf("error opening file");
        exit(0);
    }
    int size=100;
    int arr[size];
    fscanf(file,"%d",&arr[size]);

    for(int i=0;i<size;i++){
        fscanf(file,"%d",arr[i]);
    }
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    int x;
    printf("enter the elem to search:");
    scanf("%d",&x);

    int lres=linear(arr,size,x);
    if(lres==-1){
        printf("elem not found");
    }else{
        printf("elem found at index:%d\n",lres);

    }
    int bires=binary(arr,0,size-1,x);
    if(bires==-1){
        printf("elem not found");
    }else{
        printf("elem is found at index:%d\n",bires);
    }
    return 0;

}