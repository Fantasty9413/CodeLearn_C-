# include <iostream>

class Box
{
    private:
    int len;
    int wid;

    public:
    static int num;
    Box();
    Box(int len, int wid);
    friend void PrintLen(const Box &box);
    friend void PrintWid(const Box &box);
};

int Box::num = 0;

Box::Box()
{
    this->len = 1;
    this->wid = 1;
}

Box::Box(int len, int wid): len(len), wid(wid)
{}

void PrintLen(const Box &box)
{
    std::cout << "the len of the box is " << box.len << std::endl;
}

void PrintWid(const Box &box)
{
    std::cout << "the wid of the box is " << box.wid << std::endl;
}

int main()
{
    Box *box = nullptr;
    box = new Box(1, 3);
    PrintLen(*box);
    PrintWid(*box);

    return 0;
}