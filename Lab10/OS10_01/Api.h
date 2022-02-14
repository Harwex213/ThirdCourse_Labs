#pragma once
#include <Windows.h>
#include "HtHandle.h"
#include "Element.h"

namespace HT
{
	/* API HT - ����������� ��������� ��� ������� � �� - ���������
				��-��������� ������������� ��� �������� ������ � �� � ������� ����/��������
				���������������� (�����������) ������ �������������� � ������� snapshot-����������
				Create - �������  � ������� HT-��������� ��� �������������
				Open   - ������� HT-��������� ��� �������������
				Insert - ������� ������� ������
				Delete - ������� ������� ������
				Get    - ������  ������� ������
				Update - �������� ������� ������
				Snap   - �������� snapshot
				Close  - ��������� Snap � ������� HT-��������� ��� �������������
				GetLastError - �������� ��������� � ��������� ������
	*/

	HTHANDLE* Create   //  ������� HT             
	(
		int	  capacity,					   // ������� ���������
		int   secSnapshotInterval,		   // ������������� ���������� � ���.
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength,            // ������������ ������ ������
		const char fileName[CHAR_MAX_LENGTH]           // ��� ����� 
	); 	// != NULL �������� ����������  

	HTHANDLE* Open     //  ������� HT             
	(
		const char fileName[CHAR_MAX_LENGTH]		   // ��� ����� 
	); 	// != NULL �������� ����������  

	BOOL Snap         // ��������� Snapshot
	(
		HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);

	BOOL Close        // Snap � ������� HT  �  �������� HTHANDLE
	(
		HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   

	BOOL Insert      // �������� ������� � ���������
	(
		HTHANDLE* hthandle,            // ���������� HT
		const Element* element              // �������
	);	//  == TRUE �������� ���������� 

	BOOL Update     //  ������� ������� � ���������
	(
		HTHANDLE* hthandle,            // ���������� HT
		const Element* oldelement,          // ������ ������� (����, ������ �����)
		const void* newpayload,          // ����� ������  
		int             newpayloadlength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	BOOL Delete      // ������� ������� � ���������
	(
		HTHANDLE* hthandle,            // ���������� HT (����)
		const Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	Element* Get     //  ������ ������� � ���������
	(
		HTHANDLE* hthandle,            // ���������� HT
		const Element* element              // ������� 
	); 	//  != NULL �������� ���������� 

	char* GetLastError  // �������� ��������� � ��������� ������
	(
		HTHANDLE* ht                         // ���������� HT
	);

	void Print                               // ����������� ������� 
	(
		const Element* element              // ������� 
	);

	void PrintAllElements
	(
		HTHANDLE* ht
	);
};