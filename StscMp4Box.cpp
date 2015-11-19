#include "StscMp4Box.h"
#include "memUtils.h"

Mp4Box* StscMp4Box::create(uint32_t entriesNum, SampleToChunkEntry* sampleEntry)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t dataSize = 8 + sizeof(SampleToChunkEntry) * entriesNum;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy_r(data, &versionAndFlags, 4);
	memcpy_r(data + 4, &entriesNum, 4);
	for (uint32_t i = 0; i < entriesNum; ++i) {
		memcpy(data + 8 + i * sizeof(SampleToChunkEntry), sampleEntry + i, sizeof(SampleToChunkEntry));
	}

	return new Mp4Box("stsc", data, dataSize);
}
