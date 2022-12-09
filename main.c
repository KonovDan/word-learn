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
FILE * open_file(char * path) ;
int get_word_amount(FILE * file);
Word * load_words(char * path);

// Main logic
//>------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	Word * list = load_words("words.txt");

    	exit(0);
}

// Helping function
//>------------------------------------------------------------------------------------------------
FILE * open_file(char * path)
{
	FILE * filePtr = fopen(path, "r");
    	if (filePtr == NULL)
    	{
        	printf("Unable to open \"words\" file\n");
        	exit(1);
    	}
	return filePtr;
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

Word * load_words(char * path)
{
    	int wordAmount = get_word_amount(open_file(path));
	Word * wordList = NULL;
	FILE * file = open_file("words.txt");

    	for (int n = 0; n < wordAmount / 2; n++)
    	{
        	char word_1[50] = {0};
        	char word_2[50] = {0};

        	Word * word = (Word *) malloc(sizeof(Word));
        	word -> index = n;
	        word -> next = wordListPtr;

	        int i = 0;
	        for(char ch = fgetc(file); ch != ' ';ch = fgetc(file), i++)
	        {	
	            word_1[i] = ch;
	        }
	        word_1[i+1] = '\0';
	        word -> enWord = word_1;

	        i = 0;
	        for(char ch = fgetc(file); ch != '\n';ch = fgetc(file), i++)
	        {
			word_2[i] = ch;
	        }
	        word_1[i+1] = '\0';
	        word -> ruWord = word_2;
		
	        wordListPtr = word;
	}

    	return wordListPtr;
}

