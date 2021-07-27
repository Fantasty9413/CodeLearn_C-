# include <iostream>
# include <list>
# include <string>
using namespace std;

template<typename T> void list_display(T l);

int main()
{
    list<string> strs;
    strs.push_back("str1");
    strs.push_back("str2");
    strs.push_back("str3");
    strs.push_back("str4");
    strs.push_back("str5");
    list_display(strs);

    strs.push_front("str6");
    list_display(strs);
    strs.sort();            // 排序
    list_display(strs);

    strs.push_front("str1");
    list_display(strs);
    strs.unique();          // 删除重复元素
    list_display(strs);

    strs.remove("str6");        // 删除指定值的元素
    list_display(strs);

    list<string> strs2;
    strs2.push_back("str6");
    strs2.push_back("str7");
    strs2.push_back("str9");
    strs2.push_back("str8");
    strs2.sort();
    list_display(strs2);   

    strs2.swap(strs);
    list_display(strs2);
    list_display(strs);

    // cout << "merge" << '\n';
    // strs2.merge(strs);
    // // list_display(strs2);
    // list_display(strs);         // merge过后被合并list清空

    cout << "splice" << '\n';
    auto it2 = strs2.begin();
    auto it = strs.begin();
    list<string>::iterator it_s = it;
    advance(it,3);
    list<string>::iterator it_e = it;
    strs2.splice(it2, strs, it_s, it_e);       // 插入合并两list
    list_display(strs2);
    list_display(strs);            // 被合并的list会为空

    cout << "strs2's length is " << strs2.size() << '\n';
    strs2.resize(12);
    list_display(strs2);
    cout << "strs2's length is " << strs2.size() << '\n';

    return 0;
}

template<typename T> void list_display(T l)
{
    auto it = l.begin();
    while (it != l.end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
}