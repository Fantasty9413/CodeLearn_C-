# include <iostream>
# include <string>
using namespace std;

class Line
{
    private:
    int *ptr;

    public:
    void setLength(int len);
    int getLength(void);
    Line(int len);
    Line(const Line &obj);
    ~Line();
};

void Line::setLength(int len)
{
    *ptr = len;
}

int Line::getLength(void)
{
    return *ptr;
}

Line::Line(int len)
{
    cout << "调用构造函数" << '\n';
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数为指针ptr分配内存" << '\n';
    ptr = new int;
    *ptr = *obj.ptr;        // 拷贝
}

Line::~Line()
{
    cout << "调用析构函数，释放内存" << '\n';
    delete ptr;
}

void display(Line obj)
{
    cout << "线段的长度是： " << obj.getLength() << '\n';
}

int main()
{
    Line line(10);
    Line line2(line);

    display(line);
    display(line2);
    
    return 0;
}
