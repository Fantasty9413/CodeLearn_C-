# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str = "This is a str.";
    if(str.empty())
    {
        cout << "str is empty." << endl;
    }
    else
    {
        cout << "str is not empty." << endl;
    }
    
    cout << "str's size is " << str.size() << endl;
    cout << "str's capacity is " << str.capacity() << endl;
    cout << "str's max size is " << str.max_size() << endl;
    cout << "str's length is " << str.length() << endl;     //difference about size and length? no difference
    str.resize(9, 'c');
    cout << "str is " << str << endl;
    str.resize(20, 'c');
    cout << "str is " << str << endl;

    return 0;
}