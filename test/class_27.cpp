#include <iostream>
#include <string>
using namespace std;

char *get_same_string(char* p1, char *p2)
{
    char* s1 = new char[20];
    char* s = s1;
    while((*p1 != '\0') || (*p2 != '\0'))
    {
        if(*p1 == *p2)
        {
            *s = *p1;
            s = s + 2;
        }
        p1++;
        p2++;
    }
    return s;
}

int main()
{
    int a(1);
    int& b = a;
    int* p = &b;
    cout<<b<<endl;

    b = 3;
    cout<<a<<endl;
    cout<<*p<<endl;

    char s1[] = "asgfasfafa";
    char s2[] = "ashdgsfand";
    char s[20] = {};
    cout<<get_same_string(s1, s2)<<endl;

    return 0;
}