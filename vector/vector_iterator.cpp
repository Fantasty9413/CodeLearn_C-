# include <iostream>
# include <string>
# include <vector>
using namespace std;

int main()
{
    vector<int> number(10);
    cout << "number's size is " << number.size() << endl;
    cout << "number's capacity is " << number.capacity() << endl;
    cout << "number's max_size is " << number.max_size() << endl;

    for(int i=0; i<number.size(); i++)
    {
        number[i] = rand();
    }

    auto p = number.begin();        // 迭代器
    while(p != number.end())
    {
        cout << *p <<' ';
        p ++;
    }
    cout << endl;

    vector<int>::iterator p2;
    p2 = number.begin();
    while(p2 != number.end())
    {
        cout << *p2 <<' ';
        p2 ++;
    }
    cout << endl;

    vector<int>::iterator p3;
    for (p3 = number.begin(); p3 < number.end(); p3++)
    {
        cout << *p3 <<' ';      
    }
    cout << endl;
    
    vector<int>::reverse_iterator rp;       // 反向迭代器
    rp = number.rbegin();
    while(rp != number.rend())
    {
        cout << *rp << " ";
        rp ++;
    }
    cout << endl;

    return 0;
}