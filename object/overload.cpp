# include <iostream>
# include <string>
using namespace std;

class rectangle
{
    private:
    double len;
    double wid;

    public:
    rectangle(double len = 5, double wid = 5);
    double getarea();
    rectangle operator+ (const rectangle& rec);
};

rectangle::rectangle(double len, double wid)
{
    this->len = len;
    this->wid = wid;
}

double rectangle::getarea()
{
    return len*wid;
}

rectangle rectangle::operator+(const rectangle& rec)
{
    rectangle r;
    r.len = this->len + rec.len;
    r.wid = this->wid + rec.wid;
    return r;
}

int main()
{
    rectangle rec1;
    rectangle rec2;
    rectangle rec3;
    rec3 = rec1 + rec2;

    cout << "area of rec1 is " << rec1.getarea() << '\n';
    cout << "area of rec2 is " << rec2.getarea() << '\n';  
    cout << "area of rec3 is " << rec3.getarea() << '\n';       

    return 0;
}
