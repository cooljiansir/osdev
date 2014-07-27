#ifndef __TIMER_H__
#define __TIMER_H__

#include "common.h"
#include "stack.h"

//timer interrupt vector is 32
#define TIMER_VEC 32

//frequence cann't be smaller than 12
void init_timer(u32int frequency);
void timer_callback(register_t reg);



#endif