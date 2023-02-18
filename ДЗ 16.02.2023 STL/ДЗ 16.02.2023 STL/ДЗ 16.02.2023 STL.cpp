/*
    1) Создайте вектор для хранения элементов типа Point. Сохраните в этом
       векторе 5 элементов типа Point. Выведите элементы сохраненного вектора на экран.
    2) Создайте ассоциативный массив (контейнер map) из 5 элементов для сохранения
       информации о среднем балле студентов. Каждый элемент этого контейнера будет
       содержать пару "имя студента" - средний балл студента.
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int X;
//	int Y;
//public:
//	Point(int x, int y) : X(x),Y(y){}
//	friend istream& operator>>(istream& is, Point& P);
//	friend ostream& operator<<(ostream& os, const Point& P);
//};
//istream& operator>>(istream& is, Point& P) 
//{
//	is >> P.X;
//	is >> P.Y;
//	return is;
//}
//ostream& operator<<(ostream& os, const Point& P)
//{
//	os << "X = " << P.X << '\t';
//	os << "Y = " << P.Y << '\n';
//	return os;
//}
//
//int main()
//{
//	cout << " -Vector Point-" << "\n\n";
//	vector<Point> pvect;									// создаем вектор, который содержит элементы типа Point
//	int x, y;
//
//	cout << " Enter point data" << endl;
//	int i = 0;
//	for (; i < 5; i++)
//	{
//		cout << " Point " << i + 1 << endl;
//		cin >> x >> y;
//		pvect.push_back(Point(x,y));						// заполняем вектор 5-ю элементами
//	}
//
//	cout << " Created points" << endl;
//	i = 1;
//	vector<Point>::const_iterator it;						// создаем итератор 
//	for (it = pvect.begin(); it != pvect.end(); it++,i++)	// выводим элементы с помощью объекта-указателя it(итератор)
//	{
//		cout << " Point " << i << ": " << *it << endl;
//	}
//}

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	cout << " Map -Student grades-" << "\n\n";
	map<string, float> myMap;
	myMap.insert(make_pair("Ivanov Ivan", 9.7));
	myMap.insert(make_pair("Petrov Petr", 7.6));
	myMap.insert(make_pair("Fedorov Fedr", 10.8));
	myMap.insert(make_pair("Sergeev Sergey", 9.9));
	myMap.insert(make_pair("Markov Mark", 11.2));

	map<string, float>::const_iterator it; 
	it = myMap.begin(); 
	while (it != myMap.end()) 
	{
		cout << it->first << " = " << it->second << endl; 
		++it;
	}
	cout << '\n';
}

// ОПЫТЫ работы  с MAP
// ОПЫТ 1
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//
//class Student
//{
//	string name;
//	int grades[5];
//public:
//	Student(string n) : name(n)
//	{
//		cout << "Enter 5 student grades: ";
//		for (size_t i = 0; i < 5; i++)
//		{
//			cin >> grades[i];
//		}
//	}
//	float Average()
//	{
//		float sum = 0;
//		for (size_t i = 0; i < 5; i++)
//		{
//			sum += grades[i];
//		}
//		return sum / 5;
//	}
//	bool operator<(const Student b) const
//	{
//		return name > b.name;
//	}
//	//friend ostream& operator<<(ostream& os, const Student& S);
//};
//
////ostream& operator<<(ostream& os, const Student& S)
////{
////	os << S.name;
////	return os;
////}
//
//int main()
//{
//	std::map<string, float> studmap;
//	string name;
//	for (size_t i = 0; i < 2; i++)
//	{
//		cout << " Enter student name: ";
//		cin >> name;
//		studmap.insert(std::make_pair(name, Student(name).Average())); // создается временный объект(логика в создании объекта гдэ-э-э???) нет смысла, тк можно сделать массив и функцию без класса
//	}                                                                  // но работает без ошибок
//
//	map<string, float>::const_iterator it;
//	it = studmap.begin();
//	while (it != studmap.end())
//	{
//		std::cout << it->first << " = " << it->second << endl;
//		++it;
//	}
//	std::cout << '\n';
//}


// ОПЫТ 2
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//class Student
//{
//	string name;
//	int grades[5];
//public:
//	Student()
//	{
//		cout << " Enter student name: ";
//		cin >> name;
//		cout << "Enter 5 student grades: ";
//		for (size_t i = 0; i < 5; i++)
//		{
//			cin >> grades[i];
//		}
//	}
//	float Average()
//	{
//		int sum = 0;
//		for (size_t i = 0; i < 5; i++)
//		{
//			sum += grades[i];
//		}
//		return float(sum / 5);
//	}
//	bool operator<(const Student b) const
//	{
//		return name > b.name;
//	}
//	friend ostream& operator<<(ostream& os, const Student& S);
//};
//
//ostream& operator<<(ostream& os, const Student& S)
//{
//	os << S.name;
//	return os;
//}
//
//int main()
//{
//	std::map<Student, float> studmap;
//	for (size_t i = 0; i < 2; i++)
//	{
//		Student n;  // проблема тут (объект каждый раз с одним и тем же именем), но работает без ошибок
//		studmap.insert(std::make_pair(n, n.Average()));
//	}
//
//	map<Student, float>::const_iterator it;
//	it = studmap.begin();
//	while (it != studmap.end())
//	{
//		std::cout << it->first << " = " << it->second << endl;
//		++it;
//	}
//	std::cout << '\n'; 
//}

