#include<iostream>
using namespace std;

class B;// foreward declaration
class A
{
	int a;
	public:
		friend int compare(A,B);
		void get_data()
		{
			cout<<"Enter number:";
			cin>>a;
		}
		void showdata()
		{
			cout<<"the number is: "<<a<<endl;
		}
		int geta()
		{
			return a;
		}
};

class B
{
	int a;
	public:
		friend int compare(A,B);
		void get_data()
		{
			cout<<"Enter number:";
			cin>>a;
		}
		void showdata()
		{
			cout<<"the number is: "<<a<<endl;
		}
		int geta()
		{
			return a;
		}
};

int compare(A obja, B objb)
{
	if(obja.a > objb.a)
		return obja.a;
	return objb.a;
}

int main()
{
	A obja;
	B objb;
	obja.get_data();
	objb.get_data();
	int c = compare(obja,objb);
	cout<<"The greater number is: "<<c<<endl;
	return 0;
}

