#include "Mp4Box.h"


Mp4Box::Mp4Box(const char* boxName)
{
	data = NULL;
	dataSize = 0;
	for (int i = 0; i < sizeof(this->boxName); ++i) {
		this->boxName[i] = boxName[i];
	}
}

Mp4Box::~Mp4Box(void)
{
}

uint32_t Mp4Box::boxSize() {
	uint32_t sumOfChildren = 0;
	for (std::vector<Mp4Box*>::iterator i = children.begin(); i != children.end(); ++i) {
		sumOfChildren += (*i)->boxSize();
	}
	return sumOfChildren + dataSize;
}

void Mp4Box::addChild(Mp4Box* child)
{
	children.push_back(child);
}