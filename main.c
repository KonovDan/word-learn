/**
 * @file main.c
 * @author konovdan
 * @brief
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

#define MAX_WORDS 100

// Globals
//>------------------------------------------------------------------------------------------------
typedef struct Word
{
    int index;
    char *enWord;
    char *ruWord;
    struct Word *next;
} Word;

FILE *filePtr;
struct Word *wordListPtr;

// Predefinitions
//>------------------------------------------------------------------------------------------------
Word * load_words(Word * wordListPtr, FILE * filePtr);
int get_word_amount(FILE * filePtr);

// Main logic
//>------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{


    FILE * filePtr = fopen("words.txt", "r"); // Temporary
    if (filePtr == NULL)
    {
        printf("Unable to open \"words\" file\n");
        return 1;
    }

    Word * listOfWords = load_words(NULL,filePtr);


    return 0;
}

// Helping function
//>------------------------------------------------------------------------------------------------

int get_word_amount(FILE * filePtr)
{
    setlocale(LC_ALL, "ru_RU.UTF-16");

    char ch = 0;
    int value = 0;
    while (ch + 48 != '\n')
    {
        value = value * 10 + ch;
        ch = fgetc(filePtr) - 48;
    };
    return value;
};

Word * load_words(Word * wordListPtr, FILE * filePtr)
{
    int wordAmount = get_word_amount(filePtr);

    for (int n = 0; n < wordAmount; n++)
    {
        char word_1[50] = {0};
        char word_2[50] = {0};

        struct Word * word = (struct Word *) malloc(sizeof(Word));
        word -> index = n;
        word -> next = wordListPtr;

        int i = 0;
        for(char ch = fgetc(filePtr); ch != ' ';ch = fgetc(filePtr), i++)
        {
            word_1[i] = ch;
        }
        word_1[i+1] = '\0';
        word -> enWord = word_1;

        i = 0;
        for(char ch = fgetc(filePtr); ch != '\n';ch = fgetc(filePtr), i++)
        {
            word_2[i] = ch;
        }
        word_1[i+1] = '\0';
        word -> ruWord = word_2;
        
        wordListPtr = word;
    }

    return wordListPtr;
};
