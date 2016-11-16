/*
 * 如何测试洗牌程序
 * http://coolshell.cn/articles/8593.html
 *
 * */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <time.h>
using namespace std;

const size_t MAXLEN = 10;
const char TestArr[MAXLEN] =
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

static char RecurArr[MAXLEN] = { 0 };
static int cnt = 0;
void ShuffleArray_Recursive_Tmp(char* arr, int len) {
	if (cnt > MAXLEN || len <= 0) {
		return;
	}

	int pos = rand() % len;
	RecurArr[cnt++] = arr[pos];
	if (len == 1)
		return;
	ShuffleArray_Recursive_Tmp(arr, pos);
	ShuffleArray_Recursive_Tmp(arr + pos + 1, len - pos - 1);
}

void ShuffleArray_Recursive(char* arr, int len) {
	memset(RecurArr, 0, sizeof(RecurArr));
	cnt = 0;
	ShuffleArray_Recursive_Tmp(arr, len);
	memcpy(arr, RecurArr, len);
}

void ShuffleArray_Fisher_Yates(char* arr, int len)
{
    int i = len, j;
    char temp;

    if ( i == 0 ) return;
    while ( --i ) {
    	/* 为什么这样就足够随机呢，太神奇了! */
        j = rand() %(i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
/*
  >    A,   B,   C,   D,   E,   F,   G,   H,   I,   J,
0>  502, 522, 506, 516, 502, 505, 447, 499, 511, 490,
1> 1419, 939, 725, 563, 449, 316, 264, 165,  99,  61,
2> 1626,1337, 695, 420, 269, 220, 165, 114,  83,  71,
3>  986,1206,1077, 589, 380, 226, 217, 148,  83,  88,
4>  373, 697,1094,1130, 592, 390, 240, 207, 155, 122,
5>   88, 236, 644,1089,1210, 634, 428, 286, 216, 169,
6>    6,  54, 217, 552,1051,1304, 763, 477, 341, 235,
7>    0,   9,  40, 125, 467,1050,1376, 910, 588, 435,
8>    0,   0,   2,  16,  77, 318, 940,1560,1246, 841,
9>    0,   0,   0,   0,   3,  37, 160, 634,1678,2488,
 集中在对角线，为什么？和原始数据的位置有关。

  */
int main_shuffle() {
	/* 随机种子 */
	std::srand(time(0));

	char temp[MAXLEN] = { 0 };
	int result[MAXLEN][MAXLEN] = { 0 };
	for (int i = 0; i < 5000; i++) {
		strncpy(temp, TestArr, MAXLEN);
		//ShuffleArray_Recursive((char*) temp, MAXLEN);
		ShuffleArray_Fisher_Yates((char*) temp, MAXLEN);
		for (int j = 0; j < MAXLEN; ++j) {
			//printf("%4c,",temp[j]);
			int k = 0;
			for (; k < MAXLEN; ++k) {
				if (TestArr[k] == temp[j]){
					break;
				}
			}
			result[j][k]++;
		}
		//cout<<endl;
	}
	//return 0;
	cout<<" > ";
	for (int i = 0; i < MAXLEN; ++i) {
		printf("%4c,",TestArr[i]);
	}
	cout<<endl;
	for (int i = 0; i < MAXLEN; ++i) {
		cout<<i<<"> ";
		for (int j = 0; j < MAXLEN; ++j) {
			printf("%4d,",result[i][j]);
		}
		cout<<endl;
	}
}
