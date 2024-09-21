#include "Tools.h"

WORD Tools::GetCS() {
	WORD rCS = 0;
	_asm {
		mov ax, cs;
		mov rCS, ax;
	}
	
	return rCS;
}

WORD Tools::GetDS() {
	WORD rDS = 0;
	_asm {
		mov ax, ds;
		mov rDS, ax;
	}
	return rDS;
}

WORD Tools::GetSS() {
	WORD rSS = 0;
	_asm {
		mov ax, ss;
		mov rSS, ax;
	}
	return rSS;
}

WORD Tools::GetFS() {
	WORD rFS = 0;
	_asm {
		mov ax, fs;
		mov rFS, ax;
	}
	return rFS;
}

WORD Tools::GetGS() {
	WORD rGS = 0;
	_asm {
		mov ax, gs;
		mov rGS, ax;
	}
	return rGS;
}

WORD Tools::GetES() {
	WORD rES = 0;
	_asm {
		mov ax, es;
		mov rES, ax;
	}
	return rES;
}