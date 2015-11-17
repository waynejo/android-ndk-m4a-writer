#include "DrefMp4Box.h"


Mp4Box* DrefMp4Box::create()
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	
	uint32_t entriesNum = 1;
	DrefInfo drefInfo;
	drefInfo.size = 0x0C;
	memcpy(&drefInfo.type, "url ", 4);
	drefInfo.versionAndFlags = 1; // same file.
	
	uint32_t dataSize = 8 + drefInfo.size;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy(data, &versionAndFlags, 4);
	memcpy(data + 4, &entriesNum, 4);
	memcpy(data + 8, &drefInfo, drefInfo.size);
	return new Mp4Box("dref", data, dataSize);
}
