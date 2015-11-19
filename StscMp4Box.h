#pragma once

#include "Mp4Box.h"

struct SampleToChunkEntry
{
	uint32_t firstChunk;
	uint32_t samplePerChunk;
	uint32_t sampleDescriptionId;
};

class StscMp4Box
{
public:
	static Mp4Box* create(uint32_t entriesNum, SampleToChunkEntry* sampleEntry);
};
