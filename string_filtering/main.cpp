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

#include "u16_dfa_map.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

//0x4E00 ~ 0x9FCC: https://unicode-table.com/en/blocks/cjk-unified-ideographs/
#define U16_STRING_RANGE_MIN 0x4E00
#define U16_STRING_RANGE_MAX 0x9FCC
#define U16_STRING_LEN_MAX 6
#define NUM_U16_STRING_GEN 2000000

using namespace std;

static int test() {
    if (test_cvt_utf8_utf16()) {
        _log("failed to test_cvt_utf8_utf16\n");
        return -1;
    }

    test_rnd_gen();
    test_random_u16_string_generator(U16_STRING_RANGE_MIN, U16_STRING_RANGE_MAX, U16_STRING_LEN_MAX);
    return 0;
}

int main(int argc, char *argv[]) {
    string u8;
    std::vector<std::u16string> picked_up;

    if (argc >= 2 && strcmp(argv[1], "-t") == 0) {
        //test function
        return test();
    } else if (argc >= 2 && strcmp(argv[1], "-s") == 0) {
        //test static
        U16DfaMap::test_static();
    } else {
        //test dynamic
        U16DfaMap::test_dynamic(U16_STRING_RANGE_MIN, U16_STRING_RANGE_MAX, U16_STRING_LEN_MAX, NUM_U16_STRING_GEN);
    }
   
    _log("press any key to exit.\n");
    getchar();
    return 0;
}
