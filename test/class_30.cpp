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
    void set_information()
    {
        cout<<"please cin the name: "<<endl;
        cin>>name;
        cout<<endl;

        cout<<"please cin the num: "<<endl;
        cin>>num;
        cout<<endl;

        cout<<"please cin the sex: "<<endl;       
        int stusex;
        cin>>stusex;
        sex = stusex == 1 ? female : male;
        cout<<endl;

        cout<<"please cin the age: "<<endl;            
        cin>>age;
        cout<<endl;
    }

    void print_information()
    {
        cout<<"name = "<<name<<endl;
        cout<<"num = "<<num<<endl;
        cout<<"sex = "<< (sex == 0 ? "male" : "female") <<endl;
        cout<<"age = "<<age<<endl;
    }

};


int main()
{
    // student zhangsan = {"zhangsan", 101, male, 21};

    student lisi; 
    lisi.set_information();
    lisi.print_information();

    return 0;
}