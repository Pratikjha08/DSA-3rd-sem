#include <stdio.h>

long fact(long n, long a){
    if (n == 0)
        return a;
    return fact(n-1,n*a);
}

int main(){
    long n, ans;
    printf("Enter value of n: ");
    scanf("%ld",&n);
    ans = fact(n,1);
    printf("The factorial of %d is %d", n, ans);
    return 0;
}