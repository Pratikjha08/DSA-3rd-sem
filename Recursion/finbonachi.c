#include <stdio.h>

int fibo(int n){
    if (n == 1 ||  n == 2){
        return 1;
    }
    else{
        return(fibo(n-1) + fibo(n-2));
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("The fibonachi number at %d position is %d",n,fibo(n));
    return 0;
}