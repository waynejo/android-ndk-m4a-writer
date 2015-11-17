#pragma once

#include "Mp4Box.h"

struct DrefInfo
{
	uint32_t size;
	uint32_t type;
	uint32_t versionAndFlags;
	uint8_t* data;
};

class DrefMp4Box
{
public:
	static Mp4Box* create();
};


