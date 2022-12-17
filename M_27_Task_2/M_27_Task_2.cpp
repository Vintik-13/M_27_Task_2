/*Задание 2. Иерархия геометрических фигур

Что нужно сделать
Спроектируйте иерархию классов различных фигур: круг, квадрат,
равносторонний треугольник, прямоугольник.
Для всех этих фигур есть общие поля-данные — это координаты их
центра и условный цвет фигуры: красный, синий или зелёный.
Для отдельных фигур есть и уникальные параметры: радиус для круга,
длина ребра для квадрата и равностороннего треугольника, ширина и
высота для прямоугольника. Все данные — это вещественные числа с
удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения площади
фигуры, а также метод нахождения прямоугольника, описывающего фигуру
полностью (он может быть больше зоны фигуры, но не меньше).*/

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <algorithm>


enum class Color {
    RED,
    BLUE,
    GREEN
};

struct Coord {
    double x = 0.0;
    double y = 0.0;
};

class Figure {
protected:
    std::string name;
    Color color;
    Coord coord;
    Figure() : name(""), color(Color::RED) {}
    Figure(const std::string inName, Color inColor, Coord inCoord) : name(inName), color(inColor), coord(inCoord) {}
public:
    
    std::string GetName() const { return name; }
    std::string GetColor() const {
        if (color == Color::RED)
            return "The color of the figure is red";
        else if (color == Color::GREEN)
            return "The color of the figure is green";
        else if (color == Color::BLUE)
            return "The color of the figure is blue";
        else
            return "";
    }
    virtual double SquareFigure() const { return 0; }
    virtual std::string RectangLe() const { return ""; }
};

class Circle : public Figure {
    double radius;

public:    
    Circle() : radius(0) {}
    Circle(Color inColor, Coord inCoord, double inRadius) : Figure("Circle", inColor, inCoord) {
        assert(inRadius >= 0);
        radius = inRadius;
    }      
    double SquareFigure() const override {
        return atan(1) * 4 * radius;
    }
    std::string RectangLe() const override {
        double A = 0.0; double B = 0.0; double C = 0.0; double D = 0.0;

        return "A: x = " + std::to_string(coord.x - radius) + " y = " + std::to_string(coord.y - radius) + "\n" +
            "B: x = " + std::to_string(coord.x - radius) + " y = " + std::to_string(coord.y + radius) + "\n" +
            "C: x = " + std::to_string(coord.x + radius) + " y = " + std::to_string(coord.y + radius) + "\n" +
            "D: x = " + std::to_string(coord.x + radius) + " y = " + std::to_string(coord.y - radius) + "\n";
    }
};

class Triangle : public Figure {
    double length;

public:
    Triangle() : length(0) {}
    Triangle(Color inColor, Coord inCoord, double inLength) : Figure("Triangle", inColor, inCoord) {
        assert(inLength >= 0);
        length = inLength;
    }

    double SquareFigure() const override {
        return length * length * std::sqrt(3) / 4;
    }
    std::string RectangLe() const override {
        double A = 0.0; double B = 0.0; double C = 0.0; double D = 0.0;

        return "A: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y) + "\n" +
            "B: x = " + std::to_string(coord.x + (length/2)) + " y = " + std::to_string(coord.y + (sqrt(3) / 2 * length)) + "\n" +
            "C: x = " + std::to_string(coord.x + length) + " y = " + std::to_string(coord.y) + "\n";
    }
};

class Rectangle : public Figure {
protected:
    double width;
    double heigth;

public:    
    Rectangle() : width(0), heigth(0) {}
    Rectangle(Color inColor, Coord inCoord, double inWidth, double inHeigth) : Figure("Rectangle", inColor, inCoord) {
        assert(inWidth >= 0);
        assert(inHeigth >= 0);
        width = inWidth;
        heigth = inHeigth;
    }

    double SquareFigure() const override {
        return width * heigth;
    }
    std::string RectangLe() const override {
        double A = 0.0; double B = 0.0; double C = 0.0; double D = 0.0;

        return "A: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y) + "\n" +
            "B: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y + heigth) + "\n" +
            "C: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y + heigth) + "\n" +
            "D: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y) + "\n";
    }
};

//class Square : public Figure, public Rectangle {
//public:    
//    Square(Color inColor, Coord inCoord, double inWidth) : Figure("Square", inColor, inCoord) {
//        assert(inWidth >= 0);
//        width = inWidth;
//        heigth = inWidth;
//    } 
//    double SquareFigure() const override {
//        return width * heigth;
//    }
//    std::string RectangLe() const override {
//        double A = 0.0; double B = 0.0; double C = 0.0; double D = 0.0;
//
//        return "A: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y) + "\n" +
//            "B: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y + heigth) + "\n" +
//            "C: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y + heigth) + "\n" +
//            "D: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y) + "\n";
//    }
//};
class Square : public Figure {
    double width;
public:
    Square(Color inColor, Coord inCoord, double inWidth) : Figure("Square", inColor, inCoord) {
        assert(inWidth >= 0);
        width = inWidth;
        
    }
    double SquareFigure() const override {
        return width * width;
    }
    std::string RectangLe() const override {
        double A = 0.0; double B = 0.0; double C = 0.0; double D = 0.0;

        return "A: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y) + "\n" +
            "B: x = " + std::to_string(coord.x) + " y = " + std::to_string(coord.y + width) + "\n" +
            "C: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y + width) + "\n" +
            "D: x = " + std::to_string(coord.x + width) + " y = " + std::to_string(coord.y) + "\n";
    }
};

