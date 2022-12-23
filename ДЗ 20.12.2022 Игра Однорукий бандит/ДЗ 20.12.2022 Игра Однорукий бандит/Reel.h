#pragma once

class Reel
{
	int* Line;																	// массив для хранения очереди
	
	int MaxReelLength;															//Максимальный размер очереди
	
	int ReelLength;																//Текущий размер очереди

public:

	Reel(int m);																//Конструктор
	
	~Reel();																	//Деструктор
	
	bool IsEmpty();																//Проверка существования элементов в очереди

	bool IsFull();																//Проверка на переполнение очереди

	void Add(int c);															//Добавление элемента
	
	int Extract();																// извлечение элемента

	int reelRandom(int& n);														// рандом для барабана и возврат 1 числа для комбинации

	void Clear();																//Очистка очереди
	
	int GetCount();																//Количество элементов в очереди
	
	void Show();																//демонстрация очереди

};
