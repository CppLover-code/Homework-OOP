/*
В контейнере типа vector хранится набор целых чисел. Создайте функторы
для решения следующих задач:
1) Увеличение значений всех элементов контейнера на заданную константу;
2) Удаление из контейнера элементов, равных искомому значению.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Eq.h"
#include "Inc.h"

using namespace std;

void vFill(vector<int>& vect);									// заполнение вектора рандомными числами
void vOutput(vector<int>& vect);								// вывод элементов на экран
void vIncrease(vector<int>& vect);								// увеличение элементов на заданную константу
void vRemove(vector<int>& vect);								// удаление элементов, равных введенному значению

int main()
{
	srand(time(0));
	cout << " Vector Int\n\n";

	vector<int>vInt;                    
	vFill(vInt);
	vOutput(vInt);

	cout << " Increase elements\n";
	vIncrease(vInt);
	vOutput(vInt);

	cout << " Removing numbers\n";
	vRemove(vInt);
	vOutput(vInt);

	return 0;
}

void vFill(vector<int>& vect)									// заполнение вектора рандомными числами
{
	cout << " How many integers do you need to generate in a vector?\n";
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
		vect.push_back(rand() % 10 + 1);
}
void vOutput(vector<int>& vect)									// вывод элементов на экран
{
	for (vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it)
		cout << *it << " ";
	cout << "\n\n";
}
void vIncrease(vector<int>& vect)								// увеличение элементов на заданную константу
{
	cout << " Enter a number to increase vector elements:\n";
	int t;
	cin >> t;

	Inc s(t);
	vector<int>::iterator itt;
	for (itt = vect.begin(); itt != vect.end(); ++itt)
	{
		*itt = s(*itt);
	}
}
void vRemove(vector<int>& vect)									// удаление элементов, равных введенному значению
{
	cout << " Enter the number:\n";
	int n;														// число, которое нужно удалить
	cin >> n;

	Eq f(n);                                                    // создаем объект, который будет хранить число для удаления

	// Вариант с использованием функтора
	vector<int>::iterator it1 = vect.begin();					// итератор для прохода по элементам вектора и их изменения
	while (it1 != vect.end())                                   // пока не конец вектора
	{
		if (f(*it1))                                            // делаем проверку с помощью функтора ( перегрузка () сравнивает 
		{                                                       // число для удаления с каждым элементом вектора)
			vect.erase(it1);									// стираем элемент, на который указывает итератор
			it1 = vect.begin();                                 // возвращаем итератор в начало вектора
		}
		else it1++;
	}
	//// Вариант без использования функтора
	//vector<int>::iterator it1 = remove(vInt.begin(), vInt.end(),n);
	//vInt.erase(it1, vInt.end());
}
