/*
Write a menu-driven program to implement Stack(LIFO) using Linked-List
    (a) Push
    (a) Pop
    (a) Peek
    (a) display
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode; // move the top
}

void pop(){
    struct node *temp;
    temp = top;

    if(top == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("\n%d elem is pop out",top->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("\n%d is peek element",top->data);
    }
}

void display(){
    struct node *ptr;
    ptr = top;

    if(top == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("\nstack elem are : \n");
        while(ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}


int main(){
    int ch,data;

    printf("1. to push\n");
    printf("2. to pop\n");
    printf("3. to peek\n");
    printf("4. to display\n");
    printf("5. to Exit\n");

    do{
        printf("\nEnter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter num to be pushed : ");
                scanf("%d",&data);
                push(data);
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

    }while(ch != 5);


    return 0;
}