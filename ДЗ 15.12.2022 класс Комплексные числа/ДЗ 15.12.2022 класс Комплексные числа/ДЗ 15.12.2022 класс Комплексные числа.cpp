#include <iostream>

class Complex
{
	float real;
	float imagine;

public:
    Complex() = default;  // вернули в класс встроенный конструктор по умолчанию
    Complex(float x, float y)
    {
        //std::cout << " Conctructor\n";
        real = x;
        imagine = y;
    }
    ~Complex()
    {
        //std::cout << " Destructor\n";
    }

    friend  std::ostream& operator<<(std::ostream& os, const Complex& n);
    Complex operator+(const Complex& n)
    {
        Complex res;
        res.real = real + n.real;
        res.imagine = imagine + n.imagine;

        return res;
    }
    Complex operator-(const Complex& n)
    {
        Complex res;
        res.real = real - n.real;
        res.imagine = imagine - n.imagine;

        return res;
    }
    Complex operator*(const Complex& n)
    {
        Complex res;
        res.real = (real * n.real) - (imagine * n.imagine);
        res.imagine = (imagine * n.real) + (real * n.imagine);

        return res;
    }
    Complex operator/(const Complex& n)
    {
        Complex res;

        float a, b, c, d, e;                                                     // переменные будут хранить результаты
        a = real * n.real;                                                       // операций над числами
        b = imagine * n.imagine;
        c = imagine * n.real;
        d = real * n.imagine;
        e = n.real * n.real + n.imagine * n.imagine;

        res.real = (a + b) / e;
        res.imagine = (c - d) / e;

        return res;
    }

};
std::ostream& operator<<(std::ostream& os, const Complex& n)                     // вывод данных через поток
{
    os << n.real << (n.imagine >= 0 ? " + " : "") << n.imagine << "i";           // если мнимое число больше 0, то выводим '+', иначе пустые ""

    return os;
}

void check_data(float x1, float y1, float x2, float y2, char oper);

int main()
{
	std::cout << " Operations with complex numbers '+' '-' '*' '/')\n\n";

    float x1, y1;  // исп тип данных float, тк результаты некоторых 
    float x2, y2;  // операций могут давать вещественные числа

    char oper;

    std::cout << "Enter the real and imaginary part of the first complex number:\n";
    std::cin >> x1 >> y1;
    std::cout << "Enter the real and imaginary part of the second complex number:\n";
    std::cin >> x2 >> y2;
    std::cout << "Enter a math symbol:\n";
    std::cin >> oper;

    std::cout << " Result:\n";

    check_data(x1, y1, x2, y2, oper);

    Complex numb1(x1, y1);
    Complex numb2(x2, y2);
    Complex res;

    switch (oper)
    {
    case '+':
        res = numb1 + numb2;
        std::cout << "(" << numb1 << ") + (" << numb2 << ") = " << res << "\n";
        
        break;

    case '-':
        res = numb1 - numb2;
        std::cout << "(" << numb1 << ") - (" << numb2 << ") = " << res << "\n";

        break;

    case '*':
        res = numb1 * numb2;
        std::cout << "(" << numb1 << ") * (" << numb2 << ") = " << res << "\n";

        break;

    case '/':
        res = numb1 / numb2;
        std::cout << "(" << numb1 << ") / (" << numb2 << ") = " << res << "\n";

        break;
    }

    return 0;
}
void check_data(float x1, float y1, float x2, float y2, char oper)                                      // функция проверки введенных данных пользователем
{

    if (x1 == 0 && y1 == 0 && (oper == '*' || oper == '/'))                                             // если два числа первого выражения равны нулю и 
    {
        std::cout << "\n The real and imaginary parts of the -first- expression are equal to zero.\n"   // знак операции '*' или '/', то выводим предупреждение
            << " Operation not possible =( Enter all data again!\n\n";
        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
    }

    else if (x2 == 0 && y2 == 0 && (oper == '*' || oper == '/'))                                        // если два числа второго  выражения равны нулю и 
    {
        std::cout << "\n The real and imaginary parts of the -second- expression are equal to zero.\n"  // знак операции '*' или '/', то выводим предупреждение
            << " Operation not possible =( Enter all data again!\n\n";
        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
    }

    else if (oper != '+' && oper != '-' && oper != '*' && oper != '/')                                  // если введенный знак операции не соответствует указаному,
    {
        std::cout << "\n You entered an invalid math symbol! Enter all data again!\n\n";                // выводим предупреждение
        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
    }
}