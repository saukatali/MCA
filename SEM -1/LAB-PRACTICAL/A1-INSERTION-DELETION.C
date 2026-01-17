#include <stdio.h>
int n;
 int i;

// insertion,.....................
void insert(int a[10], int pos, int ele){
   
    if(pos <= 0 || pos > n + 1){
        printf("Insertion is not possible.......\n");
        return;
    }
    for(i = n; i >= pos; i--){
        a[i] = a[i - 1];
    }
    a[pos - 1] = ele;
    n++;
    
    printf("Elements: \n ");
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

// deletions...........................

void adelete(int a[10], int pos){
    if(pos <= 0 || pos > n){
        printf("Deletion is not possible....\n");
        return;
    }
   for(i = pos - 1; i < n - 1; i++){
       a[i] = a[i + 1];
    }
    n--;
    printf("Elements: \n");
     for(i =0; i < n; i++){
        printf("%d \n", a[i]);
}
}

// Main Code....................

int main(){
    int a[10], pos, val, choice;
    
    printf("Enter the size of Array: \n");
    scanf("%d", &n);
    
    printf("Enter the Elements: \n");
    for(i =0; i < n; i++){
        scanf("%d", &a[i]);
       }
        printf("Elements are there: \n");
        for(i =0 ; i < n; i++){
            printf("%d\n", a[i]);
        
    }
    
    do{
        printf("1. insert \n");
        printf("2. delete \n");
        printf("3. Exit \n");
        
        printf("Enter the choice: \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
              printf("Enter the position to insert elements: \n ");
        scanf("%d", &pos);
        
        printf("Enter the value: \n");
        scanf("%d", &val);
        insert(a, pos, val);
        break;
        
        case 2:
          printf("Enter the position to insert elements: \n ");
        scanf("%d", &pos);
        
        adelete(a, pos);
        break;
        
        case 3:
        printf("Exiting.......");
        break;
    
        default:
         printf("Invalid Input.....\n");
         break;
        }
        
    }while(choice != 3);
    return 0;
    
}
