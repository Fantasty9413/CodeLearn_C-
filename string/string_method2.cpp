# include <iostream>
# include <string>
using namespace std;

int main()
{
    string str1 = "This is string1.";
    string str2 = "This is string2!";
    string str3;

    cout << "str2's length is " << str2.length() << endl;

    str2.erase(str2.length() - 1, 1);       // 删除
    cout << "str2 for erase is " << str2 << endl;

    str2.insert(str2.length(), 1, '.');     // 插入
    cout << "str2 for insert is " << str2 << endl;

    str2.replace(8, 7, "a string fot test");        // replace = earse + insert
    cout << "str2 for replace is " << str2 << endl;

    str2.append(" It's appended."); // 延长
    cout << str2 << endl;

    // swap(str1, str2);
    str1.swap(str2);                // 字符串的交换，也可以直接用swap函数
    cout << "str1 is " << str1 << endl;
    cout << "str2 is " << str2 << endl;       

    str3 = str2.substr(5, 2);       // 提取子字符串
    cout << "str2 is " << str2 << endl;
    cout << "str3 is " << str3 << endl;        

    return 0;
}