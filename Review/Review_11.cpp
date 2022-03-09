# include <iostream>
# define PI 3.14

class Line
{
    private:
    std::string color;
    int len;

    public:
    Line();
    int Getlen();
};

Line::Line()
{
    this->color = "White";
    this->len = 1;
}

int Line::Getlen()
{
    return len;
}

class Shape
{   
    public:
    virtual int GetArea() = 0;
};

class Circle: public Shape
{
    private:
    Line Radius;

    public:
    Circle();
    int GetArea();
};

Circle::Circle(): Radius(Line())
{}

int Circle::GetArea()
{
    int radius = Radius.Getlen();
    return (PI*radius*radius);
}

class Square: public Shape
{
    private:
    Line Len;

    public:
    Square();
    int GetArea();
};

Square::Square(): Len(Line())
{}

int Square::GetArea()
{
    int len = Len.Getlen();
    return (len*len);
}

class Rectangel: public Shape
{
    private:
    Line Len;
    Line Wid;

    public:
    Rectangel();
    int GetArea();
};

Rectangel::Rectangel(): Len(Line()), Wid(Line())
{}

int Rectangel::GetArea()
{
    int len = Len.Getlen();
    int wid = Wid.Getlen();
    return (len*wid);
}

int main()
{
    Shape *shape = nullptr;

    shape = new Circle();
    std::cout << "the area is " << shape->GetArea() << std::endl;
    delete shape;

    shape = new Square();
    std::cout << "the area is " << shape->GetArea() << std::endl;
    delete shape;

    shape = new Rectangel();
    std::cout << "the area is " << shape->GetArea() << std::endl;
    delete shape;    

    return 0;
}
