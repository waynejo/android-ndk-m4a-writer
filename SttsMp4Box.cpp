#include "SttsMp4Box.h"
#include "memUtils.h"

Mp4Box* SttsMp4Box::create(uint32_t entriesNum, TimeToSampleEntry* sampleEntry)
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;

	uint32_t dataSize = 8 + sizeof(TimeToSampleEntry) * entriesNum;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy_r(data, &versionAndFlags, 4);
	memcpy_r(data + 4, &entriesNum, 4);
	for (int i = 0; i < entriesNum; ++i) {
		memcpy(data + 8 + i * sizeof(TimeToSampleEntry), sampleEntry + i, sizeof(TimeToSampleEntry));
	}
	
	return new Mp4Box("stts", data, dataSize);
}
