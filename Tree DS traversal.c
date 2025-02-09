#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    node->data = data; // Assign data to the node
    node->left = NULL;  // Initialize left and right pointers to NULL
    node->right = NULL;
    return node;
}

// Function to perform Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) { // Base condition: If the current node is not NULL
        inorder(root->left);  // Traverse the left subtree recursively
        printf("%d ", root->data); // Print the data of the current node
        inorder(root->right); // Traverse the right subtree recursively
    }
}

// Function to perform Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print the data of the current node
        preorder(root->left);   // Traverse the left subtree recursively
        preorder(root->right);  // Traverse the right subtree recursively
    }
}

// Function to perform Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);  // Traverse the left subtree recursively
        postorder(root->right); // Traverse the right subtree recursively
        printf("%d ", root->data); // Print the data of the current node
    }
}

// Main function
int main() {
	
	 // Manually creating the tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    
    struct Node* root = newNode(1); 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
