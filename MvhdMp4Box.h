#pragma once

#include "Mp4Box.h"

class MvhdMp4Box
{
public:
	static Mp4Box* create(uint32_t timescale, uint32_t duration, uint32_t nextTracId);
};

