#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <windows.h>


#include "print_read.h"

long FileSize(FILE *Text)
{
    fseek(Text, SEEK_SET, SEEK_END);

    long sizeFile = 0;
    sizeFile = ftell(Text);

    rewind(Text);

    return sizeFile;
}

int print_rules(char *filename)
{
    struct TextInfo Rules;

    ReadInBuF(&Rules, 2, filename);
    printf(Rules.buf);

    return 0;
}

int look_at_words(char *filename)
{
    struct TextInfo Words;
    ReadInBuF(&Words, 1, filename);

    return 0;
}

FILE *open(int param, char *filename)
{
    FILE *TextC;

    if(filename != NULL) {
        TextC = fopen(filename, "r");
        return TextC;

    } else {
        switch(param) {
        case(1):
            TextC = fopen("words.txt", "r");
            return TextC;
        case(2):
            TextC = fopen("rules.txt", "r");
            return TextC;
        }

    }
    return NULL;
}

int ReadInBuF(struct TextInfo *Text, int param, char *filename) //!TO DO praram-> enum
{
    FILE *TextC;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TextC = open(param, filename);

    /*if(param == 2) {
        if(filename != NULL) {
            TextC = fopen(filename, "r");
        }else {
            TextC = fopen("rules.txt", "r");
        }
    }*/


    long sizeText = FileSize(TextC);
    Text->Text_size = sizeText;

    if((Text->buf = (char*)calloc(sizeText + 1, sizeof(char))) == NULL) {
        return -1;
    }

    fread(Text->buf, 1, sizeText, TextC);

    fclose(TextC);

    return 0;

}
