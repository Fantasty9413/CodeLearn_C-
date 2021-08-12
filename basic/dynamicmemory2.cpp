# include <iostream>
using namespace std;

class Line
{
    private:
    int len;

    public:
    Line(int len = 1);
    int getlen();
};

Line::Line(int len)
{
    this->len = len;
}

int Line::getlen()
{
    return this->len;
}

int main()
{
    int* pi1, * pi2, * pi3;
    pi1 = new int;
    pi2 = new int();
    pi3 = new int(2);

    Line* pl1, * pl2, * pl3;
    pl1 = new Line;
    pl2 = new Line();
    pl3 = new Line(2);

    cout << "value of int is " << *pi1 << ' ' << *pi2 << ' ' << *pi3 << '\n';
    cout << "len of line is " << pl1->getlen() << ' ' << pl2->getlen() << ' ' << pl3->getlen() << '\n';

    return 0;
}