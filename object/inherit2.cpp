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
      Shape(int width = 3, int height = 5)
      {
         this->width = width;
         this->height = height; 
      }
      int getwid()
      {
         return width;
      }
      int gethei()
      {
         return height;
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
   cout << "the area of rect is " << rect.getArea() << '\n';

   Shape sp;
   cout << "wid: " << sp.getwid() << "  ";
   cout << "hei: " << sp.gethei() << '\n'; 

   Rectangle rect2;
   cout << "the area of rect2 is " << rect2.getArea() << '\n';   // 调用了父类的构造函数

   return 0;
}