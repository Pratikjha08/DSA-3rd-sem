#include <stdio.h>

void TOH(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        TOH(n - 1, from_rod, aux_rod, to_rod);  
        printf("Move disk %d from %c to %c\n", n, from_rod, to_rod); 
        TOH(n - 1, aux_rod, to_rod, from_rod); 
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    return 0;
}