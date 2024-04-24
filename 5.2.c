#include <stdio.h>
#include <stdlib.h>

int main()
{

FILE *fp1 = fopen("Students.txt", "r");
FILE *fp2 = fopen("Marks.txt", "r");
FILE *fp3 = fopen("Student_Info.txt", "w");
char c;
while ((c = fgetc(fp1)) != EOF){
	fputc(c, fp3);
}
while((c=fgetc(fp2))!=EOF){
    fputc(c,fp3);
}


fclose(fp1);
fclose(fp2);
fclose(fp3);
return 0;
}

