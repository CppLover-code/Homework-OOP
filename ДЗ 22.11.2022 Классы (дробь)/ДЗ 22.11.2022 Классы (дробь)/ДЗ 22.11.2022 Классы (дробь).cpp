#include <iostream>
/*
    Реализуйте класс Дробь. Необходимо хранить числитель и знаменатель
    в качестве переменных-членов.Реализуйте функции-члены для ввода 
    данных в переменные-члены,для выполнения арифметических операций
    (сложение, вычитание, умножение, деление, и т.д.). Арифметические 
    операции должны выполняться с двумя дробями. Пример заголовка 
    функции-члена для сложения дробей: void Mult(drob x)
*/

class Fraction                                                                  // класс Дробь
{
    int num;                                                                    // числитель
    int denom;                                                                  // знаменатель

public:
    void Set(int x, int y)                                                      // сeттер, присваивание значений
    {
        num = x;
        denom = y;
    }
    void Add(int numb)                                                          // функция сложения
    {
        num += (numb * denom);
    }
    void Sub(int numb)                                                          // функция вычитания
    {
        num -= (numb * denom);
    }
    void Mult(int numb)                                                         // функция умножения
    {
        num *= numb;
    }
    void Div(int numb)                                                          // функция деления
    {
        denom *= numb;
    }
    int GetNum()                                                                // гeттер для числителя
    {
        return num;
    }
    int GetDenom()                                                              // гeттер для знаменателя
    {
        return denom;
    }
    double Res()                                                                // функция для подсчета результата
    {
        return (double) num / denom;
    }
    void Output()                                                               // функция вывода результата
    {
        std::cout << " Result:  " << GetNum() << '/' 
            << GetDenom() << " = "  << Res() << std::endl;
    }
};

int main()
{
    std::cout << " Fractional Calculator\n";
 
    int x, y;                                                                   // для ввода числителя и знаменателя
    int oper;                                                                   // для выбора операции
    int numb;                                                                   // второе число для проведения нужной операции
    bool choice = true;                                                         // для продолжения работы в калькуляторе

    Fraction calc{};                                                            // выделение памяти для класса
    do
    {
        std::cout << " Enter numerator:\n";
        std::cin >> x;
        do
        {
            std::cout << " Enter denominator:\n";
            std::cin >> y;
            if (y == 0) std::cout << " The denominator cannot be zero!!!\n";
        } while (y == 0);
        
        calc.Set(x, y);

        std::cout << " Choose an operation:\n"
            << " 1 - addition\n"
            << " 2 - subtraction\n"
            << " 3 - multiplication\n"
            << " 4 - division\n";
        std::cin >> oper;

        switch (oper)
        {
        case 1:
            std::cout << " Enter term:\n";
            std::cin >> numb;
            calc.Add(numb);
            calc.Output();
            break;

        case 2:
            std::cout << " Enter subtrahend:\n";
            std::cin >> numb;
            calc.Sub(numb);
            calc.Output();
            break;

        case 3:
            std::cout << " Enter multiplier:\n";
            std::cin >> numb;
            calc.Mult(numb);
            calc.Output();
            break;

        case 4:
            do
            {
                std::cout << " Enter divisor:\n";
                std::cin >> numb;
                if (numb == 0) std::cout << " The divisor cannot be zero!!!\n";
            } while (numb== 0);
           
            calc.Div(numb);
            calc.Output();
            break;
        }

        std::cout << " Would you like to continue?\n"
            << " 1 - yes\n"
            << " 0 - no\n";
        std::cin >> choice;
        if (choice == 1) system("cls");

    } while (choice);

    return 0;
}
