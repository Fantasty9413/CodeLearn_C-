# include <iostream>
# include <queue>
# include <string>
using namespace std;

template<typename T> void queue_display(T s);

int main()
{
    queue<string> q;
    queue<string> q2;
    string c = "abcdefghijklopqrstuvwxyz";
    for(int i=0; i<5; i++)
    {
        q.push(c.substr(3*i, 5));
        q2.push(c.substr(4*i, 6));
    }
    cout << "back is " << q.back() << '\n';
    cout << "front is " << q.front() << '\n';

    queue_display(q);
    queue_display(q2);

    cout << "s's size is " << q.size() << '\n';
    cout << "s2's size is " << q.size() << '\n';

    q.swap(q2);

    queue_display(q);
    queue_display(q2);   

    return 0;
}

template<typename T> void queue_display(T s)
{
    while(! s.empty())
    {
        cout << s.back() << ' ';
        s.pop();
    }
    cout << '\n';
}