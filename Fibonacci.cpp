#include <stdio.h>
int fibonacci(int n){
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
void print_fibonacci_series(int count) {
    if (count <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
}
int main() {
    int count;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &count);
    print_fibonacci_series(count);
    return 0;
}

