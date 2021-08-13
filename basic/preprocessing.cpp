# include <iostream>
// # define test
// # define PI 3.14159
# define MIN(a, b) (a<b? a: b)

# ifndef PI
    # define PI 3.14159
# endif

namespace Shape
{
    class Circle
    {
        private:
        int r;

        public:
        Circle(int r = 1);
        double getarea();
    };

    Circle::Circle(int r):r(r){ }

    double Circle::getarea(){ return PI*r*r; }
}

int main()
{
    Shape::Circle circle(2);
    std::cout << "get area: " << circle.getarea() << '\n';
    std::cout << "PI: " << PI << '\n';

    #ifdef test
        std::cout << "it's a test for dev. " << '\n';
        std::cout << MIN(1, 2) << '\n';
    #endif

    # if 0
        std::cout << "it's uncompiled. " << '\n';
    # endif

    std::cout << "_LINE_ : " << __LINE__ << '\n';
    std::cout << "_FILE_ : " << __FILE__ << '\n';
    std::cout << "_DATE_ : " << __DATE__ << '\n';
    std::cout << "_TIME_ : " << __TIME__ << '\n';
    
    return 0;
}