#pragma once
#include <Windows.h>
#include "Element.h"

#define CHAR_MAX_LENGTH 512

namespace HT
{
	struct HTHANDLE
	{
		HTHANDLE();
		HTHANDLE(int capacity, int cecSnapshotInterval, int maxKeyLength, int maxPayloadLength, const char fileName[CHAR_MAX_LENGTH]);

		const char defaultFileName[12] = "./input/txt";

		int capacity;					// ������� ��������� � ���������� ��������� 
		int secSnapshotInterval;		// ������������� ���������� � ���. 
		int maxKeyLength;				// ������������ ����� �����
		int maxPayloadLength;			// ������������ ����� ������
		char fileName[CHAR_MAX_LENGTH];			    // ��� ����� 
		int elementSize;
		int currentSize;

		HANDLE hFile;					// File HANDLE != 0, ���� ���� ������
		HANDLE hFileMapping;			// Mapping File HANDLE != 0, ���� mapping ������  
		LPVOID addr;					// Addr != NULL, ���� mapview ��������  

		time_t snapLastTime;			// ���� ���������� snap'a (time())  
		char lastErrorMessage[CHAR_MAX_LENGTH];		// ��������� �� ��������� ������ ��� 0x00

		void initDefault();
		Element* GetElementAddr(int index);
		void CorrectElementPointers(LPVOID elementAddr);
	};
}