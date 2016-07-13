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

#define SZ 200
    uint32_t data[SZ];
    srand(0);
    for (int i = 0; i < SZ; ++i) {
        data[i] = rand() % 1000;
    }

    //uint32_t data[] = { 1, 5, 3, 2, 8, 4 };
    //uint32_t data[] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    //uint32_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };

    for (size_t i = 0; i < (sizeof(data) / sizeof(data[0])); ++i) {
        //printf("Pushing: %u\n", data[i]);
        heap[size++] = data[i];
        if (heap_push(&heap[0], size) < 0) {
            fputs("heap_push failed!\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

//    printf("Raw heap layout: ");
//    for (size_t i = 0; i < size; ++i) {
//        printf("%u ", heap[i]);
//    }
//    printf("\n");

    printf("\nMax-min order: ");
    while (size > 0) {
        printf("%u ", heap[0]);
        heap_pop(&heap[0], size--);
    }

    return 0;
}
