#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define SIZE 1000
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for(int j=0;j<high;j++){
        if(arr[j]<=pivot){
            i++;
        swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        int part=partition(arr,low,high);
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quick_sort(arr,low,part-1);
            }
            #pragma omp section
            {
                quick_sort(arr,part+1,high);
            }
        }
        
    }
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);

    }
    printf("\n");
}
int main(){
    double start,end;
    FILE *fp=fopen("num.txt","r");
    int arr[SIZE];
    if(fp==NULL){
        perror("error in opening the file");
        return -1;

    }
    int ctr=0;
    while (fscanf(fp,"%d",&arr[ctr]==1)){
        ctr++;
    }
    fclose(fp);
    start=omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            quick_sort(arr,0,SIZE-1);
        }
    }
    end=omp_get_wtime();
    printf("sorted array is:\n");
    print(arr,SIZE);
    printf("\ntime:%lf",end-start);

}