# include <iostream>

struct Grade
{
    int Chinese;
    int Math;
    int English;
};

class Student
{
    private:
    std::string name;
    int age;
    int stunum;
    Grade grade;

    public:
    static int Num;
    Student(std::string name, int age, Grade grade);
    ~Student();
    int GetGrade();
};

int Student::Num = 0;

Student::Student(std::string name, int age, Grade grade): name(name), age(age), grade(grade)
{
    Num++;
}

Student::~Student()
{
    Num--;
}

int Student::GetGrade()
{
    return (grade.Chinese + grade.Math + grade.English);
}

int main()
{
    Student stu1("lqy", 23, {89, 89, 89});

    std::cout << "the quantity of students is " << Student::Num << std::endl;

    return 0;
}