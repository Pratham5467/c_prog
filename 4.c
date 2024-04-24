/*
WAP to convert Compact to Sparse matrix
*/

#include<stdio.h>

int s[20][3];

void com_to_spa(){
    int i,j,k,flag;

    for(i=0;i<s[0][0];i++){
        for(j=0;j<s[0][1];j++){
            flag=1;
            for(k=1;k<=s[0][2];k++){
                if(s[k][0]==i&&s[k][1]==j){
                    flag=0;
                    printf("%d ",s[k][2]);
                    break;
                }

            }

            if(flag==1)
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    int i,j;

    printf("Enter total no of rows of sparse : ");
    scanf("%d",&s[0][0]);
    printf("Enter total no of columns of sparse: ");
    scanf("%d",&s[0][1]);
    printf("Enter no of non zero elements of compact: ");
    scanf("%d",&s[0][2]);

    printf("Enter compact matrix elements - \n");
    for(i=1;i<=s[0][2];i++){
        for(j=0;j<3;j++){
            scanf("%d",&s[i][j]);
        }
    }

    printf("Sparse matrix is - \n");
    com_to_spa();

    return 0;
}
