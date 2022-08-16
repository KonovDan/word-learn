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

FILE *fileptr;
struct Word *wordptr;

// Predefinitions
//>------------------------------------------------------------------------------------------------
void load_words(void);
int get_word_amount(void);

// Main logic
//>------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    argc = 2; // Temporary

    if (argc != 2)
    {
        printf("Usage: ./main wordlist.txt\n");
        return 1;
    }

    fileptr = fopen("words.txt", "r"); // Temporary
    if (fileptr == NULL)
    {
        printf("Unable to open \"words\" file\n");
        return 2;
    }

    load_words();

    printf("%s", wordptr->enWord);

    return 0;
}

// Helping function
//>------------------------------------------------------------------------------------------------

int get_word_amount(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-16");

    char ch = 0;
    int value = 0;
    while (ch + 48 != '\n')
    {
        value = value * 10 + ch;
        ch = fgetc(fileptr) - 48;
    };
    return value;
};

void load_words(void)
{

    for (int n = 0; n < get_word_amount(); n++)
    {
        Word *tmp = malloc(sizeof(Word));
        char ch = fgetc(fileptr), i = 0, j = 0;
        char *wrd = malloc(sizeof(char) * 20);
        
        while (ch != EOF && ch != '\n')
        {
            if (ch == ' ')
            {
                tmp->enWord = (char *) wrd;
                wrd = malloc(sizeof(char) * 20);
            }
            else
            {
                wrd[i] = ch;
            }

            ch = fgetc(fileptr); i++;
        }
        tmp->ruWord = wrd;
        tmp->next = wordptr;
        wordptr = tmp;
    }
};
