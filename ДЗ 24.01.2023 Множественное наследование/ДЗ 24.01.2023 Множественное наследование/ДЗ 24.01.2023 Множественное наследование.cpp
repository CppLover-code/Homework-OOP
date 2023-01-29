/*
    1) Используя множественное наследование, разработать класс “Автомобиль”.
    Автомобиль будет потомком для классов “Колеса”, “Двигатель”, “Двери”.

    2) Реализовать иерархию классов "Транспортное средство".
    Базовый класс - транспорт, производные - самолёт, судно, грузовик, велосипед и легковой автомобиль.
    Метод вывода и метод расхода топлива реализовать как virtual.
    Реализовать меню для создания объектов.
    Объекты создаются через единственный указатель на базовый класс
*/
//#include <iostream>
//using namespace std;
//
//class Wheels                                                    // базовый класс
//{
//    short count;
//public:
//    Wheels()                                      
//    {                                              
//        cout << " C-tor by default Wheels\n";
//        count = 4;
//    }
//    Wheels(short w)
//    {
//        cout << " C-tor with param Wheels\n";
//        count = w;
//    }
//    ~Wheels()
//    {
//        cout << " D-tor Wheels\n";
//    }
//    void Output()
//    {
//        cout << " Number of wheels - " << count << endl;
//    }
//};
//
//class Engine                                                    // базовый класс
//{
//    short cylinders;
//public:
//    Engine()
//    {
//        cout << " C-tor by default Engine\n";
//        cylinders = 4;
//    }
//    Engine(short c) : cylinders(c)
//    {
//        cout << " C-tor with param Engine\n";
//    }
//    ~Engine()
//    {
//        cout << " D-tor Engine\n";
//    }
//    void Output()
//    {
//        cout << " Number of cylinders - " << cylinders << endl;
//    }
//};
//    
//class Door                                                      // базовый класс
//{
//    short count;
//public:
//    Door()
//    {
//        cout << " C-tor by default Door\n";
//        count = 4;
//    }
//    Door(short d) : count(d)
//    {
//        cout << " C-tor with param Door\n";
//    }
//    ~Door()
//    {
//        cout << " D-tor Door\n";
//    }
//    void Output()
//    {
//        cout << " Number of doors - " << count << endl;
//    }
//};
//
//class Car : protected Wheels, protected Engine, protected Door  // производный класс
//{
//    string model;
//public:
//    Car(string m, short w, short c, short d) : Wheels (w), Engine(c), Door(d)
//    {
//        cout << " C-tor with param Car\n";
//        model = m;
//    }
//    ~Car()
//    {
//        cout << " D-tor Car\n";
//    }
//    void Output()
//    {
//        cout << "-Car-\n"
//             << " Car model - " << model << endl;
//        Wheels::Output();
//        Engine::Output();
//        Door  ::Output();
//    }
//};
//
//int main()
//{
//    Car car1("Lexus",6, 10, 5);
//    car1.Output();
//   
//    return 0;
//}

#include <iostream>
using namespace std;

class Vehicle           // базовый класс
{
protected:
    string name;        // название транспорта 
    short aver_cnsmptn; // средний расход топлива 
    float distance;     // расстояние, которое преодолел транспорт

public:
    Vehicle() = default;
    Vehicle(string n, short a, float d)
    {
        cout << " C-tor with param Vehicle\n";
        name = n;
        aver_cnsmptn = a;
        distance = d;
    }
    virtual ~Vehicle()
    {
        cout << " D-tor Vehicle\n";
    }
    virtual void Output()
    {
        cout << " Vehicle parameters not defined!\n";
    }
    virtual void Consumption() // метод Расход топлива
    {
        cout << " Unable to calculate fuel consumption for an undefined vehicle\n";
    }
};
 
