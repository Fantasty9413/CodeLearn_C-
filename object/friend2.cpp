# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Line
{
    private:
    static int num;
    double len;

    public:
    Line();
    Line(double len);
    ~Line();
    void setlen(double len);
    friend double getlen(Line line);
    friend int getnum();
};

int Line::num = 0;

Line::Line()
{
    this->len = 0;
    num++;
}

Line::Line(double len)
{
    this->len = len;
    num++;
}

Line::~Line()
{

}

void Line::setlen(double len)
{
    this->len = len;
}

double getlen(Line line)
{
    return line.len;
}

int getnum()
{
    return Line::num;
    // return 0;
}

int main()
{
    vector<Line> v;
    v.resize(10);
    cout << "the capacity of v is " << v.capacity() << '\n';

    for(int i=0; i<v.size(); i++)
    {
        v.at(i).setlen(i);
    }  

    Line l1(1);
    Line l2(2);
    Line l3(3);

    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);

    cout << "num of line is " << getnum() << '\n';

    cout << "the capacity of v is " << v.capacity() << '\n';
    
    for(int i=0; i<v.size(); i++)
    {
        cout << i << "th line's len is " << getlen(v.at(i)) << '\n';
        cout << "num of line is " << getnum() << '\n';
    }    

    cout << "l1's len is " << getlen(l1) << '\n';

    cout << "num of line is " << getnum() << '\n';

    return 0;
}