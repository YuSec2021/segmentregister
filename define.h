#pragma once

#define TI 0x04
#define RPL 0x03
#define INDEX 0xfff8

#define LDT 1
#define GDT 0


#define SEG_BASE_24_31	0xff000000
#define SEG_BASE_16_23	0xff0000
#define SEG_BASE_0_15	0xffff

#define SEG_LIMIT_16_19 0x000f0000
#define SEG_LIMIT_0_15 0xffff

#define SEG_G		0x00800000 
#define SEG_D_B		0x00400000 
#define SEG_L		0x00200000
#define SEG_AVL		0x00100000
#define SEG_P		0x00008000
#define SEG_DPL		0x00006000 
#define SEG_S		0x00001000 
#define SEG_TYPE	0x00000f00

// Descriptor Type
#define SYSTEM_TYPE 0
#define CODE_DATA_TYPE 1

// Default operation size
#define BIT_16 0
#define BIT_32 1