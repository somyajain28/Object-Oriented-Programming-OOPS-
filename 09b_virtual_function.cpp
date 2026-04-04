#include<iostream>
using namespace std;

class Shape
{	
	protected:
		int x,y;
	public:
		Shape(int a, int b)
		{
			x = a;
			y = b;
			cout<<"Inside shape"<<endl;
		}
		virtual void area()=0;
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
			cout<<"Square is "<<x*x<<endl;
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
			cout<<"Rectangle is "<<x*y<<endl;
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
			cout<<"Triangle is "<<(x*y)/2<<endl;
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
	Shape *sh;
	sh = &s;
	sh->area(); 
	sh = &r;
	sh->area();
	sh = &t;
	sh->area();          
}