# include <iostream>
using namespace std;

void _swap(int& a, int& b);

int main()
{
    int a = 1;
    int b = 2;

    int& c = a;
    c = 3;

    cout << "the value of a is " << a << '\n';
    _swap(a, b);

    cout << "the value of a is " << a << '\n';

    return 0;
}

void _swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}