Color SetCol(std::string& inColor) {
    std::transform(inColor.begin(), inColor.end(), inColor.begin(), ::toupper);
    if (inColor == "RED")         
        return Color::RED;    
    else if (inColor == "GREEN") 
        return Color::GREEN;    
    else if (inColor == "BLUE") 
        return Color::BLUE;    
}

Coord SetCoord(double x, double y) {
    Coord tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}


int main() 
{       
    Figure* f = nullptr;
    std::cout << "\"circle\" \"triangle\" \"rectangle\" \"square\"\n";
    std::cout << "Enter the command: ";
    std::string com;
    std::getline(std::cin, com);
    if (com == "circle") {
        std::cout << "Creating a geometric shape - Circle\n";
        std::string col;
        std::cout << "Enter the shape color: ";
        std::getline(std::cin, col);
        double x{ 0 }; double y{ 0 }; double r{ 0 };
        std::cout << "Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;
        std::cout << "Enter the radius of the circle: ";
        std::cin >> r;

        //Присваеваем указателю родителя указатель на созданыый с помощью конструктора объект потомка
        //Как тоже самое сделать в стеке, не совсем понимаю
        f = new Circle(SetCol(col), SetCoord(x, y), r);

        std::cout << "Geometric shape - " << f->GetName() << "\n" << f->GetColor() << "\n"
            << "The area of the figure - " << f->SquareFigure() << "\n"
            << "Coordinates of the describing rectangle\n"
            << f->RectangLe();
    }

    else if (com == "triangle") {
        std::cout << "Creating a geometric shape - equilateral triangle\n";
        std::string col;
        std::cout << "Enter the shape color: ";
        std::getline(std::cin, col);
        double x{ 0 }; double y{ 0 }; double r{ 0 };
        std::cout << "Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;
        std::cout << "Enter the length of the side of the equilateral triangle: ";
        std::cin >> r;

        //Присваеваем указателю родителя указатель на созданыый с помощью конструктора объект потомка
        //Как тоже самое сделать в стеке, не совсем понимаю
        f = new Triangle(SetCol(col), SetCoord(x, y), r);

        std::cout << "Geometric shape - " << f->GetName() << "\n" << f->GetColor() << "\n"
            << "The area of the figure - " << f->SquareFigure() << "\n"
            << "Coordinates of the describing rectangle\n"
            << f->RectangLe();
    }
    else if (com == "rectangle") {
        std::cout << "Creating a geometric shape - rectangle\n";
        std::string col;
        std::cout << "Enter the shape color: ";
        std::getline(std::cin, col);
        double x{ 0 }; double y{ 0 }; double w{ 0 }; double h{ 0 };
        std::cout << "Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;
        std::cout << "Enter the length of one side of the rectangle: ";
        std::cin >> w;
        std::cout << "Enter the length of the other side of the rectangle: ";
        std::cin >> h;

        //Присваеваем указателю родителя указатель на созданыый с помощью конструктора объект потомка
        //Как тоже самое сделать в стеке, не совсем понимаю
        f = new Rectangle(SetCol(col), SetCoord(x, y), w, h);

        std::cout << "Geometric shape - " << f->GetName() << "\n" << f->GetColor() << "\n"
            << "The area of the figure - " << f->SquareFigure() << "\n"
            << "Coordinates of the describing rectangle\n"
            << f->RectangLe();
    }
    else if (com == "square") {
        std::cout << "Creating a geometric shape - square\n";
        std::string col;
        std::cout << "Enter the shape color: ";
        std::getline(std::cin, col);
        double x{ 0 }; double y{ 0 }; double w{ 0 }; double h{ 0 };
        std::cout << "Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;
        std::cout << "Enter the length of the side of the square : ";
        std::cin >> w;

        //Присваеваем указателю родителя указатель на созданыый с помощью конструктора объект потомка
        //Как тоже самое сделать в стеке, не совсем понимаю
        f = new Square(SetCol(col), SetCoord(x, y), w);

        std::cout << "Geometric shape - " << f->GetName() << "\n" << f->GetColor() << "\n"
            << "The area of the figure - " << f->SquareFigure() << "\n"
            << "Coordinates of the describing rectangle\n"
            << f->RectangLe();
    }
    else
        std::cout << "Wrong command!!!\n";
}

