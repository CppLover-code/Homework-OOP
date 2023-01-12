﻿/*
	Создать шаблонный класс динамического массива (см. урок №2, с. 56).
	Добавить в этот класс методы для добавления элемента к массиву и 
	удаления элемента из массива.
	Добавить метод для расчета суммы элементов этого массива. Создать объекты этого
	класса, инкаспулирующие массивы типа int, double, char и Point.
	Point - это класс, содержащий 2 поля (координаты точки): int x и int y.
*/
// Заметки для меня: разобраться нужны ли деструкторы для char и Point + оптимизация кода!!!

#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = 10 + rand() % 20;
		y = 10 + rand() % 40;
	}

	int getX() { return x; }
	int getY() { return y; }

	friend int operator+=(int& s, Point& obj);
};

template <class T> 
class DynArray
{
	T* arr;
	int size;

public:
	DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
	{
		//std::cout << "Constructor\n";
	}

	DynArray(const DynArray& object) : arr{ new T[object.size] }, size{ object.size }	 // выделяем новый блок динамической памяти того же размера, что и в копируемом экземпляре класса
	{
		for (int i{ 0 }; i < size; ++i)													 // циклом копируем элементы из оригинального блока памяти во вновь выделенный
		{
			arr[i] = object.arr[i];
		}
		//std::cout << "Copy ctor\n";
	}
	
	void random()
	{
		double x;
		for (int i = 0; i < size; ++i)
		{
			x = (650 + rand() % 570) * 0.1;                                             // рандом от 650 до 1220 
			arr[i] = (T)x;
		}
	}
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << "\n";
	}
	T sum()
	{
		T sum = 0;

		for (int i{ 0 }; i < size; ++i) sum += arr[i];
		return sum;
	}
	void printSum()
	{
		std::cout << " Sum of array elements "
			<< this->sum() << "\n\n";
	}
	DynArray<T> addEl(T el);
	DynArray<T> delEl();
	friend int operator+=(int& s, Point& obj);
	friend std::ostream& operator<<(std::ostream& out, Point& obj);
	~DynArray()
	{
		//std::cout << "Destructor главный\n";
		delete[] arr;
	}
};

template <class T>
DynArray<T> DynArray<T>::addEl(T el)
{
	DynArray <T> temp{ size + 1 };

	for (int i{ 0 }; i < temp.size; ++i)						    // циклом копируем элементы из *this в временный объект
	{
		temp.arr[i] = arr[i];
		if (i == temp.size - 1) temp.arr[i] = el;                                   // добавляем в временный объект необходимый элемент
	}

	this->~DynArray();

	arr = new T[temp.size];
	size = temp.size;

	for (int i{ 0 }; i < size; ++i)	arr[i] = temp.arr[i];				    // циклом копируем элементы из временного объекта во вновь выделенный *this

	return *this;
}

template <class T>
DynArray<T> DynArray<T>::delEl()
{
	int s;
	do
	{
		std::cout << "\n" << " Enter the sequence number of the element to be deleted:\n";
		std::cin >> s;
		if (s > size) std::cout << " This number does not exist!\n";
	} while (s > size);
	
	DynArray <T> temp{ size - 1 };

	int t = 0;

	for (int i = 0; i < size; ++i)								// циклом копируем элементы из *this во временный, 
	{	
		if (i == s - 1) continue;								// но без выбранного элемента
		else
		{
			temp.arr[t] = arr[i];
			t++;
		}
	}

	this->~DynArray();

	size = size - 1;
	arr = new T[size];

	for (int i = 0; i < size; ++i) arr[i] = temp.arr[i];					// циклом копируем элементы из временного объекта во вновь выделенный *this

	return *this; 
}

