#include "Mp4aMp4Box.h"


Mp4Box* Mp4aMp4Box::create()
{
	uint8_t unused[6];
	uint16_t dataReferenceIndex = 1;
	uint16_t soundVersion = 0;
	uint16_t reserved1 = 0;
	uint32_t reserved2 = 0;
	uint16_t channelCount = 2;
	uint16_t sampleSize = 10;
	uint16_t compressionId = 0;
	uint16_t packetSize = 0;
	uint16_t sampleRate = 44100;
	uint16_t reserved3 = 0;

	uint32_t dataSize = 28;
	uint8_t* data = new uint8_t[dataSize];
	memset(data, 0, dataSize);
	memcpy(data, unused, 6);
	memcpy(data + 6, &dataReferenceIndex, 2);
	memcpy(data + 8, &soundVersion, 2);
	memcpy(data + 10, &reserved1, 2);
	memcpy(data + 12, &reserved2, 2);
	memcpy(data + 14, &channelCount, 2);
	memcpy(data + 16, &sampleSize, 2);
	memcpy(data + 18, &compressionId, 2);
	memcpy(data + 20, &packetSize, 2);
	memcpy(data + 22, &sampleRate, 2);
	memcpy(data + 24, &reserved3, 2);
	return new Mp4Box("mp4a", data, dataSize);
}
