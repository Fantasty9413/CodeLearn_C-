# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str = "This is a str for testing find function.";
    string str_find = "str";
    cout << str_find << "'s index is " << str.find(str_find) << endl;

    // find失败时返回的index不能直接作为整数输出，要用string::nops来比较
    cout << str_find << "'s index is " << str.find(str_find, 15) << endl;     

    if (str.find(str_find, 15) != string::npos)
    {
        cout << str_find << "'s index is " << str.find(str_find) << endl;
    }
    else
    {
        cout << str_find << " is not found." << endl;
    }     

    char c[] = {'i', 'n'};
    char c1 = 'i';

    cout << str_find << "'s index is " << str.find(c,10,2) << endl;     //只搜寻c为起始地址，长度为2字符
    cout << str_find << "'s index is " << str.find("str",10,3) << endl;

    int loc;
    loc = str.rfind("i");       //倒序寻找
    cout << "loc is " << loc << endl;

    loc = str.rfind("in",15);       //倒序寻找,从倒着的15个字符过后开始寻找
    cout << "loc is " << loc << endl;

    loc = str.find_first_of("in");      //寻找第一个
    cout << "loc is " << loc << endl;

    loc = str.find_last_of("in");      //寻找最后一个
    cout << "loc is " << loc << endl;

    loc = str.find_first_not_of("in");  //第一个不是的
    cout << "loc is " << loc << endl;

    loc = str.find_last_not_of("in");   //最后一个不是的
    cout << "loc is " << loc << endl;

    return 0;
}