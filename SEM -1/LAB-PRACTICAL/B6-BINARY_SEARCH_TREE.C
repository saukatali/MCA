#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

// Function declarations
NODE create(NODE, int);
void preorder(NODE);
void inorder(NODE);
void postorder(NODE);
NODE getnode();

void main() {
    int item, op;
    NODE root = NULL;

    do {
        printf("1. Create\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                root = create(root, item);
                break;
            case 2:
                if(root == NULL) {
                    printf("NULL Tree\n");
                } else {
                    printf("Preorder traversal: \n");
                    preorder(root);
                }
                break;
            case 3:
                if(root == NULL) {
                    printf("NULL Tree\n");
                } else {
                    printf("Inorder traversal: \n");
                    inorder(root);
                }
                break;
            case 4:
                if(root == NULL) {
                    printf("NULL Tree\n");
                } else {
                    printf("Postorder traversal: \n");
                    postorder(root);
                }
                break;
        }
    } while(op != 5);
}

// Create a node in the tree
NODE create(NODE root, int item) {
    NODE temp, cur, prev;
    temp = getnode();
    temp->data = item;
    temp->llink = NULL;
    temp->rlink = NULL;

    if(root == NULL) {
        return temp;  // Tree is empty, new node becomes root
    }

    cur = root;
    while(cur != NULL) {
        prev = cur;
        if(item < cur->data) {
            cur = cur->llink;  // Move left
        } else {
            cur = cur->rlink;  // Move right
        }
    }

    // Insert the new node
    if(item < prev->data) {
        prev->llink = temp;
    } else {
        prev->rlink = temp;
    }

    return root;  // Return the root
}

// Preorder traversal (Root -> Left -> Right)
void preorder(NODE root) {
    if(root != NULL) {
        printf("%d\t", root->data);  // Visit root
        preorder(root->llink);       // Traverse left subtree
        preorder(root->rlink);       // Traverse right subtree
    }
}

// Inorder traversal (Left -> Root -> Right)
void inorder(NODE root) {
    if(root != NULL) {
        inorder(root->llink);        // Traverse left subtree
        printf("%d\t", root->data);  // Visit root
        inorder(root->rlink);        // Traverse right subtree
    }
}

// Postorder traversal (Left -> Right -> Root)
void postorder(NODE root) {
    if(root != NULL) {
        postorder(root->llink);      // Traverse left subtree
        postorder(root->rlink);      // Traverse right subtree
        printf("%d\t", root->data);  // Visit root
    }
}

// Memory allocation for a new node
NODE getnode() {
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    return x;  // Return pointer to the newly allocated node
}