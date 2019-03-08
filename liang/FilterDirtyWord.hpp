//
//  FilterDirtyWord.hpp
//  word
//
//  Created by zerocc on 2019/2/21.
//  Copyright © 2019年 zerocc. All rights reserved.
//

#ifndef FilterDirtyWord_hpp
#define FilterDirtyWord_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <fstream>

struct node {
    std::vector<node*> *nextNodeVector = new std::vector<node*>;
    node *failNode = nullptr;
    char w;
    bool hasEnd = false;
    int wordNum = 0;
    int uft8Num = 0;
    node(char w) :w(w) {}
    
    node *findNextNode(char w)
    {
        for (auto v : *nextNodeVector)
            if (v->w == w)
                return v;
        
        return nullptr;
    }
};

class FilterDirtyWord  {
    
public:
    static std::vector<std::string> loadDirtyWord(std::string filePath);
    static void replaceDirtyWord(const std::string &input, std::vector<std::string> filteredWord, std::string &output);
};

#endif /* FilterDirtyWord_hpp */
