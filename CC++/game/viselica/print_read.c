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

int print_rules()
{
    struct TextInfo Rules;

    ReadInBuF(&Rules, 2);
    printf(Rules.buf);

    return 0;
}

int ReadInBuF(struct TextInfo *Text, int param)
{
    FILE *TextC;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if(param == 2) {

        TextC = fopen("rules.txt", "r");
    }


    long sizeText = FileSize(TextC);
    Text->Text_size = sizeText;

    if((Text->buf = (char*)calloc(sizeText + 1, sizeof(char))) == NULL) {
        return -1;
    }

    fread(Text->buf, 1, sizeText, TextC);

    fclose(TextC);

    return 0;

}

int look_at_words()
{
    return 0;
}
