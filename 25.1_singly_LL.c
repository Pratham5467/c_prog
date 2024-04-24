#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

// declare globally
struct node *head = NULL;

void add_at_end(int data){
    struct node *newnode,*ptr;

    // making newnode
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        ptr=head;

        // For Traversing
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}

void add_at_beg(int data){
    struct node *newnode;

    // making newnode
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->link = head;
        head = newnode;
    }
}

void add_at_mid(int data){
    struct node *newnode,*ptr;
    int pos;

    // making newnode
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;


    if(head == NULL){
        head = newnode;
    }
    else{
        printf("Enter the node after which you want to insert : ");
        scanf("%d",&pos);
        
        ptr = head;
        while((ptr->data != pos) && (ptr->link != NULL)){
            ptr = ptr->link;
        }
        /* important */
        newnode->link = ptr->link;  // (1)
        ptr->link = newnode;        // (2)
    }
}

void del_at_end(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->link == NULL){ // when there is only one Node
        free(head);
        head=NULL;
    }
    else{
        struct node *temp1 = head;
        struct node *temp2 = head;
        
        while(temp1->link != NULL){
            temp2 = temp1;
            temp1 = temp1->link;
        }
        temp2->link = NULL;
        printf("\n%d node is deleted",temp1->data);
        free(temp1);
    }
}

void del_at_beg(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp;
        temp=head;
        head=head->link;
        printf("\n%d node is deleted",temp->data);
        free(temp);
    }
}

// Need correction 
void del_at_mid(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->link == NULL){ // when there is only one Node
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
            temp1 = temp1->link;
        }
        temp2->link = temp1->link;
        printf("%d node is deleted",temp1->data);
        free(temp1);
    }
}

void no_of_elem(){
    struct node *ptr = NULL;
    int count = 0;

    if(head == NULL){
        printf("List is empty\n");
    }
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;    // updating the ptr value
    }
    printf("No. of elements in List are : %d",count);
}

void display(){
    struct node *ptr = NULL;
    if(head == NULL){
        printf("List is empty\n");
    }
    ptr = head;
    while(ptr != NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->link;    // updating the ptr value
    }
    printf("NULL");
}


int main(){
    int ch,data;
    printf("1. to ADD AT END\n2. to ADD AT BEG\n3. to ADD AT MID\n4. to DEL AT END\n5. to DEL AT BEG\n6. to DEL AT MID\n7. to COUNT ELEMENTS\n8. to DISPLAY\n9. to EXIT\n");


    do{
        printf("\nEnter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter data part of node : ");
                scanf("%d",&data);
                add_at_end(data);
                break;
            case 2:
                printf("Enter data part of node : ");
                scanf("%d",&data);
                add_at_beg(data);
                break;
            case 3:
                printf("Enter data part of node : ");
                scanf("%d",&data);
                add_at_mid(data);
                break;
            case 4:
                del_at_end();
                break;
            case 5:
                del_at_beg();
                break;
            case 6:
                del_at_mid();
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
