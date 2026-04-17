#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

class Student
{	
	
	static int count;
	protected:
		int roll_no;
		string name;
	public:
		Student()
		{
			count++;
			roll_no = count;			
		}
};
int Student:: count = 0;
class Academic: virtual public Student
{	protected:
		int maths,physics,chemistry;
	public:
		int total_aca()
		{
			return maths+physics+chemistry;
		}
};
class Sports: virtual public Student
{
	protected:
		int basketball,cricket;
	public:
		int total_sp()
		{
			return basketball+cricket;
		}
};
class Result: public Academic,public Sports
{
	int a;
	public:
		friend istream& operator >>(istream &is, Result &obj);
		void print_line(char ch,int n)
		{
			for(int i = 0; i < n; i++)
				cout<<ch;
			cout<<endl;
		}
		void display_report()
		{
			print_line('=',70);
			cout<<setw(40)<<"REPORT CARD"<<endl;
			print_line('=',70);
			cout<<"Roll.No: "<<roll_no<<endl;
			cout<<"Name of student: "<<name<<endl;
			print_line('-',70);
			cout<<setw(6)<<"S.No"<<setw(15)<<"Subject"<<setw(20)<<"Max Marks"<<setw(20)<<"Obtained Marks"<<endl;
			print_line('-',70);
			cout<<setw(6)<<1<<setw(15)<<"Maths"<<setw(20)<<100<<setw(20)<<maths<<endl;
			cout<<setw(6)<<2<<setw(15)<<"Physics"<<setw(20)<<100<<setw(20)<<physics<<endl;
			cout<<setw(6)<<3<<setw(15)<<"Chemistry"<<setw(20)<<100<<setw(20)<<chemistry<<endl;
			cout<<setw(6)<<3<<setw(15)<<"Basketball"<<setw(20)<<100<<setw(20)<<basketball<<endl;
			cout<<setw(6)<<3<<setw(15)<<"Cricket"<<setw(20)<<100<<setw(20)<<cricket<<endl;
			print_line('-',70);
			cout<<"Total Academic Marks: "<<total_aca()<<endl;
			cout<<"Total Sports Marks: "<<total_sp()<<endl;
			cout<<"Total Marks: "<<total_re()<<endl;
			cout<<"Average Marks: "<<avg_re()<<endl;
			cout<<"Percentage: "<<percentage()<<"%"<<endl;
			print_line('=',70);
		}	
		int total_re()
		{
			return total_aca() + total_sp();
		}
		int avg_re()
		{
			int a;
			a = total_re();
			return a/5;
		}
		int percentage()
		{
			int a1,b;
			a1 = total_re();
			b = (a1*100)/500;
			return b;
		}	
};
istream& operator >>(istream &is, Result &obj)
{
	cout<<"Enter name: ";
	is>>obj.name;
	//academic
	cout<<"Enter marks of maths: ";
	is>>obj.maths;
	cout<<"Enter marks of physics: ";
	is>>obj.physics;
	cout<<"Enter marks of chemistry: ";
	is>>obj.chemistry;
	//sports
	cout<<"Enter marks of Basketball: ";
	is>>obj.basketball;
	cout<<"Enter marks of Cricket: ";
	is>>obj.cricket;
	return is;
}
int main()
{
	int n;
	cout<<"Enter the number of sudents:";
	cin>>n;
	Result r[10];
	int ch,i;
	do
	{
		cout<<"*--MENU--*"<<endl;
		cout<<"1.Enter student details\n2.print report card\n3.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
						cin>>r[i];
				break;
			case 2:
				if(i == 0)
					cout<<"\n No student data available"<<endl;
				else
				{
					for(int i = 0; i<n;i++)
					{
						system("CLS");
						r[i].display_report();
						cout<<"Press any button to continue"<<endl;
						getch();
					}
				}
				break;
			case 3:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(1);
	return 0;
}