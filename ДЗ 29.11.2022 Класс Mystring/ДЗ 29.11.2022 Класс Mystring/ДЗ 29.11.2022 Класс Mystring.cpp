/*
    Разработать класс MyString, который в дальнейшем будет использоваться для
    работы со строками. Класс должен содержать:
• Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
• Конструктор, позволяющий создавать строку произвольного размера (принимает 
  количество символов, из которых будет состоять строка);
• Конструктор, который создаёт строку и инициализирует её строкой, полученной 
  в виде параметра этого конструктора;
• Конструктор, который создаёт строку и инициализирует её строкой, полученной 
  от пользователя (с клавиатуры).
    Класс должен содержать методы для ввода строк с клавиатуры и вывода строк 
    на экран и деструктор. Также нужно реализовать статическую функцию-член, 
    которая будет возвращать количество созданных объектов-строк.
    * конструктор копирования
    * перегрузка оператора "+"
    * 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
    char* str;
    int length;
    static int numberOfObject;                           // статическое поле класса

public:   

    MyString()                                                                                                    // конструктор по умолчанию, позволяющий создать строку длиной 80 символов
    {
        cout << " -Конструктор 1-\n";
        length = 80;
        str = new char[length + 1];
        numberOfObject++;
    }

    MyString(int n)                                                                                               // конструктор, позволяющий создавать строку произвольного размера 
    {                                                                                                             // (принимает количество символов, из которых будет состоять строка)
        cout << " -Конструктор 2-\n";
        length = n + 1;
        str = new char[length];
        numberOfObject++;
    }

    MyString(const char* s)                                                                                       // конструктор, который создаёт строку и инициализирует её строкой, 
    {                                                                                                             // полученной в виде параметра этого конструктора;
        cout << " -Конструктор 3-\n";
        length = strlen(s);
        str = new char[length + 1];
        if (str) strcpy_s(str,length + 1, s);
        numberOfObject++;
    }

    MyString(const MyString& s)                          // конструктор копирования одного объекта в другой // создание и инициализация
    {
        cout << " -Конструктор 4-\n ";

        length = strlen(s.str);
        str = new char[length + 1];
        strcpy_s(str,length + 1, s.str);
        numberOfObject++;
    }

    MyString operator+(const MyString& s)                // перегрузка опертора + для двух строк
    {
        cout << " -Перегрузка оператора \"+\" 5 - \n ";
        MyString temp;                                   // создаем временный объект, в котором будет храниться "сумма" 2 строк
        temp.length = length + s.length;                 // кол-во символов равно сумме символов двух строк (length - поле, 
                                                         //для которого вызвана функция, s.length - для второй строки, которая передана в функцию)
        temp.str = new char[temp.length + 1];            // выделяем память размером двух строк + \0 терм.
        strcpy(temp.str, str);                           // копируем в временную объект строку(this), для которой вызвана функция
        strcat(temp.str, s.str);                         // соединяем врменный объект-строку со строкой, которая передана в качестве параметра

        numberOfObject++;

        return temp;                                     // возврат результата в место вызова ф-ии
    }

    void Fill()                                                                                                   // метод для ввода строк с клавиатуры
    {
        if (str != NULL) delete[] str;
        cout << "Введите строку:\n";
        char a[20];
        cin.getline(a, 20);
        length = strlen(a) + 1;
        str = new char[length];
        strcpy_s(str, length, a);
    }

    void Output()                                                                                                 // метод для вывода строк на экран
    {
        cout << str << endl 
            << "-------------------------------------" 
            << endl;
    }

    static int getNumber()                               // статическая функция-член для подсчёта кол-ва созданных объектов
    {
        return numberOfObject;
    }

    ~MyString()
    {
        cout << "Сработал деструктор!\n";
        numberOfObject--;
        delete[] str;
    }
};

int MyString::numberOfObject{0};                         // uniform-инициализация статического поля

int main()
{
    setlocale(0, "rus");

    cout << "\tКласс MyString\n\n";
    cout << "Создание строки длиной 80 символов\n";
    MyString str1;
    str1.Fill();
    str1.Output();

    cout << "Создание строки произвольного размера\n";
    int size = 5;
    MyString str2(size);
    str2.Fill();
    str2.Output();

    cout << "Создание строки и инициализация её строкой,\nполученной в виде параметра\n";
    char* s = new char[7] {"Hello!"};
    MyString str3(s);
    str3.Output();

    cout << "Создание строки и инициализация её строкой,\nполученной от пользователя(с клавиатуры)\n";
    MyString str4 = str2;                                                                               // использую уже существующий объект str2
    str4.Output(); 

    cout << "Перегрузка оператора + для конкатенации строк\n";
    
    char* s1 = new char[7] {"Hello "};
    char* s2 = new char[7] {"world!"};

    MyString str5(s1);
    MyString str6(s2);
    MyString RES = str5 + str6;
    RES.Output();

    cout << "Количество созданных объектов-строк - " << MyString::getNumber() << endl;

    delete[] s;
    delete[] s1;
    delete[] s2;

    return 0;
}