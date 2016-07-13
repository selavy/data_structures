#include "max_heap.h"
#include <assert.h>

int32_t max_heap_push(uint32_t * restrict heap, uint32_t size) {
    assert(heap);
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
    assert(heap);
    assert(size > 0);

    heap[0] = heap[size - 1];
    int k = 0;
    int j = 1;
    int j2;
    int t;
    while (j < size) {
        j2 = j + 1;
        if (j2 < size && heap[j2] > heap[j]) ++j;
        if (heap[k] >= heap[j]) break;
        t = heap[k];
        heap[k] = heap[j];
        heap[j] = t;
        k = j;
        j = k*2+1;
    }
}

void max_heap_remove_elem(uint32_t * restrict heap, uint32_t k, uint32_t size) {
    assert(heap);
    assert(size > 0);
    assert(k < size);

    heap[k] = heap[size - 1];
    int j = 2*k + 1;
    int j2;
    int t;
    while (j < size) {
        j2 = j + 1;
        if (j2 < size && heap[j2] > heap[j]) ++j;
        if (heap[k] >= heap[j]) break;
        t = heap[k];
        heap[k] = heap[j];
        heap[j] = t;
        k = j;
        j = 2*k + 1;
    }
}
