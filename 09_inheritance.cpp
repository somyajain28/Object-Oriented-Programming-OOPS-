#include<iostream>
using namespace std;

class Shape
{	
	protected:
		int x,y,area1;
	public:
		Shape(int a, int b)
		{
			x = a;
			y = b;
			cout<<"Inside shape"<<endl;
		}
//		void getdata()
//		{
//			cin>>x>>y;
//		}
		void area()
		{
			area1 = x*y;
			cout<<"The area of ";
		}
		~Shape()
		{
			cout<<"Destructor of shape"<<endl;
		}
};
class Square: public Shape
{
	public:
		Square(int a):Shape(a,a)
		{
			cout<<"Inside Square"<<endl;
		}
		void area()
		{
//			cout<<"Enter the side of square: ";
//			cin>>x;
			Shape::area();
			cout<<"Square is "<<area1<<endl;
		}
		~Square()
		{
			cout<<"Destructor of Square"<<endl;
		}
};
class Rectangle: public Shape
{
	public:
		Rectangle(int a,int b):Shape(a,b)
		{
			cout<<"Inside Rectangle"<<endl;
		}
		void area()
		{
//			cout<<"Enter length and breadth of rectangle: ";
//			Shape::getdata();
			Shape::area();
			cout<<"Rectangle is "<<area1<<endl;
		}
		~Rectangle()
		{
			cout<<"Destructor of Rectangle"<<endl;
		}
};
class Triangle: public Shape
{
	public:
		Triangle(int a,int b):Shape(a,b)
		{
			cout<<"Inside Triangle"<<endl;
		}
		void area()
		{
//			cout<<"Enter length and height of triangle: ";
//			Shape::getdata();
			Shape::area();
			cout<<"Triangle is "<<area1/2<<endl;
		}
		~Triangle()
		{
			cout<<"Destructor of Triangle"<<endl;
		}
};
int main()
{
	Square s(2);
	Rectangle r(2,3);
	Triangle t(2,3);
	s.area();
	r.area();
	t.area();
}