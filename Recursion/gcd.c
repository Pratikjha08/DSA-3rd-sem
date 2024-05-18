#include <stdio.h>

int gcd (int n1, int n2){
    if (n2==0){
        return n1;
    }
    return gcd(n2,n1%n2);
}

int main(){
    int n1, n2;
    scanf("%d%d",&n1,&n2);
    printf("The GCD of %d and %d is %d",n1, n2, gcd(n1,n2));
    return 0;
}