/*
	Добавить в код примера (слайд №5 презентации "Интерфейсы") классы
	для пингвина, слона, утки. Воспользоваться этими классами в main()
	в соответствии с образцом в примере.
	Написать таблицу прецедентов и создать диаграмму прецедентов для
	классов и интерфейсов (действий), присутствующих в данной программе.
	Таблицу прецедентов и диаграмму прецедентов прислать в графических
	файлах со стандартным расширением.
*/
#include<iostream>
using namespace std;

class Animal                                            // базовый абстрактный класс
{
protected:
    string name;
    int kg;
public:
    Animal() = default;
    Animal(string n, int k)
    {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal                                          // интерфейсы в стиле С++
{
    virtual void Eat() = 0;
    virtual void Move() = 0;
};
struct IBird
{
    virtual void Fly() = 0;
};
struct ISwim
{
    virtual void Swim() = 0;
};

class Cat : public Animal, public IAnimal
{
    string color;
public:
    Cat(string n, int k, string c) : Animal(n, k)
    {
        color = c;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Cat eats\n";
    }
    void Move()
    {
        cout << "Cat moves\n";
    }
};

class Parrot : public Animal, public IAnimal, public IBird
{
public:
    Parrot(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Parrot eats\n";
    }
    void Move()
    {
        cout << "Parrot moves\n";
    }
    // реализация интерфейса IBird
    void Fly()
    {
        cout << "Parrot flies\n";
    }
};

class Penguin : public Animal, public IAnimal, public ISwim
{
public:
    Penguin(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Penguin eats\n";
    }
    void Move()
    {
        cout << "Penguin moves\n";
    }
    // реализация интерфейса ISwim
    void Swim()
    {
        cout << "Penguin swims\n";
    }
};
class Elephant : public Animal, public IAnimal, public ISwim
{
public:
    Elephant(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Elephant eats\n";
    }
    void Move()
    {
        cout << "Elephant moves\n";
    }
    // реализация интерфейса ISwim
    void Swim()
    {
        cout << "Elephant swims\n";
    }
};
class Duck : public Animal, public IAnimal, public ISwim, public IBird
{
public:
    Duck(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Duck eats\n";
    }
    void Move()
    {
        cout << "Duck moves\n";
    }
    // реализация интерфейса ISwim
    void Swim()
    {
        cout << "Duck swims\n";
    }
    // реализация интерфейса IBird
    void Fly()
    {
        cout << "Duck flies\n";
    }
};
int main()
{
    IAnimal* ref;       // кушать, двигаться
    IBird* f;           // летать
    ISwim* s;           // плавать

    ref = new Cat("Cat", 3, "white");
    ref->Eat();
    ref->Move();

    ref = new Parrot("Ara", 2);
    ref->Eat();
    ref->Move();
    f = new Parrot("Ara", 3);
    f->Fly();

    ref = new Penguin("Vasya", 10);
    ref->Eat();
    ref->Move();
    s = new Penguin("Vasya", 10);
    s->Swim();

    ref = new Elephant("Dusya", 1200);
    ref->Eat();
    ref->Move();
    s = new Elephant("Dusya", 1200);
    s->Swim();

    ref = new Duck("Jenya", 3);
    ref->Eat();
    ref->Move();
    f = new Duck("Jenya", 3);
    f->Fly();
    s = new Duck("Jenya", 3);
    s->Swim();
}
