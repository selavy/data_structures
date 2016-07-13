#ifndef HEAP__H_
#define HEAP__H_

#include <stdint.h>

int32_t heap_push(uint32_t *heap, uint32_t size);

void heap_pop(uint32_t *heap, uint32_t size);

#endif // HEAP__H_
