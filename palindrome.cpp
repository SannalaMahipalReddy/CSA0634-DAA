#include <stdio.h>
#include <string.h>
void isPalindrome(char str[], int start, int end)
{
    if (start >= end) {
        printf("The string is a palindrome.\n");
        return;
    }
    if (str[start] != str[end]) {
        printf("The string is not a palindrome.\n");
        return;
    }
    isPalindrome(str, start + 1, end - 1);
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    isPalindrome(str, 0, strlen(str) - 1);
    return 0;
}

