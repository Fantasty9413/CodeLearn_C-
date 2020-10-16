#include <iostream>
#include <string>
using namespace std;

enum stusex
{
    male = 0,       //男
    female = 1     //女
};

struct student
{
    string name;
    stusex sex;
    int num;
    int grade;
};

void set_stuinfo(student *stu)
{
    int i =0;
    int sex = 0;
    cout<<"请输入学生信息"<<endl;
    while(i++ < 5)
    {
        cout<<"请输入第"<<i<<"个学生的姓名:"<<endl;
        cin>>stu ->name;
        cout<<"请输入第"<<i<<"个学生的性别:(男生=0，女生=1)"<<endl;
        cin>>sex;
        stu ->sex = sex != 0 ? male : female;
        cout<<"请输入第"<<i<<"个学生的学号:"<<endl;
        cin>>stu ->num;
        cout<<endl;
        stu++;
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
    set_stuinfo(stu);

    float avg;
    set_grade(stu, avg);
    cout<<"the average grade is "<<avg<<endl;

    return 0;
}