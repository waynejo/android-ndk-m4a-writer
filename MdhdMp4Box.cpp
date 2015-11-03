#include "MdhdMp4Box.h"


Mp4Box* MdhdMp4Box::create(uint32_t timescale, uint32_t duration, uint16_t language, uint16_t quality)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t creationTime = 0;
	uint32_t modificationTime = 0;
	uint32_t reserved = 0;

	uint32_t dataSize = 24;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	(*(uint32_t*)data) = versionAndFlags;
	(*(uint32_t*)(data + 4)) = creationTime;
	(*(uint32_t*)(data + 8)) = modificationTime;
	(*(uint32_t*)(data + 12)) = timescale;
	(*(uint32_t*)(data + 16)) = duration;
	(*(uint16_t*)(data + 20)) = language;
	(*(uint16_t*)(data + 22)) = quality;
	return new Mp4Box("mdhd", data, dataSize);
}
