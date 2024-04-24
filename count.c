#include <stdio.h>

int main(){
    int r,c,count;
    printf("Enter the row and col of sparse matrix : ");
    scanf("%d%d",&r,&c);

    int spa_mat[r][c];

    printf("Enter the elements of sparse matrix - \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("spa_mat[%d][%d] : ",i,j);
            scanf("%d",&spa_mat[i][j]);
        }
    }

    printf("sparse matrix is - \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",spa_mat[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < r; i++){  
        for(int j = 0; j < c; j++){  
          if(spa_mat[i][j] == 0)  
            count++;  
        }  
    }  
    int size=r*c;
    if(count > (size/2))  
        printf("Given matrix is a sparse matrix");  
    else  
        printf("Given matrix is not a sparse matrix");
return 0;
}