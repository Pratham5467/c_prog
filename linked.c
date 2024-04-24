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
int main()
{
    int ch,data;
    printf("1 to insert\n2.to display\n3.to exit\n");

    do{
        printf("\nenter the choice:");
        scanf("%d",&ch);

            switch(ch)
            {
                case 1:
                        printf("enter the data:");
                        scanf("%d",&data);
                        add_at_end(data);
                        break;
            
                case 2:
                        display();
                        break;
                case 3:
                        printf("exit");
                        break;
                default:
                        printf("invalid choice");
            }
    }while(ch!=3);
    return 0;
}