#include <iostream>
using namespace std;

int main()
{
    char str[] = "a123x456__17960?302ab5876";
    int num[10] = {};
    char* p = &str[0];
    int* pnum = &num[0];
    while(*p != '\0')
    {
            if(((*(p-1) < '0') || (*(p-1) > '9')) && ((*(p) >= '0') && (*(p) <= '9')))
            {
                while(((*(p) >= '0') && (*(p) <= '9')))
                {
                    *pnum = 10 * *pnum + (*p - 48);
                     p ++;
                }
                pnum ++;
            } 
            p ++;

    }

    pnum = num;
    while(*pnum != '\0')
    {
        cout<<*(pnum++)<<endl;
    }

    return 0;
}