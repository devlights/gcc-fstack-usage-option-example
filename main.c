#include <stdio.h>
#include <stdlib.h>

// 以下の値を 6 * 1024 * 1024 にすると実行時に
//   (6 * 1024 * 1024) + (2 * 1024 * 1024) 
// のパスが発生するので、デフォルトの ulimit -s のサイズ 8192 を超える
#if STACKSIZE_OVER

#define BUF_LENGTH 6 * 1024 * 1024

#else

#define BUF_LENGTH 5 * 1024 * 1024

#endif


extern void usage1MB(void);
extern void usage2MB(void);

int main(void) {
    printf("[before] +%d\n", BUF_LENGTH); 
    char buf[BUF_LENGTH];
    printf("[after ] +%d\n", BUF_LENGTH); 

    printf("[before] +%d\n", 1 * 1024 * 1024); 
    usage1MB();
    printf("[after ] +%d\n", 1 * 1024 * 1024); 

    printf("[before] +%d\n", 2 * 1024 * 1024); 
    usage2MB();
    printf("[after ] +%d\n", 2 * 1024 * 1024); 

    return EXIT_SUCCESS;
}