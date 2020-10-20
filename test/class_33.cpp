#include <iostream>
#include <string>
using namespace std;

enum stusex
{
    male = 0 ,
    female = 1
};

class student
{
    private:
    string name;
    int num;
    stusex sex;
    int age;

    public:
    void set_information();
    void print_information();
    student();

    void set_age(int age)
    {
        this->age = age;
    }

};

    void student::set_information()
    {
        cout<<"please cin the name: "<<endl;
        cin>>name;
        cout<<endl;

        // cout<<"please cin the num: "<<endl;
        // cin>>num;
        // cout<<endl;

        cout<<"please cin the sex: "<<endl;       
        int stusex;
        cin>>stusex;
        sex = stusex == 1 ? female : male;
        cout<<endl;

        cout<<"please cin the age: "<<endl;            
        cin>>age;
        cout<<endl;
    }

    void student::print_information()
    {
        cout<<"name = "<<name<<endl;
        cout<<"num = "<<num<<endl;
        cout<<"sex = "<< (sex == 0 ? "male" : "female") <<endl;
        cout<<"age = "<<age<<endl;
        cout<<endl;
    }

    student::student()
    {
        static int num = 101;
        // this->set_information();
        this->num = num++;
    }

int main()
{
    // student zhangsan = {"zhangsan", 101, male, 21};
    student stulist[3] = {};
    student* p = stulist;

    int i = 0;
    int length = sizeof(stulist) / sizeof(stulist[0]);

    while(i++ < length)
    {
        p++->set_information();
    }
    
    p = stulist;
    i = 0;

    while(i++ < length)
    {
        p++->print_information();
    }

    return 0;
}