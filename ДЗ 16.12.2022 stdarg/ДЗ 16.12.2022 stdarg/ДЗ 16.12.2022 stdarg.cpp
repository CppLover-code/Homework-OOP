/*
    Написать программу, которая реализует функцию с неограниченным количеством параметров,
    организовывающую форматированный вывод на экран.
    1. Использование функции va_start() и va_arg()
    2. Использование явного параметра, равного количеству последующих неявных параметров
    3. Использование концевого признака
*/
#include <iostream>
#include <stdarg.h>
#include "colors.h"
using namespace std;

void Output1(int count, ...);
void Output2(int count, ...);
void Output3(int n, ...);

int main()
{
    setlocale(0, "rus");
    cout << " Функции с произвольным количеством параметров\n\n";

    Output1(5, 'H', 'e', 'l', 'l', 'o');
    Output2(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    Output3(1, 2, 3, 4, 5, 0, 6, 7, 0);

    return 0;
}
void Output1(int count, ...)
{
    va_list arg_ptr;                                                       // создаём указатель на список параметров
    va_start(arg_ptr, count);                                              // получаем этот указатель, отталкиваясь от первого фактического параметра
    while (count--)                                                        // count раз считываем последующие параметры
    {
        cout << va_arg(arg_ptr, char) << "\n";
    }
    va_end(arg_ptr);                                                       // закрываем список параметров
}
void Output2(int count, ...)
{
    int* pcount = &count;                                                  // адрес начала списка наших элементов
    for (; count; count--)
    {
        if (*pcount % 2 == 0)                                              // число четное - зелёный цвет, иначе - красный
        {
            cout << colors::GREEN << *(++pcount) << colors::RESET << " ";   // в скобках сдвиг на 4 байта (int), а потом разыменование
        }
        else
        {
            cout << colors::RED << *(++pcount) << colors::RESET << " ";
        }
    }
    cout << endl;
}
void Output3(int n, ...)
{
    int* pn = &n;                                                          // адрес начала списка наших элементов

    while (*pn)                                                            // пока не встретим значение 0 (признак окончания списка параметров)
    {
        cout << *(pn++) << '\t';
    }
    cout << endl;
}
