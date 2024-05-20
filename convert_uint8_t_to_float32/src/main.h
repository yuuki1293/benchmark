#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>

struct args
{
    const uint8_t *src;
    float *dst;
    int length;
};

void init(uint8_t *const src, int length);

void general(void* _args);

void look_up_table(void *_args);

void avx(void *_args);

#ifdef __AVX2__
void avx2(void *_args);
#endif

#ifdef __AVX512F__
void avx512(void *_args);
#endif

#endif