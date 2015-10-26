#pragma once

#include "Mp4Box.h"

class FtypMp4Box
{
public:
	static Mp4Box* create(const uint8_t* majorBrand, uint32_t minorVersion, const uint8_t* compatibleBrands, int8_t compatibleBrandNum);
};

