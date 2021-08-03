# include <iostream>
# include <string>
# include <list>

using namespace std;

class Line
{
    private:
    double len;
    static int objcount;

    public:
    // static int objcount;
    Line(double len = 5);
    void setlen(double len);
    static int getcount();
};

int Line::objcount = 0;

Line::Line(double len)
{
    cout << "constructor called" << '\n';
    this->len = len;
    objcount++;
}

void Line::setlen(double len)
{
    this->len = len;
}

int Line::getcount()
{
    return objcount;
}

int main()
{
    list<Line> l(10);

    cout << "the num of line is " << Line::getcount() << '\n';

    list<Line>::iterator it;
    it = l.begin();
    int len = 1;

    while(it != l.end())
    {
        (*it).setlen(len);
        len++;
        it++;
    }

    return 0;
}