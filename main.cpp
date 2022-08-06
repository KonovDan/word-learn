/**
 * @file main.cpp
 * @author konovdan
 * @brief 
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cstring>

#define MAX_WORDS 100

// Globals
//>------------------------------------------------------------------------------------------------
struct Word
{
    int index;
    char * enWord;
    char * ruWord;
};

struct Word words[MAX_WORDS];

// Predefinitions
//>------------------------------------------------------------------------------------------------
int get_word_amount(FILE * file);
std::string get_line(FILE * file);
void get_words(FILE * file);


// Main logic
//>------------------------------------------------------------------------------------------------
int main(int argc, char * argv[])
{
    argc = 2;                                                                                      // Temporary

    if (argc != 2)
    {
        printf("Usage: ./main wordlist.txt\n");
        return 1;
    }

    FILE * file = fopen("words.txt","r");                                                          // Temporary
    if (file == NULL)
    {
        printf("Unable to open \"words\" file\n");
        return 2;
    }
    
    get_words(file);

    return 0;
}


// Helping function
//>------------------------------------------------------------------------------------------------
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

void get_word(std::string line, struct Word word)                                                  // TODO
{
    std::string value = "";

    int i = 0;
    while (i != 2)
    {
        char ch = fgetc(file);
        if (ch == ';')
        {
            i++;
            switch (i)
            {
            case 1:
                word.enWord = value;
                value = "";
                break;
            
            case 2:
                word.ruWord = value;
                break;
            }
        }
        else value = value + ch;

    }
};

void get_words(FILE * file)                                                                        // TODO

{
    int amount = get_word_amount(file); 

    // Reads file line by line
    for (int i = 0; i < amount; i++)
    {
        get_word(get_line(file), words[i]);
    }
}

