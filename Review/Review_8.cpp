# include <iostream>

class Box
{
    private:
    double* len;

    public:
    Box();
    Box(double* len);
    Box(const Box &obj);
    double get(void);
};

Box::Box()
{
    len = new double[3];
}

Box::Box(double* len)
{
    this->len = len;
}

double Box::get(void)
{
    double length = *len;
    double width = *(len+1);
    double height = *(len+2);

    return (length*width*height);
}

Box::Box(const Box &obj)
{
    len = new double[3];
    for(int i=0; i<3; i++)
    {
        *(len+i) = *(obj.len+i);
    }
}

int main()
{
    double len[] = {1, 5, 9};
    Box box(len);
    std::cout << box.get() << std::endl;

    Box box2(box);
    std::cout << box2.get() << std::endl;    

    return 0;
}
