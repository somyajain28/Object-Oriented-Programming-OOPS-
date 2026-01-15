#include<iostream>
using namespace std;

class Box
{
	int l,b,h,v;
	int vol()
	{
		v = l*b*h;
		return v;	
	}
	public:
		friend bool compare(Box,Box);
		Box()
		{
			v= l*b*h;
		}
		void getdata()
		{
			cout<<"\nEnter length:";
			cin>>l;
			cout<<"\nEnter width:";
			cin>>b;
			cout<<"\nEnter height:";
			cin>>h;
		}
		void showdata()
		{
			cout<<"Length:"<<l<<endl;
			cout<<"Width:"<<b<<endl;
			cout<<"Height:"<<h<<endl;
			cout<<"Volume:"<<vol()<<endl<<endl;
		}
};

bool compare(Box a, Box b)
{
	if(a.vol() > b.vol())
		return true;
	return false;
}

int main()
{
	Box a,b;
	int ch;
	do
	{
		cout<<"\n*--BOX MENU--*"<<endl;
		cout<<"\n1.Enter details\n2.Show details\n3.Compare volume\n4.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter details of first box: "<<endl;
				a.getdata();
				cout<<"\nEnter details of second box: "<<endl;
				b.getdata();
				break;
			case 2:
				cout<<"\nDetails of first box: "<<endl;
				a.showdata();
				cout<<"\nDetails of second box: "<<endl;
				b.showdata();
				break;
			case 3:
				if(compare(a,b))
					cout<<"First box has greater volume."<<endl;
				else
					cout<<"Second box has greater volume."<<endl;
				break;
			case 4:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;	
		}
	}while(1);
	return 0;
}