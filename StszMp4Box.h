#pragma once

#include "Mp4Box.h"

class StszMp4Box
{
public:
	static Mp4Box* create(uint32_t entriesNum, uint32_t* sampleSizeEntry);
};
