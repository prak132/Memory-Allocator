#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1 = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; ++i) {
        arr1[i] = i * 2;
    }
    printf("Array 1: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    free(arr1);
    int *arr2 = (int *)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; ++i) {
        arr2[i] = i * 3;
    }
    printf("Array 2: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    int *arr3 = (int *)realloc(arr2, 5 * sizeof(int));
    for (int i = 3; i < 5; ++i) {
        arr3[i] = i * 4;
    }
    printf("Array 3: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
    return 0;
}