template <>
class DynArray<Point>
{
	Point* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new Point[sizeP] {} }, size{ sizeP }
	{
		//std::cout << "Constructor\n";
	}
	~DynArray()
	{
		std::cout << "Destructor point\n";
		delete[] arr;
	}

	void print()
	{
		for (int i{ 0 }; i < size; ++i)
		{
			std::cout << arr[i].getX() << ' ' << arr[i].getY() << " ";
		}
		std::cout << "\n";
	}
	int sum()
	{
		int sum = 0;

		for (int i{ 0 }; i < size; ++i) sum += arr[i];
		return sum;
	}
	void printSum()
	{
		std::cout << " Sum of array elements "
			<< sum() << "\n\n";
	}
};

std::ostream& operator<<(std::ostream& out, Point& obj)  // перегрузка вывода в консоль
{
	out << obj.getX() << " " << obj.getY();
	return out;
}
int operator+=(int& s, Point& obj)                       // глобальная перегрузка оператора +=
{
	s = s + obj.getX() + obj.getY();
	return s;
}

template <>
class DynArray<char>
{
	char* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new char[sizeP] {} }, size{ sizeP }
	{
		//std::cout << "Constructor\n";
	}
	~DynArray()
	{
		//std::cout << "Destructor char\n";
		delete[] arr;
	}

	void random()
	{
		int x;
		for (int i{ 0 }; i < size; ++i)
		{
			x = 58 + rand() % 68;                                             // рандом от 650 до 1220 
			arr[i] = x;
		}
	}
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << "\n";
	}
	int sum()
	{
		int sum = 0;

		for (int i{ 0 }; i < size; ++i)
		{
			sum += arr[i];
		}
		return sum;
	}
	void printSum()
	{
		std::cout << " Sum of array elements "
			<< sum() << "\n\n";
	}
};


int main()
{
	srand(time(0));
	setlocale(0, "rus");

	DynArray <int> ar1{ 3 };
	ar1.random();
	std::cout << " ar1 elements(int): ";
	ar1.print();
	ar1.printSum();

	DynArray <int> ar2{ ar1 };
	std::cout << " ar2 elements(int): ";
	ar2.print();
	ar2.printSum();

	DynArray <double> ar3{ 3 };
	ar3.random();
	std::cout << " ar3 elements(double): ";
	ar3.print();
	ar3.printSum();

	DynArray <char> ar4{ 3 };
	ar4.random();
	std::cout << " ar4 elements(char): ";
	ar4.print();
	ar4.printSum();

	ar1.addEl(23);
	std::cout << " Adding element to ar1: ";
	ar1.print();

	ar1.delEl();
	std::cout << " Removing element from ar1: ";
	ar1.print();

	DynArray <Point> ar5{3};
	std::cout << "\n" << " ar5 elements(Point): ";
	ar5.print();
	ar5.printSum();

	return 0;
}

// Второй вариант -  неточно  считает для double, потому что переменная для подсчёта суммы имеет тип данных int
// НО РАБОТАЕТ

