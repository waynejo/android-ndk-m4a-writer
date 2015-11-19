
#include "memUtils.h"

void memcpy_r(void* dst, void* src, uint32_t size)
{
	uint8_t* srcEnd = (uint8_t*)src;
	uint8_t* srcPtr = (uint8_t*)src + size;
	uint8_t* dstPtr = (uint8_t*)dst + size;
	for (; srcEnd != srcPtr; --srcPtr, --dstPtr) {
		*dstPtr = *srcPtr;
	}
	*dstPtr = *srcPtr;
}