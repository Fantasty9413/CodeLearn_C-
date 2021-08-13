# include <iostream>
using std::cout;

namespace first_space
{
    class Line
    {
        private:
        int len;

        public:
        Line(int len = 5);
        int getlen();
    };

    Line::Line(int len)
    {
        this->len = len;
    }

    int Line::getlen()
    {
        return this->len;
    }
}


int main()
{
    cout << "using std::endl. " << std::endl;
    first_space::Line line;
    cout << "the len of line is " << line.getlen();
    return 0;
}
