/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 4-3 */

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <string.h>

/* 问题：
* write乱码: 	numWritten = write(fd, (&)buf, strlen(buf));
* 数组就是首地址  */
int main_fileio(int argc, char *argv[]) {
	size_t len = 10;
	off_t offset;
	int fd, ap, j;
	char *buf= "hello world";;
	ssize_t numRead, numWritten;

	fd = open("a.txt", O_RDWR | O_CREAT,
           S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
           S_IROTH | S_IWOTH);
	if (fd == -1) {
		printf("err %d\n", __LINE__);
		exit(0);
	}
	numWritten = write(fd, buf, strlen(buf));
	printf("write size=%ld,buf=%d\n", numWritten, &buf);
//
//	buf = new char[100];
//	numRead = read(fd, buf, len);
//	printf("read size=%ld,buf=%s\n", numRead, buf);

	if (close(fd) == -1){
		printf("close err");
	}

	return 0;
}
