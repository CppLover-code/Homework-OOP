/*
    Реализовать иерархию классов "Транспортное средство". В базовом классе реализовать
    набор чисто виртуальных методов (ввод-вывод, расход топлива, получение стоимости,
    установка стоимости, грузоподъёмность, количество мест для пассажиров).
    Потомки переопределяют чисто виртуальные методы. Создать массив указателей базового
    класса. Каждый элемент указывает на объект потомка.
    Поочерёдно вызывая методы в переборном цикле, освобождаем память.
*/

// Первый вариант, но без некоторых полей в базовом классе
// Пусть будет на всякий случай=)
//#include <iostream>
//using namespace std;
//
//class Vehicle           // базовый класс
//{
//protected:
//    string name;        // название транспорта 
//    short aver_cnsmptn; // средний расход топлива на 100 км
//public:
//    Vehicle(string, short);
//    virtual ~Vehicle() = 0;
//    
//    virtual void Capacity() = 0;
//    virtual void Seats() = 0;
//    virtual void Consumption() = 0; // метод Расход топлива
//    virtual void Price() = 0;       // метод рассчета стоимости топлива
//    virtual void Output() = 0;
//};
//Vehicle::Vehicle(string n, short a)
//{
//    cout << " C-tor with param Vehicle\n";
//    name = n;
//    aver_cnsmptn = a;
//}
//Vehicle::~Vehicle()
//{
//    cout << " D-tor Vehicle\n";
//}
//void Vehicle::Capacity()
//{
//    cout << " Vehicle not defined!\n";
//}
//void Vehicle::Seats()
//{
//    cout << " Vehicle not defined!\n";
//}
//void Vehicle::Consumption()
//{
//    cout << " Unable to calculate fuel consumption for an undefined vehicle\n";
//}
//void Vehicle::Price()
//{
//    cout << " Unable to calculate fuel cost for an unspecified vehicle\n";
//}
//void Vehicle::Output()
//{
//    cout << " Name " << name << endl
//        << " Average consumption " << aver_cnsmptn << endl;
//}
//
//class Plane : public Vehicle
//{
//public:
//    Plane(string n, short a) : Vehicle(n,a)
//    {
//        cout << " C-tor with param Plane\n";
//    }
//    virtual ~Plane()
//    {
//        cout << " D-tor Plane\n";
//    }
//    virtual void Capacity()
//    {
//        float capacity;
//        cout << " Enter load capacity:\n";
//        cin >> capacity;
//        cout << " Capacity of airplane: " << capacity << endl;
//    }
//    virtual void Seats()
//    {
//        short seats;
//        cout << " Enter the number of seats:\n";
//        cin >> seats;
//        cout << " Number of seats in airplane: " << seats << endl;
//    }
//    virtual void Consumption()
//    {
//        float distance;
//        cout << " Enter distance for fuel calculation:\n";
//        cin >> distance;
//        cout << " Consumption for the plane on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n";
//    }
//    virtual void Price()
//    {
//        float cost, distance;
//        cout << " Enter the cost of 1 liter of fuel:\n";
//        cin >> cost;
//        cout << " Enter distance to calculate fuel cost:\n";
//        cin >> distance;
//
//        cout << " Plane fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
//    }
//    virtual void Output()
//    {
//        cout << "-Plane-\n";
//        Vehicle::Output();
//        Capacity();
//        Seats();
//        Consumption(); 
//        Price();
//        cout << " ***************************\n\n";
//    }
//};
//
//class Vessel : public Vehicle
//{
//public:
//    Vessel(string n, short a) : Vehicle(n, a)
//    {
//        cout << " C-tor with param Vessel\n";
//    }
//    virtual ~Vessel()
//    {
//        cout << " D-tor Vessel\n";
//    }
//    virtual void Capacity()
//    {
//        float capacity;
//        cout << " Enter load capacity:\n";
//        cin >> capacity;
//        cout << " Capacity of vessel: " << capacity << endl;
//    }
//    virtual void Seats()
//    {
//        short seats;
//        cout << " Enter the number of seats:\n";
//        cin >> seats;
//        cout << " Number of seats in vessel: " << seats << endl;
//    }
//    virtual void Consumption()
//    {
//        float distance;
//        cout << " Enter distance for fuel calculation:\n";
//        cin >> distance;
//        cout << " Consumption for the vessel on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n";
//    }
//    virtual void Price()
//    {
//        float cost, distance;
//        cout << " Enter the cost of 1 liter of fuel:\n";
//        cin >> cost;
//        cout << " Enter distance to calculate fuel cost:\n";
//        cin >> distance;
//
//        cout << " Vessel fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
//    }
//    virtual void Output()
//    {
//        cout << "-Vessel-\n";
//        Vehicle::Output();
//        Capacity();
//        Seats();
//        Consumption();
//        Price();
//        cout << " ***************************\n\n";
//    }
//};
//
//class Truck : public Vehicle
//{
//public:
//    Truck(string n, short a) : Vehicle(n, a)
//    {
//        cout << " C-tor with param Truck\n";
//    }
//    virtual ~Truck()
//    {
//        cout << " D-tor Truck\n";
//    }
//    virtual void Capacity()
//    {
//        float capacity;
//        cout << " Enter load capacity:\n";
//        cin >> capacity;
//        cout << " Capacity of truck: " << capacity << endl;
//    }
//    virtual void Seats()
//    {
//        short seats;
//        cout << " Enter the number of seats:\n";
//        cin >> seats;
//        cout << " Number of seats in truck: " << seats << endl;
//    }
//    virtual void Consumption()
//    {
//        float distance;
//        cout << " Enter distance for fuel calculation:\n";
//        cin >> distance;
//        cout << " Consumption for the truck on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n";
//    }
//    virtual void Price()
//    {
//        float cost, distance;
//        cout << " Enter the cost of 1 liter of fuel:\n";
//        cin >> cost;
//        cout << " Enter distance to calculate fuel cost:\n";
//        cin >> distance;
//
//        cout << " Truck fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
//    }
//    virtual void Output()
//    {
//        cout << "-Truck-\n";
//        Vehicle::Output();
//        Capacity();
//        Seats();
//        Consumption();
//        Price();
//        cout << " ***************************\n\n";
//    }
//};
//
//class Car : public Vehicle
//{
//public:
//    Car(string n, short a) : Vehicle(n, a)
//    {
//        cout << " C-tor with param Car\n";
//    }
//    virtual ~Car()
//    {
//        cout << " D-tor Car\n";
//    }
//    virtual void Capacity()
//    {
//        float capacity;
//        cout << " Enter load capacity:\n";
//        cin >> capacity;
//        cout << " Capacity of car: " << capacity << endl;
//    }
//    virtual void Seats()
//    {
//        short seats;
//        cout << " Enter the number of seats:\n";
//        cin >> seats;
//        cout << " Number of seats in car: " << seats << endl;
//    }
//    virtual void Consumption()
//    {
//        float distance;
//        cout << " Enter distance for fuel calculation:\n";
//        cin >> distance;
//        cout << " Consumption for the car on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n";
//    }
//    virtual void Price()
//    {
//        float cost, distance;
//        cout << " Enter the cost of 1 liter of fuel:\n";
//        cin >> cost;
//        cout << " Enter distance to calculate fuel cost:\n";
//        cin >> distance;
//
//        cout << " Car fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
//    }
//    virtual void Output()
//    {
//        cout << "-Car-\n";
//        Vehicle::Output();
//        Capacity();
//        Seats();
//        Consumption();
//        Price();
//        cout << " ***************************\n\n";
//    }
//};
//
//int main()
//{
//    Vehicle* vehicle[4] = { new Plane("Mriya", 912), new Vessel("Odessa", 320), new Truck("VAZ", 8.5), new Car("Opel", 8)};
//
//    for (size_t i = 0; i < 4; i++)
//    {
//        vehicle[i]->Output();
//        vehicle[i]->~Vehicle();
//    }
//
//    return 0;
//}

