#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>

void init(uint8_t *const src, int length);

void bench(void (*target)(const uint8_t *src, float *dst, int length), const char* const label, int count);

void general(const uint8_t *src, float *dst, int length);

void look_up_table(const uint8_t *src, float *dst, int length);

void avx(const uint8_t *src, float *dst, int length);

#ifdef __AVX2__
void avx2(const uint8_t *src, float *dst, int length);
#endif

#ifdef __AVX512F__
void avx512(const uint8_t *src, float *dst, int length);
#endif

#endif