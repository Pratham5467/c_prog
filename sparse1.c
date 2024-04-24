#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, count = 0;
    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d", &n, &m);

    int matrix[n][m];
    printf("Enter the elements of the sparse matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("matrix[%d][%d] : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("sparse matrix is - \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");

    }

    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(matrix[i][j] != 0)
            {
                if((i == 0 || matrix[i-1][j] == 0) && (j == 0 || matrix[i][j-1] == 0))
                {
                    count++;    
                }
            }
        }
    }

    printf("The number of groups in the sparse matrix is: %d", count);

    return 0;
}
