#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <cstring>
#include <string>
int main() {
	int ab;
	int b[ab];

	printf("sizeof = %d\n",sizeof(b));
	time_t now;
	struct tm newyear;
	double seconds;

	time(&now); /* get current time; same as: now = time(NULL)  */
	int a = now;

	newyear = *localtime(&now);

	newyear.tm_hour = 0;
	newyear.tm_min = 0;
	newyear.tm_sec = 0;
	newyear.tm_mon = 0;
	newyear.tm_mday = 1;

	seconds = difftime(now, mktime(&newyear));

//	INT8_MIN
//	INT_MIN

	printf("%.f seconds since new year in the current timezone.\n", seconds);

	time_t rawtime,rawtime1;
	struct tm * timeinfo,*gtime;

	time(&rawtime);
	time(&rawtime1);
	timeinfo = localtime(&rawtime);

	/*会相互影响，太诡异了 todo */
	printf("Current local time and date: %s\n", asctime(timeinfo));
	gtime = gmtime(&rawtime1);
	printf("Current gtime time and date: %s\n", asctime(gtime));

	return 0;
}
