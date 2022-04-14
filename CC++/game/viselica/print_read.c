#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>


#include "print_read.h"

const int START_SIZE = 10;


long FileSize(FILE *Text)
{
    fseek(Text, SEEK_SET, SEEK_END);
    long sizeFile = 0;
    sizeFile = ftell(Text);
    rewind(Text);

    return sizeFile;
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

    long sizeText = FileSize(TextC);
    Text->Text_size = sizeText;

    if((Text->buf = (char*)calloc(sizeText + 1, sizeof(char))) == NULL) {
        return -1;
    }

    fread(Text->buf, 1, sizeText, TextC);
    fclose(TextC);

    return 0;
}



int print_rules(struct TextInfo *Rules, char *filename)
{
    if(Rules->buf == NULL) {
        ReadInBuF(Rules, 2, filename);
    }

    printf(Rules->buf);

    return 0;
}

int buf_to_words(struct TextInfo *Words, struct words_arr *New_arr)
{
    int j = 0;

    New_arr->words = calloc(START_SIZE, sizeof(char*));
    New_arr->capacity = START_SIZE;
    New_arr->words[j++] = Words->buf;


    for(int i = 0; i < Words->Text_size; i++) {
        if(isspace(Words->buf[i])) {
            New_arr->words[j++] = &(Words->buf[i + 1]);
            Words->buf[i] = '\0';
        }

        if(j - 2 >= New_arr->capacity) {
            New_arr->words = realloc(New_arr->words, New_arr->capacity * 2);
            New_arr->capacity *= 2;
        }
    }

    New_arr->size = j;

    return 0;
}

int look_at_words(struct words_arr *Guess, struct TextInfo *Words, char *filename)
{
    int res, num;

    if(Guess->words == NULL) {
        if(Words->buf == NULL) {
            ReadInBuF(Words, 1, filename);
        }

        buf_to_words(Words, Guess);
    }

    printf("Сколько слов Вы хотите увидеть?\n");

    res = scanf("%d", &num);
    assert(res == 1);

    if(num > Guess->size) {
        printf("Слишком много хотите)\n");
    } else {
        for(int i = 0; i < num; i++) {
            printf("%s ", Guess->words[i]);
        }

    }

    return 0;
}
