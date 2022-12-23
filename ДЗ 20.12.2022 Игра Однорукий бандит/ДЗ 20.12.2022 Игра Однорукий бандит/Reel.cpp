#include "Reel.h"
#include <iostream>
#include <ctime>

using namespace std;

Reel::Reel(int m)															//Конструктор
{
	MaxReelLength = m;														//получаем размер

	Line = new int[MaxReelLength];											//создаем очередь

	ReelLength = 0;															//Изначально очередь пуста
}

Reel::~Reel()																//Деструктор
{
	delete[] Line;															//удаление очереди
}

bool Reel::IsEmpty()														//Проверка существования элементов в очереди
{
	return ReelLength == 0;													//Пуст?
}

bool Reel::IsFull()															//Проверка на переполнение очереди
{
	return ReelLength == MaxReelLength;										// Полон? 
}

void Reel::Add(int c)														//Добавление элемента
{																			//Если в очереди есть свободное место, 
																			//то увеличиваем количество																		
	if (!IsFull()) Line[ReelLength++] = c;									//значений и вставляем новый элемент 
}

int Reel::Extract()															// извлечение элемента
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь 
	if (!IsEmpty())
	{
		int temp = Line[0];													//запомнить первый

		for (int i = 1; i < ReelLength; i++)								//сдвинуть все элементы
			Line[i - 1] = Line[i];

		Line[ReelLength - 1] = temp;										// забрасываем первый "вытолкнутый элемент в конец"
		return temp;                                                        // возврат вытолкнутого элемента
	}
	else return -1;
}

int Reel::reelRandom(int& n)												// рандом для барабана и возврат 1 числа для комбинации
{
	int l = 1 + rand() % 5;													// рандомное число оборотов барабана
	//cout << " рандомное число оборотов барабана  " << l << '\n';
	for (int k = 1; k <= l; k++) n = Extract();
	return n;
}

void Reel::Clear()															//Очистка очереди
{
	ReelLength = 0;															//Эффективная "очистка" очереди
}

int Reel::GetCount()														//Количество элементов в очереди
{
	return ReelLength;														//Количество присутствующих в стеке элементов 
}

void Reel::Show()															//демонстрация очереди
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < ReelLength; i++)
	{
		cout << Line[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
