// Реализовать паттерн "Стратегия" на основе примера, приведенного в презентации.
// Применить две стратегии сортировки - по возрастанию и по убыванию.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortStrategy abstract
{
public:
    virtual void Sort(vector<string>& v) abstract;
};

class Descending : public SortStrategy          // сортировка по убыванию
{
    void Sort(vector<string>& v) override
    {
        sort(v.begin(), v.end(), greater<>());
    }
};

class Ascending : public SortStrategy           // сортировка по возрастанию
{
    void Sort(vector<string>& v) override
    {
        sort(v.begin(), v.end(), less<>());
    }
};

class SortedArray
{
    vector<string> vector;
    SortStrategy* sortstrategy{};

public:
    void SetSortStrategy(SortStrategy* sortstrategy)
    {
        this->sortstrategy = sortstrategy;
    }
    void Add(string name)
    {
        vector.push_back(name);
    }
    void Sort()
    {
        sortstrategy->Sort(vector);

        for (string name : vector)
        {
            cout << " " + name << endl;
        }
        cout << endl;
    }
};

int main()
{
    SortedArray ar;

    ar.Add("Strawberry");
    ar.Add("Apple");
    ar.Add("Pineapple");
    ar.Add("Watermelon");
    ar.Add("Grape");
    ar.Add("Apricot");
    ar.Add("Plum");
    ar.Add("Banana");
    ar.Add("Orange");
    ar.Add("Pear");

    Ascending sortUp;
    ar.SetSortStrategy(&sortUp);
    ar.Sort();

    Descending sortDown;
    ar.SetSortStrategy(&sortDown);
    ar.Sort();
}