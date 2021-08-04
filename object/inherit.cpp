# include <iostream>
# include <string>

using namespace std;

class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main()
{
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(7);

    Shape sp;
    sp.setHeight(2);
    sp.setWidth(3);

    cout << "the area of rect is " << rect.getArea() << '\n';

    return 0;
}