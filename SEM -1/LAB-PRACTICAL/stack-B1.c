#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void push(int);
void pop();
void display();

int s[MAX];
int rear = -1;
int i;
void push(int val)
{
    if (rear == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    rear++;
    s[rear] = val;
    printf("Pushed element = %d\n", val);
    
        printf("Contents of stack:\n");
    for (i = rear; i >= 0; i--)
        printf("%d\n", s[i]);
    
    
}

void pop()
{
    if (rear == -1)
    {
        printf("Stack underflow\n");
        return;
    }

    printf("Popped element = %d\n", s[rear]);
    rear--;
        printf("Contents of stack:\n");
    for (i = rear; i >= 0; i--)
        printf("%d\n", s[i]);
}

void display()
{
    if (rear == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Contents of stack:\n");
    for (i = rear; i >= 0; i--)
        printf("%d\n", s[i]);
    
}
int main()
{
    int op, val;

    do
    {
        printf("\n 1.Push \n 2.pop \n 3.Display \n 4. Exit \n ");
        printf("\nEnter option: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option\n");
        }

    } while (op != 4);

    return 0;
}