#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "max_heap.h"

#define SIZE (1 << 20)
//#define SIZE 12

typedef uint32_t u32;

// sort max -> min
int compar_max(const void *lhs, const void *rhs) {
    u32 r = *(const u32*)lhs;
    u32 l = *(const u32*)rhs; if (l < r) { return -1;
    } else if (l > r) {
        return 1;
    } else {
        return 0;
    }
}

#define PRINT(d) do { for (i=0; i<SIZE; ++i) printf("%u ", d[i]); printf("\n"); } while(0)

int main(int argc, char **argv) {
    u32 *heap = malloc(sizeof(heap[0]) * SIZE);
    size_t size = 0;
    size_t i;
    u32 *data = malloc(sizeof(data[0]) * SIZE);

    srand(0);
    for (i = 0; i < SIZE; ++i) {
        data[i] = rand() % 100;
    }

    for (i = 0; i < SIZE; ++i) {
        heap[size++] = data[i];
        if (max_heap_push(&heap[0], size) < 0) {
            fputs("max_heap_push failed!\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    qsort(&data[0], SIZE, sizeof(data[0]), &compar_max);
    //PRINT(data);
    for (i = 1; i < SIZE; ++i) {
        if (data[i] > data[i-1]) {
            assert(data[i-1] >= data[i]);
            fputs("Data not sorted!", stderr);
            exit(EXIT_FAILURE);
        }
    }

    if (size != SIZE) {
        fputs("Size incorrect\n", stderr);
        exit(EXIT_FAILURE);
    }
    //PRINT(heap);
    for (i = 0; i < SIZE; ++i) {
        //printf("%u\n", heap[0]);
        if (data[i] != heap[0]) {
            assert(data[i] == heap[0]);
            fputs("Houston we have a problem!\n", stderr);
            exit(EXIT_FAILURE);
        }
        max_heap_pop(&heap[0], size--);
    }

    if (size != 0) {
        fputs("Size != 0 after poping all elements!\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < SIZE; ++i) {
        //printf("pushing (%zu) %u\n", i, data[i]);
        heap[size++] = data[i];
        max_heap_push(&heap[0], size);
        //printf("i = %zu\n", i);
    }
    if (size != SIZE) {
        assert(size == SIZE);
        fputs("Size != SIZE\n", stderr);
        exit(EXIT_FAILURE);
    }

    #define TSIZE 256
    u32 tmp[TSIZE];
    u32 k;
    for (i = 0; i < TSIZE; ++i) {
        k = rand() % SIZE;
        tmp[i] = heap[k];
        max_heap_remove_elem(&heap[0], k, size--);
    }
    for (i = 0; i < TSIZE; ++i) {
        heap[size++] = tmp[i];
        max_heap_push(&heap[0], size);
    }

    for (i = 0; i < SIZE; ++i) {
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
