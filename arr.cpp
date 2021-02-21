#include <stdio.h>
#include <string.h>
#include "iostream"
using namespace  std;

int main() {

    char *pConst = "hello";
    printf("sizeof(p)=%d,strlen(p)=%d\n", sizeof(pConst),strlen(pConst));

    int a[3][3], *p, i;

    p = &a[0][0];

    for (i = 0; i < 9; i++)
        p[i] = i;

    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
//          printf("%d \n", *(a+i+j));
//          *(*(a+i)+j) = 99;
//          printf("%d \n", *(*(a+i)+j));
          printf("%d \n", **(a+1));//ok
        }
//https://docs.microsoft.com/zh-cn/cpp/preprocessor/predefined-macros?view=msvc-160
#if __cplusplus >= 201402 // 检查C++标准的版本号
  cout << "c++14 or later" << endl; // 201402就是C++14
#elif __cplusplus >= 201103 // 检查C++标准的版本号
  cout << "c++11 or before" << __TIME__<<endl; // 201103是C++11
#else // __cplusplus < 201103 // 199711是C++98 # error "c++ is too old" // 太低则预处理报错
#endif // __cplusplus >= 201402 // 预处理语句结束

    return 0;
}
