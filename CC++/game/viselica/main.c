#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "print_read.h"
#include "viselitca.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Привет, Дорогой Друг, давай сыграем в игру Виселица!!\n");
    printf("Нажмите:\n"
           "1 - Начало игры\n"
           "2 - Ознакомится с правилами\n"
           "3 - Посмотреть список слов\n"
           "4 - Завершить игру\n");

    int res, mode;

    while(1) {
        res = scanf("%d", &mode);
        if(res != 1) {
            printf("Ошибка ввода!\nНачните заново!");
            return 0;
        }
        switch(mode) {
        case(1):
            start_game();
            break;

        case(2):
            print_rules();
            break;

        case(3):
            look_at_words();
            break;

        case(4):
            printf("Спасибо за игру!\nЖду снова!\n");
            return 0;
        }
        printf("\nПродожим?\nВведите команду!\n");

    }

    return 0;
}
