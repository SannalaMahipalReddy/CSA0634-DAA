#include <stdio.h>
int isPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}
void generatePrimes(int n) {
    static int i = 2;
    if (i <= n) {
        if (isPrime(i, 2)) {
            printf("%d ", i);
        }
        i++;
        generatePrimes(n);
    }
}
int main() {
    int limit;
    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(limit);
    printf("\n");
    return 0;
}

