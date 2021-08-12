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
    int* p = NULL;
    p = new int();

    *p = 1;
    cout << "value is " << *p << '\n'; 

    Line line;
    cout << "len of line is " << line.getlen() << '\n';

    Line line2(2);
    cout << "len of line2 is " << line2.getlen() << '\n';

    Line line3 = 3;
    cout << "len of line3 is " << line3.getlen() << '\n';

    int i;
    cout << "value of i is " << i << '\n'; 

    int j(3);
    cout << "value of j is " << i << '\n'; 

    return 0;
}