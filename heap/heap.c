#include "heap.h"

int32_t heap_push(uint32_t *heap, uint32_t size) {
    int idx = size - 1;
    int parent = (idx - 1) / 2;
    int tmp;

    while (heap[idx] < heap[parent]) {
        tmp = heap[idx];
        heap[idx] = heap[parent];
        heap[parent] = tmp;
        idx = parent;
    }

#if 0
    int parent = size - 1;
    do {
        idx = parent;
        parent = (idx - 1) >> 1;
    } while (idx > 0 && heap[idx] < heap[parent]);
#endif

    return 0;
}
