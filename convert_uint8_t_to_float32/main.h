#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>

void init(uint8_t *const src, size_t length);

void bench(void (*target)(const uint8_t *src, float *dst, size_t length), const char* const label);

void general(const uint8_t *src, float *dst, size_t length);

void look_up_list(const uint8_t *src, float *dst, size_t length);

#endif//_MAIN_H_