#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include "max_heap.h"

#define SIZE (1 << 20)

int main(int argc, char **argv) {
    uint32_t *data = malloc(sizeof(data[0]) * SIZE);
    uint32_t *heap = malloc(sizeof(heap[0]) * SIZE);
    size_t hsize = 0;
    size_t i;

    // TODO: add other data patterns
    // random data
    for (i = 0; i < SIZE; ++i) {
        data[i] = rand();
    }

    struct timespec tp_start;
    struct timespec tp_end;
    clock_gettime(CLOCK_MONOTONIC, &tp_start);
    for (i = 0; i < SIZE; ++i) {
        heap[hsize++] = data[i];
        max_heap_push(&heap[0], hsize);
    }
    clock_gettime(CLOCK_MONOTONIC, &tp_end);
    const uint64_t ns = (tp_end.tv_sec - tp_start.tv_sec)*1000000000ULL + (tp_end.tv_nsec - tp_start.tv_nsec);
    printf("Total ns: %" PRIu64 "\n", ns);
    printf("Average : %0.4f\n", ((double)ns) / SIZE);

    free(data);
    free(heap);
    return 0;
}
