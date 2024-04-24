/*
Write a menu-driven program to implement Stack(LIFO) using array 
    (a) Push
    (a) Pop
    (a) Peek
    (a) display
*/

#include <stdio.h>

int arr[5],top=-1;
int s = sizeof(arr)/sizeof(arr[0]);

void push(int elem){
    if(top >= s-1){
        printf("Stack is overflow/full\n");
    }
    else{
        top++;
        arr[top]=elem;
    }
}

void pop(){
    if(top <= -1){
        printf("Stack is underflow/empty\n");
    }
    else{
        printf("The popped elem is %d\n",arr[top]);
        top--;
    }
}

void peek(){
    if(top>=0)
        printf("The peek element is %d\n",arr[top]);
    else
        printf("No peak elem bcs stack is empty");
}

void display(){
    if(top >= 0){
        printf("Stack elements are : \n");
        for(int i=top;i>=0;i--){
            printf("%d\n",arr[i]);
        }
    }
    else{
        printf("Nothing to display Stack is empty\n");
    }
}

int main(){
    int ch,num;
    printf("1. to Push\n2. to pop\n3. to peek\n4. to display stack\n5. to Exit\n");

    do{
        printf("Enter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the number to be pushed : ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("invalid choice selected\n");
        }
    }while(ch!=5);


    return 0;
}