# include <iostream>
using namespace std;

int Max_3(int a, int b, int c)
{
    int temp;
    temp = (a>b) ? a : b ;
    temp = (temp>c) ? temp : c;

    return temp;
}

template<typename T> T Max_3(T a, T b, T c)
{
    T temp;
    temp = (a>b) ? a : b;
    temp = (temp>c) ? temp : c;

    return temp;
}

int main()
{
    int a = 1, b = 2, c = 3;
    float var1 = 1.1, var2 = 1.2, var3 = 1.3;

    cout << "the max number is " << Max_3(a, b, c) << "." << endl;
    cout << "the max number is " << Max_3(var1, var2, var3) << "." << endl;

    return 0;
}