#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>

void init(uint8_t *const src, size_t length);

void bench(void (*target)(const uint8_t *src, float *dst, size_t length), const char* const label, size_t count, int log);

void general(const uint8_t *src, float *dst, size_t length);

void look_up_list(const uint8_t *src, float *dst, size_t length);

void avx(const uint8_t *src, float *dst, size_t length);

#ifdef __AVX2__
void avx2(const uint8_t *src, float *dst, size_t length);
#endif

#ifdef __AVX512F__
void avx512(const uint8_t *src, float *dst, size_t length);
#endif

#endif//_MAIN_H_