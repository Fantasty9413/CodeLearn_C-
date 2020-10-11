#include <iostream>
using namespace std;

//测试静态变量static

int myadd (int x, int y)
{
    static int value = 1;
    int temp;
    temp = x +y + value;
    value++;
    return temp;
}

int main()
{
    int x = 1, y = 1;
    int sum;

    sum = myadd(x, y);
    cout<<"sum = "<<sum<<endl;

    sum = myadd(x, y);
    cout<<"sum = "<<sum<<endl;

    sum = myadd(x, y);
    cout<<"sum = "<<sum<<endl;
}