#include <iostream>
#include <windows.h>
#include "Classes.h"
using namespace std;

void Roll::rollOutput()
{
    cout << "\n" << "Название обоев: " << roll_name << std::endl
        << "Длина обоев: " << roll_length << std::endl
        << "Ширина обоев: " << roll_width << std::endl
        << "Цена 1 рулона: " << price << std::endl;
}

void Room::createName(const char* name)
{
    this->room_name = new char[strlen(name) + 1];
    strcpy_s(this->room_name, strlen(name) + 1, name);
}

void Room::Output()
{
    std::cout << "\n" << "Название комнаты: " << room_name << std::endl
        << "Длина комнаты: " << room_length << std::endl
        << "Ширина комнаты: " << room_width << std::endl
        << "Высота комнаты: " << room_height << std::endl
        << "Клеить потолок: " << ((room_ceil) ? "да" : "нет") << std::endl;
    roll[0].rollOutput();
}

float Room::priceCalculation()                                                                             // для одной комнаты
{
    float P;                                                                                               // периметр
    float strips;                                                                                          // необх кол-во полос рулона для всей комнаты
    float stripsRoll;                                                                                      // кол-во полос в 1 рулоне
    float rollCountWalls;                                                                                  // кол-во рулонов обоев для стен на 1 комнату
    float rollCountCeiling;                                                                                // кол-во рулонов обоев для потолка 1 комнаты

    P = 2 * (room_length + room_width);
    strips = P / roll->getRollW();
    stripsRoll = roll->getRollL() / room_height;
    rollCountWalls = strips / stripsRoll;

    rollCountCeiling = (room_width / roll->getRollW()) / (roll->getRollL() / room_length);

    if (room_ceil) return roll->getRollP() * (rollCountWalls + rollCountCeiling);                          // если надо клеить потолок
    else return roll->getRollP() * rollCountWalls;                                                         // если НЕ надо клеить потолок
}

float Flat::getPrice()                                                                                     // метод для получения и суммирования цен на обои для каждой комнаты
{
    float totalCost = 0;
    for (int i = 0; i < rooms_count; ++i)
    {
        totalCost += rooms[i].priceCalculation();
    }
    return totalCost;
}

void Flat::flatOutput()
{
    for (int i = 0; i < rooms_count; ++i)
    {
        cout << "Комната " << i + 1 << "\n";
        rooms[i].Output();
    }
    cout << "\n\n";
}