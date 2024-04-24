#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fptr;

   fptr = fopen("cities.txt","r");
   if(fptr==NULL){
    puts("file does not exist");
    exit(0);
   }
       FILE *fp;
       fp=fopen("my cities.txt","w");
       char ch;
    
       while(1){
    
        ch=fgetc(fptr);
        if(ch==EOF){
            break;
        }
        fputc(ch,fp);
       }
       fclose(fptr);
       fclose(fp);
   return 0;
}