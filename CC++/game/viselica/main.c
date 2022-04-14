#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "print_read.h"
#include "viselitca.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("������, ������� ����, ����� ������� � ���� ��������!!\n");
    printf("�������:\n"
           "1 - ������ ����\n"
           "2 - ����������� � ���������\n"
           "3 - ���������� ������ ����\n"
           "4 - ��������� ����\n");

    int res, mode;
    struct TextInfo Rules, Words;
    struct words_arr  Guess;
    Rules.buf = NULL;
    Words.buf = NULL;
    Guess.words = NULL;

    while(1) {
        res = scanf("%d", &mode);
        if(res != 1) {
            printf("������ �����!\n������� ������!");
            return 0;
        }
        switch(mode) {
        case(1):
            start_game(&Guess, &Words, NULL);
            break;

        case(2):
            print_rules(&Rules, NULL);
            break;

        case(3):
            look_at_words(&Guess, &Words, NULL);
            break;

        case(4):
            printf("������� �� ����!\n��� �����!\n");
            return 0;
        }
        printf("\n��������?\n������� �������!\n");

    }

    return 0;
}
