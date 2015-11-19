#include "StsdMp4Box.h"
#include "memUtils.h"

Mp4Box* StsdMp4Box::create()
{
	uint8_t reserved[6] = {0, };
	uint16_t dataReferenceIndex = 1;

	uint32_t dataSize = 8;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy(data, reserved, 6);
	memcpy_r(data + 6, &dataReferenceIndex, 2);
	return new Mp4Box("stsd", data, dataSize);
}
