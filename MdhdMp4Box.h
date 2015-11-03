#pragma once

#include "Mp4Box.h"

class MdhdMp4Box
{
public:
	static Mp4Box* create(uint32_t timescale, uint32_t duration, uint16_t language, uint16_t quality);
};
