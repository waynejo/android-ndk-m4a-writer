#include "StszMp4Box.h"
#include "memUtils.h"

Mp4Box* StszMp4Box::create(uint32_t entriesNum, uint32_t* sampleSizeEntry)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t sampleSize = 0;
	uint32_t dataSize = 12 + sizeof(uint32_t) * entriesNum;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy_r(data, &versionAndFlags, 4);
	memcpy_r(data + 4, &sampleSize, 4);
	memcpy_r(data + 8, &entriesNum, 4);
	for (int i = 0; i < entriesNum; ++i) {
		memcpy_r(data + 12 + i * sizeof(uint32_t), sampleSizeEntry + i, sizeof(uint32_t));
	}

	return new Mp4Box("stsz", data, dataSize);
}