#include <iostream>
#include <windows.h>
using namespace std;

class Vehicle           // абстрактный базовый класс Транспортное средство
{
protected:
    string name;        // название транспорта 
    short aver_cnsmptn; // средний расход топлива на 100 км

    float capacity;     // грузоподъемность
    short seats;        // кол-во мест для сидения

public:
    Vehicle();
    virtual ~Vehicle()  = 0;
    virtual void Name() = 0;        // метод для ввода названия 
    virtual void Aver() = 0;        //  метод для ввода среднего расхода топлива на 100 км
    virtual void Capacity() = 0;    // метод для ввода грузоподъемности
    virtual void Seats()  = 0;      // метод для ввода кол-ва мест для сидения
    virtual void Consumption() = 0; // метод рассчета расхода топлива
    virtual void Price()  = 0;      // метод рассчета стоимости топлива
    virtual void Output() = 0;      // метод вывода данных на экран
};
Vehicle::Vehicle()
{
    cout << " C-tor by default Vehicle\n";  // поле "name" можно не инициализировать, так как пустая строка содержит " " символ пробела
    aver_cnsmptn = 0;
    capacity = 0;
    seats = 0;
}
Vehicle::~Vehicle()
{
    cout << " D-tor Vehicle\n\n";
}
void Vehicle::Name()
{
    cout << " Vehicle not defined!\n";
}
void Vehicle::Aver()
{
    cout << " Vehicle not defined!\n";
}
void Vehicle::Capacity()
{
    cout << " Vehicle not defined!\n";
}
void Vehicle::Seats()
{
    cout << " Vehicle not defined!\n";
}
void Vehicle::Consumption()
{
    cout << " Unable to calculate fuel consumption for an undefined vehicle\n";
}
void Vehicle::Price()
{
    cout << " Unable to calculate fuel cost for an unspecified vehicle\n";
}
void Vehicle::Output()
{
    cout << " Vehicle not defined!\n";
}

