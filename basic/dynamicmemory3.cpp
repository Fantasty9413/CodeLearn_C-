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
    int* pi1;
    pi1 = new int[10];

    for(int i=0; i<10; i++)
    {
        *pi1++ = i;
    }

    for(int i=0; i<10; i++)
    {
        cout << *--pi1 << ' ';
    }
    cout << '\n';

    return 0;
}