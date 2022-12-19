/*
    Создайте класс Date, который содержит информацию о дате (день, месяц, год).
    С помощью перегрузки операторов определите операцию разности двух дат
    (результат - это количество дней между датами), а также операцию увеличения даты
    на определенное количество дней
*/
#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << "\tПрограмма подсчета дней между датами\n\n";

    Data data1;

    Data data2;
   
    cout << " Дата 1: ";
    data1.Output();

    cout << " Дата 2: ";
    data2.Output();

    int total;
    total = data1 - data2;

    cout << " \nРезультат: " << total << " дн. между датами.\n\n";

    int check;
    int count;
    cout << " Увеличить дату:   \n"
         << " Дата 1 - нажмите 1\n"
         << " Дата 2 - нажмите 2\n"
         << " Выход - нажмите 0 \n";
    cin >> check;

    switch (check)
    {
    case 1:
        cout << " Сколько дней добавить?\n";
        cin >> count;
        data1 + count;
        cout << " Дата 1: " << data1;
        cout << " Дата 2: " << data2;
        total = data1 - data2;
        cout << " Результат: " << total << " дней между датами.\n";
        break;

    case 2:
        cout << " Сколько дней добавить?\n";
        cin >> count;
        data2 + count;
        cout << " Дата 1: " << data1;
        cout << " Дата 2: " << data2;
        total = data1 - data2;
        cout << " Результат: " << total << " дней между датами.\n";
        break;

    case 0:
        exit(0);
        break;

    default:
        cout << " Вы выбрали неверный пункт меню! Пока!\n";
    }

    return 0;
}
