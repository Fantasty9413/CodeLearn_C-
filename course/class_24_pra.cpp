#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int num;
    int grade;
};

void set_num(student *stu)
{
    static int stunum = 101;
    stu++ ->num = stunum++;
    // (*stu++).num = stunum++;
}

void set_name(student *stu)
{
    int i =0;
    while(i++ < 5)
    {
        cout<<"请输入第"<<i<<"个学生的姓名"<<endl;
        cin>>stu++ ->name;
    }
}

void set_grade(student *stu, float &avg)
{
    int i =0;
    while(i++ < 5)
    {
        cout<<"请输入"<<stu ->name <<"的分数"<<endl;
        cin>>stu ->grade;
        avg = avg + stu ->grade;
        stu++;
    }
    avg = avg / 5;
}

int main()
{
    student stu[5] = {}; //定义时初始化
    float avg;
    set_num(stu);
    set_name(stu);
    set_grade(stu, avg);
    cout<<"the average grade is "<<avg<<endl;

    return 0;
}