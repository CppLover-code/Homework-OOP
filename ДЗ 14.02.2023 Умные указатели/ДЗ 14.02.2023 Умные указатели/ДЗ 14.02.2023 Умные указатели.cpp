// Измените следующую программу(см.ниже), заменив обычный
// указатель на умный указатель std::unique_ptr, где это необходимо.

#include <iostream>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator) {}
    ~Fraction() { std::cout << " D-tor Fraction\n"; }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }
};

void printFraction(Fraction* ptr)
{
    if (ptr) std::cout << *ptr << std::endl;
}

//void printFraction1(std::unique_ptr<Fraction> ptr)
//{
//    if (ptr) std::cout << *ptr << std::endl;
//} // Fraction уничтожается при выходе из ф-ии

int main()
{
    auto ptr = std::make_unique<Fraction>(7, 9);
    printFraction(ptr.get());
    //printFraction1(std::move(ptr)); // используется семантика перемещения 
    std::cout << "\n" << *ptr << std::endl;
}