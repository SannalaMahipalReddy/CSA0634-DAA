#include <stdio.h>
void copyString(char*, const char*);

int main() {
    char source[100];
    printf("Enter the source string:");
    scanf("%s",source);
    
    char destination[20];
    copyString(destination, source);

    printf("Source String: %s\n", source);
    printf("Destination String: %s\n", destination);

    return 0;
}
void copyString(char *dest, const char *source) {
    *dest = *source;
    if (*source) {
        copyString(dest + 1, source + 1);
    }
}

