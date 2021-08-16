#include <iostream>
#include <cstring>
using namespace std;

//关于字符串的标准函数的运用

void swap_pointer(int* pa, int* pb)     //传指针调用，传址
{  
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap_reference(int& a, int& b)   //传引用
{  
    int temp;
    temp = a;
    a = b;
    b = temp;
}



int main()
{
    int a = 1;
    int b = 2;

    cout<<"a = "<<a<<"  b = "<<b<<endl;

    swap_pointer(&a, &b);
    cout<<"a = "<<a<<"  b = "<<b<<endl;

    swap_reference(a, b);
    cout<<"a = "<<a<<"  b = "<<b<<endl;

    swap(a, b);     //本身自带的交换函数
    cout<<"a = "<<a<<"  b = "<<b<<endl;


    return 0;

}