//#include <iostream>
//
//class Point
//{
//	int x;
//	int y;
//public:
//	Point()
//	{
//		x = 10 + rand() % 20;
//		y = 10 + rand() % 40;
//	}
//
//	int getX() { return x; }
//	int getY() { return y; }
//};
//
//template <class T> class DynArray
//{
//	T* arr;
//	int size;
//
//public:
//	DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
//	{
//		//std::cout << "Constructor\n";
//	}
//
//	DynArray() : DynArray(5) {}
//
//	DynArray(const DynArray& object) : arr{ new T[object.size] }, size{ object.size }	 // выделяем новый блок динамической памяти того же размера, что и в копируемом экземпляре класса
//	{
//		for (int i{ 0 }; i < size; ++i)													 // циклом копируем элементы из оригинального блока памяти во вновь выделенный
//		{
//			arr[i] = object.arr[i];
//		}
//		//std::cout << "Copy ctor\n";
//	}
//	int getElem(int idx) { return arr[idx]; }
//	void setElem(int idx, int val) { arr[idx] = val; }
//	void print();
//	void random();
//	int sum();
//	void printSum();
//	DynArray<T> addEl(T el);
//	DynArray<T> delEl();
//
//	~DynArray()
//	{
//		//std::cout << "Destructor\n";
//		delete[] arr;
//	}
//};
//
//template <class T>
//void DynArray<T>::print()
//{
//	for (int i{ 0 }; i < size; ++i)
//	{
//		std::cout << arr[i] << ' ';
//	}
//	std::cout << "\n";
//}
//
//template <class T>
//void DynArray<T>::random()
//{
//	double x;
//	for (int i{ 0 }; i < size; ++i)
//	{
//		x = (650 + rand() % 570) * 0.1;                                             // рандом от 650 до 1220 
//		arr[i] = (T)x;
//	}
//}
//
//template <class T>
//int DynArray<T>::sum()
//{
//	int sum = 0;
//	for (int i{ 0 }; i < size; ++i)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}
//
//template <class T>
//void DynArray<T>::printSum()
//{
//	std::cout << " Sum of array elements "
//		<< this->sum() << "\n\n";
//}
//
//template <class T>
//DynArray<T> DynArray<T>::addEl(T el)
//{
//	DynArray <T> temp{ size + 1 };
//
//	for (int i{ 0 }; i < temp.size; ++i)						    // циклом копируем элементы из *this в временный объект
//	{
//		temp.arr[i] = arr[i];
//		if (i == temp.size - 1) temp.arr[i] = el;                                   // добавляем в временный объект необходимый элемент
//	}
//
//	this->~DynArray();
//
//	arr = new T[temp.size];
//	size = temp.size;
//
//	for (int i{ 0 }; i < size; ++i)	arr[i] = temp.arr[i];				    // циклом копируем элементы из временного объекта во вновь выделенный *this
//
//	return *this;
//}
//
//template <class T>
//DynArray<T> DynArray<T>::delEl()
//{
//	int s;
//	do
//	{
//		std::cout << "\n" << " Enter the sequence number of the element to be deleted:\n";
//		std::cin >> s;
//		if (s > size) std::cout << " This number does not exist!\n";
//	} while (s > size);
//
//	DynArray <T> temp{ size - 1 };
//
//	int t = 0;
//
//	for (int i = 0; i < size; ++i)								// циклом копируем элементы из *this во временный, 
//	{
//		if (i == s - 1) continue;								// но без выбранного элемента
//		else
//		{
//			temp.arr[t] = arr[i];
//			t++;
//		}
//	}
//
//	this->~DynArray();
//
//	size = size - 1;
//	arr = new T[size];
//
//	for (int i = 0; i < size; ++i) arr[i] = temp.arr[i];					// циклом копируем элементы из временного объекта во вновь выделенный *this
//
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& out, Point& obj) // перегрузка вывода в консоль
//{
//	out << obj.getX() << " " << obj.getY();
//	return out;
//}
//
//int operator+=(int& s, Point& obj)                       // глобальная перегрузка оператора +=
//{
//	s = s + obj.getX() + obj.getY();
//	return s;
//}
//
//int main()
//{
//	srand(time(0));
//	setlocale(0, "rus");
//
//	DynArray <int> ar1{ 3 };
//	ar1.random();
//	std::cout << " ar1 elements(int): ";
//	ar1.print();
//	ar1.printSum();
//
//	DynArray <int> ar2{ ar1 };
//	std::cout << " ar2 elements(int): ";
//	ar2.print();
//	ar2.printSum();
//
//	DynArray <double> ar3{ 3 };
//	ar3.random();
//	std::cout << " ar3 elements(double): ";
//	ar3.print();
//	ar3.printSum();
//
//	DynArray <char> ar4{ 3 };
//	ar4.random();
//	std::cout << " ar4 elements(char): ";
//	ar4.print();
//	ar4.printSum();
//
//	ar1.addEl(23);
//	std::cout << " Adding element to ar1: ";
//	ar1.print();
//
//	ar1.delEl();
//	std::cout << " Removing element from ar1: ";
//	ar1.print();
//
//	DynArray <Point> ar5{ 3 };
//	std::cout << "\n" << " ar5 elements(Point): ";
//	ar5.print();
//	ar5.printSum();
//
//	return 0;
//}




