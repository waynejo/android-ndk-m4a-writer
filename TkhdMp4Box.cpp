#include "TkhdMp4Box.h"

Mp4Box* TkhdMp4Box::create(uint32_t timescale, uint32_t duration, uint32_t nextTracId)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = (version << 24) | 3;
	uint32_t creationTime = 0;
	uint32_t modificationTime = 0;
	uint32_t trackId = 1;
	uint32_t dataSize = 84;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	(*(uint32_t*)data) = versionAndFlags;
	(*(uint32_t*)(data + 4)) = creationTime;
	(*(uint32_t*)(data + 8)) = modificationTime;
	(*(uint32_t*)(data + 12)) = trackId;
	(*(uint32_t*)(data + 20)) = duration;
	(*(uint32_t*)(data + 36)) = 0x00010000; // reserved
	(*(uint32_t*)(data + 48)) = 0x00010000; // reserved
	(*(uint32_t*)(data + 60)) = 0x40000000; // reserved
	(*(uint32_t*)(data + 60)) = 0x40000000; // reserved
	(*(uint32_t*)(data + 64)) = 0x01400000; // reserved
	(*(uint32_t*)(data + 68)) = 0x00F00000; // reserved
	return new Mp4Box("tkhd", data, dataSize);
}
