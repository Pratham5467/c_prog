#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
 //#include <wait.h>

int main()
{
        pid_t pid;
        int i;

        printf("Enter the num for factorial:");
        scanf("%d",&i);
        pid = fork();

        if(pid==0)
        {
                for(int j=1;j<=i;j++)
                {
                        int fac=1;
                        for(int k=1;k<=j;k++)
                        {
                                printf("%d \t",fac);
                                fac*=k+1;
                        }
                        printf("\n");
                }
        }
        else
        {
                wait(&pid);
                printf("FINISH\n");
        }
    return 0;
}