#include "Analysis.h"
#include <iostream>
#include "define.h"

using namespace std;

VOID Analysis::AnalysisSegmentSelector(WORD selector) {
	// RPL
	cout << "RPL: ";
	cout << (selector & 0x03) << endl;

	// TI
	cout << "Specifies the descriptor table to use: ";
	(selector & TI) == 1 ? cout << "LDT" << endl : cout << "GDT" << endl;

	// Index
	cout << "Index: ";
	cout << ((selector & INDEX) >> 3) << endl;
}

VOID Analysis::AnalysisSegmentDescriptor(DWORD64 descriptor) {
	DWORD base = ((descriptor >> 0x10) & SEG_BASE_0_15)
		^ ((descriptor >> 0x10) & SEG_BASE_16_23)
		^ ((descriptor >> 0x20) & SEG_BASE_24_31);

	DWORD limit = (descriptor & SEG_LIMIT_0_15)
		^ ((descriptor >> 0x20) & SEG_LIMIT_16_19);

	cout << "Segment Limit: " << hex << limit << endl;
	cout << "Segment base address: " << hex << base << endl;

	analysisSegmentDescriptorOthers(descriptor >> 0x20);
}


VOID Analysis::analysisSegmentDescriptorOthers(DWORD descriptor) {
	DWORD seg_G = (descriptor & SEG_G) >> 0x17;
	DWORD seg_D_B = (descriptor & SEG_D_B) >> 0x16;
	DWORD seg_L = (descriptor & SEG_L) >> 0x15;
	DWORD seg_AVL = (descriptor & SEG_AVL) >> 0x14;
	DWORD seg_P = (descriptor & SEG_P) >> 0xf;
	DWORD seg_DPL = (descriptor & SEG_DPL) >> 0x0d;
	DWORD seg_S = (descriptor & SEG_S) >> 0x0c;
	DWORD seg_TYPE = (descriptor & SEG_TYPE) >> 0x08;

	cout << "Granularity: " << hex << seg_G << endl;

	cout << "Default operation size: ";
	seg_D_B == BIT_32 ? cout << "32-bit segment" : cout << "16-bit segment";
	cout << endl;

	cout << "64-bit code segment: " << hex << seg_L << endl;
	cout << "Available for use by system software: " << hex << seg_AVL << endl;
	cout << "Segment present: " << hex << seg_P << endl;

	cout << "Descriptor privilege level: " << hex << seg_DPL << endl;

	cout << "Descriptor type: ";
	seg_S == SYSTEM_TYPE ? cout << "system" : cout << "code or data";
	cout << endl;

	cout << "Segment type: ";
	if (seg_S) {
		this->checkSegmentType(seg_TYPE);
	}
	cout << endl;
}


VOID Analysis::checkSegmentType(BYTE segmentType) {
	segmentType & 0x8 ? cout << "Code " : cout << "Data ";
	cout << endl;
	cout << "Description: ";
	if (segmentType & 0x8) {
		cout << "Execute ";
		if (segmentType & 0x4) cout << "Conforming ";
		if (segmentType & 0x2) cout << "Read ";
		if (segmentType & 0x1) cout << "Accessed ";
	}
	else {
		cout << "Read ";
		if (segmentType & 0x4) cout << "Expand-down ";
		if (segmentType & 0x2) cout << "Write ";
		if (segmentType & 0x1) cout << "Accessed ";
	}
	cout << endl;
}
