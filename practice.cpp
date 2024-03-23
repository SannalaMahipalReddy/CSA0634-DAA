#include <stdio.h>

// Function to check if a number is Armstrong or not
int isArmstrong(int num, int originalNum, int sum) {
    if (num == 0) {
        return originalNum == sum;
    }
    int digit = num % 10;
    sum += digit * digit * digit;
    return isArmstrong(num / 10, originalNum, sum);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num, num, 0))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

