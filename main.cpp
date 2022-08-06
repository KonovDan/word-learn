#include <iostream>
#include <cstring>

struct word
{
    int index;
    char * enWord;
    char * ruWord;
};

int get_word_amount(FILE * file);
std::string get_line(FILE * file);
void get_words(FILE * file);

int main(int argc, char * argv[])
{
    argc = 2;
    if (argc != 2)
    {
        printf("Usage: ./main wordlist.txt\n");
        return 1;
    }

    FILE * file = fopen("words.txt","r");
    if (file == NULL)
    {
        printf("Unable to open \"words\" file\n");
        return 2;
    }

    // std::cout << get_line(file) << std::endl;
    
    get_words(file);

    return 0;
}


int get_word_amount(FILE * file)
{
    char ch = 0;
    int value = 0;
    while (ch + 48 != '\n')
    {
        value = value * 10 + ch;
        ch = fgetc(file) - 48;
    };
    return value;
};


std::string get_line(FILE * file)
{
    std::string value = "";
    char ch = fgetc(file);

    while (ch != '\n' and ch != EOF)
    {
        value = value + ch;
        ch = fgetc(file);
    }

    return value;
};

void get_words(FILE * file)
{
    int amount = get_word_amount(file);
    
    for (int i = 0; i < amount; i++)
    {
        if (i > 10) break;
        std::cout<< get_line(file) << '\n';
    }
}