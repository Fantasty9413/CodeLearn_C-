# include <iostream>
# include <string>
using namespace std;

class Line
{
    private:
    double length;

    public:
    Line();
    Line(double length);
    void setlength(double length);
    friend double getlength(Line line);
};

Line::Line()
{
    this->length = 5;
}

Line::Line(double length)
{
    this->length = length;
}

void Line::setlength(double length)
{
    this->length = length;
}

double getlength(Line line)
{
    return line.length;
}

class Rectangle
{
    private:
    Line len;
    Line wid;

    public:
    Rectangle();
    Rectangle(double len, double wid);
    void setlength(double len, double wid);
    double getarea();
};

Rectangle::Rectangle()
{
    len = Line();
    wid = Line();
}

Rectangle::Rectangle(double len, double wid)
{
    this->len.setlength(len);
    this->wid.setlength(wid);
}

void Rectangle::setlength(double len, double wid)
{
    this->len.setlength(len);
    this->wid.setlength(wid);    
}

double Rectangle::getarea()
{
    double s;
    s = getlength(this->len) * getlength(this->wid);
    return s;
}

int main()
{
    Rectangle rec;
    cout << "area of rec is " << rec.getarea() << '\n';

    Rectangle rec2(10, 12);
    cout << "area of rec is " << rec2.getarea() << '\n';    

    return 0;
}
