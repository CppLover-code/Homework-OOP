/*
Создать класс ноутбук. На основе других объектов, таких как:
Процессор
ОЗУ
Мышка
Веб-камера
Принтер
Видеокарта
Каждый объект представлен отдельным классом. Собрать ноутбук,
используя агрегацию и композицию
*/
#include <iostream>
using namespace std;

class Processor
{
	string manufacturer;											// производитель 
	int core;												// количество ядер
public:
	Processor()
	{
		manufacturer = " Intel";
		core = 4;
	}
	Processor(string s,int c) : manufacturer{s}, core{c}{}
	void show()
	{
		cout << " Processor \n"
			 << " Manufacturer - " << manufacturer << "\n"
			 << " Number of Cores - " << core << "\n\n";
	}
};
class RAM 
{
	int volume;												// объем памяти
public:

	RAM() : volume{256}{}
	RAM(int v) : volume{v}{}
	void show()
	{
		cout << " RAM \n"
			 << " Memory - " << volume << "\n\n";
	}
};
class Mouse
{
	string manufacturer;											// производитель 
public:
	Mouse() : manufacturer{ " Logitech" } {}
	Mouse(string s) : manufacturer{ s } {}
	void show()
	{
		cout << " Mouse \n"
			 << " Manufacturer - " << manufacturer << "\n\n";
	}
};
class Camera 
{
	int resolution;												// разрешение
public:
	Camera() : resolution{ 640 } {}
	Camera(int r) : resolution{ r } {}
	void show()
	{
		cout << " Camera \n"
			<< " Resolution - " << resolution << "\n\n";
	}
};
class Printer
{
	string manufacturer;											// производитель 
public:
	Printer() : manufacturer{ " Xerox" } {}
	Printer(string s) : manufacturer{ s } {}
	void show()
	{
		cout << " Printer \n"
			 << " Manufacturer - " << manufacturer << "\n\n";
	}
};
class Videocard
{
	string manufacturer;											// производитель 
public:
	Videocard() : manufacturer{ " NVIDIA" } {}
	Videocard(string s) : manufacturer{ s } {}
	void show()
	{
		cout << " Videocard \n"
			 << " Manufacturer - " << manufacturer << "\n\n";
	}
};

class Laptop
{
	string Notebook_model;
	Processor processor;											// сильная связь - композиция
	RAM memory;
	Mouse* mouse;												// слабая связь - агрегация
	Camera camera;
	Printer* printer; 
	Videocard videocard;

public:
	Laptop(string s, string s1, int y, int x, Mouse* m, int c, Printer* p, string s2) : 
					 processor(s1,y),memory(x), mouse(m), camera(c), printer(p), videocard(s2)		// конструктор принимает указатель на существующие мышку и принтер
	{
		Notebook_model = s;
	}
	void show()
	{
		cout << " Laptop \n"
			 << " Model - " << Notebook_model << "\n\n";
		processor.show();
		memory.show();
		mouse->show();
		camera.show();
		printer->show();
		videocard.show();
	}
	~Laptop()
	{
		cout << "Destruct Laptop\n";
	}
};

int main()
{
	Mouse mouse{ "Asus" };
	Printer printer{ "Canon" };

	Laptop* laptop1 = new Laptop{ " HP Pavilion", " AMD ", 8, 16, &mouse, 720, &printer, " AMD "};
	laptop1->show();

	delete laptop1;

	cout << "-------------------------------------------\n\n";
	Laptop laptop2(" Asus Zenbook Pro", " Intel ", 4, 16, &mouse, 720, &printer, " Intel ");		// вставили ту же мышку и принтер в другой ноутбук
	laptop2.show();

	return 0;
}
