# include <iostream>

class Box
{
    private:
    double length;
    double width;
    double height;

    public:
    static int num;
    Box(void);
    Box(double len, double wid, double hei);
    ~Box();
    void set(double len, double wid, double hei);
    double get(void);
};

int Box::num = 0;

Box::Box(void)
{
    this->length = 0;
    this->width = 0;
    this->height = 0;
    num++; 
}

Box::Box(double len, double wid, double hei): length(len), width(wid), height(hei)
{
    num++;
}

Box::~Box()
{
    num--;
}

void Box::set(double len, double wid, double hei)
{
    this->length = len;
    this->width = wid;
    this->height = hei;
}

double Box::get(void)
{
    return (length*width*height);
}

int main()
{
    Box *box = new Box[10];
    auto ptr = box;

    std::cout << "the quantity of box is " << Box::num << std::endl;

    for(int i=0; i<10; i++)
    {
        ptr->set(i, i, i);
        std::cout << "the volume of " << i << "th box is "  << ptr->get() << std::endl;
        ptr++;
    }

    delete[] box;
    std::cout << "the quantity of box is " << Box::num << std::endl;

    return 0;
}