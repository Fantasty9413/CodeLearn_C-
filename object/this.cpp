# include <iostream>
# include <string>

using namespace std;

class Line 
{
    private:
    double len;

    public:
    Line(double len = 5);
    double getlen();
    bool compare(Line line);
    Line* getaddress();
};

Line::Line(double len)
{
    this->len = len;
}

double Line::getlen()
{
    return this->len;
}

bool Line::compare(Line line)
{
    return this->getlen() > line.getlen();
}

Line* Line::getaddress()
{
    return this;
}

int main()
{
    Line line1;
    Line line2(10);
    cout << "the result of compare is: " << line2.compare(line1) << '\n';
    Line* p = line2.getaddress();
    cout << "the address of p is " << p << '\n';
    cout << "the len of *p is " << p->getlen() << '\n';
    cout << "the len of *p is " << (*p).getlen() << '\n';

    return 0;
}