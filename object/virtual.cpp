# include <iostream>
using namespace std;

class Shape
{
    protected:
    int wid;
    int len;

    public:
    Shape(int wid = 0, int len = 0)
    {
        this->wid = wid;
        this->len = len;
    }

    virtual int getarea()
    {
        cout << "parent class area: " << '\n';
        return 0;
    }
};

class Rectangle: public Shape
{
    public:
    Rectangle(int wid = 5, int len = 5):Shape(wid, len){}

    int getarea()
    {
        cout << "rectangle class area: " << '\n';
        return (wid*len);
    }
};

int main()
{
    Shape* shape;
    Rectangle rec;

    cout << "rec area is " << rec.getarea() << '\n';

    shape = &rec;
    shape->getarea();

    return 0;
}