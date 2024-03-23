#include <stdio.h>
#include <math.h>
int power(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}
int count_digits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}
int is_armstrong(int num, int original_num) {
    if (num == 0)
        return 0;
    else
        return power(num % 10, count_digits(original_num)) + is_armstrong(num / 10, original_num);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == is_armstrong(num, num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}
