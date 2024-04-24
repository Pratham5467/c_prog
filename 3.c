
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

   
    int size=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(spa_mat[i][j] != 0){
                size++;
            }
        }
    } 


    
    int com_mat[size][3];

    int k=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(spa_mat[i][j] != 0){
                com_mat[k][0]=i;
                com_mat[k][1]=j;
                com_mat[k][2]=spa_mat[i][j];
                k++;
            }
        }
    }

    printf("Compact matrix is - \n");
    for(int i=0;i<size;i++){
        for(int j=0;j<3;j++){
            printf("%d ",com_mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < r; i++){  
        for(int j = 0; j < c; j++){  
          if(spa_mat[i][j] == 0)  
            count++;  
        }  
    }  
    int size1=r*c;
    if(count > (size1/2))  
        printf("Given matrix is a sparse matrix");  
    else  
        printf("Given matrix is not a sparse matrix");

    return 0;
}
