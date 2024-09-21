#pragma once
#include <Windows.h>
#include "Analysis.h"

class GetSegment
{
public:
	GetSegment();

	VOID PrintSegmentSelectors();
	VOID PrintSegementSelector(WORD selector);
	VOID PrintSegmentDescriptor(DWORD64 descriptor);

	WORD CS = 0;
	WORD DS = 0;
	WORD SS = 0;
	WORD FS = 0;
	WORD GS = 0;
	WORD ES = 0;

	Analysis* analysis;

protected:
	VOID printSegementSelector(WCHAR* name, WORD selector);
	
};

