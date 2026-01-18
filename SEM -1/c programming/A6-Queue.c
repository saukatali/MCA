#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;
int i;

// insertion code
void enqueue(int val){
    if(rear == max - 1){
        printf("Queue is Overflow \n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = val;
    printf("%d Inserted \n",val);
    
    printf("Queeue Elements: ");
    for(i = front; i <=rear; i++)
    printf("%d ", queue[i]);
    printf("\n");
}
// deletion Dequeue
void dequeue(){
    if(front>rear){
        printf("Queue is UnderFlow \n");
        return;
    }
    printf("%d Deletion Successfully Done !\n ", queue[front]);
    front++;
    printf("Queue Elements:");
    for(i = front; i <=rear;i++)
    printf(" %d ", queue[i]);
    printf("\n");
}

// Display all elements
void display(){
    if(front>rear){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue Elements: ");
    for(i = front; i<=rear ; i++)
    printf(" %d ",queue[i]);
    printf("\n");
}

int main(){
    int choice , val;
    
    do{
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit \n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:printf("Enter your Value: ");
                    scanf("%d", &val);
                    enqueue(val);
                    break;
            case 2:
            dequeue();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            printf("Exiting....");
            break;
            
            default:
            printf("Invalid Choice");
            break;
        }
    }while(choice != 4);
    return 0;
}