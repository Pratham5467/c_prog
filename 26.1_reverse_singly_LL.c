/*
WAP to reverse singly linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void add_at_end(int data){
    struct node *newnode,*ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void reverse(){
    struct node *prev = NULL;
    struct node *next = NULL;

    while(head != NULL){
        next = head->next;  // 1st we set the next
        head->next = prev;
        prev = head;  // moving prev
        head = next; // moving head at last
    }
    head = prev;  // assigning lastly prev to head
}

void display(){
    struct node *ptr = NULL;

    if(head == NULL){
        printf("List is empty\n");
    }
    ptr = head;
    while(ptr != NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->next;    // updating the ptr value
    }
    printf("NULL");
}


int main(){
    add_at_end(10);
    add_at_end(20);
    add_at_end(30);
    add_at_end(40);

    printf("Before Reversing - \n");
    display();

    printf("\nAfter Reversing - \n");
    reverse();

    display();

    return 0;
}
