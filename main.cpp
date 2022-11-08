#include <iostream>
#include <cstring>

const char *PATH = "/home/user/code/word-learn/words.txt";
const char *MODE = "r";

void load_text(std::FILE * fPtr, std::string text);

int main(void)
{

    std::FILE *file = fopen(PATH, MODE);
    if (file == nullptr) {
        std::cout << "⛔ Unable to open file" << std::endl;
        return 1;
    } else {
        std::cout << "✅ File opened" << std::endl;
    }
    return 0;
}


void load_text(std::FILE * fPtr, std::string text) {
    char ch;
    while ((ch = std::fgetc(fPtr)) != EOF) {
        std::strcat(text, ch);
    }
}