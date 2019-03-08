/*
 * Copyright (c) 2018, Gary Huang (deepkh@gmail.com)
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _COMMON_
#define _COMMON_
#include <string>
#include <inttypes.h>

void __log(const char *file, int line, const char *fmt, ...);
#define _log(fmt, ...) __log(NULL, 0, fmt, ##__VA_ARGS__)
#define _log_line(fmt, ...) __log(__FILE__, __LINE__, fmt, ##__VA_ARGS__)

std::u16string cvt_utf8_utf16(std::string &str);
std::u16string cvt_utf8_utf16(const char *u8c);
std::string cvt_utf16_utf8(std::u16string &str);
std::string cvt_utf16c_utf8(char16_t u16c);
void utf16_hex(std::u16string &utf16);
int test_cvt_utf8_utf16();

int rnd_gen(int min, int max);
int test_rnd_gen();

std::u16string random_u16_string_generator(int u16_range_min, int u16_range_max, int u16_string_len_max);
int test_random_u16_string_generator(int u16_range_min, int u16_range_max, int u16_string_len_max);

std::string &leveled_space(unsigned int lv);
std::u16string &filter_u16(unsigned int num);

//1/1000000000 sec
int64_t tick_time();

// secs
double tick_time_diff_secs(int64_t t2, int64_t t1);
#endif
