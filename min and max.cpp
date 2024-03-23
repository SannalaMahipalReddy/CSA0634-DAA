#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = *max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinMax(arr, size, &min, &max);

    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);

    return 0;
}

