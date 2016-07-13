#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define SIZE (1 << 20)
#define SZ SIZE

// sort max -> min
int compar_max(const void *lhs, const void *rhs) {
    int r = *(const int*)lhs;
    int l = *(const int*)rhs;
    if (l < r) {
        return -1;
    } else if (l > r) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    uint32_t *heap = malloc(sizeof(heap[0]) * SIZE);
    size_t size = 0;

    uint32_t *data = malloc(sizeof(data[0]) * SZ);
    srand(0);
    for (int i = 0; i < SZ; ++i) {
        data[i] = rand();
    }


    for (size_t i = 0; i < ARRAY_SIZE(data); ++i) {
        heap[size++] = data[i];
        if (max_heap_push(&heap[0], size) < 0) {
            fputs("max_heap_push failed!\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    qsort(&data[0], ARRAY_SIZE(data), sizeof(data[0]), &compar_max);
    if (size != ARRAY_SIZE(data)) {
        fputs("Size incorrect\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ARRAY_SIZE(data); ++i) {
        if (data[i] != heap[0]) {
            fputs("Houston we have a problem!\n", stderr);
            exit(EXIT_FAILURE);
        }
        max_heap_pop(&heap[0], size--);
    }

    printf("Passed.\n");

    free(heap);
    free(data);
    return 0;
}
