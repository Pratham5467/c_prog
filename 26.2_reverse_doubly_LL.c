#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void add_at_end(int data){
    struct node *newnode = NULL;
    
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node *ptr;
        ptr = head;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        newnode->prev = ptr;
        ptr->next = newnode;
    }
}

void rev_doubl_LL(){
    struct node *prev = NULL;
    struct node *next = NULL;

    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head->prev = next;
        head = next;
    }
    head = prev;

}

void display(){
    struct node *ptr;
    ptr = head;

    if(head == NULL){
        printf("List is empty");
    }

    while(ptr != NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main(){
    add_at_end(10);    
    add_at_end(20);    
    add_at_end(30);    
    add_at_end(40);    
    add_at_end(50);    

    display();

    printf("\n");
    rev_doubl_LL();

    display();

    return 0;
}