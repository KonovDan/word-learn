#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word
{
    int index;
    char * enWord;
    char * ruWord;
}word;

int main(void)
{
    FILE * file = fopen("./words","r");
    if (file == NULL)
    {
        printf("Unable to open \"words\" file\n");
        return 1;
    }

    // TODO

    return 0;
}
