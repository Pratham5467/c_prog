// singly Linked list

#include <stdio.h>
#include <stdlib.h>

#define N 6

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

void add_at_beg(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void add_at_mid(int data){
    struct node *newnode,*ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    int pos;
    printf("Enter the node after which you want to insert : ");
    scanf("%d",&pos);


    if(head == NULL){
        head = newnode;
    }
    else{
        ptr = head;
        while(ptr->data != pos && ptr->next != NULL){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}


void rev_LL(){
    struct node *next = NULL;
    struct node *prev = NULL;
    
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void display(){
    struct node *ptr;
    ptr = head;

    while(ptr != NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void check_palindrome(struct node *ptr){
    int i = 0;
    int arr[N];
    int tog;

    while(ptr != NULL){
        arr[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }

    for(int i = 0;i < N;i++){
        printf("%d ",arr[i]);
    }


    for(int i = 0;i < N/2;i++){
        tog = 0;
        if(arr[i] == arr[N - i -1]){
            tog = 1;
        }
    }

    printf("\n");

    if(tog == 1){
        printf("palindrome");
    }
    else{
        printf("Not palindrome");
    }
}


int main(){
    add_at_end(10);
    add_at_end(20);
    add_at_end(30);
    add_at_end(30);
    add_at_end(20);
    add_at_end(10);
    

    check_palindrome(head);

    return 0;
}

