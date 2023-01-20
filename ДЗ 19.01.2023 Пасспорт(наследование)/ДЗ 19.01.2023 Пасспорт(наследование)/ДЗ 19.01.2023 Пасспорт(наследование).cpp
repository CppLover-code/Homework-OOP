
/*
Создайте класс Passport (паспорт), который будет содержать паспортную
информацию о гражданине Украины. С помощью механизма наследования
реализуйте класс ForeignPassport (загранпаспорт), производный от Passport.
Напомним, что загранпаспорт содержит помимо паспортных данных, также данные
о визах, номер загранпаспорта
*/

#include<iostream>
#include<Windows.h>
using namespace std;

class Ukrpas  // base class
{
protected:
    string name;
    string birth;
public:
    Ukrpas();
    Ukrpas(string, string);
    void Output_Ukrpas();
    ~Ukrpas();
};
Ukrpas::Ukrpas()
{
    cout << "Construct Ukrpas by default\n";
    name = " ";
    birth = " ";
}
Ukrpas::Ukrpas(string Name, string Birth)
{
    cout << "Construct Ukrpas with param\n";
    name = Name;
    birth = Birth;
}
void Ukrpas::Output_Ukrpas()
{
    cout << "Output Ukrpas\n";

    cout << "Name: " << name << endl;
    cout << "Date of birth: " << birth << endl << endl;
}
Ukrpas::~Ukrpas()
{
    cout << "Destruct Ukrpas\n";
    Sleep(1000);
}

class Forpas : private Ukrpas
{
    int visa;
    int s_numb;
public:
    Forpas();
    Forpas(string Name, string Birth, int Visa, int S_numb);
    ~Forpas();
    void Output();
};
Forpas::Forpas()/*:Human()*/  // вызывавется конструктор базового класса по умолчанию, поэтому можно не писать
{
    cout << "Construct Forpas by default\n";

    visa = 0;
    s_numb = 0;
}
Forpas::Forpas(string Name, string Birth, int Visa, int S_numb) : Ukrpas(Name, Birth)
{
    cout << "Construct Forpas with param\n";
    visa = Visa;
    s_numb = S_numb;
}
Forpas::~Forpas()
{
    cout << "Destruct Forpas\n";
    Sleep(1000);
}
void Forpas::Output()
{
    cout << "Output Passport\n";
    Output_Ukrpas();

    cout << "Count of visa: " << visa << endl;
    cout << "Serial number (foreign pas): " << s_numb << endl << endl;
}
int main()
{
    Forpas one("Petrov Ivan Ivanovich", "19.10.1996", 5, 2315);
    one.Output();
}