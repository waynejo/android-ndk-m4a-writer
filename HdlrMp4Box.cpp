#include "HdlrMp4Box.h"


Mp4Box* HdlrMp4Box::create()
{
	uint8_t version = 0;
	uint32_t versionAndFlags = version;
	uint32_t componentType = 0;
	uint8_t* componentSubtype = (uint8_t*)"soun";
	uint32_t componentManufacturer = 0;
	uint32_t componentFlags = 0;
	uint32_t componentFlagsMask = 0;
	uint8_t* componentName = (uint8_t*)"SoundHandler";
	uint32_t dataSize = 4 * 6 + 13;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy(data + 8, componentSubtype, 4);
	memcpy(data + 24, componentName, strlen((const char*)componentName));
	return new Mp4Box("hdlr", data, dataSize);
}
