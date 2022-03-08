#include <iostream>
#include "WordListGenerator.h"

int main() {
    WordListGenerator generator;
    for (int i = 0; i < 4; i++) {
        std::cout << i << std::endl;
        generator.GetLastWordList(&i);
    }
    return 0;
}



