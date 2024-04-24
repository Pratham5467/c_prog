/*
WAP to implement following operations on binary search tree :
    a)Insertion of a Node
    a)Searching of a Node
    a)Deletion of a Node
*/

#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function of Inorder Traversal
void InorderTraverse(struct node *root){
    // left --> root --> right
    if(root == NULL){
        return;
    }
    InorderTraverse(root->left);
    printf("%d ",root->data);
    InorderTraverse(root->right);
}

// Insertion of node in BST
struct node *insert(struct node *root,int data){
    if(root == NULL)
        return newnode(data);       // This will called for first node when root == NULL

    else if(data < root->data)
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);
    
    return root;
}

int searchInBST(struct node *node,int data){
    // Base case
    if(node == NULL)
        return 0; 
    
    if(node->data == data)
        return 1;
    
    int res1 = searchInBST(node->left,data);

    if(res1)
        return 1;

    int res2 = searchInBST(node->right,data);

    return res2;
}

struct node *minval(struct node *root){
    struct node *ptr = root;

    while(ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}

struct node *deleteFromBST(struct node *root,int val){
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            printf("%d node is deleted",root->data);
            free(root);
            return NULL;
        }

        // 1 child - left child
        if(root->left != NULL && root->right == NULL){
            struct node *temp = root->left;

            printf("%d node is deleted",root->data);
            free(root);
            return temp;
        }

        // 1 child - right child
        if(root->left == NULL && root->right != NULL){
            struct node *temp = root->right;

            printf("%d node is deleted",root->data);
            free(root);
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int min = minval(root->right)->data;
            root->data = min;
            root->right = deleteFromBST(root->right,min);
            return root;
        } 
    }

    // left part
    else if(val < root->data){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    // right part
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}


int main(){
    struct node *root = NULL;
    int ch,data,num,res,key;

    printf("1. to insert\n");
    printf("2. to display\n");
    printf("3. to search\n");
    printf("4. to delete\n");
    printf("5. to Exit\n");

    do{
        printf("\nEnter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the data part of node : ");
                scanf("%d",&data);
                root = insert(root,data);
                break;
            case 2:
                InorderTraverse(root);
                break;
            case 3:
                printf("\nEnter the num to be searched : ");
                scanf("%d",&num);
                res = searchInBST(root,num);
                if(res){
                    printf("\nThis node is preset in BST");
                }
                else{
                    printf("\nThis node is not preset in BST");
                }
                break;
            case 4:
                printf("Enter the node to be delete : ");
                scanf("%d",&key);
                root = deleteFromBST(root,key);
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("invalid choice");
        }
    }while(ch != 5);
    


/*
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    printf("Inorder traversal: ");
    InorderTraverse(root);
*/


    return 0;
}

