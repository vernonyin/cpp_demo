#include "FilterDirtyWord.hpp"

static int GetUtf8LetterNumber(const char *s) {
    int i = 0, j = 0;
    while (s[i]) {
        if ((s[i] & 0xc0) != 0x80) j++;
        i++;
    }
    return j;
}


int main(int argc, char **argv)
{


    std::string input;
    std::string output;
    std::string filePath;
    filePath = "/Users/yin/code/cpp_demo/liang/word.txt";
    input = "avxxxxav金融客户资料转让";
    std::cout<<GetUtf8LetterNumber(input.c_str())<<std::endl;
    std::vector<std::string> dirtyWord;
    //
    FilterDirtyWord fw;
    fw.func();

    FilterDirtyWord* fw = new FilterDirtyWord();
    fw->func();


    dirtyWord = FilterDirtyWord::loadDirtyWord(filePath);

    FilterDirtyWord::replaceDirtyWord(input, dirtyWord, output);
    std::cout << "output: " << output << std::endl;
	return 0;
}
