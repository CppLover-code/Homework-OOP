#include <iostream>
#include <string>
using namespace std;

// AbstractProduct - травоядные
class Herbivore abstract
{
protected:
    double weight;
    bool life;
public:
    Herbivore()
    {
        weight = 0;
        life = 0;
    }
    virtual string GetName() abstract;
    virtual void EatGrass() abstract;
    virtual double GetWeight() abstract;
    virtual bool GetLife() abstract;
};

// ConcreteProduct травоядных (также реализуют интерфейс Abstract Product)
class Wildebeest : public Herbivore  // Антилопа гну
{
public:
    Wildebeest()
    {
        weight = 180;
        life = 1;
    }
    string GetName() override
    {
        return "Wildebeest";
    }
    void EatGrass() override
    {
        weight += 10;
    }
    double GetWeight() override { return weight; }
    bool GetLife() override { return life; }
};
class Bison : public Herbivore  // Бизон
{
public:
    Bison()
    {
        weight = 400;
        life = 1;
    }
    string GetName() override
    {
        return "Bison";
    }
    void EatGrass() override
    {
        weight += 10;
    }
    double GetWeight() override { return weight; }
    bool GetLife() override { return life; }
};
class Elk : public Herbivore  // Лось
{
public:
    Elk()
    {
        weight = 300;
        life = 1;
    }
    string GetName() override
    {
        return "Elk";
    }
    void EatGrass() override
    {
        weight += 10;
    }
    double GetWeight() override { return weight; }
    bool GetLife() override { return life; }
};

// AbstractProduct - плотоядные
class Carnivore abstract
{
protected:
    int power;
public:
    Carnivore()
    {
        power = 0;
    }
    virtual string GetName() abstract;
    virtual void Eat(Herbivore* h) abstract;
    virtual double GetPower() abstract;
};

// ConcreteProduct плотоядных (также реализуют интерфейс Abstract Product)
class Lion : public Carnivore  // Лев
{
public:
    Lion()
    {
        power = 200;
    }
    string GetName() override
    {
        return "Lion";
    }
    void Eat(Herbivore* h) override
    {
        if (power > h->GetWeight()) power += 10;
        else power -= 10;
    }
    double GetPower() override { return power; }
};
class Wolf : public Carnivore  // Волк 
{
public:
    Wolf()
    {
        power = 420;
    }
    string GetName() override
    {
        return "Wolf";
    }
    void Eat(Herbivore* h) override
    {
        if (power > h->GetWeight()) power += 10;
        else power -= 10;
    }
    double GetPower() override { return power; }
};
class Tiger : public Carnivore  // Тигр
{
public:
    Tiger()
    {
        power = 330;
    }
    string GetName() override
    {
        return "Tiger";
    }
    void Eat(Herbivore* h) override
    {
        if (power > h->GetWeight()) power += 10;
        else power -= 10;
    }
    double GetPower() override { return power; }
};

//Класс КЛИЕНТ Мир животных
class AnimalWorld
{
    Herbivore* herbivore;
    Carnivore* carnivore;
public:
    Herbivore* GetHerbivore()
    {
        return herbivore;
    }
    void SetHerbivore(Herbivore* herbivore)
    {
        this->herbivore = herbivore;
    }
    Carnivore* GetCarnivore()
    {
        return carnivore;
    }
    void SetCarnivore(Carnivore* carnivore)
    {
        this->carnivore = carnivore;
    }
    void MealsHerbivore(Herbivore* herbivore)
    {
        this->herbivore->EatGrass();
    }
    void NutritionCarnivore(Carnivore* carnivore)
    {
        this->carnivore->Eat(herbivore);
    }
};

// AbstractFactory - объявляет интерфейс для операций, создающих абстрактные объекты-продукты
class Continent abstract
{
public:
    virtual Herbivore* CreateHerbivore() abstract;
    virtual Carnivore* CreateCarnivore() abstract;
};

