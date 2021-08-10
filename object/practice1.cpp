# include <iostream>
using namespace std;

class Point
{
    protected:
    static int count;
    int x;
    int y;

    public:
    Point(int x = 0, int y = 0);
    int getpositon(char axis);
};

int Point::count = 0;

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getpositon(char axis)
{   
    if(axis == 'x')
    {
        return this->x;
    }
    else if (axis == 'y')
    {
        return this->y;
    }
    else
    {
        throw axis;
        cerr << "error of input option.\n";
    }
    
}

class Animal
{
    virtual void run(int x, int y) = 0;
};

class Dog: public Animal, public Point
{
    public:
    Dog();
    void run(int x, int y);
};

Dog::Dog()
{
    Point();
}

void Dog::run(int x, int y)
{
    this->x += x;
    this->y += y;
}

int main()
{
    Point p1;
    Dog dog1;
    cout << "x position of p1 is " << p1.getpositon('x') <<'\n';
    cout << "dog1's position of p1 is (" << dog1.getpositon('x') << ", " << dog1.getpositon('y') << ") \n";
    dog1.run(10, 20);
    cout << "dog1's position of p1 is (" << dog1.getpositon('x') << ", " << dog1.getpositon('y') << ") \n";

    return 0;
}