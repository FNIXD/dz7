#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int is_leap_year(int year);
int day_of_week(int year);

int main(void)
{
    int year;
    int day;

    setlocale(LC_ALL, ".UTF8");

    printf("Введите год XXI века (2001-2100): ");
    if (scanf("%d", &year) != 1 || year < 2001 || year > 2100)
    {
        printf("Ошибка: нужно ввести год от 2001 до 2100.\n");
        return 1;
    }

    day = day_of_week(year);

    printf("1 сентября %d года - ", year);
    switch (day)
    {
    case 0:
        printf("понедельник\n");
        break;
    case 1:
        printf("вторник\n");
        break;
    case 2:
        printf("среда\n");
        break;
    case 3:
        printf("четверг\n");
        break;
    case 4:
        printf("пятница\n");
        break;
    case 5:
        printf("суббота\n");
        break;
    case 6:
        printf("воскресенье\n");
        break;
    }

    return 0;
}

int is_leap_year(int year)
{
    int leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    return leap;
}

int day_of_week(int year)
{
    int days;
    int day;

    days = (year - 2001) * 365 + (year - 1) / 4 - 500 + 243 + is_leap_year(year);
    day = days % 7;

    return day;
}