class Plane : public Vehicle
{
public:
    Plane() : Vehicle()
    {
        cout << " C-tor by default Plane\n";
    }
    virtual ~Plane()
    {
        cout << " D-tor Plane\n";
    }
    virtual void Name()
    {
        cout << " Fill in the airplane details\n";
        cout << " Enter airplane name:\n";
        cin >> name;
    }
    virtual void Aver()
    {
        cout << " Enter the average airplane fuel consumption:\n";
        cin >> aver_cnsmptn;
    }
    virtual void Capacity()
    {
        cout << " Enter load capacity of airplane:\n";
        cin >> capacity;  
    }
    virtual void Seats()
    {
        cout << " Enter the number of seats in airplane:\n";
        cin >> seats;   
    }
    virtual void Consumption()
    {
        float distance;
        cout << " Airplane Fuel Consumption Calculation\n"
             << " Enter distance:\n";
        cin >> distance;
        cout << " Consumption for the plane on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n\n";
    }
    virtual void Price()
    {
        float cost, distance;
        cout << " Airplane Fuel Cost Calculation\n"
             << " Enter the cost of 1 liter of aviation fuel:\n";
        cin >> cost;

        cout << " Enter distance:\n";
        cin >> distance;

        cout << " Airplane fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
    }
    virtual void Output()
    {
        cout << "-Plane-\n"
            << " Name - " << name << endl
            << " Average consumption: " << aver_cnsmptn << " liters\n"
            << " Capacity of airplane: " << capacity << " tons\n"
            << " Number of seats in airplane: " << seats << "\n\n";
        Consumption();
        Price();
        cout << " ***************************\n\n";
    }
};

class Vessel : public Vehicle
{
public:
    Vessel() : Vehicle()
    {
        cout << " C-tor by default Vessel\n";
    }
    virtual ~Vessel()
    {
        cout << " D-tor Vessel\n";
    }
    virtual void Name()
    {
        cout << " Fill in the vessel details\n";
        cout << " Enter vessel name:\n";
        cin >> name;
    }
    virtual void Aver()
    {
        cout << " Enter the average vessel fuel consumption:\n";
        cin >> aver_cnsmptn;
    }
    virtual void Capacity()
    {
        cout << " Enter load capacity of vessel:\n";
        cin >> capacity;
    }
    virtual void Seats()
    {
        cout << " Enter the number of seats in vessel:\n";
        cin >> seats;
    }
    virtual void Consumption()
    {
        float distance;
        cout << " Vessel Fuel Consumption Calculation\n"
            << " Enter distance:\n";
        cin >> distance;
        cout << " Consumption for the vessel on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n\n";
    }
    virtual void Price()
    {
        float cost, distance;
        cout << " Vessel Fuel Cost Calculation\n"
            << " Enter the cost of 1 liter of diesel fuel:\n";
        cin >> cost;

        cout << " Enter distance:\n";
        cin >> distance;

        cout << " Vessel fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
    }
    virtual void Output()
    {
        cout << "-Vessel-\n"
            << " Name - " << name << endl
            << " Average consumption: " << aver_cnsmptn << " liters\n"
            << " Capacity of vessel: " << capacity << " tons\n"
            << " Number of seats in vessel: " << seats << "\n\n";
        Consumption();
        Price();
        cout << " ***************************\n\n";
    }
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle()
    {
        cout << " C-tor by default Truck\n";
    }
    virtual ~Truck()
    {
        cout << " D-tor Truck\n";
    }
    virtual void Name()
    {
        cout << " Fill in the truck details\n";
        cout << " Enter truck name:\n";
        cin >> name;
    }
    virtual void Aver()
    {
        cout << " Enter the average truck fuel consumption:\n";
        cin >> aver_cnsmptn;
    }
    virtual void Capacity()
    {
        cout << " Enter load capacity of truck:\n";
        cin >> capacity;
    }
    virtual void Seats()
    {
        cout << " Enter the number of seats in truck:\n";
        cin >> seats;
    }
    virtual void Consumption()
    {
        float distance;
        cout << " Truck Fuel Consumption Calculation\n"
            << " Enter distance:\n";
        cin >> distance;
        cout << " Consumption for the truck on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n\n";
    }
    virtual void Price()
    {
        float cost, distance;
        cout << " Truck Fuel Cost Calculation\n"
            << " Enter the cost of 1 liter of diesel fuel:\n";
        cin >> cost;

        cout << " Enter distance:\n";
        cin >> distance;

        cout << " Truck fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
    }
    virtual void Output()
    {
        cout << "-Truck-\n"
            << " Name - " << name << endl
            << " Average consumption: " << aver_cnsmptn << " liters\n"
            << " Capacity of truck: " << capacity << " tons\n"
            << " Number of seats in truck: " << seats << "\n\n";
        Consumption();
        Price();
        cout << " ***************************\n\n";
    }
};

