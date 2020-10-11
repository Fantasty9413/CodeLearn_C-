#include <iostream>
#include <cstring>
using namespace std;

//关于字符串的标准函数的运用

int main()
{
    char s1[] = "hello";
    char s2[] = "world";
    char s3[50] = {};

    int dos[50];

    cout<<"the strcmp is "<<(strcmp(s1, s2))<<endl;

    cout<<"the lenth is "<<strlen(s1)<<endl;

    strcpy(s3, s1);
    cout<<"strcpy is "<<s3<<endl;

    strcat(s1, s2);
    cout<<"strcat is "<<s1<<endl;    

    cout<<"sizeof int ="<<sizeof(dos)<<endl;
    cout<<"sizeof char ="<<sizeof(s1)<<endl;        //包含字符串的结尾空格

    return 0;

}