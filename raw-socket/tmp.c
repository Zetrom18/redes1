#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define B(x) S_to_binary_(#x)

static inline unsigned long long S_to_binary_(const char *s)
{
    unsigned long long i = 0;
    while (*s) {
        i <<= 1;
        i += *s++ - '0';
    }
    return i;
}

int main()
{
    int foo = B(001100101);

    printf("%d\n", foo);

    return 0;
}
