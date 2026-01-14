#include<iostream>
using namespace std;
class arithimatic
{
	private:
		float a,b;
	public:
		void get_data()
		{
			cout<<"Enter two numbers:";
			cin>>a>>b;
		}
		void add()
		{
			cout<<"Addition: "<<a+b<<endl;
		}
		void sub()
		{
			cout<<"Subtraction: "<<a-b<<endl;
		}
		void mul()
		{
			cout<<"Multiplication: "<<a*b<<endl;
		}
		void div()
		{	if(b != 0)
				cout<<"Division: "<<a/b<<endl;
			else 
				cout<<"Division not possible"<<endl;
		}
};

int main()
{
	arithimatic a;
	int ch;
	do
	{
		cout<<"*--MENU--*"<<endl;
		cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch>=1 && ch<=4)
			a.get_data();
		switch(ch)
		{
			case 1:
				a.add();
				break;
			case 2:
				a.sub();
				break;
			case 3:
				a.mul();
				break;
			case 4:
				a.div();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;;
		}
	}while(1);
	return 0;
}
