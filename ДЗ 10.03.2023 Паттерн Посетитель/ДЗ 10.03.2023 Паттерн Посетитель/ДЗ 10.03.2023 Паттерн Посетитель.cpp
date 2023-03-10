#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Square;
class Circle;
class Rectangle;

// Абстрактный класс посетитель
class Visitor {
public:
    virtual void visit(Square& square) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
};

// Абстрактный класс фигуры
class Shape {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Конкретные классы фигур
class Square : public Shape {
public:
    Square(double side) : m_side(side) {}

    double area() const { return m_side * m_side; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_side()
    {
        return m_side;
    }
private:
    double m_side;
};

class Circle : public Shape {
public:
    Circle(double radius) : m_radius(radius) {}

    double area() const { return 3.14159265359 * m_radius * m_radius; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_radius()
    {
        return m_radius;
    }

private:
    double m_radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double area() const { return m_width * m_height; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_width()
    {
        return m_width;
    }

    double getM_height()
    {
        return m_height;
    }
private:
    double m_width;
    double m_height;
};

// Конкретный класс посетителя, реализующий операцию расчета периметра для каждой фигуры
class PerimeterVisitor : public Visitor {
public:
    void visit(Square& square) override {
        m_perimeter += 4 * square.getM_side();
    }

    void visit(Circle& circle) override {
        m_perimeter += 2 * 3.14159265359 * circle.getM_radius();
    }

    void visit(Rectangle& rectangle) override {
        m_perimeter += 2 * (rectangle.getM_width() + rectangle.getM_height());
    }

    double perimeter() const { return m_perimeter; }

private:
    double m_perimeter = 0.0;
};
class DrawVisitor : public Visitor
{
    int height = 0;
    int width = 0;
    string s;
public:
    void visit(Square& square) override 
    {
        s = "Drawing Square\n";
        height = round(square.getM_side());
        width = round(square.getM_side());
    }

    void visit(Circle& circle) override 
    {
        s = "Drawing Circle\n";
        height = 0;
        width = 0;
    }

    void visit(Rectangle& rectangle) override 
    {
        s = "Drawing Rectangle\n";
        height = round(rectangle.getM_height());
        width = round(rectangle.getM_width());
    }

    void draw() const
    {
        cout << s;

        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                cout << " * ";
            }
            cout << "\n";
        }
        cout << endl;
    }
};

// Пример использования паттерна посетитель
int main() {
    std::vector<Shape*> shapes = { new Square(3.4), new Circle(2), new Rectangle(8, 5) };

    PerimeterVisitor perimeterVisitor;
    for (auto shape : shapes) {
        shape->accept(perimeterVisitor);
    }

    cout << "Total perimeter: " << perimeterVisitor.perimeter() << "\n\n";

    DrawVisitor drawVisitor;
    for (auto shape : shapes) {
        shape->accept(drawVisitor);
        drawVisitor.draw();
    }

    // Очистка памяти
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
