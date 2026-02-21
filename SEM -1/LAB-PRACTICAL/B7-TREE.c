#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3   // Maximum keys in a node (t-1 where t is the minimum degree)
#define MIN_KEYS 1   // Minimum keys in a node (ceil(t/2) - 1)
#define MAX_CHILDREN (MAX_KEYS + 1) // Maximum children in a node (t)

// Define the structure for the BTreeNode
typedef struct BTreeNode {
    int keys[MAX_KEYS];                  // Array of keys
    struct BTreeNode* children[MAX_CHILDREN]; // Array of children pointers
    int numKeys;                         // Current number of keys in the node
    int isLeaf;                          // Boolean flag to check if it's a leaf node
} BTreeNode;

// Function to create a new node
BTreeNode* createNode(int isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to split a child of a node
void splitChild(BTreeNode* parent, int index, BTreeNode* child) {
    BTreeNode* newChild = createNode(child->isLeaf);
    newChild->numKeys = MIN_KEYS;

    // Move half the keys from child to newChild
    for (int i = 0; i < MIN_KEYS; i++) {
        newChild->keys[i] = child->keys[i + MIN_KEYS + 1];
    }

    // If the child is not a leaf, move the children as well
    if (!child->isLeaf) {
        for (int i = 0; i < MIN_KEYS + 1; i++) {
            newChild->children[i] = child->children[i + MIN_KEYS + 1];
        }
    }

    child->numKeys = MIN_KEYS;

    // Move the children of parent to make space for new child
    for (int i = parent->numKeys; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }

    // Link the new child to the parent
    parent->children[index + 1] = newChild;

    // Move the keys of parent to make space for the new key
    for (int i = parent->numKeys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }

    // Put the middle key from the child into the parent
    parent->keys[index] = child->keys[MIN_KEYS];
    parent->numKeys++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    // If the node is a leaf, insert the key
    if (node->isLeaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child to recurse into
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        // If the child is full, split it
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);

            // After splitting, check which child to recurse into
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into the B-tree
void insert(BTreeNode** root, int key) {
    BTreeNode* r = *root;

    // If the root is full, split it and create a new root
    if (r->numKeys == MAX_KEYS) {
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = r;
        splitChild(newRoot, 0, r);

        // Insert the key into the appropriate child
        int i = 0;
        if (newRoot->keys[0] < key) {
            i++;
        }
        insertNonFull(newRoot->children[i], key);

        // Update the root pointer
        *root = newRoot;
    } else {
        insertNonFull(r, key);
    }
}

// Function to traverse the B-tree in order
void traverse(BTreeNode* root) {
    if (root == NULL) return;

    // Traverse all the children and print the keys
    for (int i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    // Traverse the last child
    if (!root->isLeaf) {
        traverse(root->children[root->numKeys]);
    }
}

// Main function to demonstrate the B-tree operations
int main() {
    BTreeNode* root = createNode(1); // Create the root node as a leaf node

    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 10);
    insert(&root, 9);
    insert(&root, 1);
    insert(&root, 12);
    insert(&root, 13);

    printf("Traversal of the constructed B-tree is:\n");
    traverse(root);

    return 0;
}