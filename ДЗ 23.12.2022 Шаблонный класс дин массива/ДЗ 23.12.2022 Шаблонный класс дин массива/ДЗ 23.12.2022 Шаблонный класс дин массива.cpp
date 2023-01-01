/*
	Создать шаблонный класс динамического массива (см. урок №2, с. 56).
	Добавить в этот класс методы для добавления элемента к массиву и 
	удаления элемента из массива
*/
#include <iostream>

template <class T> class DynArray
{
	T* arr;
	int size;

public:
	DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
	{
		//std::cout << "Constructor\n";
	}

	DynArray() : DynArray(5) {}

	DynArray(const DynArray& object) : arr{ new T[object.size] }, size{ object.size }	 // выделяем новый блок динамической памяти того же размера, что и в копируемом экземпляре класса
	{
		for (int i{ 0 }; i < size; ++i)													 // циклом копируем элементы из оригинального блока памяти во вновь выделенный
		{
			arr[i] = object.arr[i];
		}
		//std::cout << "Copy ctor\n";
	}
	int getElem(int idx) { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print();
	void random();
	DynArray<T> addEl(T el);
	DynArray<T> delEl();

	~DynArray()
	{
		//std::cout << "Destructor\n";
		delete[] arr;
	}
};

template <class T>
void DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n\n";
}

template <class T>
void DynArray<T>::random()
{
	double x;
	for (int i{ 0 }; i < size; ++i)
	{
		x = (650 + rand() % 570) * 0.1;                                             // рандом от 650 до 1220 
		arr[i] = (T)x;
	}
}

template <class T>
DynArray<T> DynArray<T>::addEl(T el)
{
	DynArray <T> temp{ size + 1 };

	for (int i{ 0 }; i < temp.size; ++i)											// циклом копируем элементы из *this в временный объект
	{
		temp.arr[i] = arr[i];
		if (i == temp.size - 1) temp.arr[i] = el;                                   // добавляем в временный объект необходимый элемент
	}

	this->~DynArray();

	arr = new T[temp.size];
	size = temp.size;

	for (int i{ 0 }; i < size; ++i)	arr[i] = temp.arr[i];						   // циклом копируем элементы из временного объекта во вновь выделенный *this

	return *this;
}

template <class T>
DynArray<T> DynArray<T>::delEl()
{
	int s;
	do
	{
		std::cout << " Enter the sequence number of the element to be deleted:\n";
		std::cin >> s;
		if (s > size) std::cout << " This number does not exist!\n";
	} while (s > size);
	
	DynArray <T> temp{ size - 1 };

	int t = 0;

	for (int i = 0; i < size; ++i)													// циклом копируем элементы из *this во временный, 
	{	
		if (i == s - 1) continue;													// но без выбранного элемента
		else
		{
			temp.arr[t] = arr[i];
			t++;
		}
	}

	this->~DynArray();

	size = size - 1;
	arr = new T[size];

	for (int i = 0; i < size; ++i) arr[i] = temp.arr[i];							// циклом копируем элементы из временного объекта во вновь выделенный *this

	return *this; 
}

int main()
{
	srand(time(0));
	setlocale(0, "rus");

	DynArray <int> ar1{ 10 };
	ar1.random();
	std::cout << " ar1 elements: ";
	ar1.print();
	DynArray <int> ar2{ ar1 };
	std::cout << " ar2 elements: ";
	ar2.print();

	DynArray <double> ar3{ 10 };
	ar3.random();
	std::cout << " ar3 elements: ";
	ar3.print();

	DynArray <char> ar4{ 10 };
	ar4.random();
	std::cout << " ar4 elements: ";
	ar4.print();

	ar1.addEl(23);
	std::cout << " Adding element to ar1: ";
	ar1.print();

	ar1.delEl();
	std::cout << " Removing element from ar1: ";
	ar1.print();

	return 0;
}