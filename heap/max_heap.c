#include "max_heap.h"

int32_t max_heap_push(uint32_t * restrict heap, uint32_t size) {
    int k = size - 1;
    int p = (k - 1) / 2;
    int tmp;

    if (k > 1 && heap[p] < heap[k]) {
        do {
            tmp = heap[k];
            heap[k] = heap[p];
            heap[p] = tmp;

            k = p;
            p = (k - 1) / 2;
        } while (k > 0 && heap[p] < heap[k]);
    }
    return k;
}

void max_heap_pop(uint32_t * restrict heap, uint32_t size) {
    heap[0] = heap[size - 1];
    int k = 0;
    int j = 1;
    int t;
    while (j < size) {
        if (j < size && heap[j] < heap[j+1]) ++j;
        if (heap[k] >= heap[j]) break;
        t = heap[k];
        heap[k] = heap[j];
        heap[j] = t;
    }
}
