#include <iostream>
#include <string>
using namespace std;

char* get_same_string(char* p1, char *p2)
{
    char* head = new char[20];
    char* s = head;     //保留内存首地址
    while((*p1 != '\0') || (*p2 != '\0'))
    {
        if(*p1 == *p2)
        {
            *s = *p1;
            s ++;
        }
        p1++;
        p2++;
    }
    return head;
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

    char s1[] = "afgvasdgd";
    char s2[] = "afsgaghadg";
    // char s[20] = {};

    // delete [] head;

    char* ps = get_same_string(s1, s2);

    delete [] ps;

    cout<<*ps<<endl;

    delete [] ps;

    while(*ps != '\0')
    {
        cout << *ps++ ;
    }

    int* test = new int[3]{1,10,100};
    cout<<endl<<*(test+1)<<endl;

    // delete [] head;

    return 0;
}