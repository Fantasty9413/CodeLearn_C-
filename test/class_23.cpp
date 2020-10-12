#include <iostream>
using namespace std;

int main()
{
    int num[100] = {1, 2, 3, 4};
    int* pnum = num;
    int* pnum_0 = &num[0];
    int* pnum_1 = &num[1];

    cout<<pnum[1]<<endl;
    cout<<*pnum<<endl;
    cout<<*(num+3)<<endl;
    cout<<num[2]<<endl;

    char str1[50] = {0};
    char str2[] = "I Love u";

    char* p1 = str1;
    char* p2 = str2;
    while(*p2 != '\0')
    {
        *p1++ = *(p2++);
        // p1++;
        // p2++;
    }

    cout<<str1<<endl;
}