#include <stdio.h>

int main(){
    int d;
    int m;
    int y;

    printf("Enter d,m,y : ");
    scanf("%d%d%d",&d,&m,&y);
    
    char mon[12][10] = {"January","February","March","April","May","June",
    "July","August","September","October","November","December"};


	switch(m){
        case 1:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 2:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 3:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 4:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 5:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 6:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 7:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 8:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 9:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 10:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 11:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
        case 12:
            printf("%dth %s %d",d,mon[m-1],y);
            break;
    }

	return 0;
}



