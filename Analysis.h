#pragma once
#include <Windows.h>

class Analysis
{
public:
	VOID AnalysisSegmentSelector(WORD selector);
	VOID AnalysisSegmentDescriptor(DWORD64 descriptor);

protected:
	VOID checkSegmentType(BYTE segmentType);
	VOID analysisSegmentDescriptorOthers(DWORD descriptor);
};

