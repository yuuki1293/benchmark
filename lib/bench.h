#ifndef _BENCH_H_
#define _BENCH_H_

void bench_a(const char *const label, int count,
           void (*target)(void *), void *arg,
           void (*pre)(void *), void *pre_arg,
           void (*post)(void *), void *post_arg,
           void (*pre_loop)(void *), void *pre_loop_arg,
           void (*post_loop)(void *), void *post_loop_arg);

#define bench(label, count, target, arg) bench_a(label, count, target, arg, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

#endif