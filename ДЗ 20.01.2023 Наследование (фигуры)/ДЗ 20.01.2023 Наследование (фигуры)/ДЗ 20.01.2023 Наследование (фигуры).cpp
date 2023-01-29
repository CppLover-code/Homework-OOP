/*
1) Используя наследование, создайте классы для геометрических фигур
   (см. рисунок из презентации по наследованию). Базовый класс будет
   содержать одно поле - сторона фигуры.
2) Используя множественное наследование, разработать класс
   “Окружность, вписанная в квадрат”.
*/

#include<iostream>
using namespace std;

class Figure													// базовый класс
{
protected:
	float side;
public:

	Figure()
	{
		//cout << " C-tor Figure by default\n";
		side = 9;
	}
	Figure(float s)
	{
		//cout << " C-tor Figure with param\n";
		side = s;
	}
	~Figure()
	{
		//cout << " D-tor Figure\n";
	}
	void Show()
	{
		cout << " Figure \n"
			 << " Side = " << side << "\n";
	}
};

class Triangle : public Figure
{
public:
	Triangle() = default;
	Triangle(float s) : Figure(s) {}
	~Triangle()
	{
		//cout << " D-tor Triangle\n";
	}
	void Show()													// переопределяем метод Show() базового класса Figure
	{
		Figure::Show();
		cout << " Triangle \n"
			 << " Perimeter = " << side * 3 << "\n"
			 << " Area = "		<< pow(side, 2) * sqrt(3) / 4 << "\n\n";
	}
};

class Square : public Figure
{
public:
	Square() = default;
	Square(float s) : Figure(s) {}
	~Square()
	{
		//cout << " D-tor Square\n";
	}
	void Show()													// переопределяем метод Show() базового класса Figure
	{
		Figure::Show();
		cout << " Square \n"
			 << " Perimeter = " << side * 4 << "\n"
			 << " Area = "		<< pow(side, 2) << "\n\n";
	}
};

class Rectangle : public Figure
{
	float side2;
public:
	Rectangle()
	{
		side2 = 5;
	}
	Rectangle(float s, float s2 ) : Figure(s)
	{
		side2 = s2;
	}
	~Rectangle()
	{
		//cout << " D-tor Rectangle\n";
	}
	void Show()													// переопределяем метод Show() базового класса Figure
	{
		Figure::Show();
		cout << " Rectangle \n"
			 << " Second side = " << side2 << "\n"
			 << " Perimeter = "   << 2 * (side + side2) << "\n"
			 << " Area = "        << side * side2 << "\n\n";
	}
};

class Circle : public Figure
{
public:
	Circle() = default;
	Circle(float s) : Figure(s){}
	~Circle()
	{
		//cout << " D-tor Circle\n";
	}
	void Show()													// переопределяем метод Show() базового класса Figure
	{
		Figure::Show();
		cout << " Circle \n"
			 << " Perimeter = " << side * 3.14 << "\n"			// считаем, что известная сторона Figure - это диаметр круга
			 << " Area = "		<< pow(side, 2) / 4 * 3.14 << "\n\n";
	}
};

//////////////////////////////////////////////////////////////////

class Square2													// базовый класс
{
protected:
	float side;
public:
	Square2()
	{
		cout << " Enter the side of the square: \n";
		cin >> side;
	}
	~Square2()
	{
		cout << " D-tor Square2\n";
	}
	void ShowSquare()
	{
		cout << " Square with side " << side << "\n";
	}

};
class Circle2													// базовый класс
{
protected:
	float diameter;
public:
	Circle2()
	{
		cout << " Enter circle diameter: \n";
		cin >> diameter;
	}
	~Circle2()
	{
		cout << " D-tor Circle2\n";
	}
	void ShowCircle()
	{
		cout << " Circle with diameter " << diameter << "\n";
	}
};

class CircleInSquare : public Square2, public Circle2			// множественное наследование
{
public:
	CircleInSquare() = default;
	~CircleInSquare()
	{
		cout << " D-tor CircleInSquare\n";
	}
	void ShowCircleInSquare()
	{
		if (Circle2::diameter != Square2::side)                      // если диаметр окружности не равен стороне квадрата, 
		{
			cout << "\n Oops! A circle cannot be inscribed in a\n"   // то сообщаем, что вписать окружность невозможно
				 << " square because the diameter is not equal\n"
				 << " to the side of the square!\n\n";
		}
		else                                                         // иначе (если диаметр равен стороне),
		{
			cout << "\n Congratulations! A circle is inscribed in\n" // сообщаем, что окружность вписана в квадрат
				 << " a square with a diameter equal to the side\n"
				 << " of the square!\n\n";
		}
	}
};

int main()
{
	Triangle f1(10);
	f1.Show();

	Square f2(5);
	f2.Show();

	Rectangle f3(7, 12);
	f3.Show();

	Circle f4(8);
	f4.Show();

	cout << "\n Circle inscribed in a square\n";

	CircleInSquare f5;
	f5.ShowSquare();
	f5.ShowCircle();
	f5.ShowCircleInSquare();

	return 0;
}
