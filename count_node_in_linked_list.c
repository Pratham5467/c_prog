#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void count_node(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr=head;

    while(ptr != NULL){
        count++;
        ptr=ptr->link;
    }
    printf("Total Node is %d",count);
}

int main(){
     struct node *head = NULL;

    // Head/First Node
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 50;
    head->link = NULL;

    // Second Node
    struct node *second = malloc(sizeof(struct node));
    second->data = 100;
    second->link = NULL;

    head->link=second; // connecting first node to second

    // Third Node
    struct node *third = malloc(sizeof(struct node));
    third->data = 150;
    third->link = NULL;

    second->link=third; // connecting second node to third

    count_node(head);

    return 0;
}