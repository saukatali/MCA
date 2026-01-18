#include <stdio.h>

#define SIZE 4

void cqinsert(int);
void cqdelete();
void cqdisplay();

int cq[SIZE], front = -1, rear = -1;

int main()
{
    int item, op;

    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            cqinsert(item);
            break;

        case 2:
            cqdelete();
            break;

        case 3:
            cqdisplay();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid option\n");
        }
    } while (op != 4);

    return 0;
}

void cqinsert(int item)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Circular Queue is FULL\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    cq[rear] = item;
    printf("Inserted: %d\n", item);
}

void cqdelete()
{
    if (front == -1)
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Deleted element = %d\n", cq[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void cqdisplay()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Contents of Circular Queue:\n");

    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    else
    {
        for (i = front; i < SIZE; i++)
            printf("%d ", cq[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    printf("\n");
}
