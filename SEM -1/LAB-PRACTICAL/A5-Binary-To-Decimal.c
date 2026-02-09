#include <stdio.h>
#include <math.h>

int bindec(int bn, int dn, int i){
    int r;

    if (bn == 0){
        return dn;
    }

    r = bn % 10;
    dn = dn + r * pow(2, i);

    return bindec(bn / 10, dn, i + 1);
}

int main(){
    int bn, dn = 0;

    printf("Enter binary number: ");
    scanf("%d", &bn);

    dn = bindec(bn, dn, 0);

    printf("Decimal equivalent = %d\n", dn);

    return 0;
}




