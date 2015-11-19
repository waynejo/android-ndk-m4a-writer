#pragma once

#include "Mp4Box.h"

class StcoMp4Box
{
public:
	static Mp4Box* create(uint32_t entriesNum, uint32_t* chunkOffsetEntry);
};


