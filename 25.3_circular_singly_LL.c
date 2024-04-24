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
        newnode->next = head;
    }
    else{
        ptr = head;

        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = head;
    }
}

void add_at_beg(int data){
    struct node *newnode,*ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        newnode->next = head;
    }
    else{
        ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        newnode->next = head;
        ptr->next = newnode;
        head = newnode;
    }
}

void add_at_mid(int data){
    struct node *newnode,*ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    int pos;
    printf("\nEnter the node after which you want to insert : ");
    scanf("%d",&pos);

    if(head == NULL){
        head = newnode;
        newnode->next = head;
    }
    else{
        ptr = head;
        while((ptr->data != pos) && (ptr->next != NULL)){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

}

void del_at_end(){
    struct node *temp1,*temp2;
    temp1 = head;

    while(temp1->next != head){
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = head;
    free(temp1);
}

void del_at_beg(){
    struct node *temp,*ptr;
    temp = head;
    ptr = head;

    while(ptr->next != head){
        ptr = ptr->next;
    }
    head = head->next;
    ptr->next = head;
    free(temp);
}

void del_at_mid(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->next == NULL){ // when there is only one Node
        free(head);
        head=NULL;
    }
    else{
        int pos;
        struct node *temp1 = head;
        struct node *temp2 = head;

        printf("Enter the node which you want to delete : ");
        scanf("%d",&pos);

        while(temp1->data != pos){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        printf("%d node is deleted",temp1->data);
        free(temp1);
    }
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

    printf("\n");
    del_at_mid();

    display();

    return 0;
}