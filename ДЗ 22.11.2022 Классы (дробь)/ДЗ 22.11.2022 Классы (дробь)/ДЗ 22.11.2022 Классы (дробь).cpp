#include <iostream>
/*
    Реализуйте класс Дробь. Необходимо хранить числитель и знаменатель
    в качестве переменных-членов.Реализуйте функции-члены для ввода
    данных в переменные-члены,для выполнения арифметических операций
    (сложение, вычитание, умножение, деление, и т.д.). Арифметические
    операции должны выполняться с двумя дробями. Пример заголовка
    функции-члена для сложения дробей: void Mult(drob x)
*/

class Fraction                                                                     // класс Дробь
{
    int num;                                                                       // числитель
    int denom;                                                                     // знаменатель

public:
    void Set(int x, int y)                                                         // сeттер, присваивание значений
    {
        num = x;
        denom = y;
    }

    int NOD(Fraction x)                                                            // наибольший общий делитель для знаменателей двух дробей
    {
        int a = denom;
        int b = x.denom;
        while (a != 0 && b != 0)                                                   // пока переменные не равны нулю, выполняем
        {                                                                          // операцию деления по модулю для нахождения НОД
            if (a > b) a = a % b;
            else b = b % a;
        }

        if (a > 0) return a;                                                       // возвращаем найденный НОД
        else return b;
    }
    int NODRED()                                                                   // наибольший общий делитель для сокращения одной дроби
    {
        int a = num;
        int b = denom;
        while (a != 0 && b != 0)
        {
            if (a > b) a = a % b;
            else b = b % a;
        }

        if (a > 0) return a;
        else return b;
    }
    int GetN()
    {
        return num;
    }
    int GetD()
    {
        return denom;
    }
    int NOK(Fraction x)                                                           // функция нахождения наименьшего общего кратного
    {
        return denom * x.denom / NOD(x);
    }
    void Add(Fraction x)                                                          // функция сложения
    {
        num = num * (NOK(x) / denom) + x.num * (NOK(x) / x.denom);
        denom = NOK(x);      
        
    }
    void Sub(Fraction x)                                                          // функция вычитания
    {
        num = num * (NOK(x) / denom) - x.num * (NOK(x) / x.denom);
        denom = NOK(x);
    }
    void Mult(Fraction x)                                                         // функция умножения
    {
        num *= x.num;
        denom *= x.denom;
    }
    void Div(Fraction x)                                                          // функция деления
    {
        if (x.num < 0)                                                            // если второй знаменатель знаковый,
        {
            num *= x.denom * -1;                                                  // то переносим знак в числитель,
            denom *= x.num * - 1;                                                 // и избавляемся от знака в знаменателе
        } 
        else                                                                      // если второй знаменатель без знака,
        { 
            num *= x.denom;                                                       // то выполняем операцию деления дробей
            denom *= x.num;
        }    
    }
    void Output()                                                                                                 // метод для вывода строк на экран
    {
        std::cout << num << " " << denom << std::endl;
    }
    Fraction operator*(const Fraction& s)                // перегрузка опертора * для двух дробей
    {
        std::cout << "Перегрузка оператора *\n";
        num *= s.num;
        denom *= s.denom;

        return *this;
       
    }

