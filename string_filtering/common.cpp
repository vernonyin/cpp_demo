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


#include "common.h"
#include <random>
#include <codecvt>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <locale>
#include <map>
#include <stdarg.h>
#include <time.h>

static char _logstr[4096];

void __log(const char *file, int line, const char *fmt, ...)
{
	va_list args;
	int n;
	if (strlen(fmt) == 0) {
		memset(_logstr, 0, sizeof(_logstr));
		return;
	}
	va_start(args, fmt);
	if (file && line) {
		snprintf(_logstr, sizeof(_logstr)-1, "%s(%d): ", file, line);
		n = strlen(_logstr);
		vsnprintf (_logstr+n, sizeof(_logstr)-n-1, fmt, args);
	} else {
		vsnprintf (_logstr, sizeof(_logstr)-1, fmt, args);
	}
	va_end(args);
    printf("%s", _logstr);
}


using namespace std;

u16string cvt_utf8_utf16(string &str) {
    wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
    u16string dest = convert.from_bytes(str.c_str());    
    return dest;
}

u16string cvt_utf8_utf16(char *u8c) {
    string u8;
    u8 += u8c;
    return cvt_utf8_utf16(u8);
}

string cvt_utf16_utf8(u16string &str) {
    wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> conversion;
    string mbs = conversion.to_bytes((char16_t *) str.c_str());
    return mbs;
}

string cvt_utf16c_utf8(char16_t u16c)
{
    u16string u16;
    u16 += u16c;
    return cvt_utf16_utf8(u16);
}

void utf16_hex(u16string &utf16) {
    unsigned int i;
    _log("dump %lu of utf-16 to hex\n", utf16.size());
    for (i=0; i<utf16.size(); i++) {
        if ((i%16)== 0) {
            _log("0x%08X ", i);
        }
        _log("%02X%02X "
            , (utf16[i] >> 8) & 0xFF
            , utf16[i] & 0xFF);
        if ((i+1)%16 == 0) {
            _log("\n");
        }
    }
    _log("\n");
}

int test_cvt_utf8_utf16() {
    u16string utf16;
    string str, utf8;
    
    _log("-------test_cvt_utf8_utf16-------------------------------------------------------\n");
    str = "嘿，你好;Hello;السلام عليكم;नमस्ते;今日は おっす;ਸਤਿ ਸ੍ਰੀ ਅਕਾਲ;안녕하십니까;chào bạn;வணக்கம் ;สวัสดี;નમસ્તે;မဂႆလာပၝ";
    cout << str << endl;

    utf16 = cvt_utf8_utf16(str);
    utf16_hex(utf16);
    
    utf8 = cvt_utf16_utf8(utf16);
    cout << utf8 << endl;

    _log("-------------------------------------------------------------------------------------\n\n");
    return strcmp(str.c_str(), utf8.c_str());
}

//C++11 built-in random function
//http://chino.taipei/note-2016-1020C-11-%E7%9A%84-Random-library-%E4%BD%A0%E9%82%84%E5%9C%A8%E7%94%A8rand-%E5%97%8E/
int rnd_gen(int min, int max)
{   
    static std::random_device rd;
    static std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

int test_rnd_gen() {
    static int max_count = 10000;
    static int max_num = 100;
    int *dist = (int *) calloc(1, sizeof(int) * max_num);
    int i;
    _log("-------test_rnd_gen-------------------------------------------------------\n");
    for (i=0; i<max_count; i++) {
        dist[rnd_gen(0, max_num)]++;
    }
    for (i=0; i<max_num; i++) {
        if ((i%16)== 0) {
            _log("0x%08X ", i);
        }
        _log("%02d=%03d ", i, dist[i]);
        if ((i+1)%16 == 0) {
            _log("\n");
        }
    }
    _log("\n-------------------------------------------------------------------------------------\n\n");
    free(dist);
    return 0;
}

u16string random_u16_string_generator(int u16_range_min, int u16_range_max, int u16_string_len_max)
{
    int i;
    int gen_num = 2 + rnd_gen(0, u16_string_len_max - 1);
    u16string u16;
    //_log("gen_num: %d\n", gen_num);
    for (i=0; i<gen_num; i++) {
        u16 += (char16_t)rnd_gen(u16_range_min, u16_range_max);
    }
    return u16;
}

int test_random_u16_string_generator(int u16_range_min, int u16_range_max, int u16_string_len_max)
{
    u16string u16 = random_u16_string_generator(u16_range_min, u16_range_max, u16_string_len_max);
    string u8 = cvt_utf16_utf8(u16);

    _log("-------test_random_u16_string_generator-------------------------------------------------------\n");
    cout << u8 << endl;
    utf16_hex(u16);
    _log("-------------------------------------------------------------------------------------\n\n");

    return 0;
}

string &leveled_space(unsigned int lv) {
    static map<int, string> lv_space;
    unsigned int i = 0;
    string s = "";

    if (lv == 0) {
        lv_space[lv] = string("");
    } else if ((s = lv_space[lv]) == "") {
        for (i=0; i<lv; i++) {
            s += "   ";
        }
        lv_space[lv] = s;
    }

    return lv_space[lv];
}

u16string &filter_u16(unsigned int num)
{
    static map<int, u16string> filter_words;
    unsigned int i = 0;
    u16string s = u"";

    if (num == 0) {
        filter_words[num] = u"";
    } else if ((s = filter_words[num]) == u"") {
        for (i=0; i<num; i++) {
            s += u"*";
        }
        filter_words[num] = s;
    }

    return filter_words[num];
}

#define TICK_TIME_UNIT 1000000

int64_t tick_time()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (int64_t) ts.tv_sec*TICK_TIME_UNIT+ts.tv_nsec/1000;
}

double tick_time_diff_secs(int64_t t2, int64_t t1)
{
    return (t2 - t1)/(double)TICK_TIME_UNIT;
}

