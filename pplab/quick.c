#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define SIZE 1000

void swap( int *a ,int*b){
	int temp =*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low, int high){
	int pivot=arr[high];
	int i= (low-1);
	for(int j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;

			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}
void quick_sort(int arr[],int low, int high){
	if(low < high){
		int part=partition(arr,low,high);
		quick_sort(arr,low,part-1);
		quick_sort(arr,part+1,high);
	}
}

void print(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){

	/*
	int data[]={8,7,2,1,0,9,6};
	int n=sizeof(data)/sizeof(data[0]);
	printf("unsorted array\n");
	print(data,n);

	quick_sort(data,0,n-1);

	printf("sorted array is: \n");
	print(data,n);

	*/

	double start, end;
        FILE *fp = fopen("num.txt","r");
        int arr[SIZE];

        if(fp == NULL){
                perror("error opening in the file");
                return 1;
        }

        int ctr=0;
        while(fscanf(fp,"%d",&arr[ctr]) == 1){
                ctr++;
        }

        fclose(fp);

        start = omp_get_wtime();
        quick_sort(arr,0,SIZE-1);
        end = omp_get_wtime();

        print(arr,SIZE);
        printf("\nTime:%lf",end-start);


}


