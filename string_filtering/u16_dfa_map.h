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

#ifndef _WORD_FILTER_
#define _WORD_FILTER_
#include "common.h"
#include <map>
#include <vector>

class U16DfaMap {
public:
    U16DfaMap(int level);
    ~U16DfaMap();

    int add(std::u16string &u16, int print);
    U16DfaMap *get(char16_t u16c);
    void dump();
    int isEnd();
    int find(std::u16string &u16, int print);

protected:
    std::map<char16_t, U16DfaMap *> u16_map;
    int level;
    int is_end;

public:
    static void test_static();
    static void test_dynamic(int u16_string_range_min, int u16_string_range_max, int u16_string_len_max, int num_u16_string_gen);
};


#endif