//ConcreteFactory Africa- реализует операции, создающие конкретные объекты-продукты
class Africa : public Continent
{
public:
    Herbivore* CreateHerbivore() override
    {
        return new Wildebeest();
    }
    Carnivore* CreateCarnivore() override
    {
        return new Lion();
    }    
};

// ConcreteFactory North America - реализует операции, создающие конкретные объекты-продукты
class NorthAmerica : public Continent
{
public:
    Herbivore* CreateHerbivore() override
    {
        return new Bison();
    }
    Carnivore* CreateCarnivore() override
    {
        return new Wolf();
    }
};

// ConcreteFactory Eurasia - реализует операции, создающие конкретные объекты-продукты
class Eurasia : public Continent
{
public:
    Herbivore* CreateHerbivore() override
    {
        return new Elk();
    }
    Carnivore* CreateCarnivore() override
    {
        return new Tiger();
    }
};

/*
Класс, производящий "конфигурирование" континента
*/
class ContConfigurator
{
    // Фабрика составляющих континента
    Continent* cont;
public:
    Continent* GetCont()
    {
        return cont;
    }
    void SetCont(Continent* pCont)
    {
        cont = pCont;
    }
    void Configure(AnimalWorld& aw) // Метод "конфигурирования" континента
    {
        aw.SetHerbivore(cont->CreateHerbivore());
        aw.SetCarnivore(cont->CreateCarnivore()); 
    }
};

void Print(string configName, Continent* cont)
{
    AnimalWorld aw;
    ContConfigurator configurator{};
    configurator.SetCont(cont);
    configurator.Configure(aw);
    //cout << "======== " + configName + " ========" << endl;
   
    int t;
    do
    {
        cout << "Herbivore: " + aw.GetHerbivore()->GetName()
            << " Weight " << aw.GetHerbivore()->GetWeight()
            << " Life " << aw.GetHerbivore()->GetLife() << endl;

        cout << "Carnivore: " + aw.GetCarnivore()->GetName()
            << " Power " << aw.GetCarnivore()->GetPower() << endl;

        cout << " 1. Feed the herbivore\n"
             << " 2. Carnivore hunting\n";
        cin >> t;

        if(t == 1) aw.MealsHerbivore(aw.GetHerbivore());  // питание травоядного 
        else if (t == 2)                                  // питание хищника
        {
            aw.NutritionCarnivore(aw.GetCarnivore());
            if (aw.GetHerbivore()->GetWeight() < aw.GetCarnivore()->GetPower()) // если вес травоядного меньше силы хищника
            {
                cout << " ----------\n";
                cout << aw.GetCarnivore()->GetName() << " was eaten by " << aw.GetCarnivore()->GetName() << endl; // хищник съедает травоядного
                break;
            }
        }  
    } while (aw.GetCarnivore()->GetPower() > 0); //aw.GetHerbivore()->GetLife() != 0 || 

    if (aw.GetCarnivore()->GetPower() <= 0)  // если сила хищника на минимуме
    {
        cout << " ----------\n";             // выводим сообщение
        cout << aw.GetCarnivore()->GetName() << " was powerless!" << endl;
    }   
}


int main()
{
    Continent* contFactory{};
    cout << " Welcome to the Animal World!\n\n";

    cout << " Choose a continent\n"
        << " 1 - Africa\n"
        << " 2 - North America\n"
        << " 3 - Eurasia\n";

    short ch;
    cin >> ch;
    switch (ch)
    {
        case 1:
            contFactory = new Africa();
            cout << "======== " << "Africa" << " ========" << endl;
            Print("Africa", contFactory);            
            break;

        case 2: 
            contFactory = new NorthAmerica();
            cout << "======== " << "North America" << " ========" << endl;
            Print("North America", contFactory);
            break;

        case 3: 
            contFactory = new Eurasia();
            cout << "======== " << "Eurasia" << " ========" << endl;
            Print("Eurasia", contFactory);
            break;

        default: 
            cout << " Wrong input! Bye! Bye!\n"; 
            exit(0);
    }
    delete contFactory;
}