//
//  FilterDirtyWord.cpp
//  word
//
//  Created by zerocc on 2019/2/21.
//  Copyright © 2019年 zerocc. All rights reserved.
//

#include "FilterDirtyWord.hpp"

// 加载词库
std::vector<std::string> FilterDirtyWord:: loadDirtyWord(std::string filePath) {
    
    std::ifstream ifs;
    std::vector<std::string> dirtyWord;
    dirtyWord.reserve(255);
    std::string word;
    ifs.open(filePath);
    while (std::getline(ifs, word)) {
        dirtyWord.emplace_back(word);
    }
    ifs.close();
    
    return dirtyWord;
}

static int GetUtf8LetterNumber(const char *s) {
    int i = 0, j = 0;
    while (s[i]) {
        if ((s[i] & 0xc0) != 0x80) j++;
        i++;
    }
    return j;
}
// 创建
void CreateFilteredWordTree(const std::vector<std::string> &filteredWord, node *root)
{
    if (root == nullptr)
        return;
    
    for (auto w : filteredWord)
    {
        if (w.empty())
            continue;
        
        auto currentNode = root;
        int index = 0;
        while (index < w.length())
        {
            node *find = currentNode->findNextNode(w[index]);
            if (find != nullptr)
                currentNode = find;
            else
            {
                auto newNode = new node(w[index]);
//                newNode->nextNodeVector->reserve(3);
                currentNode->nextNodeVector->emplace_back(newNode);
                currentNode = newNode;
            }
            
            index++;
            if (index == w.length())
            {
                currentNode->hasEnd = true;
                currentNode->wordNum = (int)w.length();
                currentNode->uft8Num = GetUtf8LetterNumber(w.c_str());
            }
        }
    }
}

void CreateACAutomation(node *root)
{
    if (root == nullptr)
        return;
    
    std::queue<node*> q;
    for (auto v : *root->nextNodeVector)
    {
        v->failNode = root;
        q.push(v);
    }
    
    while (!q.empty())
    {
        auto currentNode = q.front();
        q.pop();
        for (auto v : *currentNode->nextNodeVector)
        {
            auto failNode = currentNode->failNode;
            while (failNode != nullptr)
            {
                node *find = failNode->findNextNode(v->w);
                if (find != nullptr)
                {
                    v->failNode = find;
                    break;
                }
                
                failNode = failNode->failNode;
            }
            
            if (failNode == nullptr)
                v->failNode = root;
            
            q.push(v);
        }
    }
}


void FilterDirtyWord:: replaceDirtyWord(const std::string &input,std::vector<std::string> filteredWord, std::string &output) {
    output = input;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    
    // 1.
    start = std::chrono::system_clock::now();
    auto filteredWordTree = new node('\0');
    filteredWordTree->nextNodeVector->reserve(255);
    CreateFilteredWordTree(filteredWord, filteredWordTree);
    end = std::chrono::system_clock::now();
    
    // 2.
    start = std::chrono::system_clock::now();
    CreateACAutomation(filteredWordTree);
    end = std::chrono::system_clock::now();

    // 3.
    start = std::chrono::system_clock::now();
    if (input.empty() || filteredWordTree == nullptr || filteredWordTree->nextNodeVector->size() == 0)
        return;
    
    int index = 0;
    int lastMarkIndex = -1;
    auto currentNode = filteredWordTree;
    while (index < output.length())
    {
        node *find = currentNode->findNextNode(output[index]);
        while (find == nullptr && currentNode->failNode != nullptr)
        {
            currentNode = currentNode->failNode;
            find = currentNode->findNextNode(output[index]);
        }
        
        if (find == nullptr)
        {
            currentNode = filteredWordTree;
            index++;
            continue;
        }
        
        currentNode = find;
        if (find->hasEnd)
        {

            int start = lastMarkIndex + 1 > index - find->wordNum + 1 ? lastMarkIndex + 1 : index - find->wordNum + 1;
            output=output.erase(start,index-start+1);
            output.insert(start,find->uft8Num,'*');
            index = start+find->uft8Num-1;
            lastMarkIndex = index;
            currentNode = filteredWordTree;
        }
        index++;
    }
}

