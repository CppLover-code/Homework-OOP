#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Roll
{
    char* roll_name = nullptr;
    float  roll_length = 0;
    float  roll_width = 0;
    float  price = 0;

public:
    Roll()
    {
        cout << "сработал конструктор Roll\n";
        if (std::cin.peek() == '\n') std::cin.get();                                        // если от предыдущих итераций осталс€ символ \n, то стираем его

        if (roll_name != nullptr) delete[] roll_name;
        char tmp[20];
        cout << "¬ведите название обоев: ";
        cin.getline(tmp, 20);
        roll_name = new char[strlen(tmp) + 1];
        strcpy_s(roll_name, strlen(tmp) + 1, tmp);

        cout << "¬ведите длину обоев: ";
        cin >> roll_length;

        cout << "¬ведите ширину обоев: ";
        cin >> roll_width;

        cout << "¬ведите цену 1 рулона обоев: ";
        cin >> price;
    }

    float getRollL() { return roll_length; }
    float getRollW() { return roll_width; }
    float getRollP() { return price; }

    void rollOutput();
    
    ~Roll()
    {
        cout << "сработал деструктор Roll\n";
        if (roll_name != nullptr)
        {
            delete[] roll_name;
        }
    }
};
class Room
{
    char* room_name = nullptr;
    float room_length = 0;
    float room_width = 0;
    float room_height = 0;
    bool room_ceil = 0;
    Roll* roll = nullptr;

public:

    Room()
    {
        cout << "сработал конструктор Room\n";
        if (std::cin.peek() == '\n') std::cin.get();                                        // если от предыдущих итераций осталс€ символ \n, то стираем его

        char tmp[20];
        cout << "\n¬ведите название комнаты: ";
        cin.getline(tmp, 20);
        createName(tmp);

        std::cout << "¬ведите длину комнаты: ";
        cin >> room_length;

        std::cout << "¬ведите ширину комнаты: ";
        cin >> room_width;

        std::cout << "¬ведите высоту комнаты: ";
        cin >> room_height;

        std::cout << " леить потолок: 1 - да / 0 - нет ";
        cin >> room_ceil;
        std::cout << "\n";

        roll = new Roll[1]{};
    }

    void createName(const char* name);
    void Output();
    float priceCalculation();

    ~Room()
    {
        cout << "сработал деструктор Room\n";
        if (room_name != nullptr) delete[] room_name;

        delete[] roll;
    }
};
class Flat
{
    Room* rooms = nullptr;
    int rooms_count = 0;

public:
    Flat(int count) : rooms{ new Room[count] {} }, rooms_count{ count }                                       // происходит выделение пам€ти и инициалищаци€ (комнатами)
    {
        cout << "сработал конструктор Flat дл€ выделени€ пам€ти под массив размером"
             << rooms_count << "\n";
        system("cls");
    }

    float getPrice();
    void flatOutput();

    ~Flat()
    {
        cout << "сработал деструктор Flat\n";
        delete[] rooms;
    }
};
