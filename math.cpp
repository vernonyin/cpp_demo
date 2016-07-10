/* fmax example */
#include <stdio.h>      /* printf */
#include <math.h>       /* fmax */
#include <stdint.h>
#include <ctype.h>

int main_math() {
	printf("fmax (100.0, 1.0) = %f\n", fmax(100.0, 1.0));
	printf("fmax (-100.0, 1.0) = %f\n", fmax(-100.0, 1.0));
	printf("fmax (-100.0, -1.0) = %f\n", fmax(-100.0, -1.0));

	 int i=0;
	  char str[]="Test 123456 String.\n";
	  char c;
	  while (str[i])
	  {
	    c=str[i];
	    if (islower(c)) c=toupper(c);
	    putchar (c);
	    i++;
	  }
	return 0;
}
