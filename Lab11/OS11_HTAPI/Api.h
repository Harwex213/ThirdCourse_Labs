#pragma once
#include "HtHandle.h"

#define DLL_API EXTERN_C  __declspec(dllexport)

using namespace Core;


namespace HT
{
	DLL_API Core::HTHANDLE* Create   //  ������� HT             
	(
		int	  capacity,					   // ������� ���������
		int   secSnapshotInterval,		   // ������������� ���������� � ���.
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength,            // ������������ ������ ������
		const char fileName[CHAR_MAX_LENGTH]           // ��� �����
	); 	// != NULL �������� ����������  

	DLL_API Core::HTHANDLE* Load     //  ��������� HT             
	(
		const char fileName[CHAR_MAX_LENGTH]		   // ��� ����� 
	); 	// != NULL �������� ����������  

	DLL_API Core::HTHANDLE* Open     //  ������� HT             
	(
		const char fileName[CHAR_MAX_LENGTH]		   // ��� ����� 
	); 	// != NULL �������� ����������  

	DLL_API BOOL Snap         // ��������� Snapshot
	(
		Core::HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);

	DLL_API BOOL Close        // Snap � ������� HT  �  �������� HTHANDLE
	(
		Core::HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   

	DLL_API BOOL Insert      // �������� ������� � ���������
	(
		Core::HTHANDLE* hthandle,            // ���������� HT
		const Core::Element* element              // �������
	);	//  == TRUE �������� ���������� 

	DLL_API BOOL Update     //  ������� ������� � ���������
	(
		Core::HTHANDLE* hthandle,            // ���������� HT
		const Core::Element* oldelement,          // ������ ������� (����, ������ �����)
		const void* newpayload,          // ����� ������  
		int             newpayloadlength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	DLL_API BOOL Delete      // ������� ������� � ���������
	(
		Core::HTHANDLE* hthandle,            // ���������� HT (����)
		const Core::Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	DLL_API Core::Element* Get     //  ������ ������� � ���������
	(
		Core::HTHANDLE* hthandle,            // ���������� HT
		const Core::Element* element              // ������� 
	); 	//  != NULL �������� ���������� 

	DLL_API char* GetHTLastError  // �������� ��������� � ��������� ������
	(
		Core::HTHANDLE* ht                         // ���������� HT
	);

	DLL_API void Print                               // ����������� ������� 
	(
		const Core::Element* element              // ������� 
	);

	DLL_API void PrintAllElements
	(
		Core::HTHANDLE* ht
	);

	DLL_API Core::Element* CreateElementWithKey(const void* key, int keyLength);

	DLL_API Core::Element* CreateElementWithKeyPayload(const void* key, int keyLength, const void* payload, int payloadLength);

	DLL_API Core::StorageConfig* GetStorageConfig(Core::HTHANDLE* htHandle);
}