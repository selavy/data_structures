#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main(int argc, char **argv) {
    #define SIZE 256
    uint32_t heap[SIZE];
    size_t size = 0;
    memset(&heap[0], 0, sizeof(heap[0]) * SIZE);

    uint32_t data[] = { 1, 5, 3, 2, 8, 4 };

    for (size_t i = 0; i < (sizeof(data) / sizeof(data[0])); ++i) {
        printf("Pushing: %u\n", data[i]);
        heap[size++] = data[i];
        if (heap_push(&heap[-1], size) < 0) {
            fputs("heap_push failed!\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    for (size_t i = 0; i < size; ++i) {
        printf("%u\n", heap[i]);
    }

    return 0;
}
