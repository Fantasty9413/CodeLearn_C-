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

Point::Point(int x, int y):x(x), y(y)
{
    count++;
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
    private:
    static int count;

    public:
    Dog(int x = 5, int y = 5);
    void run(int x = 1, int y = 1);
    void displaypositon();
    static int getcount();
};

int Dog::count = 0;

Dog::Dog(int x, int y):Point(x, y)
{
    count++;
}

void Dog::run(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Dog::displaypositon()
{
    cout << "dog1's position of p1 is (";
    cout << this->x << ", ";
    cout << this->y << ") \n";
}

int Dog::getcount()
{
    return count;
}

int main()
{
    Point p1;
    Dog dog1;
    cout << "x position of p1 is " << p1.getpositon('x') <<'\n';
    dog1.run();
    dog1.displaypositon();
    cout << "the count of dog is " << dog1.getcount() << '\n';

    return 0;
}