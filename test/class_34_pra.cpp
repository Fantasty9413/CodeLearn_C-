#include <iostream>
#include <string>
using namespace std;

char char_upper_diy(char str, bool b_odd_pos = true)
{
    //输入ture，变大写
    //输入flase，变小写
    if ((str >= 'A') && (str <= 'Z'))
    {
        if(! b_odd_pos)
        {
            str = str + 'a' -'A';
        }
    }
    else if ((str >= 'a') && (str <= 'z'))
    {
        if(b_odd_pos)
        {
            str = str + 'A' -'a';
        }       
    }
        return str;    
}

bool string_upper_diy(char str[], int str_len, bool b_odd_pos = true)
{
    //b_odd_pos 为true的时候，就要将 str 字符串中的奇数位置的字符变为大写，同时将非奇数位置的字符变为小写；
    //b_odd_pos 为false的时候，就要将 str 字符串中的奇数位置的字符变为小写，同时将非奇数位置的字符变为大写；
    char* p = str;
    int i = 0;
    while(i++ < str_len)
    {
        *p++ = char_upper_diy(*p, b_odd_pos);
        b_odd_pos = ! b_odd_pos;
    }
}


int main()
{
    char ch[] = "asdafsFAfaasfFS";
    int length = sizeof(ch) / sizeof(ch[0]);
    cout<<ch<<endl;

    string_upper_diy(ch, length, true);
    cout<<ch<<endl;

    return 0;

}