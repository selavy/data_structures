#include "max_heap.h"

int32_t max_heap_push(uint32_t *heap, uint32_t size) {
    int idx = size - 1;
    int parent = (idx - 1) / 2;
    int tmp;

    if (heap[parent] < heap[idx]) {
        do {
            tmp = heap[idx];
            heap[idx] = heap[parent];
            heap[parent] = tmp;

            idx = parent;
            parent = (idx - 1) / 2;
        } while (heap[parent] < heap[idx]);
    }

    return idx;
}

void max_heap_pop(uint32_t *heap, uint32_t size) {
    if (size) {
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

#if 0
        while (c1 < size) {
            if (heap[idx] < heap[c1]) {
                if (c2 < size && heap[idx] < heap[c2]) {
                    tmp = heap[c2];
                    heap[c2] = heap[idx];
                    heap[idx] = tmp;
                    idx = c2;
                    c1 = idx * 2 + 1;
                    c2 = c1 + 1;
                } else {
                    tmp = heap[c1];
                    heap[c1] = heap[idx];
                    heap[idx] = tmp;
                    idx = c1;
                    c1 = idx * 2 + 1;
                    c2 = c1 + 1;
                }
            } else if (c2 < size && heap[idx] < heap[c2]) {
                tmp = heap[c2];
                heap[c2] = heap[idx];
                heap[idx] = tmp;
                idx = c2;
                c1 = idx * 2 + 1;
                c2 = c1 + 1;
            } else {
                break;
            }
        }
#endif
    }
}
