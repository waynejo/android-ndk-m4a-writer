#include "SmhdMp4Box.h"
#include "memUtils.h"

Mp4Box* SmhdMp4Box::create()
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t componentType = 0;
	uint16_t balance = 0;
	uint16_t reserved = 0;
	uint32_t dataSize = 8;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy_r(data, &componentType, 4);
	memcpy_r(data + 4, &balance, 2);
	memcpy_r(data + 6, &reserved, 2);
	return new Mp4Box("smhd", data, dataSize);
}