class Plane : public Vehicle
{
public:
    Plane(string n, short a, float d) : Vehicle(n, a, d)
    {
        cout << " C-tor with param Plane\n";
    }
    ~Plane()
    {
        cout << " D-tor Plane\n";
    }
    virtual void Output()
    {
        cout << "-Plane-\n"
            << " Name " << name << endl
            << " Average consumption " << aver_cnsmptn << endl
            << " Distance " << distance << endl;
    }
    virtual void Consumption() override
    {
        cout << " Plane fuel consumption " << aver_cnsmptn * distance / 100 << " l\n";
    } 
};

class Vessel : public Vehicle
{
public:
    Vessel(string n, short a, float d) : Vehicle(n, a, d)
    {
        cout << " C-tor with param Vessel\n";
    }
    ~Vessel()
    {
        cout << " D-tor Vessel\n";
    }
    virtual void Output()
    {
        cout << "-Vessel-\n"
            << " Name " << name << endl
            << " Average consumption " << aver_cnsmptn << endl
            << " Distance " << distance << endl;
    }
    virtual void Consumption() override
    {
        cout << " Vessel fuel consumption " << aver_cnsmptn * distance / 100 << " l\n";
    }
};

class Truck : public Vehicle
{
public:
    Truck(string n, short a, float d) : Vehicle(n, a, d)
    {
        cout << " C-tor with param Truck\n";
    }
    ~Truck()
    {
        cout << " D-tor Truck\n";
    }
    virtual void Output()
    {
        cout << "-Truck-\n"
            << " Name " << name << endl
            << " Average consumption " << aver_cnsmptn << endl
            << " Distance " << distance << endl;
    }
    virtual void Consumption() override
    {
        cout << " Truck fuel consumption " << aver_cnsmptn * distance / 100 << " l\n";
    }
};

class Bicycle : public Vehicle
{
    float weight;  // вес человека
    int minute;    // длительность поездки в минутах
public:
    Bicycle(string n, short a, float d, float w, int m) : Vehicle(n, a, d)
    {
        cout << " C-tor with param Bicycle\n";
        weight = w;
        minute = m;
    }
    ~Bicycle()
    {
        cout << " D-tor Bicycle\n";
    }
    virtual void Output()
    {
        cout << "-Bicycle-\n"
            << " Bike name " << name << endl
            << " Average energy consumption per hour " << aver_cnsmptn << " calories\n"
            << " Distance " << distance << endl
            << " Human weight " << weight << " kilo\n"
            << " Travel time " << minute << " min\n";
    }
    virtual void Consumption() override
    {
        cout << " Energy consumption on a bike " 
             << 0.014 * weight * minute * (0.12 * 140 - 7) // 140 - средний пульс
             << " calories\n";
    }
};

class Car : public Vehicle
{
public:
    Car(string n, short a, float d) : Vehicle(n, a, d)
    {
        cout << " C-tor with param Car\n";
    }
    ~Car()
    {
        cout << " D-tor Car\n";
    }
    virtual void Output()
    {
        cout << "-Car-\n"
            << " Name " << name << endl
            << " Average consumption " << aver_cnsmptn << endl
            << " Distance " << distance << endl;
    }
    virtual void Consumption() override
    {
        cout << " Car fuel consumption " << aver_cnsmptn * distance / 100 << " l\n";
    }
};

int main()
{
    Vehicle* vehicle = nullptr;

    short choice = 0;

    cout << " Vehicle fuel consumption\n\n"
        << " 1 - plane\n"
        << " 2 - vessel\n"
        << " 3 - truck\n"
        << " 4 - bicycle\n"
        << " 5 - car\n"
        << " \nMake your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            vehicle = new Plane("Mriya", 20, 240);           
            break;

        case 2:
            vehicle = new Vessel("Giaconda", 58, 65);
            break;

        case 3:
            vehicle = new Truck("Volvo", 15, 120);
            break;

        case 4:
            vehicle = new Bicycle("Aist", 365, 5, 75, 30);
            break;

        case 5:
            vehicle = new Car("Toyota", 8, 25);
            break;
        }
        vehicle->Output();
        vehicle->Consumption();

    delete vehicle;

    return 0;
}