# include <iostream>
# include <string>
# include <vector>
using namespace std;

template<typename T> void vector_display(T v);      // 打印显示vector的内容

int main()
{
    vector<string> strs(10, "str");
    strs.push_back("head");     // 尾部增加
    // strs.pop_back();            // 尾部删除
    cout << "strs' size is " << strs.size() << endl;
    auto p = strs.rbegin();
    while(p != strs.rend())
    {
        cout << *p << " ";
        p ++;
    }
    cout << endl;

    vector<string>::iterator p2;
    p2 = strs.begin() + 1;
    strs.insert(p2, 3, "insert");
    vector_display(strs);
    cout << *(p2) << endl;

    p2 = strs.begin();
    strs.erase(p2, p2+2);
    vector_display(strs);
    cout << *(p2) << endl;

    strs.clear();       // 清除
    vector_display(strs);

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