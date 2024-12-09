#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int compare(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    if (itemA->ratio < itemB->ratio)
        return 1;
    else if (itemA->ratio > itemB->ratio)
        return -1;
    return 0;
}

void knapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0;
    float finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", finalValue);
}

int main() {
    int W = 50;
    int n = 3;

    struct Item items[] = {
        {60, 10, 60.0 / 10},
        {100, 20, 100.0 / 20},
        {120, 30, 120.0 / 30}
    };

    knapsack(W, items, n);

    return 0;
}

