#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int no_of_elem();

void add_at_end(){
    int data;
    printf("Enter the data part of node : ");
    scanf("%d",&data);

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
        tail->next = head;
        head->prev = head;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        head->prev = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void add_at_beg(){
    int data;
    printf("Enter the data part of node : ");
    scanf("%d",&data);

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
        tail->next = head;
        head->prev = head;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void add_at_any_pos(){
    struct node *newnode,*ptr;
    int pos,data;

    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos == 1){
        add_at_beg();
    }
    else if(pos > no_of_elem()){
        printf("\ninvalid position");
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
        ptr->next->prev = newnode;  // newnode->next->prev = newnode;
        ptr->next = newnode;
    }
}

void del_at_end(){
    struct node *temp;
    temp = tail;

    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
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
        head->prev = tail;
        tail->next = head;
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

    while(ptr->next != head){
        count++;
        ptr = ptr->next;    // updating the ptr value
    }

    return count + 1;
}

void display(){
    struct node *ptr;
    ptr = tail;

    while(ptr != head){
        printf("%d-->",ptr->data);
        ptr = ptr->prev;
    }
    printf("%d",ptr->data);
}

int main(){
    int ch,data;

    printf("1. to ADD AT END\n2. to ADD AT BEG\n3. to ADD AT MID\n4. to DEL AT END\n5. to DEL AT BEG\n6. to DEL AT MID\n7. to COUNT ELEMENTS\n8. to DISPLAY\n9. to EXIT\n");

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