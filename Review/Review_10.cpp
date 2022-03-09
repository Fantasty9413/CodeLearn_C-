# include <iostream>

class Grade
{
    protected:
    int Chinese;
    int Math;
    int English;

    public:
    Grade();
    Grade(int grade1, int grade2, int grade3);
    void WriteGrade(int grade1, int grade2, int grade3);
    int GetTotalGrade();
};

Grade::Grade()
{
    this->Chinese = 0;
    this->Math = 0;
    this->English = 0;
}

Grade::Grade(int grade1, int grade2, int grade3): Chinese(grade1), Math(grade2), English(grade3)
{

}

void Grade::WriteGrade(int grade1, int grade2, int grade3)
{
    this->Chinese = grade1;
    this->Math = grade2;
    this->English = grade3;
}

int Grade::GetTotalGrade()
{
    return (Chinese + Math + English);
}

class Student: public Grade
{
    private:
    std::string name;
    int age;
    int stunum;

    public:
    static int Num;
    Student(std::string name, int age);
    Student(std::string name, int age, int grade1, int grade2, int grade3);
    ~Student();
    int GetGrade();
};

int Student::Num = 0;

Student::Student(std::string name, int age): name(name), age(age)
{
    Num++;
}

Student::Student(std::string name, int age, int grade1, int grade2, int grade3): name(name), age(age), Grade(grade1, grade2, grade3)
{
    Num++;
}

Student::~Student()
{
    Num--;
}

int Student::GetGrade()
{
    return (GetTotalGrade());
}

int main()
{
    Student stu1("lqy", 23);
    stu1.WriteGrade(90, 90, 100);

    std::cout << "the quantity of students is " << Student::Num << std::endl;

    std::cout << "the grade of stu1 is " << stu1.GetGrade() << std::endl;

    Student stu2("yhx", 23, 89, 89, 89);

    std::cout << "the quantity of students is " << Student::Num << std::endl;

    std::cout << "the grade of stu1 is " << stu2.GetGrade() << std::endl;

    return 0;
}