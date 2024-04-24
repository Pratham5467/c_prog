/*
Write a menu driven program to implement following basic operations in Doubly linked list. make use of functions for each of these operations -
    a) insertion at beg
    b) insertion at end
    c) insertion at any pos
    d) deletion from beg
    e) deletion from end
    f) deletion from any pos
    g) display the list
    h) count no. of elements in a list
*/

#include <stdio.h>
#include <stdlib.h>

int no_of_elem();

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

/*
void add_at_end(int data){
    struct node *newnode,*ptr;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
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
        newnode->prev = ptr;
    }
}
*/

// using tail pointer
void add_at_end(){
    struct node *newnode;
    int data;
    printf("Enter data part of node : ");
    scanf("%d",&data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void add_at_beg(){
    struct node *newnode;
    int data;
    printf("Enter data part of node : ");
    scanf("%d",&data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head; 
        head->prev = newnode;
        head = newnode;
    }
}

// Need check
void add_at_any_pos(){
    struct node *newnode,*ptr;
    int pos,data;

    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos == 1){
        add_at_beg();
    }
    else if(pos > no_of_elem()){
        printf("\ninavlid position");
    }
    else{
        printf("Enter data part of node : ");
        scanf("%d",&data);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        ptr = head;

        int i = 1;
        while(i < pos - 1){
            ptr = ptr->next;
            i++;
        }

        newnode->prev = ptr;
        newnode->next = ptr->next;
        ptr->next = newnode;
        newnode->next->prev = newnode;
    }
}

// Using tail pointer
void del_at_end(){
    struct node *temp;
    temp = tail;

    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        tail->prev->next = NULL;
        tail = tail->prev;
        printf("\n%d node is deleted",temp->data);
        free(temp);
    }
}

void del_at_beg(){
    struct node *temp;
    temp = head;

    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        head = head->next;
        head->prev = NULL;
        printf("\n%d node is deleted",temp->data);
        free(temp);
    }
}

void del_at_any_pos(){
    int pos;

    printf("Enter the position : ");
    scanf("%d",&pos);

    if(head==NULL){
        printf("List is empty\n");
    }
    else if(pos == 1){ // for first Node
        del_at_beg();
    }
    else if(pos == no_of_elem()){ // for last Node
        del_at_end();
    }
    else if(pos > no_of_elem()){
        printf("\ninvalid position");
    }
    else{
        struct node *ptr;
        ptr = head;

        int i = 1;
        while(i < pos){
            ptr = ptr->next;
            i++;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        printf("\n%d node is deleted",ptr->data);
        free(ptr);
    }
}

int no_of_elem(){
    struct node *ptr = NULL;
    int count = 0;

    if(head == NULL){
        printf("List is empty\n");
    }
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;    // updating the ptr value
    }

    return count;
}

void display(){
    struct node *ptr = NULL;

    if(head == NULL){
        printf("List is empty\n");
    }
    ptr = head;

    while(ptr != NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}


void max_data_in_LL(){
    struct node *ptr;
    ptr = head;

    int max = 0; 
    while(ptr != NULL){
        if(ptr->data > max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    printf("max data is %d",max);
}


int main(){
    int ch,data;
    printf("1. to ADD AT END\n2. to ADD AT BEG\n3. to ADD AT MID\n4. to DEL AT END\n5. to DEL AT BEG\n6. to DEL AT MID\n7. to COUNT ELEMENTS\n8. to DISPLAY\n 9.to EXIT\n");

    do{
        printf("\nEnter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                add_at_end();
                break;
            case 2:
                add_at_beg();
                break;
            case 3:
                add_at_any_pos();
                break;
            case 4:
                del_at_end();
                break;
            case 5:
                del_at_beg();
                break;
            case 6:
                del_at_any_pos();
                break;
            case 7:
                no_of_elem();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exit");
                break;
            default:
                printf("invalid choice selected\n");
        }
    }while(ch != 9);


    return 0;
}
