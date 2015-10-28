#include "MvhdMp4Box.h"

Mp4Box* MvhdMp4Box::create(uint32_t timescale, uint32_t duration, uint32_t nextTracId)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t creationTime = 0;
	uint32_t modificationTime = 0;
	uint32_t reserved = 0;
	
	uint32_t dataSize = 96;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	(*(uint32_t*)data) = versionAndFlags;
	(*(uint32_t*)(data + 4)) = creationTime;
	(*(uint32_t*)(data + 8)) = modificationTime;
	(*(uint32_t*)(data + 12)) = timescale;
	(*(uint32_t*)(data + 16)) = duration;
	(*(uint32_t*)(data + 20)) = 0x00010000; // reserved
	(*(uint32_t*)(data + 24)) = 0x01000000; // reserved
	(*(uint32_t*)(data + 36)) = 0x00010000; // reserved
	(*(uint32_t*)(data + 52)) = 0x00010000; // reserved
	(*(uint32_t*)(data + 68)) = 0x40000000; // reserved
	(*(uint32_t*)(data + 92)) = nextTracId;
	return new Mp4Box("mvhd", data, dataSize);
}