class Car : public Vehicle
{
public:
    Car() : Vehicle()
    {
        cout << " C-tor by default Car\n";
    }
    virtual ~Car()
    {
        cout << " D-tor Car\n";
    }
    virtual void Name()
    {
        cout << " Fill in the car details\n";
        cout << " Enter car name:\n";
        cin >> name;
    }
    virtual void Aver()
    {
        cout << " Enter the average car fuel consumption:\n";
        cin >> aver_cnsmptn;
    }
    virtual void Capacity()
    {
        cout << " Enter load capacity of car:\n";
        cin >> capacity;
    }
    virtual void Seats()
    {
        cout << " Enter the number of seats in car:\n";
        cin >> seats;
    }
    virtual void Consumption()
    {
        float distance;
        cout << " Car Fuel Consumption Calculation\n"
            << " Enter distance:\n";
        cin >> distance;
        cout << " Consumption for the car on the distance " << distance << " km: " << aver_cnsmptn * distance << " liters\n\n";
    }
    virtual void Price()
    {
        float cost, distance;
        cout << " Car Fuel Cost Calculation\n"
            << " Enter the cost of 1 liter of petrol fuel:\n";
        cin >> cost;

        cout << " Enter distance:\n";
        cin >> distance;

        cout << " Car fuel cost " << ((distance / 100) * aver_cnsmptn) * cost << " UAH\n";
    }
    virtual void Output()
    {
        cout << "-Car-\n"
            << " Name - " << name << endl
            << " Average consumption: " << aver_cnsmptn << " liters\n"
            << " Capacity of car: " << capacity << " tons\n"
            << " Number of seats in car: " << seats << "\n\n";
        Consumption();
        Price();
        cout << " ***************************\n\n";
    }
};

int main()
{
    Vehicle* vehicle[4] = { new Plane(), new Vessel(), new Truck(), new Car()};  
    system("cls"); // для стирания информации о работе конструкторов
    for (size_t i = 0; i < 4; i++)
    {
        vehicle[i]->Name();
        vehicle[i]->Aver();
        vehicle[i]->Capacity();
        vehicle[i]->Seats();
        vehicle[i]->Output();
        vehicle[i]->~Vehicle();

        Sleep(1500);
        system("cls");
    }

    return 0;
}
/*  1. Считаю, что не стоит делать стоимость 1 литра топлива полем в базовом классе,
       т.к. это не считается обобщенной характеристикой для транспортного средства.
       Но можно было бы сделать поле для каждого дочернего класса по виду топлива,
       например, стоимость 1 л авиационного топлива для самолёта, стоимость 1 л 
       дизеля для судна и тд., и использовать эти поля в методе Price();

    2. Также можно было организовать такой вывод:
    - при создании объектов заполнить необходимые поля
    - очистить экран
    - в цикле красиво выводить методом Output() всю информацию о транспорте
    - сделать рассчеты  Consumption(); Price();

Plane() : Vehicle()
    {
        cout << " C-tor by default Plane\n";
        cout << " Fill in the airplane details\n";
        Name();
        Aver();
        Capacity();
        Seats();
    }
int main()
{
    Vehicle* vehicle[4] = { new Plane(), new Vessel(), new Truck(), new Car()};

    system("cls");

    for (size_t i = 0; i < 4; i++)
    {
        vehicle[i]->Output();
        vehicle[i]->~Vehicle();
    }

    return 0;
}
*/