    Fraction operator*(int r)                            // перегрузка оператора "*" - умножение на int N 
    {
        std::cout << "Перегрузка оператора * (int) " << r << "\n";
        num *= r;
        denom *= 1;

        return *this;                                    
    }
    void Result()                                                                 // функция вывода результата
    {
        int nod;                                                                  // хранит найденный НОД для одной дроби (итоговой)                                                           

        if (num < 0)                                                              // если числитель меньше нуля,
        {
            num *= -1;                                                            // то избавляемся от знака
            nod = NODRED();

            if (num < denom)                                                      // если дробь правильная, то выполняем сокращение
            {
                num /= nod;
                denom /= nod;
                std::cout << " Result:  " << num * -1 << '/'                      // возвращаем знак
                    << denom << std::endl;
            }
            else                                                                  // иначе - неправильная дробь - выводим целую часть
            {
                int part = num / denom;                                           // целая часть 
                num %= denom;                                                     // остаток - числитель, знаменатель тот же

                num /= nod;                                                       // сокращение дроби
                denom /= nod;

                std::cout << " Result: "
                    << " integer part of a fraction " << part * -1                // возвращаем знак целой части
                    << " fractional part " << num << '/'
                    << denom << std::endl;
            }
        }
        else                                                                      // иначе числитель больше нуля
        {
            nod = NODRED();

            if (num < denom)                                                      // если дробь правильная, то выполняем сокращение
            {
                
                num /= nod;
                denom /= nod;
                std::cout << " Result:  " << num << '/'
                    << denom << std::endl;
            }
            else                                                                  // иначе - неправильная дробь - выводим целую часть
            {
                int part = num / denom;                                           // целая часть 
                num %= denom;                                                     // остаток - числитель

                num /= nod;                                                       // cокращение дроби
                denom /= nod;

                std::cout << " Result: "
                    << " integer part of a fraction " << part
                    << " fractional part " << num << '/'
                    << denom << std::endl;
            }
        }
    }

    friend  std::ostream& operator<<(std::ostream& os, const Fraction& P); // перегрузка оператора вывода 
};

Fraction operator*(int r, Fraction T)                         // глобальная перегрузка оператора "*" - умножение int N на дробь
{
    std::cout << "Глобальная перегрузка оператора * - умножение int " << r << " на дробь\n";
    Fraction temp;
    temp.Set(r * T.GetN(), T.GetD());

    return temp;                                              // возврат результата в место вызова ф-ии
}

std::ostream& operator<<(std::ostream& os, const Fraction & P)  // вывод данных через поток
{
    os << "num = " << P.num << " ";
    os << "denom = " << P.denom << '\n';
    return os;
}
int main()
{
    setlocale(0, "rus");
    std::cout << " Fractional Calculator\n";
    std::cout << " For a negative value, enter the sign only in the numerator\n\n";

    int x, y, c,d;                                                                   // для ввода числителя и знаменателя
    int oper;                                                                        // для выбора операции
    bool choice = true;                                                              // для продолжения работы в калькуляторе

    Fraction one{};
    Fraction two{};
    do
    {
        std::cout << " Enter first numerator:\n";
        std::cin >> x;
        do
        {
            std::cout << " Enter first denominator:\n";
            std::cin >> y;
            if (y <= 0) std::cout << " The denominator cannot be less than zero or equal to zero!\n";
        } while (y <= 0);

         one.Set(x, y);

        std::cout << " Choose an operation:\n"
            << " 1 - addition\n"
            << " 2 - subtraction\n"
            << " 3 - multiplication\n"
            << " 4 - division\n";
        std::cin >> oper;

        std::cout << " Enter second numerator:\n";
        std::cin >> c;
        do
        {
            std::cout << " Enter second denominator:\n";
            std::cin >> d;
            if (d <= 0) std::cout << " The denominator cannot be less than zero or equal to zero!\n";
        } while (d <= 0);

        two.Set(c, d);

        switch (oper)
        {
        case 1:
            one.Add(two);
            one.Result();
            break;

        case 2:
            one.Sub(two);
            one.Result();
            break;

        case 3:
            one.Mult(two);
            one.Result();
            break;

        case 4:
            one.Div(two);
            one.Result();
            break;
        }

        std::cout << " Would you like to continue?\n"
            << " 1 - yes\n"
            << " 0 - no\n";
        std::cin >> choice;
        if (choice == 1) system("cls");

    } while (choice);                                                                          // работа цикла длится, пока выбор пользователя true (yes)


    one.Output();
    two.Output();

    one * two;
    one.Output();

    int r = 2;
    one * r;
    std::cout << one;
    Fraction R = r * one;
    std::cout << R;

    return 0;
}