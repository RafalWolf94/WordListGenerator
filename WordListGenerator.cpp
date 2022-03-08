//
// Created by Rafal on 08.03.2022.
//

#include <string>
#include "WordListGenerator.h"

std::string WordListGenerator::GetFilePath(const int *wordQty) {
    return basePath + std::to_string(*wordQty) + fileExtension;
}

void WordListGenerator::GenerateTemplate(char *baseLetters) const {
    int charIndex = 33;
    int quantityZero = 0;
    for (int i = quantityZero; i < numberOfValues; i++) {
        int index = charIndex + i;
        baseLetters[i] = (char) index;
    }
}

void WordListGenerator::GenerateWordLists(int *wordQty) {
    std::vector<std::string> lastWordList;
    std::fstream lastFile;
    std::ofstream newFile;
    char letters[numberOfValues];
    GenerateTemplate(letters);
    std::string path = GetFilePath(wordQty);
    int wordQtyIncremented = *wordQty;
    wordQtyIncremented++;
    std::string newPath = GetFilePath(&wordQtyIncremented);
    newFile.open(newPath, std::ios_base::out);
    lastFile.open(path, std::ios::in);
    if (lastFile.is_open()) {
        std::string lastWord;
        while (std::getline(lastFile, lastWord)) {
            for (char sign: letters) {
                std::string word = lastWord + sign;
                newFile << word;
                newFile << "\n";
            }
        }
        lastFile.close();
    } else {
        for (char sign: letters) {
            std::string word = std::string(1, sign);
            newFile << word;
            newFile << "\n";
        }
    }

    newFile.close();
}

