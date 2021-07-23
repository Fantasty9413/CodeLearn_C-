# include <iostream>
# include <string>
# include <vector>
using namespace std;

template<typename T> void vector_display(T v);

int main()
{
    vector<int> num;

    vector<int>::iterator p;
    p = num.begin();

    num.assign(10, 0);          // 前十个元素为0

    for(int i=0; i<10; i++)     // 尾部增加0-9的十个元素
    {
        num.push_back(i);
    }
    vector_display(num);

    cout << num.at(1) << '\n';  // 将第1个元素改为0
    num.at(1) = 100;
    cout << num.at(1) << '\n';

    num.front() = 100;          // 改头尾元素
    num.back() = 100;
    vector_display(num);

    return 0;
}

template<typename T> void vector_display(T v)
{
    auto p = v.begin();
    while(p != v.end())
    {
        cout << *p << " ";
        p ++;
    }
    cout << endl;
}