#ifndef _MONITOR_H_
#define _MONITOR_H_

#include "common.h"

void monitor_put(char c);

void monitor_clear();

void monitor_write(char *str);

void printf(const char *str,...);

#endif
