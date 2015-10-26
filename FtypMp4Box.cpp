#include "FtypMp4Box.h"


Mp4Box* FtypMp4Box::create(const uint8_t* majorBrand, uint32_t minorVersion, const uint8_t* compatibleBrands, int8_t compatibleBrandNum)
{
	int32_t dataSize = 4 + 4 + 4 * compatibleBrandNum;
	uint8_t* data = new uint8_t[dataSize];
	memcpy(data, majorBrand, 4);
	memcpy(data + 4, &minorVersion, 4);
	for (int i = 0; i < compatibleBrandNum; ++i) {
		memcpy(data + 8 + 4 * i, compatibleBrands + 4 * i, 4);
	}
	
	return new Mp4Box("ftyp", data, dataSize);
}