#include <Windows.h>
#include <cstdio>
#include "GetSegment.h"
#include "Analysis.h"

int main() {

	GetSegment seg;
	seg.PrintSegmentSelectors();
	seg.PrintSegmentDescriptor(0x00cf93000000ffff);

	return 0;
}