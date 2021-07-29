# include <iostream>
# include <stack>
# include <string>
using namespace std;

template<typename T> void stack_display(T s);

int main()
{
    stack<string> s;
    stack<string> s2;
    string c = "abcdefghijklopqrstuvwxyz";
    for(int i=0; i<5; i++)
    {
        s.push(c.substr(3*i, 5));
        s2.push(c.substr(4*i, 6));
    }
    stack_display(s);
    stack_display(s2);

    cout << "s's size is " << s.size() << '\n';
    cout << "s2's size is " << s.size() << '\n';

    s.swap(s2);

    stack_display(s);
    stack_display(s2);   

    return 0;
}

template<typename T> void stack_display(T s)
{
    while(! s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}