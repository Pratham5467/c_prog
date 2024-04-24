#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE*fp;
    fp=fopen("student.txt","r");
    fseek(fp,0,10);
    printf("%ld",ftell(fp));
    return 0;
}