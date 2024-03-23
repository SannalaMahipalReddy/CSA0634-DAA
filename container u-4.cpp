#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_CONTAINERS 100
typedef struct {
    int weight;
    int volume;
} Item;
typedef struct {
    int weight_capacity;
    int volume_capacity;
    int current_weight;
    int current_volume;
} Container;
void loadItems(Item items[], int num_items, Container containers[], int num_containers) {
    int container_index = 0;
    for (int i = 0; i < num_items; i++) {
        while (container_index < num_containers &&
               (containers[container_index].current_weight + items[i].weight > containers[container_index].weight_capacity ||
                containers[container_index].current_volume + items[i].volume > containers[container_index].volume_capacity)) {
            container_index++;
        }
        if (container_index == num_containers) {
            printf("Cannot load all items into containers.\n");
            return;
        }
        containers[container_index].current_weight += items[i].weight;
        containers[container_index].current_volume += items[i].volume;

        printf("Item %d loaded into container %d\n", i + 1, container_index + 1);
    }

    printf("All items loaded successfully.\n");
}

int main() {
    Item items[MAX_ITEMS] = {
        {10, 5},
        {5, 3},
        {8, 4},
        {3, 2},
    };

    Container containers[MAX_CONTAINERS] = {
        {15, 10, 0, 0},
        {20, 15, 0, 0},
    };
    int num_items = 4;
    int num_containers = 2;
    loadItems(items, num_items, containers, num_containers);

    return 0;
}

