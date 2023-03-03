/*
Реализовать паттерн "Фасад". Предметная область - использование стиральной машины
*/
#include <iostream>
#include <string>
using namespace std;

class Washing
{
public:
    void Start()
    {
        cout << "Start washing...\n\n";
    }
    void wWashing()
    {
        cout << "Washing\n";
    }
};

class Rinsing
{
public:
    void rRinsing()
    {
        cout << "Rinsing\n";
    }
};

class Spinning
{
public:
    void sSpinning()
    {
        cout << "Spinning\n\n";
    }
    void Finish()
    {
        cout << "Completed!\n";
    }
};

class WashingMachineFacade
{
    Washing  wash;  // стирка
    Rinsing  rins;  // полоскание 
    Spinning spin;  // отжим

public:
    WashingMachineFacade(Washing w, Rinsing r, Spinning s)
    {
        wash = w;
        rins = r;
        spin = s;
    }
    void Start()
    {

        wash.Start();
    }
    void Process()
    {

        wash.wWashing();
        rins.rRinsing();
        spin.sSpinning();
    }
    void Stop()
    {
        spin.Finish();
    }
};

class Housewife
{
public:
    void UseWashingMachine(WashingMachineFacade facade)
    {
        facade.Start();
        facade.Process();
        facade.Stop();
    }
};

int main()
{
    Washing  wash1;  // стирка                         // создаем три процесса, которые относятся к стиралке
    Rinsing  rins1;  // полоскание 
    Spinning spin1;  // отжим

    WashingMachineFacade machine(wash1, rins1, spin1); // создаем стиралку и включаем в нее процессы


    Housewife housewife;                               // создаем домохозяйку, которая пользуется стиралкой
    housewife.UseWashingMachine(machine);              // ждомохозяйка использует стиралку
}