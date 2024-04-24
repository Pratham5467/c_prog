/*
Write a menu-driven program to implement Linear-Queue(FIFO/LILO) using array 
    (a) Enqueue
    (a) Dequeue
    (a) Peek
    (a) display
*/

#include <stdio.h>

#define size 10

int queue[size];
int front = -1;
int rear = -1;

// Adding elements
void enqueue(int x){
    if(rear == size-1){
        printf("Queue is overflowed/full");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }

    printf("front is : %d\n",front);
    printf("rear is : %d\n",rear);
}

void dequeue(){
    if(front == -1 && rear == -1)
        printf("Queue is underflow/Empty.\n");
    else if(front == rear)
        front = rear = -1;
    else{
        printf("%d  elem is dequeue.\n",queue[front]);
        front++;
    }
    printf("front is : %d\n",front);
    printf("rear is : %d\n",rear);
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is underflow/Empty");
    }
    else{
        printf("%d is the front elem.. ",queue[front]);
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is underflow/Empty.");
    }
    else{
        printf("currently queue elements is : ");
        for(int i=front;i<rear + 1;i++){
            printf("%d ",queue[i]);
        }
    }
}


int main(){
    int ch,num;
    printf("1. to Enqueue\n2. to Dequeue\n3. to Peek\n4. to display queue\n5. to Exit\n");

    do{
        printf("Enter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the number to be enqueue : ");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                dequeue();
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

