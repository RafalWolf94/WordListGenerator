//
// Created by Rafal on 08.03.2022.
//

#ifndef UNTITLED_WORDLISTGENERATOR_H
#define UNTITLED_WORDLISTGENERATOR_H


#include <vector>
#include <fstream>

class WordListGenerator {
private:
    std::string basePath = R"(C:\Users\Rafal\test\word)";
private:
    std::string fileExtension = ".txt";
private:
    int numberOfValues = 94;

public:
    std::string GetFilePath(const int *wordQty);

public:
    WordListGenerator() = default;

public:
    ~WordListGenerator() = default;

public:
    void GenerateTemplate(char *baseLetters) const;

    void GenerateWordLists(int *wordQty);
};


#endif //UNTITLED_WORDLISTGENERATOR_H
