#include "GetSegment.h"
#include <cstdio>
#include "Tools.h"

GetSegment::GetSegment() {
	analysis = new Analysis();
	this->CS = Tools::GetCS();
	this->DS = Tools::GetDS();
	this->SS = Tools::GetSS();
	this->FS = Tools::GetFS();
	this->GS = Tools::GetGS();
	this->ES = Tools::GetES();
}

// Print All Segment Selectors
VOID GetSegment::PrintSegmentSelectors() {
	this->printSegementSelector((WCHAR*)&"CS", this->CS);
	this->printSegementSelector((WCHAR*)&"DS", this->DS);
	this->printSegementSelector((WCHAR*)&"SS", this->SS);
	this->printSegementSelector((WCHAR*)&"FS", this->FS);
	this->printSegementSelector((WCHAR*)&"GS", this->GS);
	this->printSegementSelector((WCHAR*)&"ES", this->ES);
}

// Print One Segment Selector
VOID GetSegment::PrintSegementSelector(WORD selector) {
	analysis->AnalysisSegmentSelector(selector);
}

// Private Print Segment Selector
VOID GetSegment::printSegementSelector(WCHAR* name, WORD selector) {
	printf("%s: %04X\n", name, selector);
	analysis->AnalysisSegmentSelector(selector);
	printf("----------------------------------------\n");
}

// Print Segment Descriptor
VOID GetSegment::PrintSegmentDescriptor(DWORD64 descriptor) {
	printf("Segment Descriptor: %0I64X\n", descriptor);
	analysis->AnalysisSegmentDescriptor(descriptor);
	printf("----------------------------------------");
}