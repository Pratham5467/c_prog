/*
WAP to implement tree traversal(preorder,Inorder,Postorder) in a binary tree using Array and Linked-List
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node* create(){
    int data;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data (-1 for no node) : ");
    scanf("%d",&data);

    if(data == -1)
        return NULL;

    newnode->data = data;

    printf("Enter the left child of  %d node",data);
    newnode->left = create();
    
    printf("Enter the right child of  %d node",data);
    newnode->right = create();

    return newnode;
}



/*
struct node* newnode(int data){
    struct node *node = NULL;

    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
*/

// root --> left --> right
void PreOrder(struct node *root){
    if (root == NULL){
        return;
    }
    
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// left --> root --> right
void InOrder(struct node *root){
    if (root == NULL){
        return;
    }

    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

// left --> right --> root
void PostOrder(struct node *root){
    if (root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}


int main(){
    /*
    struct node *root = newnode(10);
    root->left = newnode(30);
    root->right = newnode(50);

    root->left->left = newnode(90);
    root->left->right = newnode(60);

    root->right->left = newnode(101);
    root->right->right = newnode(300);
    */

    
    struct node *root = NULL;
    root = create();


    printf("Preorder Traversal : ");
    PreOrder(root);
    printf("\n");

    printf("Inorder Traversal : ");
    InOrder(root);
    printf("\n");

    printf("Postorder Traversal : ");
    PostOrder(root);

    return 0;
}
