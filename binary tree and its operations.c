#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int value) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* createtree() {
    int value;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct node* temp = createnode(value);

    printf("Enter left child of %d\n", value);
    temp->left = createtree();

    printf("Enter right child of %d\n", value);
    temp->right = createtree();

    return temp;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;

    printf("Create Binary Tree\n");
    root = createtree();

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    return 0;
}
