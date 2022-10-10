#pragma once

#include <stdio.h>
#include <malloc.h>

typedef struct LOS {
	size_t i;
	struct LOS* next;
} LOS;

LOS* NewLOS(size_t);
void Delete(LOS*,size_t);
void Add(LOS*, size_t);
LOS* Swap(LOS*, size_t,size_t);
void FreeLOS(LOS*);
void Show(LOS*);