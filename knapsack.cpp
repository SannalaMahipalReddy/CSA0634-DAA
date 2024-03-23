#include <stdio.h>
#include <stdlib.h>
typedef struct {
    float weight;
    float value;
    float ratio;
} Item;
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio > itemA->ratio) - (itemA->ratio > itemB->ratio);
}
float fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0; 
    int i;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    Item items[n];

    for (i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight;
    }

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value we can obtain = %.2f\n", maxValue);

    return 0;
}

