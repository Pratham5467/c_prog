#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void transpose(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void tranposition_sort(int arr[],int size){
    int sorted=0;
    int cycle=0;
    while(!sorted){
        sorted=1;

        #pragma omp parallel for shared(arr,size,sorted)
        {
            for(int i=0;i<size-cycle-1;i++){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                    sorted=0;
                }
            }
        }
        cycle++;
    }   
}
int main(){
    int size;
    printf("enter the size:");
    scanf("%d",&size);
    int arr[size];
    srand(time(NULL));
    printf("array with numbers are:");
    for(int i=0;i<size;i++){
        arr[i]=rand()%1000;
    }
    double start =omp_get_wtime();
    tranposition_sort(arr,size);
    double end=omp_get_wtime();
    printf("sorted array:");
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    printf("Time taken is : %lfs\n",end-start);
    return 0;
}