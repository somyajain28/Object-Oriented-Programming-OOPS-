#include<iostream>
using namespace std;

void add(int,int);
void add(float,float);

int main()
{
	int a,b;
	float x,y;
	int ch;
	do
	{
		cout<<"*--MENU--*"<<endl;
		cout<<"1.Addition of integers \n2.Addition of float values\n3.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter two numbers:";
				cin>>a>>b;
				add(a,b);
				break;
			case 2:
				cout<<"Enter two numbers:";
				cin>>x>>y;
				add(x,y);
				break;
			case 3:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;;
		}
	}while(1);
	return 0;
}

void add(int a, int b)
{
	cout<<"Addition: "<<a+b<<endl;
}
void add(float a, float b)
{
	cout<<"Addition: "<<a+b<<endl;
}

