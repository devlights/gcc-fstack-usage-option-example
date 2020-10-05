// REFERENCES:
//   - https://gcc.gnu.org/onlinedocs/gnat_ugn/Static-Stack-Usage-Analysis.html
//   - https://qiita.com/developer-kikikaikai/items/ae134d3320b016c7ef18
//   - https://www.uquest.co.jp/embedded/learning/lecture07-2.html
//   - https://syohex.hatenablog.com/entry/20110319/1300541703
//   - https://qiita.com/hirohiro77/items/713d5bcf60fef7e88dfa
//   - https://qiita.com/tobira-code/items/81d2c05f27d6a39971e4
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