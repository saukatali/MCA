#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node *NODE;

// Function declarations
NODE addbeg(NODE, int);
void display(NODE);
NODE getnode();
NODE addend(NODE, int);
NODE delbeg(NODE);
NODE delend(NODE);

int main() {
    int op, item;
    NODE first = NULL;

    do {
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at the end\n");
        printf("3. Display\n");
        printf("4. Delete node at the beginning\n");
        printf("5. Delete node at the end\n");
        printf("6. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &item);
                first = addbeg(first, item);
                break;
            case 2:
                printf("Enter an item to be inserted: ");
                scanf("%d", &item);
                first = addend(first, item);
                break;
            case 3:
                if(first == NULL) {
                    printf("Linked list is empty\n\n");
                } else {
                    printf("Contents of linked list are:\n");
                    display(first);
                }
                break;
            case 4:
                if(first == NULL) {
                    printf("Linked list is empty\n\n");
                } else {
                    first = delbeg(first);
                }
                break;
            case 5:
                if(first == NULL) {
                    printf("Linked list is empty\n\n");
                } else {
                    first = delend(first);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while(op != 6);

    return 0;
}

// Function to add node at the beginning
NODE addbeg(NODE first, int item) {
    NODE temp;
    temp = getnode();
    temp->data = item;
    temp->link = first;
    return temp;
}

// Function to add node at the end
NODE addend(NODE first, int item) {
    NODE temp, cur;
    cur = first;
    temp = getnode();
    temp->data = item;
    temp->link = NULL;
    
    if(first == NULL) {
        return temp;
    } else {
        while(cur->link != NULL) {
            cur = cur->link;
        }
        cur->link = temp;
        return first;
    }
}

// Function to display the linked list
void display(NODE first) {
    NODE cur;
    cur = first;
    while(cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n\n");
}

// Function to delete node at the beginning
NODE delbeg(NODE first) {
    NODE temp;
    temp = first;
    first = first->link;
    free(temp);
    return first;
}

// Function to delete node at the end
NODE delend(NODE first) {
    NODE cur, prev;
    cur = first;

    if(first->link == NULL) {
        free(cur);
        return NULL;
    }

    while(cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }

    prev->link = NULL;
    free(cur);
    return first;
}

// Function to get a new node (allocate memory)
NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}
