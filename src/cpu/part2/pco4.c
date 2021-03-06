#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long timestamp;

static __inline__ timestamp rdtsc (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtscp": "=a" (a), "=d" (d) );
    return (((timestamp)a) | (((timestamp)d) << 32));
}

volatile __attribute__ ((noinline)) void foo0 (a0, a1, a2, a3) {
    __asm__ __volatile__("");
}

int main(int argc, char* argv[]) {
    int loops = atoi(argv[1]);
    timestamp start, end;
    
    volatile int i;
    for (i = 0; i < loops; ++i) {
        start = rdtsc();
        foo0(0, 0, 0, 0);
        end = rdtsc();
        printf("%llu\n", end-start);
    }
}

