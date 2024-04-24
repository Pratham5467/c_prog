#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* demo;
    demo=fopen("demo_file.txt","r+");
    fprintf(demo,"%s %s %s","welcome","to","geeks");
    printf("\n %u\n %d");
    printf("\n %f");
    fclose(demo);
    return 0;

}