#include <stdio.h>
#include <conio.h>
#include <math.h>
int bindec(int,int,int);

void main(){
    int bn,dn=0;
    printf("Enter The Bianry : ");
    scanf("%d", &bn);

    dn = bindec(bn,dn,0);
    printf("The Decimal is : %d ", dn);
}
int bindec(int bn, int dn, int i) 
{    int r;
    if(bn == 0) {
        return dn;
    }
    r = bn % 10;
    dn = dn + r * pow(2, i);
    return bindec(bn / 10, dn, i + 1);
}
