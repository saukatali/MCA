#include <stdio.h>

void slength(char s1[50]){
    int i, len = 0;
    for(i = 0; s1[i] != '\0'; i++){
        len++;
    }
    printf("Length: %d\n", len);
}

// concatenation
void sconcate(char s1[50], char s2[50]){
    int i, j;
    for(i = 0; s1[i] != '\0'; i++);
    for(j = 0; s2[j] != '\0'; j++){
        s1[i] = s2[j];
        i++;
    }
    s1[i] = '\0';
    printf("Concatenated String: %s\n", s1);
}

// comparison
void scompare(char s1[50], char s2[50]){
    int i, j;

    for(i = 0; s1[i] == s2[i]; i++){
        if(s1[i] == '\0')
            break;
    }

    j = s1[i] - s2[i];

    if(j == 0)
        printf("Strings are Equal\n");
    else if(j > 0)
        printf("First string is Bigger\n");
    else
        printf("Second string is Bigger\n");
}

int main(){
    char s1[50], s2[50];
    int choice;

    do{
        printf("\n1. Length\n");
        printf("2. Concatenation\n");
        printf("3. Comparison\n");
        printf("4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the String: ");
                scanf("%s", s1);
                slength(s1);
                break;

            case 2:
                printf("Enter String 1: ");
                scanf("%s", s1);
                printf("Enter String 2: ");
                scanf("%s", s2);
                sconcate(s1, s2);
                break;

            case 3:
                printf("Enter String 1: ");
                scanf("%s", s1);
                printf("Enter String 2: ");
                scanf("%s", s2);
                scompare(s1, s2);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid input\n");
        }

    }while(choice != 4);

    return 0;
}
