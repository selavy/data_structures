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
    if (size > 0) {
        heap[0] = heap[size - 1];
        int idx = 0;
        int c1;
        int c2;
        int mdx;
        int tmp;

        while (1) {
            c1 = idx * 2 + 1;
            c2 = c1 + 1;
            if (c2 < size) {
                mdx = heap[c1] > heap[c2] ? c1 : c2;
                if (heap[idx] < heap[mdx]) {
                    tmp = heap[mdx];
                    heap[mdx] = heap[idx];
                    heap[idx] = tmp;
                    idx = mdx;
                } else {
                    break;
                }
            } else if (c1 < size && heap[idx] < heap[c1]) {
                tmp = heap[c1];
                heap[c1] = heap[idx];
                heap[idx] = tmp;
                idx = c1;
            } else {
                break;
            }
        }
    }
}
