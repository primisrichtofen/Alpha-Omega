#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio > itemA->ratio) - (itemA->ratio > itemB->ratio);
}

void knapsackGreedy(Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int remainingCapacity = capacity;
    int taken[n];

    for (int i = 0; i < n; i++) {
        taken[i] = 0;  // Initialize taken array
    }

    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            taken[i] = 1;
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total value: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(Item), compare);

    knapsackGreedy(items, n, capacity);

    return 0;
}

