#pragma once
#include <Windows.h>

class Tools
{
public:

	// x86 compile
	static WORD GetCS();
	static WORD GetDS();
	static WORD GetSS();
	static WORD GetFS();
	static WORD GetGS();
	static WORD GetES();

};

