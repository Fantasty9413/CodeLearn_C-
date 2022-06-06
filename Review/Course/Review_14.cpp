# include <iostream>
# include <algorithm>
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
    bool operator==(const Box &box);
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

bool Box::operator==(const Box &box)
{
    return ((len==box.len)&&(wid==box.wid));
}

int main()
{
    std::vector<Box> boxs;
    int N = 4;
    for(int i=0; i<N; i++)
    {
        boxs.push_back(Box(i, i));
    }

    Box *box = new Box(2, 2);
    
    std::vector<Box>::iterator it = boxs.begin();
    std::vector<Box>::iterator pos = find(boxs.begin(), boxs.end(), *box);

    if(pos != boxs.end())
    {
        std::cout << "get it in the stl" << '\n';
    } 
    else
    {
        std::cout << "not get it in the stl" << '\n';
    }
    

    return 0;
}