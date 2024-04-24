/*
Write a menu-driven program to implement Circular-Queue(FIFO/LILO) using array 
    (a) Enqueue
    (a) Dequeue
    (a) Peek
    (a) display
*/
 
#include <stdio.h>

#define N 5

int c_queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if((rear + 1) % N == front){
        printf("Queue is overflow/full");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        c_queue[rear] = x;
    }
    else{
        rear = (rear + 1) % N;
        c_queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is underflow/empty");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        printf("%d elem is dequeue",c_queue[front]);
        front = (front + 1) % N;
    }
}

void peek(){
    if(front == - -1 && rear == -1){
        printf("Queue is underflowed/empty");
    }
    printf("peek elem is %d",c_queue[front]);
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("Queue is underflowed/empty");
    }
    else{
        printf("Queue is : ");
        while(i != rear){
            printf("%d ",c_queue[i]);
            i = (i+1) % N;
        }
        printf("%d",c_queue[rear]);
    }
}


int main(){
     int ch,num;
    printf("1. to Enqueue\n2. to Dequeue\n3. to Peek\n4. to display queue\n5. to Exit\n");

    do{
        printf("\nEnter the choice : ");
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
