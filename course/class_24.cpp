#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int num;
    char sex;
    int age;
};

void ste_num(student *stu)
{
    static int stunum = 101;
    stu++ ->num = stunum++;
    // (*stu++).num = stunum++;
}

int main()
{
    student zhangsan = {"zhangsan", 101, 'm', 20};  //定义时初始化
    student lisi;   //先定义再初始化
    lisi.name = "lisi";
    lisi.num = 102;
    lisi.sex = 'm';
    lisi.age = 21;

    student stu[3] = { 
        { "aaa", 0, 'f', 10 },
        { "bbb", 0, 'm', 12 },
        { "ccc", 0, 'm', 12 },        
        };

    cout<<stu[0].num<<endl;
    ste_num(stu);
    cout<<stu[0].num<<endl; 

    return 0;
}