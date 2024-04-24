#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_at_end(int data){
    struct node *newnode,*ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
        tail->next = head;
    }
    else{
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}

void rev_cir_LL(){
    struct node *prev,*curr,*next;
    curr = head; 
    prev = tail;

    while(curr != tail){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    tail->next = prev;
    head = tail;
}


void display(){
    struct node *ptr;
    ptr = head;

    while(ptr->next != head){
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
}



int main(){
    add_at_end(10);
    add_at_end(20);
    add_at_end(30);
    add_at_end(40);

    display();

    rev_cir_LL();
    printf("\n");

    display();

    return 0;
}

