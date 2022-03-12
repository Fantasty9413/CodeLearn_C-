# include <iostream>
# include <vector>

class Box
{
    private:
    int len;
    int wid;

    public:
    static int num;
    Box();
    Box(int len, int wid);
    int GetArea();
};

int Box::num = 0;

Box::Box()
{
    this->len = 1;
    this->wid = 1;
}

Box::Box(int len, int wid): len(len), wid(wid)
{}

int Box::GetArea()
{
    return (len*wid);
}

int main()
{
    std::vector<Box> box;
    int N = 4;
    for(int i=0; i<N; i++)
    {
        box.push_back(Box(i, i));
    }
    
    std::vector<Box>::iterator it = box.begin();
    while(it != box.end())
    {
        std::cout << "the area of box is " << (*it).GetArea() << std::endl;
        it++;
    }

    return 0;
}