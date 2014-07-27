#ifndef __STACK_H__
#define __STACK_H__

#include "common.h"

typedef struct int_reg{
	u32int ds;																				//push
	u32int edi,esi,ebp,esp,ebx,edx,ecx,eax;//pusha
	u32int int_no,err_code;											//push 
	u32int eip,cs,eflags;//,useresp,ss;													//pushed by CPU
} register_t;




#endif