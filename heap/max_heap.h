#ifndef HEAP__H_
#define HEAP__H_

#include <stdint.h>

#ifndef restrict
#define restrict __restrict
#endif

int32_t max_heap_push(uint32_t * restrict heap, uint32_t size);

void max_heap_pop(uint32_t * restrict heap, uint32_t size);

#endif // HEAP__H_
