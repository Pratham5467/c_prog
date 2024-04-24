#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i] = arr[low + i];
    }

    for(int j=0;j<n2;j++){
        R[j] = arr[(mid + 1) + j];
    }

    i=0;
    j=0;
    k = low;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }

}

void merge_sort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high)/2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                merge_sort(arr,low,mid);        
            }
            #pragma omp section
            {
                merge_sort(arr,mid+1,high);
            }
                
        }
        merge(arr,low,mid,high);   


    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main(){
    int n;

    printf("Enter the size of array : ");
    scanf("%d",&n);

    int arr[n];


    FILE *fp = fopen("number.txt","r");

    if(fp == NULL){
        perror("error opening in the file");
        return 1;
    }
    
    int ctr = 0;
    while(fscanf(fp, "%d",&arr[ctr]) == 1){
        ctr++;
        if(ctr == n){
            break;
        }
    }

    fclose(fp);

    printArray(arr,n);
    double start,end;

    start = omp_get_wtime();

    merge_sort(arr,0,n-1);
    
    end = omp_get_wtime();

    printArray(arr,n);
    printf("\nExecution Time in Parallel is : %lf\n",end - start);
    

    return 0;
}
