///*************************************************************************\
//*                  Copyright (C) Michael Kerrisk, 2015.                   *
//*                                                                         *
//* This program is free software. You may use, modify, and redistribute it *
//* under the terms of the GNU General Public License as published by the   *
//* Free Software Foundation, either version 3 or (at your option) any      *
//* later version. This program is distributed without any warranty.  See   *
//* the file COPYING.gpl-v3 for details.                                    *
//\*************************************************************************/
//
///* Listing 4-3 */
//
//#include <sys/stat.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <ctype.h>
//#include <stdio.h>
//#include <memory.h>
//#include <stdlib.h>
//#include <errno.h>
//#define GN_NONNEG       01      /* Value must be >= 0 */
//#define GN_GT_0         02      /* Value must be > 0 */
//
//                                /* By default, integers are decimal */
//#define GN_ANY_BASE   0100      /* Can use any base - like strtol(3) */
//#define GN_BASE_8     0200      /* Value is expressed in octal */
//#define GN_BASE_16    0400      /* Value is expressed in hexadecimal */
//
//static void
//gnFail(const char *fname, const char *msg, const char *arg, const char *name)
//{
//    fprintf(stderr, "%s error", fname);
//    if (name != NULL)
//        fprintf(stderr, " (in %s)", name);
//    fprintf(stderr, ": %s\n", msg);
//    if (arg != NULL && *arg != '\0')
//        fprintf(stderr, "        offending text: %s\n", arg);
//
//    exit(EXIT_FAILURE);
//}
//
//static long
//getNum(const char *fname, const char *arg, int flags, const char *name)
//{
//    long res;
//    char *endptr;
//    int base;
//
//    if (arg == NULL || *arg == '\0')
//        gnFail(fname, "null or empty string", arg, name);
//
//    base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 :
//                        (flags & GN_BASE_16) ? 16 : 10;
//
//    errno = 0;
//    res = strtol(arg, &endptr, base);
//    if (errno != 0)
//        gnFail(fname, "strtol() failed", arg, name);
//
//    if (*endptr != '\0')
//        gnFail(fname, "nonnumeric characters", arg, name);
//
//    if ((flags & GN_NONNEG) && res < 0)
//        gnFail(fname, "negative value not allowed", arg, name);
//
//    if ((flags & GN_GT_0) && res <= 0)
//        gnFail(fname, "value must be > 0", arg, name);
//
//    return res;
//}
//
//long
//getLong(const char *arg, int flags, const char *name)
//{
//    return getNum("getLong", arg, flags, name);
//}
//
//
//int
//main_fileio2(int argc, char *argv[])
//{
//    size_t len;
//    off_t offset;
//    int fd, ap, j;
//    char *buf;
//    ssize_t numRead, numWritten;
//
//    if (argc < 3 || strcmp(argv[1], "--help") == 0)
//        printf("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
//                 argv[0]);
//
//    fd = open(argv[1], O_RDWR | O_CREAT);                     /* rw-rw-rw- */
//    if (fd == -1)
//    	printf("open");
//
//    for (ap = 2; ap < argc; ap++) {
//        switch (argv[ap][0]) {
//        case 'r':   /* Display bytes at current offset, as text */
//        case 'R':   /* Display bytes at current offset, in hex */
//            len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
//
//            buf = malloc(len);
//            if (buf == NULL)
//                printf("malloc");
//
//            numRead = read(fd, buf, len);
//            if (numRead == -1)
//                printf("read");
//
//            if (numRead == 0) {
//                printf("%s: end-of-file\n", argv[ap]);
//            } else {
//                printf("%s: ", argv[ap]);
//                for (j = 0; j < numRead; j++) {
//                    if (argv[ap][0] == 'r')
//                        printf("%c", isprint((unsigned char) buf[j]) ?
//                                                buf[j] : '?');
//                    else
//                        printf("%02x ", (unsigned int) buf[j]);
//                }
//                printf("\n");
//            }
//
//            free(buf);
//            break;
//
//        case 'w':   /* Write string at current offset */
//            numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
//            if (numWritten == -1)
//                printf("write");
//            printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
//            break;
//
//        case 's':   /* Change file offset */
//            offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
//            if (lseek(fd, offset, SEEK_SET) == -1)
//                printf("lseek");
//            printf("%s: seek succeeded\n", argv[ap]);
//            break;
//
//        default:
//        	printf("Argument must start with [rRws]: %s\n", argv[ap]);
//        }
//    }
//
//    if (close(fd) == -1)
//        printf("close");
//
//    exit(EXIT_SUCCESS);
//}
