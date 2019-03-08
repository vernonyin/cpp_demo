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

using namespace std;


U16DfaMap::U16DfaMap(int level)
:level(level)
,is_end(0)
{

}

U16DfaMap::~U16DfaMap()
{
    map<char16_t, U16DfaMap *>::iterator it = u16_map.begin();
    //string space = leveled_space(level);
    while (it != u16_map.end()) {
        //_log("%sdelete %s\n", space.c_str(), cvt_utf16c_utf8(it->first).c_str());
        delete it->second;
        it = u16_map.erase(it);
    }
}

//ret = 0 -> no added;
//ret = 1 -> added;
//ret = -1 -> error
int U16DfaMap::add(std::u16string &u16, int print)
{
    char16_t u16c;
    U16DfaMap *node;
    u16string u16_next;
    const char *space = leveled_space(level).c_str();
    int lastest_ch = (u16.size() - 1) <= 0 ? 1 : 0;

    //add new node
    u16c = u16[0];
    node = get(u16c);
    if (node == NULL) {
        node = new U16DfaMap(level+1);
        u16_map[u16c] = node;
        if (print) {
            _log("%sadd %s \n", space, cvt_utf16c_utf8(u16c).c_str());
        }

        //lastest char, lastest node, is_end = 1
        if (lastest_ch) {
            if (print) {
                _log("%sis_end=1, ret 1 \n", space);
            }
            node->is_end = 1;
            return 1;
        }

    //get exists node
    } else {
        if (print) {
            _log("%sget %s \n", space, cvt_utf16c_utf8(u16c).c_str());
        }

        //lastest char, not lastest node, is_end = 0, no added
        if (lastest_ch) {
            if (print) {
                _log("%sis_end=0, no added, ret 0 \n", space);
            }
            return 0;
        }
    }

    //not lastest node, keep going
    u16_next = u16.substr(1, u16.size() - 1);
    node->is_end = 0;
    return node->add(u16_next, print);
}

U16DfaMap *U16DfaMap::get(char16_t u16c)
{
    return u16_map[u16c];
}

void U16DfaMap::dump()
{
    map<char16_t, U16DfaMap *>::iterator it;
    string space = leveled_space(level);
    
    for (it = u16_map.begin(); it != u16_map.end(); ++it) {
        _log("%s", space.c_str());
        _log("%s %d\n", cvt_utf16c_utf8(it->first).c_str(), it->second->isEnd());
        it->second->dump();
    }
}

int U16DfaMap::isEnd()
{
    return is_end;
}

//ret = 0 -> found, but is_end = 0;
//ret = 1 -> found, is_end = 1
//ret = -1 -> not found
int U16DfaMap::find(std::u16string &u16, int print)
{
    char16_t u16c;
    U16DfaMap *node;
    u16string u16_next;
    int lastest_ch = (u16.size() - 1) <= 0 ? 1 : 0;
    string space = leveled_space(level);

    u16c = u16[0];
    node = get(u16c);

    //node not found
    if (node == NULL) {
        return -1;
    //get exists node
    } else {
        if (print) {
            _log("%sget %s \n", space.c_str(), cvt_utf16c_utf8(u16c).c_str());
        }

        //lastest char
        if (lastest_ch) {
            //lastest char, is_end = 1
            if (node->isEnd()) {
                if (print) {
                    _log("%sis_end=1, found str, ret 1 \n", space.c_str());
                }
                return 1;
            }

            //lastest char, is_end = 0
            if (print) {
                _log("%sis_end=0, not end, ret 0 \n", space.c_str());
            }
            return 0;
        }
    }

    //not lastest node, keep going
    u16_next = u16.substr(1, u16.size() - 1);
    return node->find(u16_next, print);
}

void U16DfaMap::test_static()
{
    string u8a[] = {
        "甘",
        "甘寧娘親娘",
        "甘寧娘",
        "甘寧親娘",
        "甘寧",
        "甘寧的娘親",
        "甘寧的親娘",
        "甘寧的娘",
        "甘寧的娘親娘",
        "甘寧的娘親娘握指能打牆",
        "曹",
        "曹爽",
        "曹爽德",
        "曹爽德尖刀",
        "曹爽德尖刀一百塊",
        "曹爽德尖刀二百塊",
        "曹植白",
        "曹植",
        "曹植白",
        "曹植白素藍嬌",
        "曹植白樹懶",
        "曹植白花轎",
        "Yo!",
        "Yo!What's up",
        "Yo!What's up man",
        "Yo!What's up the fu*k man",
    };
    unsigned int i, len = 21/*25*/;
    U16DfaMap *root_map = new U16DfaMap(0);
    u16string u16;
   
    _log("-------U16DfaMap::test_static::add-------------------------------------------------------\n");
    for (i=0; i<len; i++) {
        _log("\ntry to add '%s'\n", u8a[i].c_str());
        u16 = cvt_utf8_utf16(u8a[i]);
        root_map->add(u16, 1);
    }
    _log("-------U16DfaMap::test_static::dump-------------------------------------------------------\n");
    root_map->dump();

    _log("-------U16DfaMap::test_static::find-------------------------------------------------------\n");

    for (i=0; i<len; i++) {
        _log("try to find '%s' ", u8a[i].c_str());
        u16 = cvt_utf8_utf16(u8a[i]);
        _log(" %s\n", root_map->find(u16, 0) == 1 ? "found" : " ");
    }

    _log("-------------------------------------------------------------------------------------\n\n");

    delete root_map;
}

