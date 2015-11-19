#pragma once

#include "Mp4Box.h"

struct TimeToSampleEntry
{
	uint32_t sampleCount;
	uint32_t sampleDuration;
};

class SttsMp4Box
{
public:
	static Mp4Box* create(uint32_t entriesNum, TimeToSampleEntry* sampleEntry);
};
