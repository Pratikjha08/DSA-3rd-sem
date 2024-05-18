#include <stdio.h>

int fact(int n){
    if (n == 0){
        return 1;
    }else{
        return n * fact(n-1);
    }
}

int main(){
    int n;
    printf("Enter number to calculate factorial: ");
    scanf("%d",&n);
    int factorial = fact(n);
    printf("The factorial of %d is %d",n,factorial);
    return 0;
}