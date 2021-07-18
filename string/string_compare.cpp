# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str;
    cout << "Please input your name: " << endl;
    cin >> str;
    if (str == "Li")
    {
        cout << "Your are Li!" << endl;
    }
    else
    {
        cout << "Your are not Li!" << endl;
    }
    
    str = str + ". Welcome!";
    cout << str << endl;
    
    for(int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    return 0;
}