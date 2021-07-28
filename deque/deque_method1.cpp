# include <iostream>
# include <deque>
# include <string>
using namespace std;

template<typename T> void deque_display(T d);
template<typename T> void deque_display2(T d);

int main()
{
    deque<int> num;
    for(int i=0; i<10; i++)
    {
        num.push_back(i);
    }
    deque_display(num);
    deque_display2(num);

    auto it = num.begin(), it2 = it;
    it++;
    it2 = num.insert(it, -1);
    cout << "it: " << *it << '\n';
    cout << "it2: " << *it2 << '\n';
    it2++;
    cout << "it2: " << *it2 << '\n';
    deque_display(num);

    cout << "erase" << '\n';
    auto it3 = num.begin();
    advance(it3, 3);
    it2--;
    cout << "it2(before erase): " << *it2 << '\n';
    cout << "it3(before erase): " << *it3 << '\n';
    // it = num.erase(it2, it3);
    it = num.erase(it2);
    cout << "it2: " << *it2 << '\n';
    cout << "it: " << *it << '\n';
    it2++;
    cout << "it2: " << *it2 << '\n';
    deque_display(num);

    return 0;
}

template<typename T> void deque_display(T d)
{
    auto it = d.begin();
    while(it != d.end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
}

template<typename T> void deque_display2(T d)
{
    int i = 0;
    while(i < d.size())
    {
        cout << d.at(i++) << ' ';       // 把i++放进循环中
    }
    cout << '\n';
}