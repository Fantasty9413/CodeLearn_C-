# include <iostream>

struct Position
{
    int x;
    int y;
};

class Point
{
    private:
    static int num;
    Position position;

    public:
    Point(int x = 0, int y = 0);
    void SetPosition(int x, int y);
    friend std::ostream &operator << (std::ostream &output, const Point point);
};

int Point::num = 0;

Point::Point(int x, int y)
{
    position.x = x;
    position.y = y;
}

void Point::SetPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

std::ostream &operator << (std::ostream &output, const Point point)
{
    output << "Position of point: ";
    output << "x = " << point.position.x;
    output << ", ";
    output << "y = " << point.position.y;
    output << '\n';
    return output;
}

int main()
{
    Point point1(1, 1);
    std::cout << point1;

    Point& point2 = point1;

    point2.SetPosition(2, 3);
    std::cout << point1;

    Point *point3 = new Point(3, 3);
    std::cout << *point3;

    return 0;
}