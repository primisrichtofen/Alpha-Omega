#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {25, 17, 31, 13, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

