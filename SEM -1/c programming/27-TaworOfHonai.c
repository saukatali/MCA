#include <stdio.h>
#include <conio.h>

void hanoi(int, char, char, char);

void main() 
{
    int n;
    printf("Enter a Disk : ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');
    // getch();
}

void hanoi(int n, char b, char t, char d)
{
    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, b, d, t);

    printf("Move Disk = %d its moves %c to %c  \n", n,b,d);

    hanoi(n - 1, t, b, d);
    

}
