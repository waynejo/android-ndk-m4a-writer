#include "ElstMp4Box.h"

Mp4Box* ElstMp4Box::create(const uint32_t tracNum, const TrackInfo* tracInfos)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;

	uint32_t dataSize = 8 + tracNum * sizeof(TrackInfo);
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	(*(uint32_t*)data) = versionAndFlags;
	(*(uint32_t*)(data + 4)) = tracNum;
	for (uint32_t i = 0; i < tracNum; ++i) {
		memcpy(data + 8 + i * sizeof(TrackInfo), tracInfos + i, sizeof(TrackInfo));
	}
	return new Mp4Box("elst", data, dataSize);
}