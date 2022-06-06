# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

# define Conn(x, y) x##y

class Student
{
    private:
    std::string name;
    int age;
    int num;

    public:
    static int StuNum;
    Student();
    Student(std::string name, int age, int num);
    bool operator== (const Student &student);
    friend std::ostream &operator<< (std::ostream &out, const Student &stu);
};

int Student::StuNum = 0;

Student::Student()
{
    name = "Null";
    age = 0;
    num = 0;
}

Student::Student(std::string name, int age, int num): name(name), age(age), num(num)
{
    StuNum++;
}

bool Student::operator== (const Student &student)
{
    return ((name==student.name)&&(num==student.num));
}

std::ostream &operator<< (std::ostream &out, const Student &stu)
{
    out << "name: " << stu.name << ", ";
    out << "age:  " << stu.age << ", ";
    out << "num:  " << stu.num << ". ";
    out << '\n';

    return out;
}

int main()
{
    Student *stus = new Student[3];
    Student stu1 = Student("lqy", 23, 101);
    Student stu2 = Student("mze", 23, 102);
    Student stu3 = Student("clf", 23, 103);
    *(stus+0) = stu1;
    *(stus+1) = stu2;
    *(stus+2) = stu3;

    Student *stu = nullptr;

    std::list<Student> students;
    for (int i = 0; i < 3; i++)
    {
        stu = stus + i;
        students.push_front(*stu);
    }

    std::list<Student>::iterator pos;
    pos = find(students.begin(), students.end(), stu2);

    // std::cout << stu2;

    if(pos != students.end())
    {
        std::cout << *pos << '\n';
    }
    else
    {
        std::cout << "not find!" << '\n';
    }

    return 0;
}