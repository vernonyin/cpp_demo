#include <stdio.h>
#include <string.h>

int main() {

    char *pConst = "hello";
    printf("sizeof(p)=%d,strlen(p)=%d\n", sizeof(pConst),strlen(pConst));

    int a[3][3], *p, i;

    p = &a[0][0];

    for (i = 0; i < 9; i++)

        p[i] = i;

    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%d \n", a[i][j]);

    return 0;
}
