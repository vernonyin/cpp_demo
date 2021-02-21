//
// Created by yin on 2018/11/11.
//
//

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
    //替换掉所有空格，优雅
    void replaceBlack(char *str) {
        int count = 0;
        for (int i = 0; str[i] != 0; i++) {
            if (str[i] != ' ') {
                str[count++] = str[i];
            }
        }
        str[count] = '\0';
    }

    //https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.01.html
    //旋转字符串
    //要求空间复杂度为1，时间复杂度是n
    void LeftRotateString(char *s, int n, int m) {
        m = m % n;
        rever(s, 0, m - 1);
        rever(s, m, n - 1);
        rever(s, 0, n - 1);
    }

    void rever(char *str, int first, int second) {
        while (first < second) {
            char tmp = str[first];
            str[first++] = str[second];
            str[second--] = tmp;
        }
    }

    //学会用const
    char *Strcpy(char *s1, const char *s2) {
        char *dst = s1;
        const char *src = s2;
        /* Do the copying in a loop.  */
        while ((*dst++ = *src++) != '\0');               /* The body of this loop is left empty. */
        /* Return the destination string.  */
        return s1;
//        char *ret = s1;
//        while((*s1++ = *s2++) != '\0'){
////            *s1++ = *s2++;
//        }
//        return ret;
    }

    int StrToInt(const char *str) {
        int ret = 0;
        while (*str != '\0') {
            ret = ret * 10 + (*str - '0');
            str++;
        }
        return ret;
    }

    //学会用const
    char *Strncpy(char *s1, const char *s2, int size) {
        char *dst = s1;
        const char *src = s2;
        /* Do the copying in a loop.  */
        while (size-- && (*dst++ = *src++) != '\0');               /* The body of this loop is left empty. */
        /* Return the destination string.  */
        return s1;
    }

    void *memmove(void *s1, const void *s2, size_t n) {
        /* note: these don't have to point to unsigned chars */
        char *p1 = (char *) s1;
        const char *p2 = (char *) s2;
        /* test for overlap that prevents an ascending copy */
        if (p2 < p1 && p1 < p2 + n) {
            /* do a descending copy */
            p2 += n;
            p1 += n;
            while (n-- != 0) {
                *--p1 = *--p2;
                printf("p1=%s\n", p1);
                printf("p2=%s\n", p2);
            }

        } else
            while (n-- != 0)
                *p1++ = *p2++;
        return s1;
    }

//    size_t (strlen)(const char *s) {
//        size_t len = 0;
//        while (*s++ != '\0') {
//            ++len;
//        }
//        return len;
//
//
//        const char *p = s;
//        /* Loop over the data in s.  */
//        while (*p != '\0')
//            p++;
//        return (size_t) (p - s);
//    }

    int StrToInt2(const char *str) {
        /* 1、为空判断
         * 2、正负号
         * 3、非法字符
         * 4、整型溢出
         * */
        if (str == NULL) return 0;
        int sign = 1;
        int base = 0;
        int i = 0;
        while (str[i] == ' ') { i++; }

        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base = base * 10 + (str[i] - '0');
            i++;
        }
        return base * sign;
    }

    //"A man, a plan, a canal: Panama"
    //"race a car"
    bool checkPalindrome(const char *str) {
        int i = 0;
        int j = strlen(str) - 1;
        while (i < j) {
            if(str[i] < 'A' || str[i]>'z'){
                i++;
                continue;
            }
            if(str[j] < 'A' || str[j]>'z'){
                j--;
                continue;
            }
            if (toupper(str[i]) != toupper(str[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string reverseWords(string s) {
      string res;
      int start = s.size()-1;
      int end = start;
      while(start >0 && end>0){
        if(s[end] == ' '){
          --end;
          continue;
        }
        start = end;

        while(start > 0 ){
          if(s[start] == ' '){
            break;
          }else{
            --start;
          }
        }

        res += s.substr(start+1,end-start);
        res += " ";
        end = --start;
      }

      return res.substr(0,res.size()-1);
    }
};

void getMemory(char **p) {
    *p = (char *) malloc(100);   // 1
}

char *GetMemory(int num) {
    char *p = (char *) malloc(sizeof(char) * num); // allocate space on heap
    return p;
}

void Test() {
    char *str = NULL;
    str = GetMemory(1);
    strcpy(str, "Hello");
    free(str);
    str = NULL;
    strcpy(str, "Hello");
}

int main() {
    Solution s;
    string str = "a good   example";
    //"a good   example"
    s.reverseWords(str);
    return 0;
//    char stri[] = "12353453";
//
//    printf("checkPalindrome A man, a plan, a canal: Panama %d\n", s.checkPalindrome("A man, a plan, a canal: Panama"));
//    printf("checkPalindrome race a car %d\n", s.checkPalindrome("race a car"));
//    printf("checkPalindrome OP %d\n", s.checkPalindrome("OP"));
//    printf("checkPalindrome abc %d\n", s.checkPalindrome("abc"));
//    int ret = s.StrToInt2(stri);
//    printf("%s=%d", stri, ret);
//    char str[] = "memmove can be very useful......";
//
//    s.LeftRotateString(str, strlen(str), 4);
//    puts(str);
//    return 0;
//    size_t t = s.strlen(str);
//    puts(str);
//    putchar(t);
//    s.memmove(str + 20, str + 15, 11);
//    puts(str);
//    memcpy(str + 20, str + 15, 11);
//    puts(str);
//    return 0;
//
//    char str[]="h e ll o";
//    char s1[]="first string";
//    char s2[]="secondstring";
//    char* ret2= s.Strcpy(s1,s1);
//    char *ret = s.Strncpy(s1,s2,3);
//
//    printf("strcpy str:%s",ret);
//    s.replaceBlack(str);

//    Test();
//    return 0;
//        char *str = NULL;
//        getMemory(&str);
//        strcpy(str,"hello wrold");   //2
//        printf("%s\n", str);   //3
//        free(str);   //4
}