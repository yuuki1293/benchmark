#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void bench(const char *const label, int count,
             void (*target)(void *), void *arg,
             void (*pre)(void *), void *pre_arg,
             void (*post)(void *), void *post_arg,
             void (*pre_loop)(void *), void *pre_loop_arg,
             void (*post_loop)(void *), void *post_loop_arg)
{
    int i;
    char *out_file = malloc(strlen(label) + 4);
    FILE *fp;
    struct rusage r;
    struct timeval start, end;
    long res;

    sprintf(out_file, "%s.csv", label);
    fp = fopen(out_file, "w");

    if (pre)
        (*pre)(pre_arg);

    for (i = 0; i < count; i++)
    {
        if (pre_loop)
            (*pre_loop)(pre_loop_arg);

        getrusage(RUSAGE_SELF, &r);
        start = r.ru_utime;

        (*target)(arg);

        getrusage(RUSAGE_SELF, &r);
        end = r.ru_utime;
        res = ((end.tv_sec - start.tv_sec) * 1000000L) + end.tv_usec - start.tv_usec;

        if (post_loop)
            (*post_loop)(post_loop_arg);

        fprintf(fp, "%ld\n", res);
#ifdef BENCH_LOG
        printf("(%d/%d)%s: %ldμs\n", i + 1, count, label, res);
#endif
    }

    if (post)
        (*post)(post_arg);

    fclose(fp);
}