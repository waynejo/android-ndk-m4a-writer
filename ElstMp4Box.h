#pragma once

#include "Mp4Box.h"

struct TrackInfo
{
	uint32_t trackDuration;
	uint32_t mediaTime;
	uint32_t mediaRate;
};

class ElstMp4Box
{
public:
	static Mp4Box* create(const uint32_t tracNum, const TrackInfo* tracInfos);
};


