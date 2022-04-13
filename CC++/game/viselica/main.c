#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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

    int mode, res;

    res = scanf("%d", &mode);

    if(res != 1) {
        printf("������ �����!\n������� ������!");
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
        printf("������� �� ����!\n��� �����!\n");
        return 0;




    }

    return 0;
}
