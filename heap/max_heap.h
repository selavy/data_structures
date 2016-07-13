#ifndef HEAP__H_
#define HEAP__H_

#include <stdint.h>

#ifndef restrict
#define restrict __restrict
#endif

#define maxheap_getmax(heap) (heap[0])

// heap != 0
int32_t max_heap_push(uint32_t * restrict heap, uint32_t size);

// size != 0, heap != 0
void max_heap_pop(uint32_t * restrict heap, uint32_t size);

// heap != 0
void max_heap_remove_elem(uint32_t * restrict heap, uint32_t idx, uint32_t size);

#endif // HEAP__H_
