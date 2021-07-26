# include <iostream>
# include <string>
# include <list>
using namespace std;

template<typename T> void list_display(T l);

int main()
{
    list<int> num(10, 1);
    list_display(num);
    
    num.assign(15, 2);
    list_display(num);

    num.push_front(0);      // 尾部插入
    num.push_back(100);     // 头部插入

    list<int>::iterator p = num.begin();

    num.insert(p, 100);
    list_display(num);

    list<int> num2;
    for(int i=0;i<10;i++)
    {
        num2.push_back(i);
    }

    list_display(num2);

    auto it2 = num2.begin();

    // num2.push_front(100);

    list_display(num2);

    // cout << *it2 << endl;

    advance(it2, num2.size()-1);     // 移动迭代器
    cout << *it2 << '\n';
    advance(it2, -1);
    cout << *it2 << '\n';

    num2.back() = 100;      // 改尾部元素
    num2.front() = 100;     // 改头部元素
    list_display(num2);

    return 0;
}

template<typename T> void list_display(T l)
{
    auto p = l.begin();
    while(p != l.end())
    {
        cout << *p << " ";
        p ++;
    }
    cout << endl;
}