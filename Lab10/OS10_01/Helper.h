#pragma once

namespace HT
{
	int CalcHashTableMaxSizeMemory(int htCapacity, int elMaxKeyLength, int elMaxPayloadLength);
	int CalcElementMaxSizeMemory(int elMaxKeyLength, int elMaxPayloadLength);
}