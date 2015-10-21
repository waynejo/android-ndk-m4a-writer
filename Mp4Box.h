#pragma once

#include <stdint.h>
#include <vector>

class Mp4Box
{
	uint8_t* data;
	uint32_t dataSize;
	uint8_t boxName[4];
	std::vector<Mp4Box*> children;
public:
	Mp4Box(const char* boxName);
	~Mp4Box(void);

	uint32_t boxSize();
	void addChild(Mp4Box* child);
};