void U16DfaMap::test_dynamic(int u16_string_range_min, int u16_string_range_max, int u16_string_len_max, int num_u16_string_gen)
{
    unsigned int i, j =0 ,pos;
    int ret;
    U16DfaMap *root_map = new U16DfaMap(0);
    u16string u16;
    string u8;

    map<int,int> test_u16_pos;
    string test_u16_word[] = {
        "有一",
        "神父",
        "很髒",
        "浪費生命",
        "神父旁邊",
        "關節炎",
        "醉漢",
     };
    unsigned int test_u16_word_len = 6;

    string test_text = "有一有一個滿身酒氣的醉漢上了一班公共汽車，他坐在一個神父旁邊。那個醉漢的襯衫很髒，他的臉上有女人的亮紅唇印，口袋放著空酒瓶，他拿出他的報紙閱讀，過了一會兒，他問神父說： 「神父，得關節炎的原因是什麼？」「這位先生，它是因為浪費生命、和妓女鬼混、酗酒和不自重所引起的。」神父如是說。「噢，原來如此！」醉漢喃喃自語後繼續閱讀報紙。神父想了一下後，又向醉漢道歉說：「對不起，我剛剛講話是不應該這麼直接的，你患關節炎有多久了？」「不是我，神父，我衹是在報紙上看到教皇得了關節炎。」";

    u16string test_text_u16 = cvt_utf8_utf16(test_text);
    u16string test_text_u16_filtered;
    int print = 0;
    int64_t t1,t2,t3,t4;

    _log("-------U16DfaMap::test_dynamic-------------------------------------------------------\n");
    _log("___origin text %d:\n", test_text_u16.size());
    _log("%s\n", test_text.c_str());
    //generate the randomly postion 
    for (i=0; i<test_u16_word_len; i++) {
        //guarantee we won't be duplicated
        while(1) {
            pos = rnd_gen(0, num_u16_string_gen - 1); 
            if (test_u16_pos[pos]) {
                _log("%d duplicated\n", pos);
                continue;
            }
            break;
        }
        test_u16_pos[pos] = 1;
    }
    
    _log("\n___adding num of %d u16 filter string ...\n", num_u16_string_gen);
    t1 = tick_time();
    //randomly generate the num_u16_string_gen of u16 string 
    for (i=0; i<(unsigned int) num_u16_string_gen; i++) {
        u16 = random_u16_string_generator(u16_string_range_min, u16_string_range_max, u16_string_len_max);
        root_map->add(u16, print);
        if (test_u16_pos[i]) {
            //add test_u16_word at pos of i
            u16 = cvt_utf8_utf16(test_u16_word[j]);
            t3 = tick_time();
            root_map->add(u16, print);
            t4 = tick_time();
            _log("add filter string %s at %d. cost:%f\n", test_u16_word[j].c_str(), i,  tick_time_diff_secs(t4, t3));
            j++;
        }
    }
    t2 = tick_time();
    _log("___adding done. total cost:%f\n", num_u16_string_gen, tick_time_diff_secs(t2, t1));

    t3 = tick_time();
    _log("\n___filtering the origin text ...\n", num_u16_string_gen);
    //find if the test_u16_word is find in test_text
    for (i=0; i<test_text_u16.size(); i++) {
        ret = 0;
        for (j=i+2; j<test_text_u16.size(); j++) {
            u16 = test_text_u16.substr(i, j - i);
            //_log("try to find %d-%d ", i, j - i);
            t1 = tick_time();
            ret = root_map->find(u16, print);
            t2 = tick_time();
            //_log(" %s\n", ret == 1 ? "found" : "");

            if (ret == 1) {
                test_text_u16_filtered += filter_u16(j - i);
                u8 = cvt_utf16_utf8(u16);
                _log("found filter string %s at %d. cost:%f\n", u8.c_str(), i, tick_time_diff_secs(t2, t1));
                i = j - 1;
                break;
            }
            //getchar();
        }

        if (ret != 1) {
            test_text_u16_filtered += test_text_u16[i];
        }
    }
    t4 = tick_time();

    _log("___filtering done %d: total cost:%f\n", test_text_u16_filtered.size(), tick_time_diff_secs(t4, t3));


    _log("\n___filtered results:\n");
    u8 = cvt_utf16_utf8(test_text_u16_filtered);
    _log("%s\n", u8.c_str());
    _log("-------------------------------------------------------------------------------------\n\n");
    delete root_map;
}


